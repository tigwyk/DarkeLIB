/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   object ob;
 
   ::create();
   set_name("mithril skeleton");
   set("id", ({"skeleton", "mithril skeleton"}) );
   set_level(19);
   set("short", "[19]mithril skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with mithril.  Its metal frame shines in the faint torchlight.  As "
   "it moves, you hear its metal limbs scrape against each other.  This "
   "creature is obviously the product of very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(600)+200);
   set_body_type("human");
   set_emotes(5, ({
                   "The skeleton's mithril bones shine in the torchlight.",
                   "The mithril skeleton turns toward you and watches you carefully.",
                   "The skeleton's bones clang loudly against the stone as it walks about.",
                   }), 0);
   set_achats(30, ({
                    "The skeleton swings violently at empty space.",
                    "The skeleton's bones flash brilliantly as the monster fights.",
                  }) );
   ob = new(WEAP_PATH+"cutlass");
   ob->move(this_object());
   ob->set_wc(5, "electricity");
   ob->add_poisoning(random(100));
   force_me("wield cutlass in right hand");
}
 
