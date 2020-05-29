//	Some fun special results for crits.

#define A_NAME ((string)from->query_cap_name())

#define T_NAME ((string)to->query_cap_name())



void create() {

  seteuid(getuid());

}



void shatter_me(object me, object you) {

    call_out("do_shatter", 2, ({ (string)you->query_name(),

	environment(you), you }));

    return;

}



void blind_me(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/std/spells/shadows/blind_shadow");

  ob->start_shadow(to);

  return;

}



void melt_weapon(object from, object to) {

  object *weap;

  int i;



  weap = (object *)to->query_wielded();

  if(sizeof(weap)) {

    i = random(sizeof(weap));

    if(objectp(weap[i]))

      weap[i]->remove();

  }

  return;

}



void impact_crit(object from, object to) {

  string crit;



  crit = sprintf("impact %s", ({ "B", "C", "D" })[random(3)]);

  do_critical(from, to, ({ crit }) );

  return;

}



void increase_ac(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/std/spells/shadows/ac_shadow");

  ob->set_shad_ac(10 + random(10));

  ob->set_expire_message("The holy aura about you dissipates.");

  ob->start_shadow(from, 40);

  return;

}



void raise_weapon1(object from, object to) {

  object shad, weap;

  int sz;



  if(!from->query_wielded() || !(sz = sizeof((object *)from->query_wielded())))

    return;

  weap = ((object *)from->query_wielded())[random(sz)];

  shad = new("/std/spells/shadows/weapon_shadow");

  shad->set_enchantment(1+random(4));

  shad->start_shadow(weap, 50+random(25), "%^CYAN%^An aura about your weapon wears off.");

  return;

}



void raise_weapon2(object from, object to) {

  object shad, weap;

  int sz;



  if(!from->query_wielded() || !(sz = sizeof((object *)from->query_wielded())))

    return;

  weap = ((object *)from->query_wielded())[random(sz)];

  shad = new("/std/spells/shadows/weapon_shadow");

  shad->set_enchantment(4+random(4));

  shad->start_shadow(weap, 50+random(25), "%^CYAN%^An aura about your weapon wears off.");

  return;

}



void electricity_crit(object from, object to) {

  string crit;



  crit = sprintf("electricity %s", ({ "B", "C", "D" })[random(3)]);

  do_critical(from, to, ({ crit }) );

  return;

}



void impact_A_crit(object from, object to) {

  do_critical(from, to, ({ "impact A" }) );

  return;

}



void dest_pet(object what) {

  if(objectp(what)) {

    message("info", (string)what->query_short() +

      " winks out of existence.", environment(what));

    what->remove();

  }

  return;

}



void summon_ethereal_entity1(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/wizards/diewarzau/obj/pet/ethereal_entity");

  ob->move(environment(to));

  if(from->is_pet() && from->query_owner())

    ob->set_owner((string)from->query_owner());

  else

    ob->set_owner((string)from->query_name());

  ob->set_up(random(3)+1);

  ob->set_dur(100 + random(200));

  ob->kill_ob(to, 0);

  return;

}



void summon_ethereal_entity2(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/wizards/diewarzau/obj/pet/ethereal_entity");

  ob->move(environment(to));

  if(from->is_pet() && from->query_owner())

    ob->set_owner((string)from->query_owner());

  else

    ob->set_owner((string)from->query_name());

  ob->set_up(random(3)+4);

  ob->set_dur(200 + random(200));

  ob->kill_ob(to, 0);

  return;

}



void summon_elder_seraph(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/wizards/diewarzau/obj/pet/elder_seraph");

  ob->move(environment(to));

  if(from->is_pet() && from->query_owner())

    ob->set_owner((string)from->query_owner());

  else

    ob->set_owner((string)from->query_name());

  ob->set_up(random(4)+2);

  call_out("dest_pet", 100+random(50), ob);

  ob->kill_ob(to, 0);

  return;

}



void summon_arch_angel(object from, object to) {

  object ob;



  seteuid(getuid());

  ob = new("/wizards/diewarzau/obj/pet/arch_angel");

  ob->move(environment(to));

  if(from->is_pet() && from->query_owner())

    ob->set_owner((string)from->query_owner());

  else

    ob->set_owner((string)from->query_name());

  ob->set_up(random(4)+1);

  call_out("dest_pet", 100+random(50), ob);

  ob->kill_ob(to, 0);

  return;

}



