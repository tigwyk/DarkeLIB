//  Wizard:   Khojem
//  Monster:  Rogue
//  File:     rogue.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc rogue");
    set_id( ({ "half-orc rogue", "rogue" }) );
    set_level(4);
    set_short("[4]rogue");
    set_long("The shadowy rogue looks frightful in this dim light." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_class("thief");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set("aggressive",1);
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 20);
    set_skill("dodge", 45);
    set_skill("parry", 45);
    set_skill("knife", 60);
    set_skill("thrown",30);
    set_skill("back stab", 30);
    set_stats("strength",60);
    set_stats("dexterity",80);
    set_wimpy(0);
    set_alignment(-500);
    money=new("std/obj/coins");
    money->set_money("silver",((random(10)*100)+random(10)));
    money->move(this_object());
    new("/d/khojem/new/weapon/envenom_dagger")->move(this_object());
    force_me("wield dagger in right hand");
    new("/d/damned/virtual/cloak.armour")->move(this_object());
    force_me("wear cloak");
    new("/d/khojem/new/armor/muddy_boots")->move(this_object());
    force_me("wear boots");
}
