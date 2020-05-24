//  Wizard:   Khojem
//  Monster:  Half-Orc Warrior
//  File:     orc_warrior0.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
int zlevel;
  ::create();
    set_name("half-orc warrior");
    set_id( ({ "warrior","orc", "half-orc warrior"}) );
   zlevel=(random(2)+2);

if (zlevel == 2) set_short("[2]half-orc warrior");
else
if (zlevel == 3) set_short("[3]half-orc warrior");
else
if (zlevel == 4) set_short("[4]half-orc warrior");
else set_short("[5]half-orc warrior");
	set_level(zlevel);
    set_long("The half-orc warrior is bruising for a wood-elf." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(2);
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
    set_max_hp(40);
    set_hp(40);
    switch(random(4)){
      case 0:new("/d/khojem/new/weapon/hammer")->
                 move(this_object());
             force_me("wield hammer in right hand");
             break;
      case 1:new("/d/khojem/new/weapon/hand_axe")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 2:new("/d/khojem/new/weapon/quarterstaff")->
                 move(this_object());
             force_me("wield quarterstaff in right hand and left hand");
             break;
      case 3:new("/d/khojem/new/weapon/morningstar")->
                 move(this_object());
             force_me("wield morningstar in right hand");
             break;
    }

    switch(random(4)){
      case 0:new("/d/khojem/new/armor/rag_shirt")->
                 move(this_object());
             force_me("wear jacket");
             break;
      case 1:new("/d/khojem/new/armor/stone_shield")->
                 move(this_object());
             force_me("wear shield");
             break;
      case 2:new("/d/khojem/new/armor/pants")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/khojem/new/armor/leather_mittens")->
                 move(this_object());
             force_me("wear mittens");
             break;
    }
    money=new("std/obj/coins");
    money->set_money("silver",random(10));
    money->set_money("copper",random(300));
    money->move(this_object());
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
	force_me("kill wood-elf warrior");
}
// res=command("kill wood-elf warrior");

