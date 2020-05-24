
#include "../ruins.h"
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("demon rat");
   set("id", ({"demon", "rat", "demon rat"}) );
set_level(7);
   set("short", "[7]demon rat");
   set("long", "A seven-foot long rat lies before you. It has red glowing
eyes and razor-sharp claws. The demon rat seems to grin at you with its
blood stained teeth.");
   set("race", "demon");
set ("aggressice", 2);
   set_gender("neuter");
   set_money("silver", random(200)+100);
set_body_type("rat");
   set_emotes(5, ({
                    "The demon rat grins at you.",
                    "The demon rat glances at you.",          
                    }), 0);
   set_achats(30, ({
                   "The demon rat whips his tail at its attacker.",
                   "The demon rat jumps at empty space.",
                   "The demon rat's eyes glow more brightly.",
                   }) );
   new("/d/damned/virtual/war-hammer_2.weapon")->move(this_object());
force_me("wield hammer in right hand and left hand");
   switch(random(2)) {
      case 0:
new("/d/damned/virtual/chain-vest.armour")->move(this_object());
force_me("wear chain vest");
              break;
      case 1:
new("/d/damned/virtual/studded-leather-jacket.armour")->move(this_object())
;
              force_me("wear jacket");
              break;
   }
   new("/d/damned/virtual/cloak.armour")->move(this_object());
   force_me("wear cloak");
}


