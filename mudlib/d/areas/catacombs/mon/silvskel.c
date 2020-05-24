/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   object ob;
 
   ::create();
   set_name("silver skeleton");
   set("id", ({"skeleton", "silver skeleton"}) );
   set_level(15);
   set("short", "[15]silver skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with silver.  Its metal frame shines in the faint torchlight.  As "
   "it moves, you hear its metal limbs scrape against each other.  This "
   "creature is obviously the product of very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(400)+400);
   set_body_type("human");
   set_emotes(5, ({
               "The faint light glints off the silver skeleton's bones.",
               "The silver skeleton turns and seems to grin at you.",
               "The silver skeleton steps in front of you.",
                   }), 0);
   set_achats(30, ({
               "Sparks fly as the silver skeleton thrashes about.",
               "The silver skeleton's joints squeak slightly as it fights.",
               "The silver skeleton lunges towards its attacker.",
                    }) );
   ob = new(WEAP_PATH+"bonedggr");
   ob->move(this_object());
   if(random(3)==0)
      ob->set_wc(10, "electricity");
   force_me("wield dagger in right hand");
}
