//  Wizard:   Khojem
//  Monster:  Half-Orc Chief
//  File:     orc_chief.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc chief");
    set_id( ({ "chief", "orc", "half-orc chief", "half-orc" }) );
    set_level(5);
    set_short("[5]half-orc chief");
    set_long("The half-orc chief rules this unruly tribe of half-orcs." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 30]));
    set_skill("melee", 40);
    set_skill("dodge", 40);
    set_skill("attack", 40);
    set_skill("parry", 40);
    set_skill("two handed blunt", 50);
    set_stats("dexterity", 50);
    set_stats("intelligence", 50);
    set_stats("strength",60);
    set_wimpy(0);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
    set_alignment(-500);
    money=new("std/obj/coins");
    money->set_money("silver",(random(100)+120));
    money->move(this_object());
    new("/d/damned/virtual/war-hammer_6.weapon")->
      move(this_object());
    force_me("wield hammer in right hand");
    new("/d/khojem/new/obj/chieftain_key")->
      move(this_object());
    set_emotes(1, ({
	  "The orc smiles a toothless smile.",
	  "The orc coughs up some spew and spits it out.",
	  "The orc spits tobacco juice in your face.",
	}),1);
}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
