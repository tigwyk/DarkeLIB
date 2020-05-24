// DarkeMUD generic weapon object.  See /doc/build/weapons for information
// on using.
// Modified by Geldron 031096 to fix bugs
// -Diewarzau 3/19/94

#include "/adm/include/config.h"
#include "/adm/include/std.h"

#define VALID_TYPES ({ "rusted", "cheap", "decent", "fine", "very fine",\
	"superb", "unsurpassed" })


inherit OBJECT;

private mapping __Weapon;

int __Wield(string str);
int __Unwield(string str);
varargs void set_ac(int x,string type);
string query_verb();
void set_verb(string verb);
void set_wc(int x, string type);
void set_enh_critical(mixed x);
void set_auto_critical(mixed type);
void set_hit(mixed val);
void set_wield(mixed val);
void set_unwield(mixed val);
void set_type(string str);
void set_decay_rate(int x);
void add_poisoning(int x);
int query_ac(string type);
string *query_ac_types();
mapping query_all_ac();
mixed query_enh_critical();
string *query_auto_critical();
int query_wc(string type);
string *query_wc_types();
mapping query_all_wc();
mixed query_hit();
mixed query_wield();
mixed query_unwield();
void set_short(string desc);
object query_wielded();
string query_type();
int query_decay_rate();
int query_poisoning();
int is_weapon();
int query_parry_bonus();
void set_parry_bonus(int x);
void unequip();
void __ActuallyUnwield();
void set_not_equipped();
void decay();
void set_quality(int x);
int query_quality();
string query_quality_desc();

#ifdef __OLD_ROOM_BEHAVIOUR
#include <old_weapon.h>
#endif /* __OLD_ROOM_BEHAVIOUR */

void create() {
    ::create();
    __Weapon = ([]);
    __Weapon["verb"] = "hit";
    set_material("metal/iron");
    set_decay_rate(200);
}

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("__Wield", "wield");
    add_action("__Unwield", "unwield");
    if(__Weapon["throwable"])
      add_action("throw_me", "throw");
}

void set_throwable(int x) { __Weapon["throwable"] = x; }

