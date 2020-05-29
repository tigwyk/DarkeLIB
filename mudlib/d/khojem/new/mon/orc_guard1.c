//  Wizard:   Khojem
//  Monster:  Half-Orc Guard1
//  File:     orc_guard1.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc guard");
    set_id( ({ "guard","orc", "half-orc guard"}) );
    set_level(random(2)+2);
    set_short("half-orc guard");
    set_long("The half-orc guard is sleeping soundly." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 1]));
    set_skill("melee", 1);
    set_skill("dodge", 1);
    set_skill("parry", 1);
    set_skill("axe", 30);
    set_skill("blunt", 30);
    set_skill("blade",30);
    set_stats("dexterity", 10);
    set_stats("intelligence", 10);
    set_stats("strength",10);
    set_wimpy(0);
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+9));
    money->move(this_object());
    set_languages(({ "orcish" }));
    set_lang_prof("orcish",10);
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc grins and wipes the sleep from his eyes.",
	  "The orc coughs up some spew and spits it out.",
	}),1);
	set_speech(5,"orcish",({ 
	  "You dirt bag!  You shouldn't be here!",
	  "Ah, shit!  And I was having such a good sleep.",
	  "Oh!  That was a good move!",
	  "What tha...  Where did you come from?!",
	}),1);
}
