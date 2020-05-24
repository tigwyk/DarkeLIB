/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   mixed str;
   ::create();
   set_name("bone sword");
   set("id", ({"bone sword", "sword", "bone crusher"}) );
   set("short", "Bone Sword");
   set("long",
   "This longsword has a finely-crafted and very ornate hilt made entirely "
   "of stark white bone.  Its blade is very long and extremely sharp.  "
   "There seems to be an inscription on the sword's blade."
   );
   set_weight(250);
   set_value(10000);
   set_type("blade");
   set_wc(20, "impaling");
   set_wc(35, "cutting");
   set_ac(7);
   set_property("no add quality", 1);
//   set_property("no decay", 1);
   set_quality(6);
   set("read", "The inscription reads: \"The Bone Crusher of Rufus Tenderfoot\"");
/*   set_property("enchantment", 1);
   str = ({ ({"This sword glows with an unholy light.\n", "detect magic" }) });
   set_property("extra long", str); */
   set_wield("Your bones ache for a brief moment as you wield the sword.");
   set_unwield("Your body shivers as you place the sword back in its sheath.");
set_hit( (: call_other, this_object(), "weapon_hit" :) );
   set_material("metal/mithril");
   set_property("brittle", 10);
   set_decay_rate(1000);
}
 
/*int weapon_hit(object attacker) {
   string target;
   int align;
 
   target = lower_case((string)attacker->query_name());
   if(random(2) == 0) {
      if(interact("skeleton", target)) {
         write("%^BOLD%^%^YELLOW%^Bones crunch as the Bone Sword connects with the skeleton's body!");
         say("%^BOLD%^%^YELLOW%^Bones crunch as the Bone Sword connects with the skeleton's body!");
         return random(15)+15;
      }
      else if((string)attacker->query_race() == "undead" || (string)attacker->query_race() == "lich") {
         write("%^BOLD%^%^YELLOW%^Sparks fly as the Bone Sword connects with the undead monster!");
         say("%^BOLD%^%^YELLOW%^Sparks fly as the Bone Sword connects with the undead monster!");
         return random(15)+5;
      }
      else
         return random(10);
   }
   return 0;
}

int restore_me(string file) {
  ::restore_me(file);
  set_hit( (: call_other, find_object_or_load("/wizards/duridian/catacomb/weapon/boneswrd"), "weapon_hit" :) );
  return 1;
}

  */
