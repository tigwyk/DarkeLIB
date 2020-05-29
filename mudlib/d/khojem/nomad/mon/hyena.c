//  Wizard:   Khojem
//  Monster:  hyena
//  File:     hyena.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int mod;
  ::create();
    set_name("hyena");
    set_id( ({ "hyena", "dog" }) );
    mod=(random(2));
    set_level(5);
    set_short("A blood-thirsty hyena");
    set_long("A blood-frenzied hyena is attracted by the smell of blood.  "+
      "It bares its teeth and snarls at you."
      );
    set("race", "dog");
    set_body_type("quadruped");
    set_gender("male");
    set_stats("intelligence", 20);
    set_property("melee damage", ([ "cutting" : 15]));
    set_skill("perception",90);
    set_wimpy(10);
    set_moving(1);
    set_speed(300);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    set_emotes(20,({
      "A hyena barks and snaps viciously at your feet.",
      "A salivating hyena lungs at you.",
      "A hyena leaps at you and knocks you into the rocky, ravine wall.",
      "A hyena welps and retreats back a few feet.",
      "A hyena has circled around behind you.",
      "A hyena lunges!  Its jaws snap at your throat!",
      "A hyena charges you and its teeth tear through your armor and into "+
        "your flesh."
    }),1);    
 }

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
