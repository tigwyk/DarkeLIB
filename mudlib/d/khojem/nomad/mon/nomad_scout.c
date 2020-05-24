//  Wizard:   Khojem
//  Monster:  nomad scout
//  File:     nomad scout.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("nomad scout");
    set_id( ({ "nomad scout", "nomad", "scout" }) );
    set_level(10);
    set_short("[10]nomad scout");
    set_long("The nomad scout is looking for invaders of his land."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_alignment(-100);
    set_moving(1);
    set_speed(120);
    set("aggressive", (: call_other, this_object(), "attack_bob" :) );
    set_emotes(5, ({
	  "The nomad scout leaps at you in a fit of frenzy!",
	  "The scout whirls his scimitar, spins and lungs at you.",
	  "The scout spits tobacco juice on your tunic!"
	}),1);
	set_class("fighter");
    money=new("std/obj/coins");
    money->set_money("silver",((random(10))+25));
    money->move(this_object());
	new("/d/damned/virtual/scimitar_4.weapon")->move(this_object());
	force_me("wield scimitar in right hand");
	new("/d/khojem/nomad/armor/green_sash")->move(this_object());
	force_me("wear sash");
}

int query_kho_mon() { return 1;}

int attack_drill(object who) {
  who->init();
  tell_room(environment(this_object()),
    "\nThe nomad scout shrieks and shouts,\n"+
    "Death to the "+(who->query_race())+"!\n",
    ({ this_object() }));
  return 1;
}


int attack_bob(object who) {
	if (!who->is_player()) return 0;
	call_out( "attack_drill",1,who );
	return 1;
}
