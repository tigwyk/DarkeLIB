/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
   set_name("kobold chieftain");
   set("id", ({"kobold chieftain", "kobold", "chieftain"}) );
   set_level(7+random(4));
   set("short", "kobold chieftain");
   set("long",
   "Before you stands the chieftain of the kobold campgrounds.  He is "
   "heavily armored, and carries a menacing-looking longsword at his "
   "side.  Muscles bulge from beneath his chainmail armor and he stands "
   "taller than any of the kobolds you have come across thus far.  The "
   "mighty kobold chieftain is not someone who messes around.  He is no "
   "doubt well-trained in the art of fighting."
   );
   set("race", "kobold");
   set_gender("male");
   set_combat_chance(50);
   add_spell("fireball", "$A");
   set_spell_level("fireball", 4);
   set_skill("conjuration", 75);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 4);
   set_money("silver", random(150)+350);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold chieftain eyes you warily.",
                  "The kobold chieftain grunts at one of his lackeys.",
                  "The kobold chieftain shifts his position.",
                  "The kobold chieftain admires his longsword.",
                  "The kobold chieftain adjusts his shield.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold chieftain screams a battle cry!",
                  "The kobold chieftain swings his sword wildly.",
                  "The kobold chieftain's eyes widen as he tastes his own blood.",
                  "The kobold chieftain circles around his opponent.",
                  "The kobold chieftain calls for help!"
                }) );
   new(WEAP_PATH+"longswrd")->move(this_object());
   new(ARMOR_PATH+"chainmal")->move(this_object());
   new(ARMOR_PATH+"shield")->move(this_object());
   new(ARMOR_PATH+"helmet")->move(this_object());
   new(ARMOR_PATH+"boots")->move(this_object());
   new(ARMOR_PATH+"cloak")->move(this_object());
   force_me("wield longsword in right hand");
   force_me("wear chainmail");
   force_me("wear shield on left hand");
   force_me("wear helmet");
   force_me("wear boots");
   force_me("wear cloak");
}
 
void catch_tell(string str) {
   string a, b;
   object ob1;
   if(sscanf(str, "%s attacks %s", a, b) == 2) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("Kobold", b)) {
            if (random(2) == 0) 
               force_me("cast *4 fireball at "+a);
            else
               force_me("cast *4 lightning bolt at "+a);
            return;
         }
      }
   }   
}
 
