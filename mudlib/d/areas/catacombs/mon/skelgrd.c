/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();
   set_name("skeleton guard");
   set("id", ({"skeleton", "skeleton guard", "guard"}) );
   set_level(21);
   set("short", "[21]skeleton guard");
   set("long",
   "The skeleton guard before you boasts a large shield and a nasty-"
   "looking cutlass.  A red glow emanates from its eye sockets.  This "
   "undead creature is obviously the product of some very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("gold", 100+random(25));
   set_body_type("human");
   set_emotes(5, ({
                   "The skeleton guard watches you carefully.",
                   "The skeleton guard adjusts its position slightly.",
                   "The skeleton guard turns and grins at you.",
                   }), 0);
   set_achats(30, ({
                    "The skeleton guard swings violently at empty space.",
                    "The skeleton guard's eyes glow brighter.",
                  }) );
   set_skill("conjuration", 75);
   set_skill("necromancy", 75);
   set_skill("concentrate", 70);
   set_languages( ({"common"}) );
   set_combat_chance(75);
   add_spell("fireball", "$A");
   set_spell_level("fireball", 6);
   add_spell("ice dagger", "$A");
   set_spell_level("ice dagger", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   new(WEAP_PATH+"cutlass")->move(this_object());
   force_me("wield cutlass in right hand");
   new(ARMOR_PATH+"boneshld")->move(this_object());
   force_me("wear shield on left hand");
   new("/d/damned/virtual/chain-mail.armour")->move(this_object());
   force_me("wear chain mail");
   new("/d/damned/virtual/chain-coif.armour")->move(this_object());
   force_me("wear coif");
   new("/d/damned/virtual/cloak.armour")->move(this_object());
   force_me("wear cloak");
   force_me("use concentrate");
}
 
void catch_tell(string str) {
   string a, b;
   object ob1;
   if(sscanf(str, "%s attacks %s", a, b) == 2) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("Lich", b)) {
            force_me("kill "+a);
            return;
         }
      }
   }   
}
