//  Wizard:   Khojem
//  File:     citizen.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  int    flip_coin,zlevel,roll;  
  ::create();
    set_name("citizen");
    set_id( ({ "citizen", "mob" }) );
    roll=random(10);
    switch(roll){
      case 0:zlevel=5;break;
      case 1:zlevel=5;break;
      case 2:zlevel=5;break;
      case 3:zlevel=5;break;
      case 4:zlevel=5;break;
      case 5:zlevel=5;break;
      case 6:zlevel=6;break;
      case 7:zlevel=6;break;
      case 8:zlevel=6;break;
      case 9:zlevel=7;break;
    }
    set_level(zlevel);
	

if (zlevel == 5) set_short("[5]citizen");
else 
if (zlevel == 6) set_short("[6]citizen");
else
if (zlevel == 7) set_short("[7]citizen");
else set_short("[4]citizen");
	set_level(zlevel);

    set_long("The citizen is tending to the daily chores." 
      );
    set("race", "gromek");
    flip_coin=random(2);
    if(flip_coin)
      set_gender("male");
    else set_gender("female");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 10]));
    set_overall_ac(6);
    set_moving(1);
    set_speed(200);
    set_wimpy(10);
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+(10*zlevel)));
    money->move(this_object());
}

int query_kho_mon() { return 1;}

