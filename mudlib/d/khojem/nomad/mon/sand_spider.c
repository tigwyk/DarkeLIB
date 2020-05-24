//  Wizard:   Khojem
//  Monster:  sand spider
//  File:     sand_spider.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("sand spider");
    set_id( ({ "sand spider","spider" }) );
    set_level(9);
    set_short("[9]sand spider");
    set_long("The sand spider is a large spider.  Its body is a darke black "+
      "and has a hard, smooth surface.  The shell is smooth yet reflects no "+
      "light.  It has "+
      "a number of legs that reachout beyond its body and BIG, serrated pinchers "+
      "for tearing and holding its foe."
      );
    set("race", "arachnid");
    set_gender("female");
    set_body_type("arachnid");
    set_stats("intelligence", 70);
    set_stats("wisdom", 70);
    set_property("melee damage", ([ "cutting" : 5]));
    set_wimpy(0);
    set_alignment(-200);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    set_emotes(2, ({
	  "The sand spider darts quickly across the floor.",
	  "The sand spider shoots venom and just misses you in the eyes.",
	  "The sand spider scrambles between your legs.",
	  "The sand spider drops back into the darkness.  You hear it "+
	    "circle behind you in the darkness."
	}),1);
	set_class("mage");
	set_casting_chance(0);
	set_combat_chance(70);
	add_spell("killing cloud","$A");
	set_spell_level("killing cloud",1);
	set_skill("conjuration",55);
	add_spell("disruption bolt","$A");
	set_spell_level("disruption bolt",4);
	set_skill("chaos magic",55);
	new("/d/khojem/nomad/armor/white_sash")->move(this_object());
	force_me("wear sash");
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}

