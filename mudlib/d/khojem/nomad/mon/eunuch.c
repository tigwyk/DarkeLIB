//  Wizard:   Khojem
//  Monster:  oiled eunuch
//  File:     eunuch.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int    mod;
  ::create();
    set_name("oiled eunuch");
    set_id( ({ "oiled eunuch", "eunuch" }) );
    mod=random(2);
    set_level(15+mod);
    set_short("oiled eunuch");
    set_long("He is a large, rotund castrated servant.  The eunuch's "+
      "entire body is devoid of hair.  His massive body and bald head "+
      "are oiled from rare, desert plant oils."
      );
    set("race", "high-man");
    set_gender("neuter");
    set_body_type("human");
    set_class("fighter");
    set_overall_ac(15+(2*mod));
    set_melee_damage( (["crushing" : 40 ]) );
    set_property("enhance criticals",-1);
    set_property("magic resistance",55);
    set_wielding_limbs( ({ "right hand" }) );
    set_wimpy(0);
    add_money("silver", random(30));
    set_emotes(2, ({
      "The eunuch charges you!  His massive flesh ripples with his every move!",
      "You briefly brush up against the eunuch during battle.  The eunuch "+
         "leaves a big oily patch on your arm.  Yuck!",
      "The eunuch throws his massive gut at you.  You are repelled across "+
         "the room!",
      "A eunuch clumsy tries to advance on you from your flank side."
    }),1);
    set_casting_chance(0);
    set_combat_chance(80);
    add_spell("blur","$ME");
    set_spell_level("blur",4);
    set_skill("illusionism",90);
    set_skill("concentrate",85);
    new("/d/damned/virtual/scimitar_6.weapon")->move(this_object());
    force_me("wield scimitar in right hand");
    force_me("use concentrate");
}

int query_kho_mon() { return 1;}
 
void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
      b = lower_case(b);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("oiled eunuch", b)) {
           message("info","A eunuch shouts, Intruders at "
             "the hareem!\nDeath to "+c+"!\n",
             environment(this_object()));
           ob1 -> add_follower(this_object());
           force_me("kill "+a);
           return;
         }
      }
   }   
}