int throw_me(string arg) {
  string what, at, *wc_keys, limb, *crits;
  object who;
  mapping wc, tmp_res;
  int res, i;
  mixed w_hit, tmp_mix;

  if(sscanf(arg, "%s at %s", what, at) != 2) return 0;
  if(environment(this_player())->query_property("no attack")) {
    write("Mystic forces prevent your aggression.");
    return 1;
  }
  wc_keys = (string *)this_player()->query_wielding_limbs();
  if(!wc_keys || !(i=sizeof(wc_keys))) {
    write("You cannot throw a weapon with no wielding limbs!");
    return 1;
  }
  res = 0;
  while(i--)
    if(!this_player()->query_weapon(wc_keys[i])) res = 1;
  if(!res) {
    write("You must have a free hand to throw a weapon.");
    return 1;
  }
  if(present(what, this_player()) != this_object()) return 0;
  if(time() - (int)this_player()->query("last throw") < 4) {
    write("You may only throw a weapon every other round.");
    return 1;
  }
  this_player()->set("last throw", time());
  if(this_object()->query_wielded()) {
    write("You may not throw a wielded weapon.");
    return 1;
  }
  who = present(at, environment(this_player()));
  if(!who) {
    write("There is no '"+at+"' here.");
    return 1;
  }
  if(!living(who)) {
    write("You could do that, but I doubt it would do much good.");
    return 1;
  }
  message("my_combat", "You throw " + article((string)this_object()->
					      query_name()) +
	  " at "+ (string)who->query_cap_name()+".", this_player());
  res = (skill_contest((int)this_player()->query_skill("thrown"),
		       ((int)who->query_skill("dodge") -
			to_int(percent((int)who->query_internal_encumbrance(),
				       (int)who->
				       query_max_internal_encumbrance()))),
		       1) != 1 && !who->query_paralyzed());
  res = (res || skill_contest((int)this_player()->query_skill("thrown"),
			      (int)who->query_skill("parry missile"), 1) != 1);
  who->kill_ob(this_player(), 1);
  if(res) {
    message("my_combat", "You miss pitifully.", this_player());
    message("other_combat", (string)this_player()->query_cap_name() +
	    " misses you with "+article((string)this_object()->query_name())+
	    " which "+nominative(this_player())+ " threw at you.",
	    who);
    message("other_combat", (string)this_player()->query_cap_name()+
	    " hurls "+article((string)this_object()->query_name())+
	    " at "+ (string)who->query_cap_name() + 
	    " but misses pitifully.", all_inventory(environment(this_player())),
	    ({ this_player(), who }) );
    this_object()->remove();
    return 1;
  }
  message("other_combat", (string)this_player()->query_cap_name() +
	  " hits you with "+article((string)this_object()->query_name())+
	  " which "+nominative(this_player())+ " threw at you.",
	  who);
  message("my_combat", "You hit "+objective(who)+"!", this_player());
  message("other_combat", (string)this_player()->query_cap_name()+
	  " hurls "+article((string)this_object()->query_name())+ 
	  " at "+ (string)who->query_cap_name() +
	  ", hitting "+ objective(who)+".",
	  all_inventory(environment(this_player())),
	  ({ this_player(), who }) );
  wc = (mapping)this_player()->get_damage(this_object());
  if(!mapp(wc)) return 1;
  w_hit = this_object()->query_hit();
  if(functionp(w_hit)) {
    w_hit = (*w_hit)(who);
    if(intp(w_hit)) tmp_res = ([ "crushing" : w_hit ]);
    else if(mapp(w_hit)) tmp_res = w_hit;
  } else if(pointerp(w_hit)) {
    i = sizeof(w_hit);
    tmp_res = ([]);
    while(i--) {
      if(!functionp(w_hit[i])) continue;
      tmp_mix = (*w_hit[i])(who);
      if(intp(tmp_mix)) tmp_res += ([ "crushing" : tmp_mix ]);
      else if(mapp(tmp_mix)) tmp_res += tmp_mix;
    }
  }
  if(!tmp_res) tmp_res = ([]);
  wc += tmp_res;
  wc_keys = keys(wc);
  i = sizeof(wc_keys);
  limb = (string)who->return_target_limb();
  if(!limb) return 1;
  crits = ({});
  while(i--) {
    res = wc[wc_keys[i]] - (int)who->query_ac(limb, wc_keys[i]);
    if(res < 0) res = 0;
    who->do_damage(limb, res * 2);
    res -= (random(100) - 50);
    switch(res) {
    case 0..20:
      crits += ({ sprintf("%s A", wc_keys[i]) });
      break;
    case 21..40:
      crits += ({ sprintf("%s B", wc_keys[i]) });
      break;
    case 41..65:
      crits += ({ sprintf("%s C", wc_keys[i]) });
      break;
    case 66..90:
      crits += ({ sprintf("%s D", wc_keys[i]) });
      break;
    case 91..10000:
      crits += ({ sprintf("%s E", wc_keys[i]) });
      break;
    }
  }
  do_critical(this_player(), who, crits);
  this_object()->remove();
  return 1;
}

string query_long(string null) {
  string res;
  int i;
  mixed tmp;

if(::query_long(null))
  res = ::query_long(null);
/* Added by Geldron 031096, fixes a couple bugs */
if(!res) res = "";
if(stringp(query_type()))
    res += sprintf("\nThis weapon uses the skill: %s.\n",
      query_type());
//HONSPRON 2020 Add brittle to weapons so people know when they might explode
    res += sprintf("\nIt is fashioned of: %s.\n",
   this_object()->query_property("material_name"));
res += sprintf("\nTotal Magic: %d",
   this_object()->query_property("brittle"));
  if(tmp=query_property("extra long")) {
    if(stringp(tmp)) res += "\n"+tmp;
    else if(pointerp(tmp)) {
      i = sizeof(tmp);
      while(i--) {
        if(stringp(tmp[i]))
          res += "\n"+tmp[i];
        else if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2) {
          if(random(100) < (int)this_player()->query_skill(tmp[i][1]))
            res += "\n"+tmp[i][0];
        }
      }
    }
  }
return res;
}

