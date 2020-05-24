//  Wizard:   Khojem
//  Monster:  Wood-Elf Hawker
//  File:     elf_hawker.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("street hawker");
    set_id( ({ "street hawker","hawker", "elf" }) );
    zlevel=(random(3)+2);
if (zlevel == 3) set_short("[3]street hawker");
else 
if (zlevel == 4) set_short("[4]street hawker");
else
if (zlevel == 5) set_short("[5]street hawker");
else
if (zlevel == 6) set_short("[6]street hawker");
else
if (zlevel == 7) set_short("[7]street hawker");
else set_short("[8]street hawker");
	set_level(zlevel); 
    set_long("The wood-elf hawker is here trying to encourage people to "+
      "buy the goods at the nearby shop." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    zskill=zlevel*6;
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_stats("intelligence", 80);
    set_stats("strength", zskill);
    set_alignment(zskill);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    money=new("std/obj/coins");
    money->set_money("silver",random(5)+10);
    money->move(this_object());
    set_emotes(10, ({
	  "The hawker waves his hands and beckons you to approach.",
	  "The hawker looks about for a likely customer.",
	  "The hawker beams a toothy smile and waves at you.",
	  "The hawker bounces on the balls of his feet."
	}),0);
	set_speech(20,"common",({ 
	  "Step right up!  Step right up!",
	  "Every day is a discount day at the Fresh Grocer!",
	  "We got a great selection of the finest, freshest goods!",
	  "We got the firmest, juiciest melons that can be found!",
	  "Greetings citizens!  It's a fine day to go to market!",
	  "Wayfarer's bread baked fresh this morning!  Guaranteed to stay fresh "
	    "for a week!",
	  "The Fresh Grocer has the finest selection of grapes and berries.  "+
	    "These berries are so fresh, they still have this morning's dew "+
	    "on em'!",
	  "You need calves milk?  Try the Fresh Grocer's calves milk!",
	  "Mutton.  Mutton.  We got the mutton at the Fresh Grocer!"
	}),0);
	new("/d/damned/virtual/cloak.armour")->move(this_object());
	force_me("wear cloak");
	new("/d/khojem/new/armor/slippers")->move(this_object());
	force_me("wear slippers");
}
