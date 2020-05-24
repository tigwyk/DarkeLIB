/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   object ob;
   ::create();
   set_name("gold skeleton");
   set("id", ({"skeleton", "gold skeleton"}) );
   set_level(11);
   set("short", "gold skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with gold.  Its metal frame shines in the faint torchlight.  The "
   "monster has large golden fangs that look rather sharp!"
   );
   set("race", "undead");
   set_gender("neuter");
   set_skill("back stab", 50);
   set_money("silver", random(500)+500);
   set_body_type("human");
   set_emotes(5, ({
                   "The gold skeleton turns its head and stares at you.",
                   "The gold skeleton's jaw slowly opens and closes.",
                   }), 0);
   set_achats(30, ({
               "Sparks fly as the gold skeleton thrashes about.",
               "The gold skeleton lunges toward its attacker.",
               "The gold skeleton thrashes about very violently.",
                    }) );
   ob = new(WEAP_PATH+"bonedggr");
   ob->move(this_object());
   ob->add_poisoning(50);
   force_me("wield dagger in right hand");
}
 
void catch_tell(string str) {
   string a;
   object ob1;
   if(sscanf(str, "%s enters.", a) == 1) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) 
         if (random(10) == 0)
            force_me("use back stab at " + a); 
   }
}
 
