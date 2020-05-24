//           Maxwell's Underground Mud Library
//                  Dwarf Miner Cart Pusher

#include <std.h>
#include <under.h>
inherit MONSTER;
inherit UNEQP;

string here,play,play1,play2,name,race,race1; 
object money;
create() {
    ::create();
   set_name("Miner");
   set_id( ({ "Miner","dwarf","miner" }) );
   set_short("A stocky dwarf Miner");
   set_level(20);
   set("long", "The Miner is covered in dust and dirt.");
   set_gender("male");
   set("race", "dwarf");
   set_max_hp(2500);
   set_hp(2500);
   set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   set_overall_ac(25);
   set("gang bang", 0);
   set_emotes(10,
     ({ "The Miner struggles with one of the mine carts.",
     "The Miner wipes the sweat from his eyes.",
     "The Miner glances at you suspiciously.",}),0 );
   set_achats(50,
     ({ "The Miner loses his balance.",
       "The Miner grunts.",
       "The Miner smiles wickedly.",}) );
//  call_out("cart",3,this_player());

  set("aggressive", (: call_other,this_object(), "test" :) );
// Spell Code
    set_combat_chance(80);
    add_spell("heal","$(ME)"); 
    set_spell_level("heal",6);
    add_spell("harm","$A");
    set_spell_level("harm",3);
//    add_spell("internal flame","$A");
//    set_spell_level("internal flame",2); 
// Skills For Spells and Combat
    add_skill("conjuration",95);
    add_skill("prayer",95);
    set_skill("resist stun",115);
    set_skill("two handed blunt",115);
    set_skill("two handed polearm",115);
    set_skill("two handed flail",115);
    set_skill("two handed blade",115);
    set_skill("parry",115);
    set_skill("defense",115);
    set_skill("dodge",120);  
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(50)+200));
    money->move(this_object());
//Equipment Code
    mob = this_object();
    wield_hand = "right hand";
}
int cart(string fun){
   object me;
   if(present("cart")){
     me = this_object();
     me->force_me("pull lever"); 
     tell_room(UNDER+"dm2","The Miner pulls a lever on the side of the "
     "mine cart.");
     return 1;
   }
}
int test(object who) {
   here = file_name(environment(this_object()));
 if(who->is_player()) {
   play = (who->query_name());
   race = (who->query_race());
   if(race == "dwarf") {
    if(who->is_player()){
     play1 = play;
     race1 = race;
     call_out("test2",2,this_player());
    }
    return 0;
   }
   if(race != "dwarf") { 
    if(who->is_player()){
     play2 = play;
     call_out("attack",2,this_player());
    }
   return 0;
   }
   return 0;
 }
return 0;
}
int test2() {   
   this_object()->
        force_me("tell "+play1+" You don't look like any "+race1+" I "
        "know!\n"); 
   this_object()->force_me("kill "+play1);
   return 1;
}
int attack() {
   force_me("tell "+play2+" You don't belong here "+play2+". Prepare to "
   "die!!\n");
   force_me("kill "+play2);
   return 1;
}
void die(object who) {
  string here;
  tell_room(environment(this_object()),"Miner takes his last gasp of air.");
  ::die(who);
  return;
}
