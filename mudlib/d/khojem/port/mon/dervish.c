//  Wizard:   Khojem
//  Monster:  whirling dervish
//  File:     dervish.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();
void slam_door();

void init() {
   ::init();
   if(!this_player()->is_player()) { return; }
   delayed_call("do_att",5,this_player());
   delayed_call("slam_door", 4);
   return;
}

create() {
  object obj;
  ::create();
    set_name("dervish");
    set_id( ({ "dervish", "whirling dervish" }) );
    set_level(12);
    set_short("[12]a whirling dervish");
    set_long("The dervish is moving, whirling, and twirling so fast... you can't "+
      "destinguish many of its features."
      );
    set("race", "dervish");
    set_gender("neuter");
    set_body_type("human");
    set_wimpy(0);
	set_class("arch-mage");
    set_overall_ac(10);
	set_wielding_limbs( ({ "right hand" }) );
    set_melee_damage( ([ "crushing" : 15, "cold" : 10 ]) );
    set_casting_chance(0);
    set_combat_chance(80);
    add_spell("faerie fire","$A");
    set_spell_level("faerie fire",4);
    add_spell("magic missile","$A");
    set_spell_level("magic missile",4);
    set_skill("illusionism",90);
    set_skill("conjuration",90);
    set_skill("concentrate",80);
    command("use concentrate");
}

void slam_door() {
  object zroom;
  zroom = environment(this_object());
  tell_room(zroom,"The whirling dervish spins across the room and passes the "+
    "trapdoor.");
  force_me("close iron trapdoor");
  return;
}

int query_kho_mon() { return 1;}

void do_att(object who) {
  if(!who || !present(who,environment())) { return; }
  this_object()->kill_ob(who,0);
  return;
}


