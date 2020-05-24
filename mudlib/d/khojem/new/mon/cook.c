//  Wizard:   Khojem
//  Monster:  Half-Orc Cook
//  File:     cook.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc cook");
    set_id( ({ "cook","orc", "half-orc cook"}) );
    set_level(4);
    set_short("[4]half-orc cook");
    set_long("The half-orc cook is covered in grease from his work." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 20);
    set_skill("dodge", 20);
    set_skill("blunt", 40);
    set_stats("dexterity", 70);
    set_stats("intelligence", 50);
    set_stats("strength",100);
    set_wimpy(0);
    new("/d/khojem/new/weapon/skillet")->move(this_object());
    force_me("wield skillet in right hand");
    new("/d/khojem/new/armor/apron")->move(this_object());
    force_me("wear apron");
    set_alignment(-100);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+10));
    money->move(this_object());
    set_languages(({ "orcish" }));
    set_lang_prof("orcish",10);
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc grins wickedly.",
	  "The orc spits tobacco juice in your eye.",
	  "The orc flings mud in your eye",
	  "The orc cackles insanely."
	}),1);
	set_speech(5,"orcish",({ 
	  "You swine!  You want to steal the food!",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
