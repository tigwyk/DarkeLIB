//  Wizard:   Khojem
//  Monster:  Nomad Peasant
//  File:     peasant.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

create() {
  object money;
  int    flip_coin,zlevel,roll;  
  ::create();
    set_name("nomad peasant");
    set_id( ({ "peasant","nomad", "nomad peasant"}) );
    roll=random(10);
    switch(roll){
      case 0:zlevel=5;break;
      case 1:zlevel=5;break;
      case 2:zlevel=5;break;
      case 3:zlevel=6;break;
      case 4:zlevel=6;break;
      case 5:zlevel=6;break;
      case 6:zlevel=6;break;
      case 7:zlevel=7;break;
      case 8:zlevel=7;break;
      case 9:zlevel=8;break;
    }
    set_level(zlevel);
    set_short("nomad peasant");
    set_long("The nomad peasant is out tending to the daily chores." 
      );
    set("race", "high-man");
    flip_coin=random(2);
    if(flip_coin)
      set_gender("male");
    else set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : (6*zlevel)]));
    set_wimpy(30);
    set_moving(1);
    set_speed(180);
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+(4*zlevel)));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_languages(({ "middle-english" }));
    set_lang_prof("middle-english",10);
    set_emotes(2, ({
	  "The dirty peasant grunts as you approach.",
	  "The nomad peasant spits on the ground.",
	  "A nomad peasant wipes some tobacco juice dribble from his jaw.",
	  "A peasant eyes you warily."
	}),0);
	set_speech(2,"common",({ 
	  "Get out of my way!",
	  "A peasant's work is never done!",
	  "That was a bad sandstorm the other night.",
	  "The market never seems to have any food!",
	  "Prices at the bazaar are too high!  Those merchants have a monopoly!"
	}),0);
}

int chk_my_mon() { return 1;}

