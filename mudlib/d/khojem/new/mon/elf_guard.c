//  Wizard:   Khojem
//  Monster:  Wood-Elf Guard
//  File:     elf_guard.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("wood-elf guard");
    set_id( ({ "guard","elf", "wood-elf guard"}) );
    zlevel=random(2)+3;
    zskill=zlevel*8;
	if (zlevel == 3) set_short("[3]wood-elf guard");
else 
if (zlevel == 4) set_short("[4]wood-elf guard");
else
if (zlevel == 5) set_short("[5]wood-elf guard");
else
if (zlevel == 6) set_short("[6]wood-elf guard");
else
if (zlevel == 7) set_short("[7]wood-elf guard");
else set_short("[8]wood-elf guard");
	set_level(zlevel);

    set_long("The wood-elf guard is defending Fir'nvillee." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_overall_ac(4);
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack", (zskill+10));
    set_skill("axe", zskill);
    set_skill("two handed polearm", zskill);
    set_skill("blade", zskill);
    set_stats("dexterity", zskill);
    set_stats("intelligence", 50);
    set_stats("strength", (zskill+20));
    set_wimpy(0);
    set_alignment(100);
    set_moving(1);
    set_speed(300);
    zlevel = random(4);
    switch(random(zlevel)){
      case 0:new("/d/damned/virtual/great-axe_4.weapon")->
                 move(this_object());
             force_me("wield axe in right hand and left hand");
             break;
      case 1:new("/d/damned/virtual/spear_4.weapon")->
                 move(this_object());
             force_me("wield spear in right hand and left hand");
             break;
      case 2:new("/d/damned/virtual/broad-sword_4.weapon")->
                 move(this_object());
             force_me("wield sword in right hand");
             break;
      case 3:new("/d/damned/virtual/morning-star_3.weapon")->
                 move(this_object());
             force_me("wield morning star in right hand");
             break;
    }
    if(zlevel<2) {
       new("/d/damned/virtual/studded-leather-jacket.armour")->
                 move(this_object());
       force_me("wear jacket"); 
    } else {     
    switch(random(4)){
      case 0:new("/d/damned/virtual/studded-leather-jacket.armour")->
                 move(this_object());
             force_me("wear jacket");
             break;
      case 1:new("/d/damned/virtual/studded-leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
             break;
      case 2:new("/d/damned/virtual/studded-leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/khojem/new/armor/wooden_shield")->
                 move(this_object());
             force_me("wear shield on left hand");
             break;
    }
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+10));
    money->move(this_object());
    set_languages(({ "elvish" }));
    set_lang_prof("elvish",10);
    set_emotes(5, ({
	  "The elf blinks and his mouth opens wide.",
	  "The elf grins wickedly.",
	  "The elf bounds away and flips head-over-heels.",
	}),1);
	set_speech(5,"elvish",({ 
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}

int chk_my_mon() { return 1;}

