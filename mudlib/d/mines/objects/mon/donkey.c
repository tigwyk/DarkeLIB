//           Maxwell's Underground Mud Library
//                  Dwarf Miner Cart Pusher


#include <std.h>
inherit MONSTER;

create() {
    ::create();
   set_name("Donkey");
   set_id( ({ "Donkey","donkey" }) );
   set_short("[25]A strong brown Donkey.");
   set_level(25);
   set("long", "The Donkey is covered in dust and dirt.");
   set_gender("male");
   set("race", "equine");
   //set_exp(400000);
   set_overall_ac(30);
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

