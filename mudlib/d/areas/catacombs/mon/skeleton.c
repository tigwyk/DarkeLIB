/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("skeleton");
   set("id", ({"skeleton"}) );
   set_level(14);
   set("short", "[14]skeleton");
   set("long",
   "A six-foot tall skeleton stands before you.  The bony monster looks "
   "rather frail, and some of its bones are cracked in places."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("silver", random(100)+30);
   set_skill("axe", 40);
   set_body_type("human");
   set_emotes(5, ({
                   "The skeleton's teeth chatter.",
                   "The skeleton's bones rattle as it walks about.",
                   }), 0);
   set_achats(30, ({
                   "The skeleton makes a feeble swipe at its attacker.",
                   "The skeleton's head is thrown back.",
                   }) );
   switch(random(5)){
      case 0: new("/d/damned/virtual/dagger_2.weapon")->move(this_object());
              force_me("wield dagger in right hand");
              break;
      case 1: new("/d/damned/virtual/short-sword_2.weapon")->move(this_object());
              force_me("wield short sword in right hand");
              break;
      case 2: new("/d/damned/virtual/long-sword_2.weapon")->move(this_object());
              force_me("wield longsword in right hand");
              break;
      case 3:
      case 4: new(WEAP_PATH+"cabis")->move(this_object());
              force_me("wield cabis in right hand");
              break;
   }
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
   if(random(3) == 0)
      new("/std/obj/torch")->move(this_object());
}
 
int chk_my_mob() { return 1; }
