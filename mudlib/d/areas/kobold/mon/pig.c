/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("hairy pig");
   set("id", ({"pig", "hairy pig"}) );
   set_level(2);
   set("short", "[2]hairy pig");
   set("long",
   "The plump, hairy pig snorts and wallows about in the mud.  It would "
   "probably make tasty bacon.",
   );
   set("race", "pig");
   set_max_hp(75);
   set_hp(75);
   set_body_type("equine");
   set_gender("female");
   set_alignment(0);
/*  
 set_emotes(5,
                ({
                  "The pig snorts loudly.",
                  "The pig wallows in the mud.",
                }), 0);
   set_achats(30,
                ({
                  "The pig oinks in pain!",
                  "The pig foams at the mouth.",
                }) );
*/
}
