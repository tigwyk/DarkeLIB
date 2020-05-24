//  Wizard:   Khojem
//  Monster:  Assassin
//  File:     assassin.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
int hide_in_shadows,in_stealth;

void init() {
  :: init();
  if(!this_player()->is_player()) { return; }
  if(this_player()->query_invis()) { return; }
  if(this_player()->query_stealth() > 40) { return; }
  if(hide_in_shadows==0) {
    force_me("use hide in shadows");
    hide_in_shadows = 1;
  }
  if(in_stealth==0) {
    force_me("use stealth");
    in_stealth = 1;
  }
  delayed_call("do_bs",4,this_player());
  return;    
}

create() {
  object money,ob;
  int    zlevel;
  ::create();
    set_name("shadowy figure");
    set_id( ({ "shadowy figure", "man", "rogue", "thief", "figure" }) );
    set_level(6);
    set_short("[6]shadowy figure");
    set_long("He is a hooded, full-bearded man with a mischevious glint "+
      "in his eyes." 
      );
    set("race", "high-man");
    set_gender("male");
    set_class("thief");
    set_body_type("human");
    set_overall_ac(5);
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("pick pocket",80);
    set_skill("back stab",40);
    set_skill("stealth",40);
    set_skill("hide in shadows",40);
    set_wimpy(0);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(5, ({
	  "The shadowy figure darts quickly to the left.",
	  "The shadowy figure darts quickly to the right.",
	  "The shadowy figure ducks your swing."
	}),1);
	set_speech(5,"elvish",({ 
	  "Oh!  That was a good move!",
	  "Argh!  Foiled again!",
	  "I'll get away!  I always do!",
	}),1);
    money=new("std/obj/coins");
    money->set_money("silver",((random(20))+90));
    money->move(this_object());
    ob=new("/d/damned/virtual/dagger_5.weapon");
    ob->set_short("darke shiv");
    ob->set("id",({ "dagger", "knife", "shiv", "darke shiv" }));
    ob->set_long("The short, darke shiv appears to be a dangerous "+
            "weapon.  Wielded by the proper hand it can do much damage."); 
    ob->set_wc(8, "impaling");
    ob->move(this_object());
    command("wield shiv in right hand");
    hide_in_shadows = 0;
    in_stealth = 0;
}

int query_kho_mon() { return 1;}

void do_bs(object tp){
  if(!tp || !present(tp, environment())) { return; }
  force_me("use back stab at "+(string)tp->query_name());
  hide_in_shadows = 0;
  in_stealth = 0;
  return;
}

