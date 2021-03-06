//  Wizard:   Khojem
//  Monster:  Half-Orc Warrior2
//  File:     orc_warrior2.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("half-orc warrior");
    set_id( ({ "warrior","orc", "half-orc warrior"}) );
    set_level(3);
    set_short("half-orc warrior");
    set_long("The half-orc warrior is bruising for anyone." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 10);
    set_skill("dodge", 15);
    set_skill("parry", 15);
    set_skill("axe", 20);
    set_skill("flail", 20);
    set_skill("blunt", 20);
    set_skill("two handed polearm", 40);
    set_stats("dexterity", 40);
    set_stats("intelligence", 40);
    set_stats("strength",40);
    set_wimpy(0);
    set_alignment(-75);
    set("aggressive", (: this_object(), "no_other_monsters" :) );
    switch(random(3)){
      case 0:new("/d/damned/virtual/hammer_3.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand");
             new("/wizards/khojem/new/armor/rag_shirt")->
                 move(this_object());
             force_me("wear shirt");
             break;
      case 1:new("/d/damned/virtual/hand-axe_3.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             new("/wizards/khojem/new/armor/stone_shield")->
                 move(this_object());
             force_me("wear shield on left hand");
             break;
      case 2:new("/d/damned/virtual/morning-star_3.weapon")->
                 move(this_object());
             force_me("wield morning star in right hand");
             new("/wizards/khojem/new/armor/rag_pants")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/damned/virtual/hammer_3.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand");
             new("/wizards/khojem/new/armor/leather_mittens")->
                 move(this_object());
             force_me("wear mitten on right hand");
             break;    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+40));
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
	  "You swine!  I'm only interested in killing wood-elf peasants!",
	  "Hey, let's call it even!  Seen any wood-elf slugs nearby?",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}

