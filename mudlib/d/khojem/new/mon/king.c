//  Wizard:   Khojem
//  Monster:  Wood-Elf King
//  File:     king.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

create() {
  object money;
  ::create();
    set_name("Wood-Elf King");
    set_id( ({ "king","wood-elf king" }) );
    set_level(6);
    set_short("[6]Fir'burger, the wood-elf king");
    set_long("The wood-elf king looks like a veteran of many battles.  "+
      "The years are worn as the wrinkles on his face." 
      );
    set("race", "wood-elf");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_property("melee damage", ([ "crushing" : 40]));
    set_skill("melee", 40);
    set_skill("attack",50);
    set_skill("dodge", 50);
    set_skill("parry", 50);
    set_skill("two handed",60);
    set_stats("dexterity", 60);
    set_stats("intelligence", 90);
    set_stats("strength",70);
    set_wimpy(0);
    set_alignment(500);
    set_languages(({"common", "elvish", "drow", "middle-english", "serra" }));
    set_lang_prof("elvish",10);
    set_lang_prof("drow",10);
    set_lang_prof("middle-english",9);
    set_lang_prof("serra",8);
    money=new("std/obj/coins");
    money->set_money("silver",(random(200)+200));
    money->move(this_object());
    set_emotes(5, ({
	  "The king beams a smile at you.",
	  "The king contemplates a thought for a moment.",
	}),0);
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;
  
  who  = (string)whom->query_cap_name();
  if (sscanf(cmd,"%sdead rose%s",p1, p2) == 2) {
    say_this("A dead rose?  Hmm...  I recall taking a dead rose off "+
      "a wandering gnome cleric years back.  But, before returning "+
      "to the village we were attacked by a faerie who made off with "+
      "it.",whom);
  }
  if(sscanf(cmd,"%sfaerie%s",p1, p2) == 2) {
    say_this("That damn faerie!  It was all over my men and gone within "+
      "a few minutes.  Fast, damn fast!  The faerie whirled around us "+
      "and snatched the dead rose.  I sent many of my men into the "+
      "forest to track it down, but never saw it again.",whom);
  }
  if(sscanf(cmd,"%smage%s",p1, p2) == 2) {
    say_this("What about the mage?  One lives here in the village.  "+
      "She's an odd sort, but handy to have around in combat.",whom);
  }
  if(sscanf(cmd,"%shermit%s",p1, p2) == 2) {
    say_this("Yes...  I recall a wandering gnome cleric years back.  "+
      "My warriors say she lives up in some tree now.  She doesn't "+
      "bother my people, so we leave her alone.",whom);
  }
  if(sscanf(cmd,"%sgnome%s",p1, p2) == 2) {
    say_this("I've met a few gnomes in my day.  There is that hermit, "+
      "too.",whom);
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
