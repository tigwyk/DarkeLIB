// unicorn

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("a unicorn");
   set("id", ({"unicorn"}) );
   set_level(16);
   set("short", "An animated stuffed unicorn");
   set("long",
   "You see a large stuffed unicorn that seems to have broken "+
   "free from it's display somehow.  It doesn't look very happy "+
   "about being brought back to life."
   );
   set("race", "unicorn");
   set_gender("male");
   set_body_type("quadruped");
   set("aggressive", 1);
}

