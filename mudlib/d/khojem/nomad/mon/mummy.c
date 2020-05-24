//  Wizard:   Khojem
//  Monster:  mummy
//  File:     mummy.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("mummy");
    set_id( ({ "mummy","mummy" }) );
    set_level(12);
    set_short("[12]mummy");
    set_long("Your presence has disturbed the mummy from its long rest.  "+
      "The mummy stirs and moves stiffly as he engages in combat with you.  "+
      "His advance is relentless.  Years of dust are stirred from his "+
      "wrappings and shroud him in a mist."
      );
    set("race", "undead");
    set_gender("male");
    set_body_type("human");
    set_skill("dodge",2);
    set_skill("parry",2);
    set_stats("intelligence", 80);
    set_stats("wisdom", 70);
    set_property("melee damage", ([ "cutting" : 10]));
    set_wimpy(0);
    set_alignment(-500);
    set_emotes(2, ({
	  "The mummy advances slowly and relentlessly towards you.",
	  "The mummy raises his hand and stretches his arm out towards your throat!",
	  "The mummy is briefly thrown off balance and stiffly recovers himself."
	}),1);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
	set_class("mage");
	set_casting_chance(0);
	set_combat_chance(70);
	add_spell("drain life","$A");
	set_spell_level("drain life",6);
	set_skill("necromancy",70);
	new("/d/khojem/nomad/armor/mummy_wrappings")->move(this_object());
	force_me("wear rags");
    money=new("std/obj/coins");
    money->set_money("silver",((random(20))+20));
    money->move(this_object());
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
