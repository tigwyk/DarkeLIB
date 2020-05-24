//  Wizard:   Khojem
//  Monster:  sand tiger
//  File:     sand_tiger.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("tiger");
    set_id( ({ "sand tiger","tiger" }) );
     set("race", "tiger");
    set_short("[6]stalking sand tiger");
    set_long("The sand tiger's fur is the color of the surrounding sand "+
      "allowing it to close distance with you quickly without being noticed.  "+
      "Its claws are sharp and has long canine teeth to tear and ripe flesh.\n"
    );
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    set_body_type("quadruped");
    set_gender("male");
    set_level(6);
    set_stats("intelligence", 20);
    set_property("melee damage", ([ "cutting" : 25]));
    set_speed(240);
    set_moving(1);
    set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
    set_emotes(10,({
      "The tiger snarls and snaps viciously at your feet.",
      "The salivating tiger lungs at you.",
      "The sand tiger leaps at you and knocks you onto the sand.",
      "The sand tiger retreats and circles you.",
      "The tiger charges you and its teeth tear into your flesh!",
      "The sand tiger yawns and displays its HUGE teeth!"
    }),1);    
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
