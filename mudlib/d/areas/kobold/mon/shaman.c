/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold shaman");
   set("id", ({"kobold shaman", "kobold", "shaman"}) );
   set_level(3);
   set("short", "[3]kobold shaman");
   set("long",
   "The kobold shaman is dressed in long, flowing robes and carries a "
   "menacing-looking mace at his hip.  He looks peaceful."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(75);
   set_money("silver", random(150)+100);
   set_body_type("human");
   set_skill("conjuration", 80);
   set_combat_chance(50);
   add_spell("fireball", "$A");
   set_spell_level("fireball", 4);
   set_wielding_limbs( ({"right hand", "left hand"}) );
/*  
 set_emotes(5,
                ({
                  "The kobold shaman mutters something incomprehensible.",
                  "The kobold shaman smiles at you happily.",
                  "The kobold shaman adjusts his robes and checks his mace.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold shaman swings his mace wildly.",
                  "The kobold shaman's eyes widen in fear.",
                  "The kobold shaman gets tangled in his robes.",
                }) );
*/
   new(WEAP_PATH+"mace")->move(this_object());
   new(ARMOR_PATH+"robe")->move(this_object());
   force_me("wield mace in right hand");
   force_me("wear robe");
}
