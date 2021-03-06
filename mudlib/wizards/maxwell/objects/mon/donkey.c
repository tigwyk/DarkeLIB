//           Maxwell's Underground Mud Library
//                  Dwarf Miner Cart Pusher


#include "/adm/include/std.h"
inherit MONSTER;

create() {
    ::create();
   set_name("Donkey");
   set_id( ({ "Donkey","donkey" }) );
   set_short("A strong brown Donkey.");
   set_level(20);
   set("long", "The Donkey is covered in dust and dirt.");
   set_gender("male");
   set("race", "equine");
   set_exp(400000);
    set_property("enhance criticals",-2);
   set_overall_ac(75);
   set_alignment(0);
   set_body_type("quadruped");
   set("aggressive",0);
   set("gang bang", 0);
//   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(6,
     ({ "The Donkey paws at the ground.",
     "The Donkey's tail swishes to the side.",
     "The Donkey shakes his head.",
     "The Donkey snorts.",}),0 );
   set_achats(50,
    ({ "The Donkey snorts.",
     "The Donkey kicks up some dirt.",
     "The Donkey lowers his head.",}) );
 
}

