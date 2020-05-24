//  Wizard:   Khojem
//  Monster:  Wood-Elf Scout
//  File:     elf_scout.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("wood-elf scout");
    set_id( ({ "scout","elf", "wood-elf scout"}) );
    set_level(1);
    set_short("[1]wood-elf scout");
    set_long("The wood-elf scout is hunting half-orcs." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_skill("axe", 15);
    set_skill("two handed polearm", 15);
    set_stats("dexterity", 30);
    set_stats("intelligence", 50);
    set_stats("strength",30);
    set_wimpy(0);
    switch(random(4)){
      case 0:new("/d/khojem/new/weapon/wooden_spear")->
                 move(this_object());
             force_me("wield spear in right hand and left hand");
             break;
      case 1:new("/d/damned/virtual/hand-axe_3.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 2:new("/d/damned/virtual/quarter-staff_3.weapon")->
                 move(this_object());
             force_me("wield staff in right hand and left hand");
             break;
      case 3:new("/d/khojem/new/weapon/wooden_spear")->
                 move(this_object());
             force_me("wield spear in right hand and left hand");
             break;
    }
    switch(random(4)){
      case 0:new("d/damned/virtual/leather-jacket.armour")->
                 move(this_object());
             force_me("wear jacket");
             break;
      case 1:new("d/damned/virtual/leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
             break;
      case 2:new("d/damned/virtual/leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/khojem/new/armor/slippers")->
                 move(this_object());
             force_me("wear slippers");
             break;
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+20));
    money->move(this_object());
    set_languages(({ "elvish" }));
    set_lang_prof("elvish",10);
    set_emotes(5, ({
	  "The elf blinks and his mouth opens wide.",
	  "The elf grins wickedly.",
	  "The elf spits in your eye.",
	  "The elf bounds away from you and flips head-over-heels.",
	  "The elf chuckles at your flimsy attack."
	}),1);
	set_speech(5,"elvish",({ 
	  "You swine!  I'm only interested in killing half-orc raiders!",
	  "Hey, let's call it even!  Seen any half-orc pigs nearby?",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}
