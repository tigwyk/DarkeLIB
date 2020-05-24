//  Wizard:   Khojem
//  Monster:  Wood-Elf Warrior
//  File:     elf_warrior.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("wood-elf warrior");
    set_id( ({ "warrior","elf", "wood-elf warrior"}) );
    zlevel=random(4)+2;
    zskill=zlevel*8;
if (zlevel == 1) set_short("[1]wood-elf warrior");
else 
if (zlevel == 2) set_short("[2]wood-elf warrior");
else
if (zlevel == 3) set_short("[3]wood-elf warrior");
else
if (zlevel == 4) set_short("[4]wood-elf warrior");
else
if (zlevel == 5) set_short("[5]wood-elf warrior");
else set_short("[6]wood-elf warrior");
	set_level(zlevel);
    set_long("The wood-elf warrior is tracking half-orcs." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack",zskill);
    set_skill("axe", zskill);
    set_skill("flail", zskill);
    set_skill("two handed polearm", zskill);
    set_stats("dexterity", 40);
    set_stats("intelligence", 50);
    set_stats("strength",40);
    set_wimpy(0);
    set_alignment(10);
    zlevel = random(4);
    switch(zlevel){
      case 0:new("/d/khojem/new/weapon/wooden_spear")->
                 move(this_object());
             force_me("wield spear in right hand and left hand");
             break;
      case 1:new("/d/damned/virtual/hand-axe_5.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 2:new("/d/damned/virtual/quarter-staff_5.weapon")->
                 move(this_object());
             force_me("wield staff in right hand and left hand");
             break;
      case 3:new("/d/damned/virtual/morning-star_5.weapon")->
                 move(this_object());
             force_me("wield morning star in right hand");
             break;
    }
    if(zlevel==2){
      new("/d/damned/virtual/leather-jacket.armour")->
                 move(this_object());
      force_me("wear jacket");
    } else {
    switch(random(3)){
      case 0:new("/d/damned/virtual/leather-jacket.armour")->
                 move(this_object());
             force_me("wear jacket");
             break;
      case 1:new("/d/damned/virtual/cloak.armour")->
                 move(this_object());
             force_me("wear cloak");
             break;
      case 2:new("/d/damned/virtual/leather-pants.armour")->
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
    money->set_money("silver",(random(20)+5));
    money->move(this_object());
    set_emotes(5, ({
	  "The elf blinks and his mouth opens wide.",
	  "The elf grins wickedly.",
	  "The elf spits in the orc's eye.",
	  "The elf bounds away from the orc and flips head-over-heels.",
	  "The elf chuckles at the orc's flimsy attack."
	}),1);
	set_speech(5,"elven",({ 
	  "You swine, half-orc raider!",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}

