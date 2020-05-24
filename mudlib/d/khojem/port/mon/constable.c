//  Wizard:   Khojem
//  Monster:  constable
//  File:     constable.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

void do_kill(object who);

create() {
  int zlevel,roll;
  ::create();
    set_name("constable");
    set_id( ({ "constable", "guard", "cop" }) );
    zlevel = 16 + random(4);
if (zlevel == 16) set_short("[16]constable");
else 
if (zlevel == 17) set_short("[17]constable");
else
if (zlevel == 18) set_short("[18]constable");
else
if (zlevel == 19) set_short("[19]constable");
else
if (zlevel == 20) set_short("[20]constable");
else set_short("[15]constable");
    set_level(zlevel);
    set_melee_damage( ([ "crushing" : 30, "strike" : 10 ]) );
    set_overall_ac(25);
    set_exp(200000);
    set("gang bang",1);

    set_long("A broad shouldered constable of Vo'Sangor."
      );
    set("race", "dwarf");
    set_gender("male");
    set_body_type("human");
    set_property("enhance criticals", -2);
    set_wimpy(0);
    set_moving(1);
    set_speed(90);
    add_spell("blur","$ME");
    set_spell_level("blur",6);
    add_spell("mad rage","$ME");
    set_spell_level("mad rage",6);
    set_combat_chance(98);
    set_property("magic resistance",80);
    set_skill("illusionism",90);
    set_skill("magery",70);
    set_skill("concentrate",80);
    set_skill("whirlwind attack",100);
    add_money("gold", 20);
    add_money("silver", (random(200)));
    set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
      "dwarvish", "drow", "middle-english", "mountainspeak" }));
    set_lang_prof("common",10);
    set_class("fighter");
    new("/d/khojem/port/weapon/blackjack")->move(this_object());
    force_me("use concentrate");
    force_me("wield blackjack in right hand");
}

void do_kill(object who) {
  if(!present(who,environment(this_object()))) { return; }
  message("info",who->query_cap_name()+"! Criminals like you "
         "are not welcome in Vo'Sangor!\n",this_object());
  force_me("use whirlwind attack");
  this_object()->kill_ob(who,0);
  return;
}

int query_kho_mon() { return 1;}

void catch_tell(string str) {
  string a, b, who;
  object obj;
  
  if(sscanf(str,"%s attacks %s",a,b) == 2) {
    b = lower_case(a);
    obj = present(b,environment(this_object()));
    if(obj) {
      obj -> add_follower(this_object());
      force_me("use whirlwind attack");
      force_me("kill "+b);
      b = a+" you criminal!  The likes of you are not welcome in
Vo'Sangor!";
      force_me("yell in common "+b);
    }
  }
  return;
}

