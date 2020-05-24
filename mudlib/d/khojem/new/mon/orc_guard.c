//  Wizard:   Khojem
//  Monster:  Half-Orc Guard
//  File:     orc_guard.c

#include <std.h>

inherit MONSTER;

int chk_my_mon();

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("half-orc guard");
    set_id( ({ "guard","orc", "half-orc guard"}) );
    zlevel=random(2)+3;
    zskill=zlevel*8;
	if (zlevel == 3) set_short("[3]half-orc guard");
else 
if (zlevel == 4) set_short("[4]half-orc guard");
else
if (zlevel == 5) set_short("[5]half-orc guard");
else
if (zlevel == 6) set_short("[6]half-orc guard");
else
if (zlevel == 7) set_short("[7]half-orc guard");
else set_short("[8]half-orc guard");
	set_level(zlevel);

    set_long("The half-orc guard is a killing machine." 
      );
    set("race", "half-orc");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack", zskill);
    set_skill("axe", zskill);
    set_skill("blunt", zskill);
    set_skill("blade", zskill);
    set_stats("dexterity", zskill);
    set_stats("intelligence", 50);
    set_stats("strength", (zskill+20));
    set_wimpy(0);
    set_alignment(-100);
    set_moving(1);
    set_speed(240);
    set("aggressive", (: this_object(), "no_other_monsters" :) );
    switch(random(3)){
      case 0:new("/d/damned/virtual/hammer_3.weapon")->
                 move(this_object());
             force_me("wield hammer in right hand");
             new("/d/khojem/new/armor/rag_shirt")->
                 move(this_object());
             force_me("wear shirt");
             break;
      case 1:new("/d/damned/virtual/hand-axe_3.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             new("/d/damned/virtual/cloth-pants.armour")->
                 move(this_object());
             force_me("wear pants");
             break;
      case 2:new("/d/damned/virtual/long-sword_3.weapon")->
                 move(this_object());
             force_me("wield longsword in right hand");
             new("/d/khojem/new/armor/leather_mittens")->
                 move(this_object());
             force_me("wear mitten on right hand");
             break;
    }
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+9));
    money->move(this_object());
    set_languages(({ "orcish" }));
    set_lang_prof("orcish",10);
    set_emotes(5, ({
	  "The orc smiles a toothless smile.",
	  "The orc grins wickedly.",
	  "The orc spits tobacco juice in your eye.",
	  "The orc flings mud in your eye",
	  "The orc cackles insanely."
	}),1);
	set_speech(5,"orcish",({ 
	  "You dirt bag!  You shouldn't be here!",
	  "Prepare to die, scum!",
	  "Oh!  That was a good move!",
	  "Can't you do any better than that?!",
	}),1);
}

int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}

int chk_my_mon() { return 1;}