int __Wield(string str) {
    object ob;
    function *funx;
    int i;
    string what, hand1, hand2, ok;

    if(!str) return notify_fail("Wield what?\n");
    if(sscanf(str, "%s in %s", what, hand1) != 2)
	return notify_fail("In what hand?\n");
    if(!id(what)) {
	if(!(ob = parse_objects(this_player(), what))) return 0;
	if(ob != this_object()) return 0;
	what = query_name();
    }
    if(query("skill level") > (int)this_player()->query_skill(query_type()))
	return notify_fail("You do not have the talent to use that weapon.\n");

//HONSPRON 2020
    if(this_player()->is_player() &&
      (int)this_player()->query_skill(query_type()) < (int)query_property("brittle"))
        return notify_fail("There is too much magic inside this weapon for you to control.\n");

    if(__Weapon["wielded"]) {
	message("my_action", "You are already wielding that!\n",this_player());
	return 1;
    }
    if(__Weapon["type"][0..9] == "two handed") {
	str = hand1;
	if(sscanf(str, "%s and %s", hand1, hand2) != 2) {
	    message("my_action", "You must wield such a weapon with two hands.\n",
	      this_player());
	    return 1;
	}
	if(functionp(__Weapon["wield"]) && !((*__Weapon["wield"])())) return 1;
	if(pointerp(__Weapon["wield"])) {
	    funx = __Weapon["wield"];
	    i = sizeof(funx);
	    while(i--)
		if(!(*funx[i])()) return 1;
	}
	ok = (string)this_player()->equip_weapon_to_limb(this_object(), hand1,
	  hand2);
    }
    else {
	if(sscanf(hand1, "%s and %s", str, hand2) == 2) {
	    message("my_action", "You must only use one hand to wield that "+
	      "weapon.", this_player());
	    return 1;
	}
	if(pointerp(__Weapon["wield"])) {
	    funx = __Weapon["wield"];
	    i = sizeof(funx);
	    while(i--)
		if(!(*funx[i])()) return 1;
	}
	if(functionp(__Weapon["wield"]) && !((*__Weapon["wield"])())) return 1;
	ok  = (string)this_player()->equip_weapon_to_limb(this_object(),hand1,0);
    }
    if(ok) {
	message("my_action", ok, this_player());
	return 1;
    }
    if(stringp(__Weapon["wield"]))
	message("my_action", __Weapon["wield"], this_player());
    else message("my_action", "You wield "+query_short()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name() +
      " wields " + query_short() + ".", environment(this_player()),
      ({ this_player() }));
    __Weapon["wielded"] = this_player();
    __Weapon["limb string"] = " (wielded in " + hand1 +
    (hand2 ? " and "+hand2+")" : ")");
    return 1;
}

int __Unwield(string str) {
    object ob;
    function *funx;
    int i;

    if(!str) return notify_fail("Unwield what?\n");
    if(!id(str)) {
	if(!(ob = parse_objects(this_player(), str)) || (ob != this_object()))
	    return notify_fail("You don't have that!\n");
	str = query_name();
    }
    if(!__Weapon["wielded"])
	return notify_fail("You are not wielding that!\n");
    if(functionp(__Weapon["unwield"]) && !((*__Weapon["unwield"])())) return 1;
    if(pointerp(__Weapon["unwield"])) {
	funx = __Weapon["unwield"];
	i = sizeof(funx);
	while(i--)
	    if(!(*funx[i])()) return 1;
    }
    __ActuallyUnwield();
    return 1;
}

void set_parry_bonus(int x) { __Weapon["parry bonus"] = x; }

int query_parry_bonus() { return __Weapon["parry bonus"]; }

void set_hit_bonus(int x) { __Weapon["hit bonus"] = x; }

int query_hit_bonus() {
	int stf;
	if(query_wielded()) {
		if(query_property("balanced") && 
			query_property("balanced") ==
			(string)query_wielded()->query_name()) {
			stf = query_property("balanced hit bonus");
		}
		else {
			if(query_property("balanced") && 
				query_property("balanced") != 
				(string)query_wielded()->query_name()) {
				stf = 5 - query_property("balanced hit bonus");
			}
	}}
    if(!undefinedp(__Weapon["hit bonus"]))
	return prop("hit bonus") + __Weapon["hit bonus"] + 3*(query_quality()-2) + stf;
    else return prop("hit bonus") + 3*(query_quality()-2) + stf; 
}

