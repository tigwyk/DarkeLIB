/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("skeleton warrior");
   set("id", ({"warrior", "skeleton", "skeleton warrior"}) );
   set_level(16);
   set("short", "[16]skeleton warrior");
   set("long",
   "A seven-foot tall human skeleton stands before you.  It has red "
   "glowing eyes and razor-sharp claws.  It wears ripped and tattered "
   "military clothing, suggesting that it was a soldier as a mortal.  "
   "The skeleton warrior seems to grin at you with its stark white teeth."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(300)+200);
   set_body_type("human");
   set_emotes(5, ({
                    "The skeleton warrior grins at you.",
                    "The skeleton warrior glances at you.",
                    "The skeleton warrior stomps its bony foot and salutes.",
                    }), 0);
   set_achats(30, ({
                   "The skeleton warrior makes a mad swing at its attacker.",
                   "The skeleton warrior swipes at empty space.",
                   "The skeleton warrior's eyes glow more brightly.",
                   }) );
   new(WEAP_PATH+"cutlass")->move(this_object());
   force_me("wield cutlass in right hand");
   switch(random(2)) {
      case 0: new("/d/damned/virtual/chain-mail.armour")->move(this_object());
              force_me("wear chain mail");
              break;
      case 1: new("/d/damned/virtual/studded-leather-jacket.armour")->move(this_object());
              force_me("wear jacket");
              break;
   }
   new("/d/damned/virtual/chain-coif.armour")->move(this_object());
   force_me("wear coif");
   new("/d/damned/virtual/cloak.armour")->move(this_object());
   force_me("wear cloak");
}