void multitude_of_the_heavenly_host(object from, object to) {

  object ob;

  int i;



  seteuid(getuid());

  for(i=1;i<=5;i++) {

    ob = new("/wizards/diewarzau/obj/pet/elder_seraph");

    ob->move(environment(to));

    if(from->is_pet() && from->query_owner())

      ob->set_owner((string)from->query_owner());

    else

      ob->set_owner((string)from->query_name());

    ob->set_up(random(5)+2);

    call_out("dest_pet", random(50) + 100, ob);

    ob->kill_ob(to, 0);

    if(i >= 4) {

      ob = new("/wizards/diewarzau/obj/pet/arch_angel");

      ob->move(environment(to));

      if(from->is_pet() && from->query_owner())

        ob->set_owner((string)from->query_owner());

      else

        ob->set_owner((string)from->query_name());

      ob->set_up(random(4)+1);

      call_out("dest_pet", random(50) + 100, ob);

      ob->kill_ob(to, 0);

    }

  }

  return;

}



void extra_a_hbeat(object from, object to) {

  from->heart_beat(1);

  return;

}



void extra_attack(object me, object you) {

  me->continue_attack();

  return;

}



void haste_me(object me, object you) {

  object ob;



  ob = new("/std/spells/shadows/haste_shadow");

  ob->start_shadow(me, 20, "%^CYAN%^You stop attacking speedily.");

  return;

}



void haste_me2(object me, object you) {

  object ob;



  ob = new("/std/spells/shadows/haste_shadow");

  ob->start_shadow(me, 30, "%^CYAN%^You stop attacking speedily.");

  ob = new("/std/spells/shadows/haste_shadow");

  ob->start_shadow(me, 30, "%^CYAN%^You stop attacking speedily.");

  return;

}



void fire_E_crit(object from, object to) {

  do_critical(from, to, ({ "fire E" }) );

  return;

}



void dest_corpse(object from, object to) {

  call_out("remove_corpse", 2, to);

  return;

}



void remove_corpse(object who) {

  object corpse;



  corpse = (object)who->query("corpse ob");

  if(corpse) corpse->remove();

  return;

}



void do_shatter(mixed *arg) {

  object env;

  string name;

  object corpse;

  int i, count;



  if(sizeof(arg) != 3) return;

  name = arg[0];

  env = arg[1];

  if(arg[2])

    corpse = (object)arg[2]->query("corpse ob");

  else corpse = 0;

  if(objectp(corpse))

    corpse->remove();

  seteuid(getuid(this_object()));

  count = random(7)+3;

  for(i = 0; i <= count; i++) {

    corpse = new("/wizards/diewarzau/crits/shards");

    corpse->set_person(name);

    corpse->move(env);

  }

  return;

}



void decay_weapon(object from, object to) {

  object *weap;



  weap = (object *)to->query_wielded();

  if(!weap || !sizeof(weap)) return;

  weap[0]->decay_me(20+random(50));

  message("info", A_NAME+" attacks your weapon, inflicting "+

    "some damage upon it.", to);

  message("info", "You inflict some damage upon "+T_NAME+"'s "+

    " weapon.", from);

  message("info", A_NAME+" strikes "+T_NAME+"'s weapon, "+

    "damaging it.", environment(to), ({ from, to }));

  return;

}



void break_weapon1(object from, object to) {

  if(random(100) <= 1) this_object()->shatter_weapon(from, to);

  return;

}



void break_weapon2(object from, object to) {

  if(random(100) <= 5) this_object()->shatter_weapon(from, to);

  return;

}



void shatter_weapon(object from, object to) {

  object *weap;



  weap = (object *)to->query_wielded();

  if(!weap || !sizeof(weap)) return;

  message("info", A_NAME+" attacks your weapon, shattering "+

    "it completely!", to);

  message("info", "You attack "+T_NAME+"'s "+

    "weapon, shattering it completely!", from);

  message("info", A_NAME+" strikes "+T_NAME+"'s weapon, "+

    "shattering it completely!", environment(to), ({ from, to }));

  weap[0]->remove();

  return;

}



int not_shield(object item) {

  if(!item->is_armour()) return 0;

  if(!item->query_worn()) return 0;

  if((string)item->query_type() == "shield") return 0;

  return 1;

}



int shield_filter(object item) {

  if(!item->is_armour()) return 0;

  if(!item->query_worn()) return 0;

  if((string)item->query_type() == "shield") return 1;

  return 0;

}



void break_armour1(object from, object to) {

  if(random(100) <= 1) this_object()->shatter_armour(from, to);

  return;

}



void break_armour2(object from, object to) {

  if(random(100) <= 5) this_object()->shatter_armour(from, to);

  return;

}



