//  Wizard:   Khojem
//  Monster:  sand devil
//  File:     sand_devil.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("sand devil");
    set_id( ({ "sand devil","devil" }) );
    set_level(8);
    set_short("[8]sand devil");
    set_long("The sand devil is a small, four-legged creature with an arched back "+
      "and small spiked horns protruding from its head.  "+
      "The devil's skin is dry and cracked and looks much like sand.  "
      );
    set("race", "sand devil");
    set_gender("neuter");
    set_body_type("quadruped");
    set_property("melee damage", ([ "cutting" : 12]));
    set_stats("intelligence", 35);
    set_wimpy(0);
    set_moving(1);
    set_speed(180);
    set_alignment(-100);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    money=new("std/obj/coins");
    money->set_money("silver",((random(10))+20));
    money->move(this_object());
    set_emotes(2, ({
	  "The sand devil scurries around you.",
	  "The sand devil spins like a dervish."
	}),1);
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
