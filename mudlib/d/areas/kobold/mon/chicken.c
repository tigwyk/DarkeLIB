/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("chicken");
   set("id", ({"chicken"}) );
   set_level(2);
   set("short", "[2]chicken");
   set("long",
   "The chicken pecks at the ground, content with its boring existence.  "
   "It looks like an easy kill.",
   );
   set("race", "chicken");
   set_max_hp(75);
   set_hp(75);
   set_body_type("fowl");
   set_gender("female");
   set_alignment(0);
   set_emotes(5,
                ({
                  "The chicken pecks at the ground.",
                  "The chicken clucks.",
                }), 0);
   set_achats(30,
                ({
                  "The chicken flaps its wings wildly.",
                  "The chicken clucks uncontrollably.",
                }) );
}