void shatter_armour(object from, object to) {

  object *weap;

  int idx;



  weap = filter_array(all_inventory(to), "not_shield", this_object());

  if(!weap || !sizeof(weap)) return;

  message("info", A_NAME+" attacks a piece of your armour, destroying "+

    "it completely!", to);

  message("info", "You attack a piece of "+T_NAME+"'s "+

    "armour, destroying it completely!", from);

  message("info", A_NAME+" strikes a piece of "+T_NAME+"'s armour, "+

    "destroying it completely!", environment(to), ({ from, to }));

  idx = sizeof(weap);

  if(idx > 1) idx = random(idx);

  else idx = 0;

  message("info", (string)weap[idx]->query_short()+" is destroyed!",

     to);

  weap[idx]->remove();

  return;

}



void break_shield1(object from, object to) {

  if(random(100) <= 1) this_object()->shatter_shield(from, to);

  return;

}



void break_shield2(object from, object to) {

  if(random(100) <= 5) this_object()->shatter_shield(from, to);

  return;

}



void shatter_shield(object from, object to) {

  object *weap;

  int idx;



  weap = filter_array(all_inventory(to), "shield_filter", this_object());

  if(!weap || !sizeof(weap)) return;

  message("info", A_NAME+" attacks your shield, destroying "+

    "it completely!", to);

  message("info", "You attack "+T_NAME+"'s "+

    "shield, destroying it completely!", from);

  message("info", A_NAME+" strikes "+T_NAME+"'s shield, "+

    "destroying it completely!", environment(to), ({ from, to }));

  idx = sizeof(weap);

  if(idx > 1) idx = random(idx);

  else idx = 0;

  message("info", (string)weap[idx]->query_short()+" is destroyed!",

     to);

  weap[idx]->remove();

  return;

}



int armour_limb_filter(object armour, string limb) {

  string *ac_limbs;

  

  if(!armour->is_armour()) return 0;

  if(!armour->query_worn()) return 0;

  if(!(ac_limbs=(string *)armour->query_actual_limbs())) return 0;

  if(member_array(limb, ac_limbs) < 0) return 0;

  return 1;

}



void torso_no_armour(object me, object you) {

  object *inv;

  int i;



  inv = filter_array(all_inventory(you), "armour_limb_filter",

    this_object(), "torso");

  if(!inv || !(i=sizeof(inv))) return;

  while(i--) {

    message("info", (string)inv[i]->query_short()+

      " is vaporized!", environment(you));

    inv[i]->remove();

  }

  return;

}



int leg_filter(string limb) {

  string *words;



  words = explode(limb, " ");

  if(member_array("leg", words) >= 0 ||

    member_array("root", words) >= 0) return 1;

  return 0;

}



void leg_no_armour(object me, object you) {

  object *inv;

  string *limbs;

  int i;



  if(!living(you)) return;

  limbs = filter_array((string *)you->query_limbs(), "leg_filter", this_object());

  if(!limbs || !(i=sizeof(limbs))) return;

  if(i == 1) i = 0;

  else i = random(i);

  inv = filter_array(all_inventory(you), "armour_limb_filter",

    this_object(), limbs[i]);

  if(!inv || !(i=sizeof(inv))) return;

  while(i--) {

    message("info", (string)inv[i]->query_short()+

      " is vaporized!", environment(you));

    inv[i]->remove();

  }

  return;

}



void drop_all(object me, object you) {

  object *inv;

  int i;

  

  message("info", "You drop all of your possessions!", you);

  inv = all_inventory(you);

  while(i--) {

    if(inv[i]->drop()) continue;

    if(inv[i]->query_worn()) continue;

    message("info", (string)you->query_cap_name()+

      " drops "+(string)inv[i]->query_short()+".",

      environment(you), ({ you }));

    inv[i]->move(environment(you));

  }

  return;

}



void goo_janitor(object me, object you) {

    call_out("do_janitor", 2, ({ (string)you->query_name(),

	environment(you), you }));

    return;

}



void do_janitor(mixed *arg) {

  object env;

  string name;

  object corpse, jan;



  if(sizeof(arg) != 3) return;

  name = arg[0];

  env = arg[1];

  if(arg[2])

    corpse = (object)arg[2]->query("corpse ob");

  else corpse = 0;

  if(objectp(corpse))

    corpse->remove();

  seteuid(getuid(this_object()));

  if(!env) return;

  corpse = new("/wizards/diewarzau/obj/misc/puddle");

  corpse->move(env);

  corpse->set_person(name);

  jan = new("/wizards/diewarzau/obj/mon/janitor");

  jan->move(env);

  jan->set_puddle(corpse);

  message("info", "Janitor arrives.", env);

  return;

}



