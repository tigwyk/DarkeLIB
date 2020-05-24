//  Wizard:   Khojem
//  Monster:  Wood-Elf Child
//  File:     child.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

create() {
  int    flip_coin;  
  ::create();
    set_name("wood-elf child");
    set_id( ({ "child","elf", "wood-elf child"}) );
    set_level(1);
    set_short("[1]wood-elf child");
    set_long("The wood-elf child is playing ball and doing childlike things." 
      );
    set("race", "wood-elf");
    flip_coin=random(2);
    if(flip_coin)
      set_gender("male");
    else set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 1]));
    set_skill("melee", 2);
    set_skill("dodge", 2);
    set_skill("parry", 2);
    set_wimpy(30);
    set_max_hp(10);
    set_hp(10);
    set_alignment(50);
    new("/d/khojem/new/obj/ball")->move(this_object());
    set_languages(({ "elvish" }));
    set_lang_prof("elvish",10);
    set_emotes(5, ({
	  "The child smiles at you innocently.",
	  "The little one beams a smile at you.",
	  "The tyke bursts into tears.",
	  "The child bounces the ball.",
	  "The tyke punches the ball into the air with a fist and catches it."
	}),0);
	set_speech(5,"elvish",({ 
	  "I was told never to talk to strangers.  Teeehee",
	  "Wanta play ball?",
	  "Hello!",
	  "Have you seen my Mommy?",
	  "I can count to five!"
	}),0);
}

int chk_my_mon() { return 1;}
