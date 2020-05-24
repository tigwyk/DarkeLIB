/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold girl");
   set("id", ({"kobold girl", "kobold", "girl"}) );
   set_level(1);
   set("short", "kobold girl");
   set("long",
   "The snotty kobold girl has braided hair, which is filled with dirt, "
   "and wears a filthy green dress.  She twirls a broken stick in her "
   "right hand."
   );
   set("race", "kobold");
   set_gender("female");
   set_alignment(50);
   set_wimpy(10);
   set_money("silver", random(30)+40);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold girl points at you and laughs.",
                  "The kobold girl gnaws on the broken stick.",
                  "The kobold girl kicks dirt on you.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold girl cries for her mother!",
                  "The kobold girl flails her arms helplessly.",
                  "The kobold girl cries for her father!",
                }) );
   new(WEAP_PATH+"stick")->move(this_object());
   force_me("wield stick in right hand");
}
