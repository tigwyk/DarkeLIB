// zombie

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("rotting zombie");
   set("id", ({"zombie", "man"}) );
   set_level(14);
   switch(random(3)) {
           case 0: var = "A pale looking man"; break;
           case 1: var = "A skinless walking corpse"; break;
           case 2: var = "A limping zombie"; break;
   }
   this_object()->set("short", var);
   set("long",
   "You see a stinking sack of flesh before you.  His skin sits "
   "loosely on fleshy bones and torn muscles."
   );
   set("race", "undead");
   set_gender("male");
   set_body_type("human");
   set_emotes(5, ({
                   "The zombie mumbles: itchy... tastey...",
                   "The zombie wails and stumbles towards you.",
                   }), 0);
   set("aggressive", 1);
}
