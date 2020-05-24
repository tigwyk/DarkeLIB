/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();

   set_name("kobold boy");
   set("id", ({"kobold boy", "kobold", "boy"}) );
   set_level(1);
   set("short", "[1]kobold boy");
   set("long",
   "The snotty kobold boy is covered in mud.  He sticks his tongue at you "
   "and flashes his dagger in your face.  What a brat!"
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(50);
   set_money("silver", random(50)+25);
   set_body_type("human");
   set_skill("knife", 15);
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_wimpy(10);
/*
   set_emotes(5,
                ({
                  "The kobold boy spits at you.",
                  "The kobold boy drools over his dagger.",
                  "The kobold boy picks up a handful of mud and hurls it at you.",
                  "The kobold boy picks his nose.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold boy flails his arms wildly.",
                  "The kobold boy cries in pain!",
                  "The kobold boy spits at you.",
                }) );
*/
   new(WEAP_PATH+"dagger")->move(this_object());
   force_me("wield dagger in right hand");
}
