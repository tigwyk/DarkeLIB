//  Wizard:   Khojem
//  Monster:  Gnome Hermit
//  File:     hermit.c

#include <std.h>

inherit MONSTER;

create() {
  object money;
  int    zskill;
  ::create();
    set_name("gnome hermit");
    set_id( ({ "gnome hermit","hermit" }) );
    set_level(5);
    set_short("gnome hermit");
    set_long("A gnome hermit with a pleasant smile and warm eyes.  "+
      "Long ago this hermit decided to leave the trappings of the "+
      "world and live the life of a recluse.  Now, tempered by years "+
      "of solitude she enjoys the sight of the infrequent traveller "+
      "to her humble hut." 
      );
    set("race", "gnome");
    set_gender("female");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    zskill=random(3)*10+10;
    set_skill("melee",zskill);
    set_skill("dodge",zskill);
    set_stats("intelligence", 100);
    set_stats("wisdom", 100);
    money=new("std/obj/coins");
    money->set_money("silver",random(200));
    money->move(this_object());
    set_languages(({ "common" }));
    set_wimpy(0);
    set_alignment(300);
    set_emotes(2, ({
	  "The hermit smiles and waves at you.",
	  "The hermit slowly raises her arm and extends a finger.  "+
	    "a dove suddenly flutters into the room and lands on the "+
	    "gnome's out-stretched finger.  The gnome bows her head "+
	    "slightly and gently kisses the back of the dove's head.  "+
	    "Then the dove flies off through the open window.",
	  "Briefly, the gnome stares absently out the window.  She is "+
	    "somehow preoccupied and behaves like you are not here.",
	  "The gnome briefly cocks her head and listens to the song "+
	    "birds chirping outside.  After a few moments she smiles."
	}),0);
	set_speech(5,"common",({ 
	  "I certainly hope those half-orcs didn't bother you!",
	  "Those half-orcs have raised hell in this small, hollow "+
	    "ever since they arrived here a few months back.",
	  "The wood-elves are trying to cast the half-orcs out "+
	    "of the hollow.  They have been fighting each other "+
	    "constantly.",
	  "It is easy to get lost in the forest.",
	  "I hear the half-orcs have an evil priest.  His magic is strong."
	}),0);
	set_class("cleric");
	set_casting_chance(0);
	set_combat_chance(70);
	add_spell("cure light wounds","$(ME)");
	add_spell("cure serious wounds","$ME)");
	add_spell("cause light wounds", "$R");
	add_spell("cause serious wounds","$A");
	add_spell("instill poison","$A");
	add_spell("holy armour","$(ME)");
	set_spell_level("cure light wounds",5);
	set_spell_level("cure serious wounds",2);
	set_spell_level("cause light wounds",5);
	set_spell_level("cause serious wounds",2);
	set_spell_level("instill poison",3);
	set_spell_level("holy armour",1);
	set_skill("prayer",60);
	set_skill("body alteration",30);
	set_fingers(5);
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

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
    (sscanf(cmd, "%sdead rose%s",p1, p2) == 2)){
    tell_room(environment(this_object()),
      "The hermit says:  \n"+
      "Long ago...  when I was very young...  I transfered much of "+
      "my magical powers to this beautiful rose I found growing wild.  I did "+
      "this so I could ration my powers if beset by evil doers.  "+
      "If weakened I could later transfer the strength contained in the "+
      "rose back to myself and rejuvenate some of my lost powers.  "+
      "A few years later, after the rose had long lost its bloom, "+
      "I was travelling in these woods that surround us.  "+
      "Fir'burger, king of the Fir'nvillee wood-elves, and his followers "+
      "beset upon me.  After a long battle the king spared my life, but "+
      "took my much valued dead rose.  Later, I took "+
      "up lodgings here in this old tree in hopes that one day I might "+
      "recover my dead rose.  Now, I have grown old and weary.  My powers "+
      "are greatly reduced and I need the dead rose now more than "+
      "ever.  Please help me and return my dead rose.  I promise to "+
      "reward you handsomely if you succeed.\n", ({ this_object() }));
    return;
  }
}

void catch_tell(string str) {
  string a, b, lang;
  object tp, ob;
  
  if(sscanf(str, "%*s says something in %s.", lang) == 2) {
    say_this("I don't understand "+lang+".  Please speak in common.");
    return;
  }
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    a = lower_case(a);
    tp = present(a, environment(this_object()));
    if(!tp) return;
    ob = present("dead_rose_quest_ob", this_object());
    if(!ob) {
      tell_object(tp, "This is very nice, but it is not what I seek.\n");
      return;
   }
   ob->remove();
   if(!tp->set_quest("dead rose")) {
     tell_object(tp,"Thank you.  No rewards for you.  You have already\n"+
       "completed this quest.\n");
     return; 
   }
   tell_object(tp, "The hermit says: You have recovered my dead rose!\nThe "+
     "hermit thanks you very much.\n");
   tell_object(tp, "The hermit pays you 200 mithril coins in reward.\n");
   tell_object(tp, "You gain 1000 experience points.\n");
   tell_object(tp, "Your alignment is slightly more good.\n");
   tp->add_money("mithril", 200);
   tp->add_exp(1000);  
   tp->add_alignment(50);  
   return;
  }
}
