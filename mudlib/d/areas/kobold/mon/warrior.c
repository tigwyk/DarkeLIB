/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold warrior");
   set("id", ({"kobold warrior", "kobold", "warrior"}) );
   set_level(4);
   set("short", "[4]kobold warrior");
   set("long",
   "The strong kobold warrior standing before you is wearing sturdy-"
   "looking chainmail, a small helmet, and an iron shield.  At his "
   "right hip he carries a mean-looking shortsword.  He would definitely "
   "be a worthy opponent."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(-100);
   set_money("silver", random(100)+100);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
/*  
 set_emotes(5,
                ({
                  "The kobold warrior looks at you and grunts.",
                  "The kobold warrior adjusts his helmet.",
 
                 "The kobold warrior checks his sword and finds it's still there.",
                  "The kobold warrior snorts loudly.",
 
               }), 0);
 
  set_achats(30,
 
               ({
                  "The kobold warrior screams a battle cry!",
                  "The kobold warrior swings his sword wildly.",
                  "The kobold warrior grins at you with yellow teeth.",
                }) );
*/
   new(WEAP_PATH+"shrtswrd")->move(this_object());
   new(ARMOR_PATH+"helmet")->move(this_object());
   new(ARMOR_PATH+"shield")->move(this_object());
   new(ARMOR_PATH+"chainmal")->move(this_object());
   force_me("wield sword in right hand");
   force_me("wear helmet");
   force_me("wear shield on left hand");
   force_me("wear chainmail");
}
