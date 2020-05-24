//  Wizard:   Khojem
//  Monster:  sand worm
//  File:     sand_worm.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void create() {
  object money;
  ::create();
  set_name("sand worm");
  set_id( ({ "sand worm", "worm", "slug" }) );
  set_short("A ooze-dripping worm");
  set_long("The sand worm is huge.  It has a long cylindrical body with many "+
    "scales that ooze a strange yellow ooze from its scaly joints.  The "+
    "worm stands upright within a pit in the center of the room.  Most of its body "+
    "is firmly rooted in the pit.");
  set("race", "serpent");
  set_property("melee damage", ([ "crushing" : 15 ]));
  set_level(13);
  set_body_type("[13]serpent");
  set_skill("dodge", 0);
  set_skill("parry", 10);
  set_gender("male");
    set_emotes(4,({
      "The worm hisses at you!",
      "The sand worm arches upwards towards the chamber's ceiling.",
      "The sand worm hurls its huge mass at you!",
      "The sand worm retreats momentarily to the protection of the pit.",
    }),1);    
	set_casting_chance(0);
	set_combat_chance(75);
	add_spell("disruption bolt","$A");
	set_spell_level("disruption bolt",5);
	set_skill("chaos magic",60);
	add_spell("drain life","$R");
	set_spell_level("drain life",4);
	set_skill("necromancy",60);
    money=new("std/obj/coins");
    money->set_money("gold",((random(10))+35));
    money->move(this_object());
    new("/d/khojem/nomad/obj/quest_sash")->move(this_object());
    force_me("wear sash");
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
