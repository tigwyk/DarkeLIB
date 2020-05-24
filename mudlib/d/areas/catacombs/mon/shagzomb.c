/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("shaggy zombie");
   set("id", ({"zombie", "hairy zombie", "shaggy zombie"}) );
   set_level(12);
   set("short", "[12]shaggy zombie");
   set("long",
   "This zombie, like most, is wearing tattered, filthy clothing and smells "
   "of rotting flesh.  This particular one has long hair that sticks out in "
   "every direction, giving it a somewhat comical appearance."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(200)+100);
   set_body_type("human");
   set_emotes(5, ({
                   "The zombie looks at you with sunken eyes.",
                   "The zombie groans at you.",
                   "A small piece of flesh falls off the zombie.",
                   "The zombie swings its sword in the air.",
                   }), 0);
   set_achats(30, ({
                    "The shaggy zombie swings its sword slowly in the air.",
                    "The shaggy zombie groans loudly.",
                    "The shaggy zombie moans loudly.",
                    "The shaggy zombie grunts in pain.",
                    }) );
   new(WEAP_PATH+"shrtswrd")->move(this_object());
   force_me("wield shortsword in right hand");
   switch(random(2)) {
      case 0: new("/d/damned/virtual/chain-coif.armour")->move(this_object());
              force_me("wear coif");
              break;
      case 1: new("/d/damned/virtual/cloak.armour")->move(this_object());
              force_me("wear cloak");
              break;
   }
   switch(random(2)) {
      case 0: new("/d/damned/virtual/leather-jacket.armour")->move(this_object());
              force_me("wear jacket");
              break;
      case 1: new("/d/damned/virtual/studded-leather-jacket.armour")->move(this_object());
              force_me("wear jacket");
              break;
   }
}
 
int chk_my_mob() { return 1; }
