/*
 * Lightsaber, altered to include:
 * 1. Ichthus's custom color code (/d/weap/cust_saber.c)
 * 2. Stavros's cortosis code (allowing for temporary wc reductions)
 *
 * I've tried to comment at places I've made changes.
 *
 * NOTE: To achieve the WC reduction, I've overridden query_wc()... This was 
 * the easiest and simplest way I could think of to achieve my goal, but if
 * there is any combat code out there that, for some reason, uses query_orig_wc
 * or query_real_wc, retracted lightsabers may act strangely.
 *
 * Stavros, 15 Apr 2010
 *
 * Now cleaned up so that the color lists are in defines, and everything uses
 * them instead of re-listing the colors in each function.
 */
// Merged practice sabers into saber.c
// Ichthus - 9/30/2011

#include <std.h>
#include <armour.h>
#include <abbr.h>
#include <daemons.h>
#include <saber.h>

inherit WEAPON;

int cortosis_effect, retracted;
string saber_color;

varargs void create(int _wc, string _cust_col) {
  ::create();
  set_name("lightsaber");
  set_id( ({
    "handle",
    "saber",
    "lightsaber"
  }) );
  set_short((: TO->saber_short() :));
  set_long((: TO->saber_long() :));
  set_weight(100);
  set_type("saber");
  set_wield_func(TO);
  set_unwield_func(TO);
  set_destroy(1);
  set("catalog_item",1);
  set_damage_type("energy");
  //set_saber("violet");
  if (!_wc)
    _wc = 10;
  set_wc(_wc);
  if (_cust_col)
    set_custom_color(_cust_col);
  set_weapon_stat("force");
  set_spec_guild("jedi");
}

string base_saber_name() {
  return "lightsaber";
}

string saber_short() {
  string ret = "";
  if (query_wielded() && !retracted) {
    if(query_mod("blade-prefix")) {
      ret  += implode(explode(query_mod("blade-prefix"),"\n"), " ") + " ";
    }
    ret += query_color()+" ";
  }
  ret += base_saber_name();
  if (!query_wielded())
    ret += " handle";
  else if (retracted)
    ret += " (retracted)";
  return ret;
}

string saber_long() {
  string ret;
  if (query_wielded())
    ret = "This "+query_color()+" "+base_saber_name()+" is the preferred "
      +"weapon of the Jedi Knights. Type 'retract' to retract the saber, "
      +"and 'extend' to re-extend it.\n";
  else
    ret = "This is the handle of a Jedi Knight's "+query_color()+" "
      +base_saber_name()+". Just wield it to ignite it.\n";
  ret += ASCII_ART;
  return ret;
}

void init() {
  ::init();
  add_action("retract_action","retract");
  add_action("extend_action","extend");
}

int is_saber() {
  return 1;
}

int is_phased_saber() {
  return 0;
}

int is_sith_saber() {
  return 0;
}

int is_special_saber() {
  return 0;
}

string query_special_id() {
  return 0;
}

int is_master_saber() {
  return 0;
}

int set_wc(int x) {
  int ret = ::set_wc(x);
  return ret;
}

int set_new_wc(int x) {
  set_wc(x);
  set_orig_wc(x);
  set_orig_value(100 * x);
  orig_value = 100 * x;
  return 1;
}

void set_saber(string col, string cust_color) {
  int new_wc;
  new_wc = _color_to_wc(col);
  if (cust_color)
    saber_color = cust_color;
  set_new_wc(new_wc);
}

private int _color_to_wc(string col) {
  int i;
  col = decolorize(col);
  i = member_array(col,PLAIN_COLORS);
  if (i < 0)
    i = 1;
  return i;
}

private string _wc_to_color(int x) {
  if (x < 0)
    x = 0;
  if (x >= 50)
    x = 50;
  return COLORS[x];
}

string query_s_color(int num) {
  return decolorize(query_color(num));
}

string query_color(int x) {
  if (ENV(TO) && ENV(TO)->is_master_saber())
    return ENV(TO)->query_color();
  if (saber_color)
    return saber_color;
  return _wc_to_color(undefinedp(x) ? query_mods_wc() : x);
}

int extra_wield() {
  if (JEDI_D->no_force_check(TP)) {
    write("You cannot wield a saber when cut off from the force.");
    return 0;
  }
  if(TP->query_wielded()) {
    write("You are already wielding a weapon.");
    return 0;
  }
  write("The room takes on a "+query_color()+" glow as your saber ignites "
      +"with a Snap-hiss.");
  say("The room takes on a "+query_color()+" glow as "+TP->query_cap_name()
      +" ignites "+TP->query_possessive()+" saber with a Snap-hiss.");
  TP->set_property("light", 1);
  // If there's a cortisis effect still going, don't want the player to 
  // be able to unwield then rewield to turn it off. Not the prettiest
  // way to do it...
  if (cortosis_effect)
    retract();
  return 1;
}

