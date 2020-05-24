// giant rat

#include "mansion.h"
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("giant rat");
   set("id", ({"rat"}) );
   set_level(10);
   set("short", "[10]giant rat");
   set("long",
   "You see a very large rodent, with it's wee beedy eyes!"
   );
   set("race", "rat");
   set_gender("neuter");
   set_body_type("quadruped");
   set("aggressive", 0);
}

