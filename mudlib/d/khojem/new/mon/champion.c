//  Wizard:   Khojem
//  Monster:  King's Champion
//  File:     champion.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  ::create();
    set_name("King's Champion");
    set_id( ({ "champion","wood-elf" }) );
    set_level(5);
    set_short("[5]king's champion");
    set_long("The Wood-Elf King's Champion is a formidable opponent." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_property("melee damage", ([ "crushing" : 40]));
    set_overall_ac(6);
    set_skill("melee", 50);
    set_skill("dodge", 50);
    set_skill("parry", 50);
    set_skill("attack", 50);
    set_skill("two handed",60);
    set_stats("dexterity", 80);
    set_stats("intelligence", 100);
    set_stats("strength",100);
    set_wimpy(0);
    set_alignment(300);
    new("/d/damned/virtual/two-handed-sword_5.weapon")->
      move(this_object());
    force_me("wield sword in right hand and left hand");
    new("/d/damned/virtual/breast-plate.armour")->
      move(this_object());
    force_me("wear breast plate");
    new("/d/damned/virtual/great-helm.armour")->
      move(this_object());
    force_me("wear helm");
    new("/d/khojem/new/armor/leather_belt")->
      move(this_object());
    force_me("wear belt");
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+50));
    money->move(this_object());
    set_emotes(5, ({
	  "The champion smiles broadly.",
	  "The champion chuckles at your pathetic attempt.",
	}),1);
}
