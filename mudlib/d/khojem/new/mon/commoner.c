//  Wizard:   Khojem
//  Monster:  Wood-Elf Commoner
//  File:     commoner.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

create() {
  object money;
  int    flip_coin,zlevel,zskill,roll;  
  ::create();
    set_name("wood-elf commoner");
    set_id( ({ "commoner","elf", "wood-elf commoner"}) );
    roll=random(10);
    switch(roll){
      case 0:zlevel=1;break;
      case 1:zlevel=1;break;
      case 2:zlevel=2;break;
      case 3:zlevel=2;break;
      case 4:zlevel=2;break;
      case 5:zlevel=3;break;
      case 6:zlevel=3;break;
      case 7:zlevel=3;break;
      case 8:zlevel=3;break;
      case 9:zlevel=4;break;
    }
    set_level(zlevel);
    zskill=8*zlevel;
    set_short("wood-elf commoner");
    set_long("The wood-elf commoner is out tending to the daily chores." 
      );
    set("race", "wood-elf");
    flip_coin=random(2);
    if(flip_coin)
      set_gender("male");
    else set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_stats("dexterity", 20);
    set_stats("intelligence", 60);
    set_wimpy(30);
    set_alignment(20);
    set_moving(1);
    set_speed(180);
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
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+(10*zlevel)));
    money->move(this_object());
    set_languages(({ "elvish" }));
    set_lang_prof("elvish",10);
    set_emotes(5, ({
	  "The elf smiles a toothy smile.",
	  "The elf beams at you.",
	  "You make brief eye contact, the wood-elf nods at you.",
	}),0);
	set_speech(5,"elvish",({ 
	  "Good day, Governor.  Good day.",
	  "Nice day, huh?",
	  "Hello!",
	  "My!  I got chores to do!  Chores to do!"
	}),0);
}

int chk_my_mon() { return 1;}
