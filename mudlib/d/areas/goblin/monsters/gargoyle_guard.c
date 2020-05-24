//  Wizard:  Kil 
//  Monster: Gargoyle Castle Guard
//  File:    gargoyle_guard.c
#include <std.h>
#include "../goblin.h"
inherit MONSTER;

int chk_my_mon();

create() {
  ::create();
    set_name("castle guard");
    set_id( ({ "guard", "gargoyle", "castle guard"}) );
    set_level(15);
    set_short("[15]gargoyle castle guard");
    set_long("The guard is defending %^YELLOW%^Xamelot%^RESET%^ Castle.  "
	     "He is seems to be an honorable, yet formadable gargoyle guard. Let him "
	     "do his job.\n" 
      );
    set("race", "gargoyle");
    set_gender("male");
    set_body_type("winged-humanoid");
    set_wielding_limbs( ({ "right hand" }) );
    set_skill("melee", 299);
    set_stats("intelligence", 150);
    set_stats("strength", 250);
    set_wimpy(10);
    set_alignment(5);
    set_moving(1);
    set_speed(300);
    switch(random(3)){
case 0:new("/d/damned/virtual/great-axe_6.weapon")->
                 move(this_object());
             force_me("wield axe in right hand and left hand");
             break;
      case 1:new("/d/damned/virtual/broad-sword_6.weapon")->
                 move(this_object());
             force_me("wield sword in right hand");
             break;
    }
    switch(random(4)){
      case 0:new("/d/damned/virtual/scale-mail.armour")->
                 move(this_object());
             force_me("wear mail");
             break;
      case 1:new("/d/damned/virtual/breast-plate.armour")->
                 move(this_object());
             force_me("wear plate");
             break;
      case 2:new("/d/damned/virtual/chain-greaves.armour")->
                 move(this_object());
             force_me("wear greaves");
             break;
    }
set_money("gold", 10);
    set_languages(({ "common", "middle-engish", "scotish", "xamelotion" }));
    set_lang_prof("scotish",10);
    set_emotes(5, ({
	  "The guard flaps his wings then wraps them around his body.",
	  "The guard cracks his knuckles.",
	  "The guard bounds looks around carefully for any evil do'ers.",
	}),1);
	set_speech(5,"common",({ 
	  "You dare attack a gargoyle, when will you people learn!!!!",
	  "Can't you do any better than that?!",
	}),1);
}




