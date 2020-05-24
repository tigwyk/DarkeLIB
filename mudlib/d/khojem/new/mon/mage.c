//  Wizard:   Khojem
//  Monster:  Wood-elf Mage
//  File:     mage.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

create() {
  object money;
  int    zskill;
  ::create();
    set_name("wood-elf mage");
    set_id( ({ "wood-elf mage","mage", "elf" }) );
    set_level(5);
    set_short("[5]wood-elf mage");
    set_long("The wood-elf mage has a dour look.  "+
      "It appears she does not like the company of strangers.  She "+
      "constantly paces the floor of her hut and trys to ignore "+
      "your presence." 
      );
    set("race", "wood-elf");
    set_gender("female");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    zskill=random(3)*10+40;
    set_skill("melee",zskill);
    set_skill("dodge",zskill);
    set_stats("intelligence", 120);
    set_stats("wisdom", 120);
    money=new("std/obj/coins");
    money->set_money("silver",random(zskill)+30);
    money->move(this_object());
    set_wimpy(0);
    set_alignment(350);
    set_languages(({"common", "elvish", "drow" }));
    set_lang_prof("elvish",10);
    set_lang_prof("drow",9);
    set_emotes(2, ({
	  "The mage strokes her chin and contemplates something which bothers her.",
	  "The mage grasps her hands behind her back and paces about."
	}),0);
	set_class("mage");
	set_casting_chance(0);
	set_combat_chance(90);
	add_spell("magic missile","$A");
	set_spell_level("magic missile",5);
	add_spell("burning hands","$A");
	set_spell_level("burning hands",5);
	add_spell("fireball","$A");
	set_spell_level("fireball",1);
	set_skill("conjuration",70);
	set_fingers(5);
	new("/d/damned/virtual/quarter-staff_5.weapon")->
	  move(this_object());
	force_me("wield staff in right hand and left hand");
	new("/d/damned/virtual/cloak.armour")->
	  move(this_object());
	force_me("wear cloak");
	new("/d/khojem/new/armor/slippers")->
      move(this_object());
    force_me("wear slippers");
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if(sscanf(cmd,"%sdead rose%s",p1,p2) ==2){
    say_this("A dead rose?  I don't know what you are talking about...",whom);
  }
  if(random(2))
    say_this("Hmm... where is that servant of mine!  He has much work to do! "+
      "I imagine he's off drunk some place again!",whom);
  if(sscanf(cmd,"%sfaerie%s",p1,p2) == 2) {
    say_this("Faeries?  Well, there was a faerie who long ago plagued "+
      "the villagers for a short time.  But, none for some years since.",whom);
  }
  if(sscanf(cmd,"%sking%s",p1,p2) == 2) {
    say_this("The king use to be useful in his younger years, but now "+
      "he is a babbling fool!",whom);
  }
  if(sscanf(cmd,"%shermit%s",p1,p2) == 2) {
    say_this("Hermit?  The only hermit I know is that weak cleric who lives "+
      "up a tree at the forest's edge.",whom);
  }
  return;
}

varargs void say_this(string str, object whom) {
  string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
     >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}

void catch_tell(string str) {
  string lang;

  if(sscanf(str, "%*s says something in %s.", lang) == 2 && random(2)) {
    say_this("I don't understand "+lang+".");
    return;
  }
}
