/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold fighter");
   set("id", ({"kobold", "fighter", "kobold fighter"}) );
   set_level(4);
   set("short", "kobold fighter");
   set("long",
   "A short, gruff kobold fighter stands before you.  He stares back at "
   "you, snorts, and scratches himself.  He is clad in leather armor and "
   "sports a kobold shortsword."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(-50);
   set_money("silver", random(100)+100);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5, ({
                   "The kobold fighter burps rudely.",
                   "The kobold fighter snorts loudly and wipes his nose on his sleeve.",
                   "The kobold fighter scratches himself.",
                   "The kobold fighter coughs loudly.",
                   }), 0);
   set_achats(30, ({
                   "The kobold fighter squeals in pain.",
                   "The kobold fighter looks around frantically.",
                   "The kobold fighter's eyes widen in fear.",
                   }) );
   new(WEAP_PATH+"shrtswrd")->move(this_object());
   new(ARMOR_PATH+"shield")->move(this_object());
   new(ARMOR_PATH+"lthrarm")->move(this_object());
   new(ARMOR_PATH+"boots")->move(this_object());
   force_me("wield shortsword in right hand");
   force_me("wear shield on left hand");
   force_me("wear leather armor");
   force_me("wear boots");
}
