/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("zombie");
   set("id", ({"zombie", "ugly zombie"}) );
   set_level(11);
   set("short", "[11]ugly zombie");
   set("long",        
   "The zombie stares back at you with sunken eyes.  You smell rotting "
   "flesh, and you realize that the smell is coming from the zombie "
   "standing before you.  The undead creature is wearing tattered, dirty "
   "clothing that hangs loosely on its body."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(150)+75);
   set_body_type("human");
   set_emotes(5, ({
                    "The zombie moans softly.",
                    "The zombie reaches a maggot-infested hand towards you.",
                    "A piece of the zombie's tattered clothing falls off.",
                  }), 0);
   set_achats(30, ({
                    "The zombie searches frantically for an escape.",
                    "The zombie grunts in pain.",
                    "The zombie's head is thrown back.",
                   }) );
   switch(random(2)) {
      case 0: new("/d/damned/virtual/leather-jacket.armour")->move(this_object());
              force_me("wear jacket");
              break;
      case 1: new("/d/damned/virtual/studded-leather-jacket.armour")->move(this_object());
              force_me("wear jacket");
              break;
   }
   switch(random(2)) {
      case 0: new("/d/damned/virtual/chain-coif.armour")->move(this_object());
              force_me("wear coif");
              break;
      case 1: new(WEAP_PATH+"typh")->move(this_object());
              force_me("wield typh in right hand");
              break;
   }
}
