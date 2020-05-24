//  Wizard:   Khojem
//  Monster:  gambler
//  File:     gambler.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money, obj;
  ::create();
    set_name("gambler");
    set_id( ({ "nomad gambler", "gambler", "nomad" }) );
    set_level(13);
    set_short("[13]nomad gambler");
    set_long("The gambler appears interested in playing the game.  He is a short "+
      "fat nomad with a bald, sunburnt head.  He is alert to the game and "+
      "constantly mutters to himself."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(10);
    set_skill("flail",85);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_languages(({ "middle-english" }));
    set_lang_prof("middle-english",10);
    set_emotes(5, ({
	  "The nomad gambler shakes his head.",
	  "The nomad gambler checks his purse.",
	  "The nomad gambler puts some coins on the table and bets on black.",
	  "The nomad gambler puts some coins on the table and bets on red.",
	  "The nomad gambler puts some coins on the table and plays a number."
	}),0);
	set_speech(6,"common",({ 
	  "This table must be rigged!  I can't win!",
	  "Maybe I should quit while I'm ahead.",
	  "Did you see that!  The pit boss pressed a lever under the table!",
	  "Come on SEVEN!",
	  "The pit boss should let us double down!",
	  "I've been here for hours!  I can't start a winning streak!",
	  "The thought of facing my wife later chills me to the bone!"
	}),0);
	set_class("tinker");
	new("/d/khojem/nomad/weapon/flail")->move(this_object());
	force_me("wield flail in right hand");
	obj=new("/d/khojem/nomad/obj/purse");
    money=new("std/obj/coins");
    money->set_money("gold",(random(10)+20));
    money->move(obj);
}

int query_kho_mon() { return 1;}
