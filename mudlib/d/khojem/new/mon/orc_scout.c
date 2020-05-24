//  Wizard:   Khojem
//  Monster:  Half-Orc Scout
//  File:     orc_scout.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc scout");
    set_id( ({ "scout","orc", "half-orc scout"}) );
    set_level(1);
    set_short("[1]half-orc scout");
    set_long("The half-orc scout is hunting wood-elves." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_skill("blunt", 15);
    set_skill("axe", 15);
    set_skill("two handed polearm", 15);
    set_stats("dexterity", 30);
    set_stats("intelligence", 40);
    set_stats("strength",40);
    set_wimpy(0);
    switch(random(4)){
      case 0:new("/d/khojem/new/weapon/wooden_club")->
                 move(this_object());
             force_me("wield club in right hand");
             break;
      case 1:new("/d/damned/virtual/hammer_3.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand");
             break;
      case 2:new("/d/damned/virtual/hand-axe_3.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 3:new("/d/damned/virtual/quarter-staff_3.weapon")->
                 move(this_object());
             force_me("wield staff in right hand and left hand");
             break;
    }
    switch(random(4)){
      case 0:new("/d/khojem/new/armor/rag_shirt")->
                 move(this_object());
             force_me("wear shirt");
             break;
      case 1:new("/d/khojem/new/armor/leather_mittens")->
                 move(this_object());
             force_me("wear mittens on right hand");
             break;
      case 2:new("/d/khojem/new/armor/rag_pants")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/khojem/new/armor/rag_boots")->
                 move(this_object());
             force_me("wear boots");
             break;
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+20));
    money->move(this_object());
    set_languages(({ "orcish" }));
    set_lang_prof("orcish",10);
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc grins wickedly.",
	  "The orc spits tobacco juice in your eye.",
	  "The orc flings mud in your eye",
	  "The orc cackles insanely."
	}),1);
	set_speech(5,"orcish",({ 
	  "You swine!  I'm only interested in killing wood-elf peasants!",
	  "Hey, let's call it even!  Seen any wood-elf slugs nearby?",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}
