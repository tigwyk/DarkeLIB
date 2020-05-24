//  Wizard:   Khojem
//  Monster:  king spider
//  File:     king_spider.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("king sand spider");
    set_id( ({ "king sand spider","sand spider", "spider" }) );
    set_level(11);
    set_short("[11]king sand spider");
    set_long("The king sand spider is a huge spider.  Its body is a darke black "+
      "and has a hard, smooth surface.  The shell is smooth yet reflects no "+
      "light.  It has "+
      "a number of legs that reachout beyond its body and BIG, serrated pinchers "+
      "for tearing and holding its foe."
      );
    set("race", "arachnid");
    set_gender("male");
    set_body_type("arachnid");
    set_stats("intelligence", 80);
    set_stats("wisdom", 80);
    set_wimpy(0);
    set_alignment(-400);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    set_property("melee damage", ([ "cutting" : 10]));
    set_emotes(2, ({
	  "The king sand spider darts quickly across the floor.",
	  "The king sand spider grins at you wickedly.",
	  "The king sand spider shoots venom and just misses you in the eyes.",
	  "The king sand spider scrambles between your legs.",
	  "The king sand spider drops back into the darkness.  You hear it "+
	    "circle behind you in the darkness."
	}),1);
	set_class("mage");
	set_casting_chance(0);
	set_combat_chance(70);
	add_spell("killing cloud","$A");
	set_spell_level("killing cloud",3);
	set_skill("conjuration",65);
	add_spell("disruption bolt","$A");
	set_spell_level("disruption bolt",4);
	set_skill("chaos magic",65);
    money=new("std/obj/coins");
    money->set_money("silver",((random(20))+30));
    money->move(this_object());
	new("/d/khojem/nomad/armor/white-green_sash")->move(this_object());
	force_me("wear sash");
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
