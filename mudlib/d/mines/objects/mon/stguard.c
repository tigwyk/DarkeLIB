//           Maxwell's Underground Mud Library
//                 Guardian of Steel Altar


#include <std.h>
#include "under.h"
inherit MONSTER;

object money;
create() {
    ::create();
   set_name("frenish");
   set_id( ({ "guardian","guard","dwarf","frenish" }) );
   set_short("Frenish the guardian of the Steel Altar");
   set_level(35);
   set("long", " Frenish stands before you in all her glory. Her dark "
    "flowing hair crackles with magical energy as she returns your gaze. "
   "In her eyes you see her internal strength and pureness, just like the "
   "Steel Altar she guards.\n");
   set_gender("female");
   set("race", "dwarf");
   set_exp(3000000);
   set_alignment(0);
   set_overall_ac(35);
   set_body_type("human");
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(15,({ "Frenish glances around the room.",
                "The floor seems to vibrate as Frenish adjusts her stance.",
                "Frenish flexs her arm, testing her strength.",
                "Frenish grins evilly.",
    }),0 );
    set_achats(50,({ "Frenish adjusts her hands.",
                     "Frenish steps to the side.",
                     "Frenish grins evilly.",
                     "Frenish laughs at your pitiful attack techniques.",
    }) );
// Spell Code
    set_combat_chance(90);
    add_spell("blizzard", "$A");
    add_spell("fireball", "$A");
    add_spell("wrath of god", "$A");
    set_spell_level("blizzard", 6);
    set_spell_level("chaos storm", 6);   
    set_spell_level("wrath of god", 6);
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
   add_skill("two handed blunt",150);
//Equipment Code
  new(UNWEAP+"fhamer")->move(this_object());
  force_me("wield hammer in right hand and left hand");
  new(UNARM+"rashield")->move(this_object());
  force_me("wear shield on right arm");
}
void die(object who){
string here;  
  here = file_name( environment(this_object()));
  if(here == (UNDER+"dm39")){
    tell_room(here,"\nThe Steel Altar unlocks and opens!");
    tell_room(here,"Frenish's Soul flies out of her corpse and flows "
             "into the open Alter!\n");
    tell_room(here,"Venkart's voice echoes through the chamber, 'So "
  "the time has come I see. The worthy adventurer is successful in "
  "defeating the Duke's Greatest Warriors! I will prepare the Center of "
  "the Temple for the Final Ceremony!\n\n");
   find_object_or_load(UNDER+"dm34")->set_property("x",2);
   if( present("altar",find_object(here)) ){
      present("altar",find_object(here))->set_lock("unlocked");
      present("altar",find_object(here))->toggle_closed();
      new(UNQST+"shaft")
         ->move((present("altar",find_object(here))));
   }
  }
  ::die(who);
  return;
}

