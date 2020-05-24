/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold hunter");
   set("id", ({"kobold hunter", "kobold", "hunter"}) );
   set_level(3);
   set("short", "[3]kobold hunter");
   set("long",
   "The kobold before you carries a spear and is wearing some studded "
   "leather armor.  By the looks of him, you guess that he is a hunter "
   "of some kind."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(-50);
   set_money("silver", random(75)+50);
   set_body_type("human");
   set_skill("two handed polearm", 30);
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold hunter admires his spear.",
                  "The kobold hunter coughs nervously.",
                  "The kobold hunter looks off into the distance.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold hunter makes a wild stab with his spear.",
                  "The kobold hunter searches frantically for an escape.",
                  "The kobold hunter grits his teeth in pain.",
                }) );
   new(WEAP_PATH+"spear")->move(this_object());
   new(ARMOR_PATH+"lthrarm")->move(this_object());
   force_me("wear leather armor");
   force_me("wield spear in left hand and right hand");
}
