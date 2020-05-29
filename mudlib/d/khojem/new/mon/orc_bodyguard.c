//  Wizard:   Khojem
//  Monster:  Half-Orc Bodyguard
//  File:     orc_bodyguard.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc bodyguard");
    set_id( ({ "bodyguard","orc", "half-orc bodyguard", "guard" }) );
    set_level(5);
    set_short("half-orc bodyguard");
    set_long("The half-orc bodyguard protects the chief." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 30]));
    set_skill("melee", 40);
    set_skill("dodge", 40);
    set_skill("parry", 40);
    set_skill("attack", 40);
    set_skill("two handed blunt", 40);
    set_stats("dexterity", 40);
    set_stats("intelligence", 40);
    set_stats("strength",60);
    set_wimpy(0);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
    set_alignment(-400);
    money=new("std/obj/coins");
    money->set_money("silver",(random(100)+90));
    money->move(this_object());
    new("/d/damned/virtual/war-hammer_5.weapon")->
      move(this_object());
    force_me("wield hammer in right hand");
    set_languages(({ "orcish" }));
    set_lang_prof("orcish",10);
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc coughs up some spew and spits it out.",
	  "The orc spits tobacco juice in your face.",
	}),1);
	set_speech(5,"orcish",({ 
	  "You dirt bag!  You shouldn't be here!",
	  "Oh!  That was a good move!",
	  "Time to die!",
	}),1);
}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
