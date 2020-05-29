//           Maxwell's Underground Mud Library
//                 Guardian of Gold Altar


#include <std.h>
#include "under.h"
inherit MONSTER;

object money;
create() {
    ::create();
   set_name("greveck");
   set_id( ({ "guardian","guard","dwarf","greveck" }) );
   set_short("Greveck the guardian of the silver altar");
   set_level(35);
   set("long", " As you glance at Greveck you sense his great power. You "
   "can see a faint glow around his body as he moves around.\n"
   " His skin has a strange silverish glow to it. You can "
   "see several tattoos on his arms and neck. Some of them seem to "
   "glow with dark color and radiate energy.\n");
   set_gender("male");
   set("race", "dwarf");
   set_body_type("human");
   set_exp(3000000);
   set_alignment(0);
   set_overall_ac(35);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(5,
     ({ "Greveck adjusts his grip on his sword.",
     "Greveck glances at one of his tattoos and murmurs a few words under "
     "his breath.",
     "Greveck glances at you and grins evilly.",
     }),0 );
    set_achats(50,
    ({ "Greveck steps to the side.",
     "Greveck ducks.",
     "Greveck grins evilly.",
      "Greveck laughs at your pitiful attack techniques.",
     }) );
// Skill Code
    add_skill("block",120);
    add_skill("reverse stroke",125);
// Spell Code
    set_combat_chance(90);
    add_spell("meteor storm", "$A");
    add_spell("fireball", "$A");
    add_spell("wrath of god", "$A");
    set_spell_level("meteor storm",2);
    set_spell_level("chaos storm",2);   
    set_spell_level("wrath of god",2);
// Skills For Spells
    add_skill("conjuration",75);
    add_skill("chaos magic",75);
    add_skill("prayer",75);
    add_skill("worship of k'thach",75);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+500));
    money->move(this_object());
//Equipment Code
    new(UNWEAP+"psword")->move(this_object());
    force_me("wield sword in right hand and left hand");
    new(UNARM+"lashield")->move(this_object());
    force_me("wear shield on left arm");
}
void die(object who){
string here;  
  here = file_name( environment(this_object()));
  if(here == (UNDER+"dm38")){
    tell_room(here,"\nThe Silver Altar unlocks and opens!");
    tell_room(here,"Greveck's Soul flies out of his corpse and flows "
             "into the open Alter!\n");
    tell_room(here,"Venkart's voice echoes through the chamber, 'Very "
  "impressive for a puny weakling. The Silver Blade is yours..and your next "
  "challenge is waiting for you in the chamber north of the center of the "
  "temple!\n\n");
   find_object_or_load(UNDER+"dm37")->set_property("x",2);
   if( present("altar",find_object(here)) ){
      present("altar",find_object(here))->set_lock("unlocked");
      present("altar",find_object(here))->toggle_closed();
      new(UNQST+"sblade")
         ->move((present("altar",find_object(here))));
   }
  }
  ::die(who);
  return;
}

