//  Wizard:   Khojem
//  Monster:  Half-Orc Warrior1
//  File:     orc_warrior1.c

#include <std.h>

inherit MONSTER;

void init() {
	call_out("force_me",1,"kill wood-elf warrior");
	add_action("damnation","bog");
	force_me("kill wood-elf warrior");
	::init();
}

create() {
  object money;
  int    zskill, zlevel;
  ::create();
    set_name("half-orc warrior");
    set_id( ({ "warrior","orc", "half-orc warrior"}) );
    zlevel=random(2)+2;
    zskill=8*zlevel;
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
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_skill("attack", zskill);
    set_skill("parry", zskill);
    set_skill("axe", zskill);
    set_skill("flail", zskill);
    set_skill("blunt", zskill);
    set_skill("two handed polearm", zskill);
    set_stats("dexterity", 40);
    set_stats("intelligence", 40);
    set_stats("strength",45);
    set_wimpy(0);
    set_alignment(-50);
    switch(random(4)){
      case 0:new("/d/damned/virtual/hammer_5.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand");
             break;
      case 1:new("/d/damned/virtual/hand-axe_5.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 2:new("/d/damned/virtual/quarter-staff_5.weapon")->
                 move(this_object());
             force_me("wield staff in right hand and left hand");
             break;
      case 3:new("/d/damned/virtual/morning-star_5.weapon")->
                 move(this_object());
             force_me("wield morning star in right hand");
             break;
    }
    switch(random(4)){
      case 0:new("/d/khojem/new/armor/rag_shirt")->
                 move(this_object());
             force_me("wear shirt");
             break;
      case 1:new("/d/khojem/new/armor/stone_shield")->
                 move(this_object());
             force_me("wear shield");
             break;
      case 2:new("/d/khojem/new/armor/rag_pants")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 3:new("/d/khojem/new/armor/leather_mittens")->
                 move(this_object());
             force_me("wear mitten on right hand");
             break;
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+4));
    money->move(this_object());
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc grins wickedly.",
	  "The orc spits tobacco juice in your eye.",
	  "The orc flings mud in your eye",
	  "The orc cackles insanely."
	}),1);
}

void damnation() {
	force_me("kill wood-elf warrior");
}

