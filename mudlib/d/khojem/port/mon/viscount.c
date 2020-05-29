//  Wizard:   Khojem
//  Monster:  Viscount of Vo'Sangor
//  File:     viscount.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  object obj;
  ::create();
    set_name("viscount");
    set_id( ({ "viscount", "viscount of vo'sangor" }) );
    set_level(21);
    set_exp(120000);
    set_short("Viscount of Vo'Sangor");
    set_long("The Viscount of Vo'Sangor tends to the daily "
      "workings of running a city."
    );
    set("race", "drow-elf");
    set_gender("male");
    set_body_type("human");
    set("gang bang",1);
    set_wimpy(0);
    set_class("arch-mage");
    set_overall_ac(30);
    set_wielding_limbs( ({ "right hand" }) );
    set_melee_damage( ([ "crushing" : 20 ]) );
    set_casting_chance(0);
    set_property("enhance criticals",-1);
    set_combat_chance(90);
    add_spell("faerie fire","$A");
    set_spell_level("faerie fire",6);
    add_spell("magic missile","$A");
    set_spell_level("magic missile",6);
    add_spell("power word, stun","$A");
    set_spell_level("power word, stun",4);
    set_skill("illusionism",90);
    set_skill("conjuration",90);
    set_skill("concentrate",80);
    set_fingers(5);
    obj = new("/d/damned/virtual/dagger_5.weapon");
    obj->move(this_object());
    command("wield dagger in right hand");
    command("use concentrate");
}

int query_kho_mon() { return 1;}
