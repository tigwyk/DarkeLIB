/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold man");
   set("id", ({"kobold", "man", "kobold man"}) );
   set_level(2);
   set("short", "[2]kobold man");
   set("long",
   "The male kobold before looks like a sturdy fellow.  He wears faded "
   "and dirty clothing and looks content."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(50);
   set_money("silver", random(50)+50);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold man looks at you and laughs loudly!",
                  "The kobold man snorts loudly.",
                  "The kobold man coughs.",
                  "The kobold man farts and gives you a dirty look.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold man grunts in pain.",
                  "The kobold man grunts loudly.",
                  "The kobold man frantically searches for an escape.",
                }) );
}
