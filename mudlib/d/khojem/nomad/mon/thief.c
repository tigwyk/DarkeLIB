//  Wizard:   Khojem
//  Monster:  Desert Thief
//  File:     thief.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("desert thief");
    set_id( ({ "desert thief", "thief" }) );
    set_level(11);
    set_short("[11]desert thief");
    set_long("The tall, full-bearded man with a mischevious glint "+
      "in his eyes.  He makes his trade by stealing from desert "+
      "wanderers as they rest by the oasis." 
      );
    set("race", "high-man");
    set_gender("male");
    set_class("thief");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set("aggressive", (: call_other, this_object(), "aggro_test" :) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("thrown",40);
    set_skill("back stab", 20);
    set_wimpy(0);
    set_alignment(-500);
    money=new("std/obj/coins");
    money->set_money("silver",((random(10))+30));
    money->move(this_object());
    new("/d/khojem/nomad/weapon/ob_dirk")->move(this_object());
    force_me("wield dirk in right hand");
}
