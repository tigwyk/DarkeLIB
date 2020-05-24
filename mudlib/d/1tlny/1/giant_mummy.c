/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("giant mummy");
   set("id", ({"giant mummy", "mummy"}) );
   set_level(5+random(5)+random(5));
   set("short", "giant mummy");
   set("long",
   "A giant 15-foot-tall mummy stands before you.  The wrappings on its "
   "body are coming loose, revealing rotted flesh underneath.",
   );
   set("race", "undead");
   set_overall_ac(20);
   set_skill("necromancy", 85);
   set_skill("concentrate", 85);
   set_gender("neuter");
   set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
   set_moving(1);
   set_speed(120);
   set_body_type("human");
   set_combat_chance(25);
   add_spell("drain life", "$A");
   set_spell_level("drain life", 4);
   add_spell("cold blast", "$A");
   set_spell_level("cold blast", 4);
   add_spell("decay", "$A");
   set_spell_level("decay", 4);
   add_spell("curse", "$A");
   set_spell_level("curse", 4);
   force_me("use concentrate");
}
 
int not_other_monsters(object who) {
   if(who->is_player()) return 1;
   else return 0;
}
 
