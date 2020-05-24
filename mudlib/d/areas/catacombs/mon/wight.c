/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("ugly wight");
   set("id", ({"wight", "ugly wight"}) );
   set_level(11);
   set("short", "[11]ugly wight");
   set("long",
   "The horrid creature before stinks of rotting flesh.  The wight is "
   "clothed in filthy rags that hang off its decomposing body.  It somehow "
   "manages to laugh at you, revealing its yellowed and decayed teeth.  "
   "Around its neck is a small key tied to a string."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(100)+200);
   set_body_type("human");
   set_languages( ({"common"}) );
   set_emotes(5, ({
                   "The ugly wight points at you and cackles.",
                   "The ugly wight grins widely, displaying its yellow teeth.",
                   "The ugly wight snorts loudly.",
                   "The ugly wight flashes its key at you.",
                   }), 0);
   set_achats(30, ({
                    "The ugly wight cackles loudly as it fights.",
                    "The ugly wight swings its swords wildly.",
                    "The ugly wight looks nervous.",
                    }) );
   new(MISC_PATH+"wightkey")->move(this_object());
   new(WEAP_PATH+"cutlass")->move(this_object());
   force_me("wield cutlass in right hand");
   new("/d/damned/virtual/breast-plate.armour")->move(this_object());
   force_me("wear plate");
}
