//           Maxwell's Underground Mud Library
//                    cougar Guard


#include <std.h>
#include "under.h"
inherit MONSTER;

int c,x,w,fred,d,e,f;
object who2,who,*who_attacked,*who_entered,master_mob;
string target;
create() {
    ::create();
   set_name("black cougar");
   set_id( ({ "cougar","black cougar"}) );
   set_short("A large muscular black cougar");
   set_level(20);
   set("long", "The cougar has a very muscular body and looks very nasty! "
               "His deep green eyse stare at you intently.\n");
   set_gender("male");
   set("race", "cougar");
   set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(30);
   set_body_type("quadruped");
   set("gang bang",0);
   who_attacked = ({});
   who_entered = ({});
   x = 0;
   set_emotes(10,
     ({ "The cougar growls softly.",
     "The cougar glances at you and drools.",
     "The cougar whines.",}),0 );
   set_achats(50,
    ({ "Black cougar howls!.",
     "Black cougar snarls!.",
     "Black cougar bares his teeth!.",}) );
   set("aggressive", (: call_other,this_object(), "attack" :) );
   x = 0;
   w = 0;
}
mixed query_master(){
   return master_mob;
}
void kill_ob(object who,int i) {
   ::kill_ob(who,i);
   if(member_array(who,who_attacked) == -1)     
      who_attacked += ({who});
}
int attack(object who){
object mon;
   master_mob = (this_object()->query_property("master"));
//   tell_player(find_player("maxwell"),"In attack mode!\n");
   if(who->is_player()) {
//     tell_player(find_player("maxwell"),"Target is player\n");
     if(member_array(who,who_entered) == -1){
       who_entered += ({who});
//      tell_player(find_player("maxwell"),"Target in array!\n");
       call_out("attack2",2,this_player());
     }
     else 
       call_out("attack3",2,this_player());     
   }
   return 0;
}
int attack3(){
object mon;
      d = e;
//    tell_player(find_player("maxwell"),"In attack3 Code "+
//                master_mob->query_name()+"\n");
    if(master_mob != 0 && present(master_mob) )
//      tell_player(find_player("maxwell"),"In attack3 mode with Mob\n");
      call_other(present(master_mob),"insult");
}
int attack2(){
object mon;
int num;
    master_mob = (this_object()->query_property("master"));
//    tell_player(find_player("maxwell"),"In attack2 Code\n");
    if(master_mob != 0 && present(master_mob) ){
//      tell_player(find_player("maxwell"),"In attack2 mode with Mob\n");
      while(w <= ( sizeof(who_entered) - 1 )){
       if(present(who_entered[w])){
          target = (who_entered[w]->query_cap_name());
          call_other(master_mob,"intro",target);
       if(present("chain",master_mob)){
        tell_room(environment(this_object()),master_mob->query_cap_name()+
          " drops the chain holding the cougar.");
        present("chain",master_mob)->remove();      
       }
       tell_object(who_entered[w],"The cougar leaps for your throat!");
       tell_room(environment(this_object()),"The black cougar growls and "
         "leaps for "+who_entered[w]->query_cap_name()+
         "'s throat.",who_entered[w]);
       this_object()->force_me("kill "+who_entered[w]->query_name());
       }
      w = w + 1;
      }
    }
    return 1;
}
void die(object who) {
  int z;

  if( master_mob != 0 && present(master_mob) ){
    master_mob->force_me("say You have killed my best wolf!");
    master_mob->force_me("say I shall avenge his death!!");
    z = 0;
    while(z < sizeof(who_attacked)){
     if(present(who_attacked[z])){
        target =  (who_attacked[z]->query_name() );
        switch(random(2)){
          case 0: 
           call_other(master_mob,"throw_axe", target);
           break;
          case 1: 
           call_other(master_mob,"throw_dagger",target );
           break;
       }
     }
     z = z + 1;
    }
  }
  ::die(who);
  return;
}





