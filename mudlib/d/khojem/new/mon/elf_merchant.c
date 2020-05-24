//  Wizard:   Khojem
//  Monster:  Wood-Elf Merchant
//  File:     elf_merchant.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("Elf Merchant");
    set_id( ({ "elf merchant","merchant", "elf" }) );
    set_level(1);
    set_short("[1]elf merchant");
    set_long("The Wood-Elf Merchant is busy carrying his goods to market." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    set_skill("melee", 10);
    set_skill("attack", 15);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_stats("intelligence", 60);
    set_languages(({"common", "elvish", "drow", "middle-english" }));
    set_lang_prof("elvish",10);
    set_lang_prof("common",10);
    set_lang_prof("drow",8);
    set_lang_prof("middle-english",8);
	for(int x = 0;x > 5;x++)
    new("/std/obj/torch")->move(this_object());
    new("/std/obj/torch")->move(this_object());

    add_money("silver",random(50)+20);
    set_emotes(5, ({
	  "The merchant blinks and his mouth opens wide.",
	  "The merchant smiles and waves at you."
	}),0);
	set_speech(10,"common",({ 
	  "I'm glad to get away from those damn half-orcs!",
	  "Ever since those half-orcs showed up getting to market is dangerous.",
	  "Gotta go!  I'm off to market and I am running late",
	  "Greetings fellow travellers!",
	  "Don't go in the forest if you don't know the path!",
	  "Have you been to the market?  Have the other merchants arrived yet?"
	}),0);
}
