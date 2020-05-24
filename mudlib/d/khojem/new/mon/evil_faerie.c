//  Wizard:   Khojem
//  Monster:  Evil Faerie
//  File:     evil_faerie.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

void create() {
  int    zskill;
  ::create();
    set_name("evil faerie");
    set_id( ({ "evil faerie","faerie" }) );
    set_level(7);
    set_short("[7]evil faerie");
    set_long("The ghostly-looking winged, sprint moves very quickly.  "+
      "It is constantly fluttering about and whirls circles around you." 
      );
    set("race", "wood-elf");
    set_gender("female");
    set_body_type("pixie");
    set_property("melee damage", ([ "crushing" : 10]));
    zskill=random(3)*10+60;
    set_skill("melee",zskill);
    set_skill("dodge",zskill);
    set_stats("intelligence", 120);
    set_stats("wisdom", 120);
    set_wimpy(0);
    set_alignment(-800);
    set_emotes(50, ({
      "The evil faerie spins up high towards the ceiling.",
      "The evil faerie flies between your legs.",
      "The evil faerie whirls away into the darkness.",
	  "The evil faerie whirls around behind you.",
	  "The evil faerie flutters over your head and around you."
	}),1);
	set_class("mage");
	set_casting_chance(40);
	set_combat_chance(95);
	add_spell("instill poison","$A");
	set_spell_level("instill poison",2);
	set_skill("body alteration",70);
	add_spell("magic missile","$A");
	set_spell_level("magic missile",5);
	add_spell("burning hands","$A");
	set_spell_level("burning hands",5);
	add_spell("fireball","$A");
	set_spell_level("fireball",2);
	set_fingers(5);
	set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
	set_moving(1);
	set_speed(40);              
    new("/d/khojem/new/obj/dead_rose")->move(this_object());
}

int chk_my_mon() { return 1;}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
