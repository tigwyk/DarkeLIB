//  Wizard:   Khojem
//  Monster:  a citizen peon
//  File:     peon.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
create() {
  int zlevel;
  object obj;
  ::create();
    zlevel = 1 + random(3);
	set_overall_ac((zlevel+1));
    set_level(zlevel);
    add_money("silver", (zlevel*10)+random(9));
    set_property("melee damage", ([ "crushing" : (zlevel + 2)]));
    zlevel = random(4);
    switch(zlevel) {
      case(0) : set_name("filthy peon"); break;
      case(1) : set_name("toothless peon"); break;
      case(2) : set_name("cross-eyed peon"); break;
      case(3) : set_name("bald peon"); break;
      default : set_name("another peon"); break;
    }
    set_id( ({ "peon", "mob" }) );
    set_short("peon");
    set_long("The peon appears to be wondering about with no place to go.");
    zlevel = random(4);
    switch(zlevel) {
      case(0) : set("race", "nerid"); break;
      case(1) : set("race", "halfling"); break;
      case(2) : set("race", "pech"); break;
      case(3) : set("race", "gnome"); break;
      default : set("race", "pech"); break;
    }
    set_gender("male");
    set_body_type("human");
    set_wimpy(30);
	set_class("fighter");
    set_wimpy(0);
    set_moving(1);
    zlevel = 60 + random(60);
    set_speed(zlevel);
    set_emotes(1, ({
	  "The peon blinks and his mouth opens wide.",
	  "The peon spits on the ground.",
	  "The peon reaches back and pulls his underwear out of the "+
	    "the crack of his ass.",
	  "The peon burps rudely.",
	  "The peon looks up at the sky."
	}),0);
  }

int query_kho_mon() { return 1;}

