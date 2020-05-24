/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold woman");
   set("id", ({"kobold", "woman", "kobold woman"}) );
   set_level(2);
   set("short", "kobold woman");
   set("long",
   "The buxom kobold woman has her arms folded and looks disgusted.  She "
   "snorts at you when she realizes that you are looking at her."
   );
   set("race", "kobold");
   set_gender("female");
   set_alignment(50);
   set_money("silver", random(50)+25);
   set_wimpy(10);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_wimpy(20);
   set_emotes(5,
                ({
                  "The kobold woman runs her hands through her dirty hair.",
                  "The kobold woman picks at a wart on her face.",
                  "The kobold woman spits at your feet.",
                  "The kobold woman sneezes and wipes her hand on her clothes.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold woman's body shakes violently!",
                  "The kobold woman's eyes widen in fear.",
                  "The kobold woman screams in pain!",
                }) );
}
