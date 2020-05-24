/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("giant skeleton");
   set("id", ({"giant skeleton", "skeleton"}) );
   set_level(5+random(5)+random(5));
   set("short", "giant skeleton");
   set("long",
   "A twelve-foot-tall skeleton stands before you, and it looks nasty.  "
   "This undead creature is one of the evil lich's soldiers of death."
   );
   set("race", "undead");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("human");
   set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
   set_moving(1);
   set_speed(120);
   new("/d/damned/virtual/broad-sword_5.weapon")->move(this_object());
   force_me("wield broad sword in right hand");
}
 
int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
 
int chk_my_mob() { return 1; }
