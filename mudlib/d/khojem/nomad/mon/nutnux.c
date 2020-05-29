//  Wizard:   Khojem
//  Monster:  Nutnux
//  File:     nutnux.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

int query_kho_mon();

create() {
  ::create();
    set_name("nutnux");
    set_id( ({ "nutnux" }) );
    set_level(20);
    set_exp(200000);
    set_overall_ac(22);
    set_max_hp(2500);
    set_hp(2500);
    set_short("Nutnux");
    set_long("Nutnux is a high-man employed in the profession of mercenary. "+
      "He looks like a formitable foe and one not to be tangled with."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_alignment(500);
    set_moving(1);
    set_property("enhance criticals",-3);
    set_speed(360);
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 50]));
    add_money("silver", random(200));
    set_languages(({
     "common", "stormspeak", "elvish", "serra", "yin", "dwarvish", 
     "drow", "undead-tongue",
     "pix", "orcish", "vr'krr", "catfolk", "gr'grr", "rachk"
   }));
   set_lang_prof("common",10);
   set_lang_prof("stormspeak",8);
   set_lang_prof("elvish",9);
   set_lang_prof("serra",10);
   set_lang_prof("yin",10);
   set_lang_prof("dwarvish",9);
   set_lang_prof("drow",9);
   set_lang_prof("undead-tongue",10);
   set_lang_prof("pix",10);
   set_lang_prof("orcish",8);
   set_lang_prof("vr'krr",9);
   set_lang_prof("catfolk",9);
   set_lang_prof("gr'grr",9);
   set_lang_prof("rachk",10);
   set_emotes(5, ({
     "Nutnux grins broadly at you and chuckles.",
     "Nutnux shows off some fancy ninja stuff.",
     "Nutnux spits tobacco juice into your face!"
   }),1);
   set_class("fighter");
   set_skill("offhand training",90);
   set_skill("dual attack",90);
   set_skill("reverse stroke",70);
   set_skill("concentrate",80);
   set_casting_chance(0);
   set_combat_chance(90);
   add_spell("blur","$ME");
   set_spell_level("blur",6);
   set_skill("illusionism",90);
   add_spell("cure light wounds","$(ME)");
   set_spell_level("cure light wounds",6);
   set_skill("prayer",70);
   set("aggressive", (: call_other, this_object(), "attack_bob" :) );
   new("/d/damned/virtual/scimitar_5.weapon")->move(this_object());
   force_me("wield scimitar in right hand");
   new("/wizards/khojem/nomad/weapon/rapier")->move(this_object());
   force_me("wield rapier in left hand");
   force_me("use concentrate");
}

int query_kho_mon() { return 1;}

int attack_drill(object who) {
  force_me("nod at "+(who->query_cap_name()));
  return 1;
}

int attack_bob(object who) {
        if (!who->is_player()) return 0;
        call_out( "attack_drill",1,who );
        return 0;
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
    (sscanf(cmd, "%ssash%s",p1, p2) == 2)){
    tell_room(environment(this_object()),
      "Nutnux says:  \n"+
      "I seem to have misplaced my sash.  It was given to me as a gift from "+
      "a dear friend.  I've been looking everywhere for it.  Can you help me "+
      "and return my sash?  I will give you a nice reward if you do.\n",
        ({ this_object() }));
    return;
  }
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
    ob = present("nutnux_quest_ob", this_object());
    if(!ob) {
      tell_object(tp, "This is very nice, but it is not what I seek.\n");
      return;
   }
   ob->remove();
   if(!tp->set_quest("Nutnux's Quest")) {
     tell_object(tp,"Thank you.  No rewards for you.  You have already "+
       "completed this quest.\n");
     return; 
   }
   tell_object(tp, "Nutnux says: Oh!  You have found my sash!\n");
   tell_object(tp, "Nutnux pays you 400 mithril coins in reward.\n");
   tell_object(tp, "You gain 5000 experience points.\n");
   tp->add_money("mithril", 400);
   tp->add_exp(5000);  
   return;
  }
}
