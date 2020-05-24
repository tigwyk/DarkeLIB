/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("fluffy sheep");
   set("id", ({"sheep", "fluffy sheep"}) );
   set_level(1);
   set("short", "fluffy sheep");
   set("long",
   "The fluffy sheep jumps around and stops occasionally to look at you.  "
   "It looks too cute to kill!"
   );
   set("race", "sheep");
   set_max_hp(75);
   set_hp(75);
   set_body_type("equine");
   set_gender("female");
   set_alignment(0);
   set_emotes(5,
                ({
                  "A sheep jumps around happily.",
                  "A sheep munches on something.",
                  "A sheep tries to eat your pants!",
                }), 0);
   set_achats(30,
                ({
                  "The sheep screeches in pain!",
                  "The sheep foams at the mouth.",
                }) );
}
