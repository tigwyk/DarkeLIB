/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("large cow");
   set("id", ({"cow", "large cow"}) );
   set_level(2);
   set("short", "[2]large cow");
   set("long",
   "The large white cow munches on grass and looks at peace in its pen.  "
   "Its horns are short, but look quite sharp.",
   );
   set_max_hp(150);
   set_hp(150);
   set("race", "cow");
   set_body_type("equine");
   set_gender("female");
   set_alignment(0);
   set_emotes(5,
                ({
                  "The cow moos loudly.",
                  "The cow breathes heavily.",
                }), 0);
   set_achats(30,
                ({
                  "The cow screeches in pain!",
                  "The cow foams at the mouth.",
                }) );
}