int id(string str) {
    if(::id(str)) return 1;
    return ::id(replace_string(str, query_quality_desc()+" ", ""));
}

varargs void set_ac(int x, string type) {
    int i;

    if(!__Weapon["ac"]) __Weapon["ac"] = ([]);
    if(!type || !stringp(type)) {
	for(i=0;i<sizeof(DAMAGE_TYPES);i++) {
	    __Weapon["ac"][DAMAGE_TYPES[i]] = x;
	} return; }
    if(member_array(type, DAMAGE_TYPES) < 0) return;
    else
	__Weapon["ac"][type] = x;
}

void set_quality(int x) {
    if(x >= sizeof(VALID_TYPES) || x < 0) __Weapon["quality"] = 2;
    else __Weapon["quality"] = x;
}

int query_quality() { return __Weapon["quality"]; }

string query_quality_desc() {
    if(__Weapon["quality"] < 0) {
	if(living(environment()))
	    message("info", "Your weapon shatters in twain!!!", environment());
	remove();
	return 0;
    }
    return VALID_TYPES[__Weapon["quality"]];
}

void set_enh_critical(mixed x) {
    if(mapp(x) || intp(x))
	__Weapon["enhance critical"] = x;
    return;
}

void set_auto_critical(mixed type) {
    string dmg_type, level;

  if(stringp(type)) {
    if(sscanf(type,"%s %s",dmg_type,level) != 2) {
      if(member_array(type,DAMAGE_TYPES) < 0) return;
      type = type + " A";
    }
    type = dmg_type + " " + capitalize(level);
    if(!__Weapon["auto critical"]) __Weapon["auto critical"] = ({ type });
    else __Weapon["auto critical"] += ({ type });
  }
  else if(pointerp(type) || mapp(type))
    __Weapon["auto critical"] = type;
}

string query_verb() { return __Weapon["verb"]?__Weapon["verb"]:"hit"; }

void set_verb(string verb) {
    __Weapon["verb"] = verb;
}

void set_wc(int x, string type) {
    if(!type || !stringp(type)) type = DAMAGE_TYPES[0];
    if(member_array(type, DAMAGE_TYPES) < 0) return;
    if(!__Weapon["decay rate"]) __Weapon["decay rate"] = 10000/(x+1);
    if(!__Weapon["wc"]) __Weapon["wc"] = ([ type : x ]);
    else __Weapon["wc"][type] = x;
    if(!__Weapon["original wc"]) __Weapon["original wc"] = ([]);
    if(!__Weapon["original wc"][type]) __Weapon["original wc"][type] = x;
}

void set_hit(mixed val) {
    if(!val) __Weapon["hit"] = 0;
    if(!functionp(val) && !pointerp(val) && !stringp(val)) return;
    if(functionp(val)) __Weapon["hit"] = bind(val, this_object());
    else
    __Weapon["hit"] = val; 
}

void set_wield(mixed val) {
    if(!stringp(val) && !functionp(val) && !pointerp(val)) return;
    __Weapon["wield"] = val;
}

void set_unwield(mixed val) {
    if(!functionp(val) && !stringp(val) && !pointerp(val)) return;
    __Weapon["unwield"] = val;
}

void set_type(string str) { __Weapon["type"] = str; }

void set_decay_rate(int x) { __Weapon["decay rate"] = x; }

void add_poisoning(int x) {
    if(!__Weapon["poison"]) __Weapon["poison"] = x;
    else __Weapon["poison"] += x;
    if(__Weapon["poison"] < 1) map_delete(__Weapon, "poison");
}

string query_short() {
    string tmp;

    tmp = ::query_short();
    if(!props["no add quality"])
	tmp = capitalize(article(query_quality_desc() + " " + tmp));
    if(!__Weapon["wielded"]) return tmp;
    else return tmp + __Weapon["limb string"];
}

string actual_short_desc() {
  if(__Weapon["short desc"])
  return __Weapon["short desc"];
  else return query("short desc");
}

