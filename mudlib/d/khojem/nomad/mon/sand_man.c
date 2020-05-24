//  Wizard:   Khojem
//  Monster:  Sandman
//  File:     sand_man.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("sandman");
    set_id( ({ "sandman" }) );
    set_level(12);
    set_short("[12]sandman");
    set_long("The man is constructed entirely of sand.  He appears "+
      "strong and fearless in battle.  Whatever life or magic that "+
      "spawned this abomination of nature is beyond your "+
      "comprehension." 
      );
    set("race", "sandman");
    set_gender("male");
    set_class("fighter");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set("aggressive", (: call_other, this_object(), "aggro_test" :) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_wimpy(0);
    set_alignment(-300);
	set_casting_chance(0);
	set_combat_chance(80);
	add_spell("lifesteal","$R");
	set_spell_level("lifesteal",4);
	set_skill("necromancy",70);
    money=new("std/obj/coins");
    money->set_money("gold",((random(20))+35));
    money->move(this_object());
    new("/d/khojem/nomad/weapon/darkeblade")->move(this_object());
    force_me("wield blade in right hand");
}
