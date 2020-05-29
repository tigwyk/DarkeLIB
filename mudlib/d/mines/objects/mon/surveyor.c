//           Maxwell's Underground Mud Library
//                     Dwarf Miner Surveyor


#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

object money;
void create() {
    ::create();
   set_name("samuel");
   set_id( ({ "dwarf","Surveyor","surveyor","samuel" }) );
   set_short("Dwarf Samuel the Surveyor");
   set_level(20);
   set("long", "Samuel is dressed in better clothes than most of the "
   "other miners. His job must be to inspect the mine, looking for damage "
   "to the structure of the mine.");
   set_gender("male");
   set("race", "dwarf");
   set_body_type("human");
   set_overall_ac(25);
   set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_moving(1); 
   set_speed(20);	
   set_emotes(5,
     ({ "Samuel feels the wall, running his finger along some cracks.",
     "Samuel makes a note on his clipboard.",
     "Samuel glances at the ceiling and looks nervous.",}),0 );
    set_achats(50,
    ({ "Samuel loses his balance.",
     "Samuel grunts.",
     "Samuel smiles wickedly.",}) );
// Spell Code
    set_combat_chance(80);
    add_spell("explosive fireball", "$A");
    set_spell_level("explosive fireball", 6);   
// Skills For Spells
    set_skill("conjuration",75);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+200));
    money->move(this_object());
//Equipment Code
    mob = this_object();
    wield_hand = "right hand";
//Key Code
    new(UNETC+"mkey")->move(this_object());
}

void die(object who) {
  call_other(find_object_or_load(UNDER+"dm9j"),"miner_dying");
  ::die(who);
  return;
}



