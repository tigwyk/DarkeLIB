//           Maxwell's Underground Mud Library
//                    Wolf Guard


#include <std.h>
#include "under.h"
inherit MONSTER;

int c,x,w,fred,d,e,f;
object who2,who,*who_attacked,*who_entered,mon,master;
string target;
create() {
    ::create();
   set_name("grey wolf");
   set_id( ({ "wolf"}) );
   set_short("[25]large grey wolf");
   set_level(25);
   set("long", "The grey wolf looks very strong.");
   set_gender("male");
   set("race", "wolf");
   //set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("quadruped");
   set_overall_ac(25);
   set("gang bang",0);
   who_attacked = ({});
   who_entered = ({});
   x = 0;
   set_emotes(10,
     ({ "The wolf growls softly.",
     "The wolf glances at you and drools.",
     "The wolf whines.",}),0 );
   set_achats(50,
    ({ "Grey wolf howls!.",
     "Grey wolf snarls!.",
     "Grew wolf bares his teeth!.",}) );
   set("aggressive", (: call_other,this_object(), "attack" :) );
   x = 0;
   w = 0;
}
int attack(object who){   
   if(!query_property("master")) return 0;
   if(present(query_property("master"))) 
      master = (query_property("master"));
   if(who->is_player()) {
     e = member_array(who,who_entered);
     if(e == -1){
       who_entered += ({who});
       call_out("attack2",2,this_player());
     }
     else 
       call_out("attack3",2,this_player());     
   } 
}
void attack3(){
    if(master != 0 && present(master) ) 
       call_other(master,"insult");    
    return;
}
int attack2(){
int num;
    if(master != 0 && present(master)){      
      num = sizeof(who_entered);
      w = 0;
      while(w < num){
       if(present(who_entered[w])){
          target = (who_entered[w]->query_cap_name());
         if(present(master))         
           call_other(master,"intro",target);
         if(present("chain",master)){
           tell_room(environment(this_object()),
            master->query_cap_name()+" drops the chain holding the wolf!");
           present("chain",master)->remove();      
         }
         tell_object(who_entered[w],"The wolf leaps for your throat!");
         tell_room(environment(this_object()),"The grey wolf growls and "
         "leaps for "+who_entered[w]->query_name()+"'s throat."
         ,who_entered[w]);
         this_object()->force_me("kill "+target);
       }
       w = w + 1;
     }
    }
    return 1;
}
void die(object who) {

  int z,y;
  string here;
  here=file_name(environment(this_object()));
  if(master != 0 && present(master)){
     y = sizeof(who_attacked);
     z = 0;
     while(z < y){
       if(present(who_attacked[z])){
         target =  (who_attacked[z]->query_name() );
         switch(random(2)){
           case 0: 
             call_other(master,"throw_axe", target);
           break;
           case 1: 
            call_other(master,"throw_dagger",target );
           break;
         }

      }
      z = z + 1;
    }  
 }
 ::die(who);
 return;
}
void kill_ob(object who,int i) {
int b;
	::kill_ob(who,i);
        b=member_array(who,who_attacked);     
        if(b == -1) who_attacked += ({who});
}




