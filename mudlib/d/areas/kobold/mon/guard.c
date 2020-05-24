/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
int zlevel;
   ::create();
   set_name("kobold guard");
   set("id", ({"kobold guard", "guard", "kobold"}) );
   set_level(5+random(3));
if (zlevel == 5) set_short("[5]kobold guard");
else
if (zlevel == 6) set_short("[6]kobold guard");
else 
if (zlevel == 7) set_short("[7]kobold guard");
else
if (zlevel == 8) set_short("[8]kobold guard");
else set("short", "[0]kobold guard");
	set_level(zlevel);
   set("long",
   "This is one of the formidable kobold guards of the campgrounds.  "
   "Heavily armored and afraid of nothing, the guard would give his life "
   "for his leader, the kobold chieftain.  He looks very strong and very "
   "dangerous."
   );
   set("race", "kobold");
   set_gender("male");
   set_alignment(-150);
   set_money("silver", random(50)+150);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The kobold guard eyes you warily.",
                  "The kobold guard shifts his position.",
                  "The kobold guard checks his mace.",
                  "The kobold guard adjusts his shield.",
                  "The kobold guard stands at attention.",
                }), 0);
   set_achats(30,
                ({
                  "The kobold guard screams a battle cry!",
                  "The kobold guard swings his mace wildly.",
                  "The kobold guard grits his teeth in pain.",
                  "The kobold guard foams at the mouth.",
                }) );
   new(WEAP_PATH+"mace")->move(this_object());
   new(ARMOR_PATH+"chainmal")->move(this_object());
   new(ARMOR_PATH+"shield")->move(this_object());
   new(ARMOR_PATH+"helmet")->move(this_object());
   new(ARMOR_PATH+"boots")->move(this_object());
   force_me("wield mace in right hand");
   force_me("wear chainmail");
   force_me("wear shield on left hand");
   force_me("wear helmet");
   force_me("wear boots");
}
 
void catch_tell(string str) {
   string a, b;
   object ob1;
   if(sscanf(str, "%s attacks %s", a, b) == 2) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("Kobold", b)) {
            ob1->add_follower(this_object());
            force_me("kill "+a);
            return;
         }
      }
   }   
}
 