void set_short(string desc) {
  __Weapon["short desc"] = desc;
  set("short desc", desc);
  ::set_short((: call_other, this_object(), "actual_short_desc" :));
}

int a_c_filter(string crit, mapping chance) {
  if(!mapp(chance) || !chance[crit]) return 0;
  if(random(100) < chance[crit]) return 1;
  return 0;
}

string *query_auto_critical() {
    string *ret, tmp;
    mixed auto_crit;
    int i;

    auto_crit = prop("auto critical");
    if(auto_crit && mapp(auto_crit)) {
      ret = filter_array(keys(auto_crit), "a_c_filter", this_object(),
        auto_crit);
    }
    else if(auto_crit && pointerp(this_object()->prop("auto critical")))
      ret = (string *)this_object()->prop("auto critical");
    else ret = ({});
    auto_crit = __Weapon["auto critical"];
    if(auto_crit && mapp(auto_crit)) {
      ret += filter_array(keys(auto_crit), "a_c_filter", this_object(),
        auto_crit);
      i = sizeof(ret);
      while(i--)
        if(sscanf(ret[i], "%s #%*d", tmp) == 2) ret[i] = tmp;
    }
    else if(auto_crit && pointerp(auto_crit)) ret += auto_crit;
    return ret;
}

mixed query_enh_critical() {
    int i;
    string *e_keys;
    mapping tmp;

    if(!prop("enhance criticals"))
	return __Weapon["enhance critical"];
    else if(intp(__Weapon["enhance critical"]))
	return __Weapon["enhance critical"] + prop("enhance criticals");
    else if(mapp(__Weapon["enhance critical"])) {
        e_keys = DAMAGE_TYPES;
	i = sizeof(e_keys);
	tmp = ([]);
	while(i--) {
	    if(!__Weapon["enhance critical"][e_keys[i]])
		tmp[e_keys[i]] = prop("enhance criticals");
	    else
		tmp[e_keys[i]] = prop("enhance criticals") +
		__Weapon["enhance critical"][e_keys[i]];
	}
	return tmp;
    }
    return 0;
}

int query_ac(string type) {
    string *dmg_types;
    if(!__Weapon["ac"]) return 0;
    dmg_types = keys(__Weapon["ac"]);
    if(!pointerp(dmg_types) || !sizeof(dmg_types)) return 0;
    if(!type || !stringp(type))
	type = dmg_types[0];
    return __Weapon["ac"][type];
}


string *query_ac_types() {
    if(!__Weapon["ac"]) return ({});
    return keys(__Weapon["ac"]);
}

mapping query_all_ac() {
    if(!__Weapon["ac"]) return ([]);
    return __Weapon["ac"];
}

int query_wc(string type) {
    string *dmg_types;
    int tmp,stf;
    mapping extra;

    if(!__Weapon["wc"]) return 0;
    dmg_types = keys(__Weapon["wc"]);
    if(!pointerp(dmg_types)) return 0;
    if(query_wielded()) {
    	if(query_property("balanced") &&
    		query_property("balanced") ==
			(string)query_wielded()->query_name()) {
			stf = query_property("balanced wc bonus"); 
		}
		else {
			if(query_property("balanced") &&
				query_property("balanced") != 
				(string)query_wielded()->query_name()) {
			stf = 5 - query_property("balanced wc bonus");
		}}
	}
    if(!type || !stringp(type)) type = dmg_types[0];
    tmp = __Weapon["wc"][type] + props["enchantment"] +
    ((__Weapon["wc"][type]/5)*(query_quality()-2)) + stf;
    if(intp(this_object()->prop("damage bonus")))
	tmp += (int)this_object()->prop("damage bonus");
    if(mapp(extra=query_property("extra wc")))
	    if(extra[type]) tmp += extra[type];
	if(mapp(extra=prop("extra wc")))
	    if(extra[type]) tmp += extra[type];
	if(tmp < 0) tmp = 0;
    return tmp;
}

mapping all_base_wc() {
  if(!__Weapon["wc"]) return ([]);
  return __Weapon["wc"];
}

