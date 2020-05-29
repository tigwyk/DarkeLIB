//           Maxwell's Underground Mud Library
//                 Guardian of Gold Altar


#include <std.h>
#include "under.h"
inherit MONSTER;

object money;
create() {
    ::create();
   set_name("dravack");
   set_id( ({ "guardian","guard","dwarf","dravack" }) );
   set_short("Dravack the guardian of the gold altar");
   set_level(35);
   set("long", " Dravack stands before you. His presence radiates power "
   "and spreads fear into your very soul. As you look into his burning "
   "eyes you realize that you could never beat him alone.\n "
   "His thick golden body armour wraps around him, covered with paintings "
   "and strange writing. On his chest plate is an image of a glowing "
   "golden axe blade.\n");
   set_gender("male");
   set("race", "dwarf");
   set_alignment(0);
   set_exp(3000000);
   set_body_type("human");
   set_overall_ac(35);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(5,({ "Dravack adjusts his grip on the scythe.",
                    "Dravack's eyes seem to glow dark red.",
                    "Dravack adjusts his stance in front of the altar.",
                    "Dravack spins his scythe in a large arc.",
    }),0 );
    set_achats(50,({ "Dravack adjusts his grip on the scythe.",
                     "Dravack steps to the side.",
                     "Dravack grins evily.",
                     "Dravack laughs at your pitiful attack techniques.",
    }) );
// Spell Code
    set_combat_chance(90);
    add_spell("blizzard", "$A");
    add_spell("fireball", "$A");
    add_spell("wrath of god", "$A");
    set_spell_level("blizzard", 3);
    set_spell_level("chaos storm", 3);   
    set_spell_level("wrath of god", 3);
// Skills For Spells
    add_skill("conjuration",75);
    add_skill("chaos magic",75);
    add_skill("prayer",75);
    add_skill("worship of k'thach",75);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+500));
    money->move(this_object());
//Skill Code
   add_skill("two handed polearm",150);
//Equipment Code
  new(UNWEAP+"scythe")->move(this_object());
  force_me("wield scythe in right hand and left hand");
  new(UNARM+"rashield")->move(this_object());
  force_me("wear shield on right arm");
}
void die(object who){
string here;  
  here = file_name( environment(this_object()));
  if(here == (UNDER+"dm40")){
    tell_room(here,"\nThe Gold Altar unlocks and opens!");
    tell_room(here,"Dravack's Soul flies out of his corpse and flows "
             "into the open Alter!\n");
    tell_room(here,"Venkart's voice echoes through the chamber, 'I'm "
  "sure the Duke would be impressed by your bravery and skill. "
  "The Gold Blade is yours..and your final "
  "challenge is awaiting your arrival in the chamber southwest of the "
  "center of the temple!\n\n");
   find_object_or_load(UNDER+"dm36")->set_property("x",2);
   if( present("altar",find_object(here)) ){
      present("altar",find_object(here))->set_lock("unlocked");
      present("altar",find_object(here))->toggle_closed();
      new(UNQST+"gblade")
         ->move((present("altar",find_object(here))));
   }
  }
  ::die(who);
  return;
}