int extra_unwield() {
  // different unwield message if retracted --Stav, 15 Apr 2010
  if (retracted && query_wielded()) {
    message("info","You unwield your lightsaber.",query_wielded());
    if (ENV(query_wielded()))
      message("info",query_wielded()->query_cap_name()+" unwields "
          +query_wielded()->query_possessive()+" lightsaber."
          ,ENV(query_wielded()),query_wielded());
    // extend it just before unwielding, so we do all of the lighting 
    // stuff properly, and don't have to check for retracted-ness when we
    // re-wield
    // --Stav, 15 Apr 2010
    extend();
  }
  else if (query_wielded()) {
    message("info","The area darkens as you shut down your lightsaber.",
        query_wielded());
    if (ENV(query_wielded()))
      message("info","The area darkens as "+query_wielded()->query_cap_name()+
          " shuts down "+query_wielded()->query_possessive()+" lightsaber.",
          ENV(query_wielded()),({query_wielded()}));
    query_wielded()->set_property("light", -1);
  }
  return 1;
}

/*
 * The following functions are added for retract/extend, as well as cortosis.
 *
 * Pretty self-explanatory. I'll drop a comment every now and then.
 *
 * Stav, 15 Apr 2010
 */
int query_wc() {
  if (retracted)
    return 1;
  return ::query_wc();
}

int is_lit() {
  return (!retracted && objectp(query_wielded()));
}

// we don't do messages in two these next two functions so we can do different
// messages for different causes of retraction/extension
void retract() {
  if (retracted)
    return;
  query_wielded()->set_property("light", -1);
  set_type("blunt");
  retracted = 1;
}

void extend() {
  if (!retracted)
    return;
  retracted = 0;
  query_wielded()->set_property("light",1);
  set_type("saber");
}

// add_action function so players can retract/extend their sabers themselves
int retract_action(string str) {
  if (str && str != "saber")
    return 0;
  if (TP != query_wielded())
    return 0;
  if (retracted)
    return notify_fail("Your saber is already retracted!");
  message("info",DARK+"You flip a switch, and your saber retracts into "
      +"its handle."+RESET,TP);
  message("info",DARK+TP->query_cap_name()+" flips a switch,"
      +" and "+TP->query_possessive()+" saber retracts into its "
      +"handle."+RESET,ENV(TP),TP);
  retract();
  return 1;
}

// add_action function so players can retract/extend their sabers themselves
int extend_action(string str) {
  if (str && str != "saber")
    return 0;
  if (TP != query_wielded())
    return 0;
  if (!retracted)
    return notify_fail("You saber is already extended.");
  // Can't extend if it's been *forced* to retract (i.e. cortosis).
  if (cortosis_effect)
    return notify_fail("Your saber flickers, but won't ignite!");
  extend();
  message("info","You flip a switch, and your "+query_color()
      +" saber extends with a snap-hiss.",TP);
  message("info",TP->query_cap_name()+" flips a switch, "
      +"and "+TP->query_possessive()+" "
      +query_color()+" saber extends with a snap-hiss."
      ,ENV(TP),TP);
  extend();
  return 1;
}

// len is # of rounds
void cortosis_hit(int len) {
  if (retracted)
    return;
  if (len < 1)
    len = 1;
  message("info",DARK+"Your lightsaber touches the cortosis, flickers "
      +"for an instant, and dies."+RESET,query_wielded());
  message("info",DARK+query_wielded()->query_cap_name()+"'s lightsaber "
      +"touches the cortosis, flickers for an instant, "
      +"and dies."+RESET,ENV(query_wielded())
      ,query_wielded());
  retract();
  cortosis_effect = 1;
  call_out("cortosis_end",len*2-1);
}

void cortosis_end() {
  if (!cortosis_effect)
    return;
  cortosis_effect = 0;
  if (!query_wielded()) {
    set_type("saber");
    return;
  }
  extend();
  message("info","A "+query_color(query_mods_wc())+" beam sputters to life "
      +"from your lightsaber.",query_wielded());
  message("info","A "+query_color(query_mods_wc())+" beam sputters to life "
      +"from "+query_wielded()->query_cap_name()+"'s lightsaber."
      ,ENV(query_wielded()),query_wielded());
}

// From Ichthus's cust_saber -- Stav, 15 Apr 2010
void set_custom_color(string col) {
  saber_color = col;
  set_wc(query_real_wc());
}

object query_wielded() {
  if (ENV(TO) && ENV(TO)->is_saber())
    return ENV(TO)->query_wielded();
  return ::query_wielded();
}

string *query_id() {
  string c = query_s_color();
  string *ids = ({});
  ids += ::query_id();
  ids += ({ c, c+" saber", c+" lightsaber" });
  if (query_special_id()) {
    ids += uniq_array(ids + ({ query_special_id() }));
  }
  return ids;
}

int id(string str) {
  if(!stringp(str) ) return 0;
  if(member_array(str, query_id()) != -1) return 1;
  return ::id(str);
}
