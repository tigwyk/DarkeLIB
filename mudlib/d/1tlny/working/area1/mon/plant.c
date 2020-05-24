// plant

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("a strange plant");
   set("id", ({"plant"}) );
   set_level(16);
   set("short", "A strange plant is moving here");
   set("long",
   "This is no ordinary plant.  You see long tentacle like stems "
   "slithering across the grouund.  At the base of them you see a "
   "large bud that has many sharp thorns all over it."
   );
   set("race", "plant");
   set_gender("neuter");
   set_body_type("plant");
}