mapping query_all_wc() {
    int i, tmp, stf;
    string *types;
    mapping ret_val, extra;

    if(!__Weapon["wc"]) return ([]);
    i = sizeof((types = query_wc_types()));
    if(i) ret_val = allocate_mapping(i);
    if(query_wielded()) {
    	if(query_property("balanced") &&
    		query_property("balanced") ==
			(string)query_wielded()->query_name()) {
			stf = query_property("balanced wc bonus"); 
		}
		else {
			if(query_property("balanced") &&
				query_property("balanced") != 
				(string)query_wielded()->query_name()) {
			stf = 5 - query_property("balanced wc bonus");
		}}
	}
    if(!mapp(extra=query_property("extra wc")))
      extra = ([]);
    if(prop("extra wc") && mapp(prop("extra wc"))) extra += prop("extra wc");
    while(i--) {
	tmp = __Weapon["wc"][types[i]] + props["enchantment"]+
	((__Weapon["wc"][types[i]]/5)*(query_quality()-2)) + stf;
	if(prop("damage bonus")) tmp += (int)prop("damage bonus");
	if(extra[types[i]]) tmp += extra[types[i]];
	if(tmp < 0) tmp = 0;
	ret_val[types[i]] = tmp; }
    return ret_val;
}

string *query_wc_types() {
  string *ret;
  
    if(!__Weapon["wc"]) return ({});
    ret = keys(__Weapon["wc"]);
    if(mapp(query_property("extra wc")))
      ret += keys(query_property("extra wc"));
    if(prop("extra wc") && mapp(prop("extra wc"))) ret += keys(prop("extra wc"));
    return distinct_array(ret);
}


mixed query_hit() { return __Weapon["hit"]; }

mixed query_wield() { return __Weapon["wield"]; }

mixed query_unwield() { return __Weapon["unwield"]; }

string query_type() { return __Weapon["type"]; }

object query_wielded() { return __Weapon["wielded"]; }

int query_decay_rate() { return __Weapon["decay rate"]; }

int query_poisoning() { return __Weapon["poison"]; }

int is_weapon() { return 1; }

void unequip() { 
  if(__Weapon["wielded"]) {
    if(functionp(__Weapon["unwield"]))
      evaluate(__Weapon["unwield"]);
    else if(pointerp(__Weapon["unwield"]))
      map_array(filter_array(__Weapon["unwield"],
			     (: functionp :)),
		(: evaluate :));
  }
  __ActuallyUnwield();
}

void __ActuallyUnwield() {
    if(!__Weapon["wielded"]) return;
    __Weapon["wielded"]->remove_weapon_from_limb(this_object());
    if(stringp(__Weapon["unwield"]))
	message("my_action", __Weapon["unwield"], __Weapon["wielded"]);
    else message("my_action", "You unwield "+query_short()+".",
	  __Weapon["wielded"]);
    message("other_action", (string)__Weapon["wielded"]->query_cap_name() +
      " unwields "+query_short()+".", environment(__Weapon["wielded"]),
      ({ __Weapon["wielded"] }));
    set_not_equipped();
}

void set_not_equipped() {
    map_delete(__Weapon, "wielded");
    map_delete(__Weapon, "limb string");
}

void decay() {
    if(undefinedp(__Weapon["quality"])) return;
    if(query_property("no decay")) return;
    __Weapon["decay status"]++;
    if(__Weapon["decay status"] >= __Weapon["decay rate"]) {
	if(__Weapon["quality"] <= 0) {
	    message("environment", "Your weapon shatters in twain!  "+
	      "It is now useless.", __Weapon["wielded"]);
	    remove();
	    return;
	}
	__Weapon["quality"]--;
	if(props["value"]) props["value"] /= 2;
	if(props["float value"]) props["float value"] /= 2.0;	
	message("environment", "You notice some wear on your "+
	  query_short()+".", __Weapon["wielded"]);
	__Weapon["decay status"] = 0;
    }
}

void repair(int amt) {
    __Weapon["decay status"] -= amt;
    if(__Weapon["decay status"] < 0) __Weapon["decay status"] = 0;
    return;
}

int query_decay_status() {
    return __Weapon["decay status"];
}
