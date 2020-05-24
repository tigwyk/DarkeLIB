/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold shepherd");
   set("id", ({"kobold", "kobold shepherd", "shepherd"}) );
   set_level(2);
   set("short", "kobold shepherd");
   set("long",
   "The happy kobold shepherd looks over his sheep, occasionally tapping "
   "one of them with his staff."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(50);
   set_money("silver", random(25)+50);
   set_body_type("human");
   set_skill("two handed blunt", 30);
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold shepherd looks at you worriedly.",
                  "The kobold shepherd taps a sheep with his staff.",
                  "The kobold shepherd hits a sheep with a good whack to the head!",
                }), 0);
   set_achats(30,
                ({
                  "The kobold shepherd calls on his sheep for help!",
                  "The kobold shepherd searches frantically for an escape.",
                  "The kobold shepherd cowers in fear.",
                }) );
   new(WEAP_PATH+"staff")->move(this_object());
   force_me("wield staff in left hand and right hand");
}
