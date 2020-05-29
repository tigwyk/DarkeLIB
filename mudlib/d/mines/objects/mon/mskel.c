//           Maxwell's Underground Mud Library
//                     Dwarf Miner


#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

object money;
int pass;
create() {
    ::create();
   set_name("skeleton");
   set_id( ({ "skeleton","dwarf skeleton","corpse" }) );
   set_short("a decaying skeleton corpse");
   set_level(25);
   set_max_hp(2500);
   set_hp(2500);
   set("long", "The skeleton is covered in dust and tattered clothing. "
"Most of his flesh has rotted off but you can still see some remains "
"behind. His thinning white beard is now dirty and fallin out.");
   set_gender("male");
   set("race", "dwarf");
   set_exp(800000);
   set_alignment(0);
   set_body_type("human");
   set_overall_ac(33);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(10,
     ({ "The skeleton's bones crackle and creak.",
     "The skeleton reachs toward you with his bony hand.",
     }),0 );
    set_achats(50,
    ({ "Skeleton moans loudly.",
     "Skeleton flails his limbs.",
     "Skeleton reachs toward your throat.",}));
// Spell Code
    set_combat_chance(95);
    add_spell("heal","$(ME)"); 
    set_spell_level("heal",6);
    add_spell("harm","$A");
    set_spell_level("harm",6);
//    add_spell("internal flame","$A");
//    set_spell_level("internal flame",2); 
// Skills For Spells and Combat
    add_skill("conjuration",115);
    add_skill("prayer",115);
    set_skill("resist stun",150);
    set_skill("two handed blunt",150);
    set_skill("two handed polearm",150);
    set_skill("two handed flail",150);
    set_skill("two handed blade",150);
    set_skill("parry",150);
    set_skill("defense",150);
    set_skill("dodge",150);  
    set_skill("reverse stroke",100); 
//Equipment Code
    mob = this_object();
    wield_hand = "right hand";
//Misc
    set_moving(1); 
    set_speed(60);
    set("aggressive",(: call_other,this_object(), "no_other_monsters" :) );
    mob = this_object();
    pass = 1;
}
int no_other_monsters(object who) {
  if(who->is_player() || who->is_pet()) return 1;
    else return 0;
}
int kill_ob(object who,int i) {
string moan;
 ::kill_ob(who,i);
 if(pass == 1){
  switch(random(2)){
   case 0 :
    moan = "\nSkeleton moans I shall consume your soul!!\n";
    break;
   case 1 :
    moan = "\nSkeleton moans Finally living flesh!!\n";
    break;
   case 2 :
    moan = "\nSkeleton grins wickedly and advances toward you!!\n";
    break;
  } 
  tell_room(environment(mob),moan);
  pass = 0;
 }
 return 1;
}
void die(object who) {
int current,i,lmd,lcd,dam;
string limb;
object *targets;
 i = 0;
 if(query_property("master_room") != 0){
  current = ( (query_property("master_room"))->query_property("dead"));
  (query_property("master_room"))->set_property("dead",(current+1));
 }
  tell_room(environment(mob),"\nThe skeleton moans Bastards!!\n"
   "The skeleton staggers back and explodes into a cloud of dust "
    "and bone fragments!!\n");
  targets = query_attackers();
  while(i < sizeof(targets)){
    if(present(targets[i])){
       limb = targets[i]->return_target_limb();
      if(random(3) == 0){
       lmd =  targets[i]->query_max_dam(limb);
       lcd =  targets[i]->query_dm(limb); 
       dam = (random(4)+3);       
       targets[i]->do_damage(limb,((lmd-lcd)/dam) );
       tell_object(targets[i],"You get sprayed with fragments! Your "
        +limb+" is impaled with sharp pieces of bone and nasty bits "
        "of rotten flesh!!\n");
       tell_room(environment(mob),targets[i]->query_cap_name()+"'s "+
        limb+" is pelted with tiny bony fragments and bits of rotting "
        "flesh!!\n",targets[i]);
      }
      else {
       tell_object(targets[i],"You dodge to the side as the fragments "
         "fly by!! Just barely missing your "+limb+"!!\n");
       tell_room(environment(mob),targets[i]->query_cap_name()+" dodges "
        "some bone fragments!\n",targets[i]);
      }
    }
   i = i + 1;
  }
  this_object()->remove();
//  ::die(who);
  return;

}



