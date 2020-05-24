/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold farmer");
   set("id", ({"kobold farmer", "kobold", "farmer"}) );
   set_level(2);
   set("short", "kobold farmer");
   set("long",
   "The peaceful kobold farmer before you is hard at work, tilling the "
   "soil with his trusty hoe.  He looks tired, but happy."
   );
   set("race", "kobold");
   set_gender("male");
   set_skill("two handed blunt", 20);
   set_alignment(50);
   set_money("silver", random(50)+50);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold farmer wipes the sweat from his brow.",
                  "The kobold farmer pauses to take a rest.",
                  "The kobold farmer works the soil with his hoe.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold farmer screams in pain!",
                  "The kobold farmer swings his hoe wildly in the air.",
                  "The kobold searches frantically for an exit.",
                }) );
   new(WEAP_PATH+"hoe")->move(this_object());
   force_me("wield hoe in right hand and left hand");
}
