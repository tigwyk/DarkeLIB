// Maxwell's Underground Mud Library
// Jenkarb Dwarf                 

#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

object money;
create() {
    ::create();
   set_name("jenkarb");
   set_id( ({ "jenkarb","Jenkarb","dwarf","miner" }) );
   set_short("Jenkarb the Evil Dwarf");
   set_level(25);
   set_max_hp(3500);
   set_hp(3500);
   set("long", "Jenkarb stands before you and sneers in your general "
       "direction. He reminds you of the typical bully.");
   set_gender("male");
   set("race", "dwarf");
   set_exp(800000);
   set_alignment(-500);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   set_overall_ac(33);
   set_emotes(5,
     ({ "Jenkarb wipes his hands on his pants.",
     "Jenkarb mutters under his breath.",
     "Jenkarb wonders what his little slave is doing",}),0 );
    set_achats(50,
    ({ "Jenkarb says in common: Did the slave put you up to this!!.",
     "Jenkarb grunts.",
     "Jenkarb smiles wickedly.",
     "Jenkarb spits at you!",}) );
// Spell Code
    set_combat_chance(80);  
    add_spell("internal flame","$A");
    set_spell_level("internal flame",3);
// Skills For Spells and Combat
    set_skill("conjuration",95);
    set_skill("resist stun",130);
    set_skill("two handed blunt",130);
    set_skill("two handed polearm",130);
    set_skill("two handed flail",130);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+200));
    money->move(this_object());
//Equipment Code
    mob = this_object();
    wield_hand = "left hand";
//Misc
    set_moving(1); 
    set_speed(60);	 
    set("aggressive",0);
//    set("aggressive",(: call_other,this_object(), "no_other_monsters" :) );
}
int no_other_monsters(object who) {
  if(who->is_player() || who->is_pet()) return 1;
    else return 0;
}
void die(object who) {
int current;
 if(query_property("master_room") != 0){
  current = ( (query_property("master_room"))->query_property("dead"));
  (query_property("master_room"))->set_property("dead",(current+1));
 }
  new(UNETC+"heart")->move(this_object());
  ::die(who);
  return;

}




