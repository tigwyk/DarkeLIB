//           Maxwell's Underground Mud Library
//                     Dwarf Miner Sweeper


#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

create() {
    ::create();
   set_name("Miner");
   set_id( ({ "dwarf","miner","sweeper","worker" }) );
   set_short("[25]dwarf worker");
   set_level(25);
   set("long", "This Miner is in charge of making sure the tracks "
   "stay clear of rubble and dust. He looks very dedicated.");
   set_gender("male");
   set("race", "dwarf");
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   //set_exp(400000);
   set_overall_ac(25);
   set_emotes(10,
     ({ "The miner sweeps some debris off the track.",
     "The miner sweeps some debris into a neat little pile.",
     "The miner wipes some dirt off his clothing."}),0 );
    set_achats(50,
    ({ "Miner loses his balance.",
     "Miner grunts.",
     "Miner smiles wickedly."}) );
//Equipment Code
    mob = this_object();
      wield_hand = "right hand";
}
void kill_ob(object who,int i) {
	::kill_ob(who,i);
   if(present("broom",this_object())){
    tell_room(environment(this_object()),"The Miner throws down his "
    "broom and grins as he pulls a sharp dagger out from under his shirt.");
     new(UNWEAP+"sdagger")->move(this_object());
     force_me("drop broom");
     force_me("wield dagger in right hand");
   }
}





