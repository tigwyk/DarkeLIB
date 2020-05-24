// raven

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("giant raven");
   set("id", ({"raven", "bird"}) );
   set_level(6);
   set("short", "An abnormaly large bird");
   set("long",
   "You see a gigantic raven perched on the balcony before you."
   );
   set("race", "bird");
   set_gender("neuter");
   set_body_type("bird");
   set_emotes(5, ({
                   "A giant raven squaks and peers at you.",
                   "A giant raven flaps it's wings and settles.",
                   }), 0);
}
