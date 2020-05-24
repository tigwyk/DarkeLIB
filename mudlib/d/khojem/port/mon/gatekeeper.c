//  Wizard:   Khojem
//  Monster:  gatekeeper
//  File:     gatekeeper.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("gatekeeper");
    set_id( ({ "gatekeeper", "guard" }) );
    set_level(8);
    set_short("[8]gatekeeper");
    set_long("A bearded gatekeeper stands stone-face at his post."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set("gang bang",1);
    add_money("silver", random(10));
	set_class("fighter");
	new("/d/damned/virtual/halberd_3.weapon")->move(this_object());
	force_me("wield halberd in right hand and left hand");
}

int query_kho_mon() { return 1;}

