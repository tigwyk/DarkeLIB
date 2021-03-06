//  Wizard:   Myrddin
//  Monster:  Tracker
//  File:         tracker.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("tracker");
    set_id( ({ "tracker","man"}) );
    set_level(1);
    set_short("tracker");
    set_long("He appears to be trained in the woodland arts, but does "
                   "not seem to have the confidence one gains with "
                   "experience." 
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_skill("blade", 15);
    set_stats("dexterity", 30);
    set_stats("intelligence", 50);
    set_stats("strength",30);
    set_wimpy(0);
    new("d/damned/virtual/broad-sword_3.weapon")->
                 move(this_object());
             force_me("wield sword in right hand");
    new("d/damned/virtual/studded-leather-jacket.armour")->
                 move(this_object());
             force_me("wear jacket");
    new("d/damned/virtual/studded-leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+20));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(2, ({
	  "The tracker watches carefully for hidden enemies.",
	  "The tracker sighs.",
                "The tracker acts as if he is ready for anything.",
	  "The tracker looks concerned about the current situation.",
	}),0);
	set_speech(2,"common",({ 
	  "They were tougher than anything I've seen.",
	  "Hopefully there will not be any more attacks.",
	  "The safety of the entire region may rest with me.",
	  "I hope there is no more fighting... too many people are "
                "already dead.",
	}),0);
              set_emotes(1, ({
	  "The tracker looks at you in spite.",
	}),1);
	set_speech(1,"common",({ 
	  "You fool, don't you see the greater dangers around you!?!",
	}),1);
}

