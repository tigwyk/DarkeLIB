//  Wizard:   Khojem
//  Monster:  Nomad War Cleric
//  File:     nomad_cleric.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("nomad war cleric");
    set_id( ({ "nomad war cleric","war cleric","cleric","Rom'mir",
      "rom'mir", "rommir", "Rommir" }) );
    set_level(16);
    set_short("[16]Rom'mir");
    set_long("The dark, robed half-orc shaman stands before you.  "+
      "A hood is drawn up over his head and shadows his face from view.  "+
      "He is a short, stocky half-orc but you are wary of his powers." 
      );
    set("race", "gnome");
    set_gender("female");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    money=new("std/obj/coins");
    money->set_money("silver",10);
    money->move(this_object());
    set_wimpy(0);
    set_emotes(2, ({
	  "The war cleric briefly looks your way and examines your weapons.",
	  "The war cleric shakes her head as she reads the parchment.",
	  "The cleric looks distantly towards the tent's ceiling and ponders.",
	  "The cleric waves her hand and mutters something."
	}),1);
	set_class("war priest");
	set_casting_chance(0);
	set_combat_chance(99);
	add_spell("rain of spears","$A");
	set_spell_level("rain of spears",6);

	add_spell("harm","$A");
	set_spell_level("harm",6);
	add_spell("instill poison","$R");
	set_spell_level("instill poison",6);
	add_spell("battle aura","$ME");
	set_spell_level("battle aura",5);
	add_spell("shields of war","$ME");
	set_spell_level("shields of war",3);
	add_spell("divine might","$ME");
	set_spell_level("devine might",6);
	set_skill("prayer",100);
	set_skill("body alteration",95);
	set_fingers(5);
	new("/d/khojem/nomad/weapon/nomad_staff")->
	  move(this_object());
	force_me("wield staff in right hand and left hand");
}
