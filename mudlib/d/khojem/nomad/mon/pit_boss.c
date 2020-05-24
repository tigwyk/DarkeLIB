//  Wizard:   Khojem
//  Monster:  pit boss
//  File:     pit_boss.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("pit boss");
    set_id( ({ "pit boss", "boss", "nomad" }) );
    set_level(16);
    set_short("[16]pit boss");
    set_long("This bearded nomad operates the roulette table for Babba.  He is lean "+
      "and appears talented at the art of running a gambling table... even though "+
      "he lacks a left arm."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_exp(2000);
    remove_limb("left arm");
    set_wielding_limbs("right hand");
    set_emotes(2, ({
	  "The boss shouts and lunges at towards you!",
	  "The boss checks to to make sure his bank is secure.",
	  "The boss angles slightly away towards your weak side.",
	  "The boss cracks an ale bottle on your head!  Ouch!",
	  "The boss frowns and thinks Babba isn't paying him enough money for this hassle."
	}),1);
	set_class("fighter");
}

int query_kho_mon() { return 1;}
