//           Maxwell's Underground Mud Library
//                    Wolf Guard


#include <std.h>
#include "under.h"
inherit MONSTER;

int c,x,w,fred,d,e,f;
object who2,who,*who_attacked,*who_entered,mon;
string target;
create() {
    ::create();
   set_name("black cougar");
   set_id( ({ "cougar","black cougar"}) );
   set_short("A large muscular cougar");
   set_level(20);
   set("long", "The black cougar looks very strong and very nasty! His "
       "deep green eyes stare at you intently.");
   set_gender("male");
   set("race", "wolf");
   set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("quadruped");
   set_overall_ac(30);
   set("gang bang",0);
   who_attacked = ({});
   who_entered = ({});
   x = 0;
   set_emotes(10,
     ({ "The cougar growls softly.",
     "The cougar glances at you and snarls!",
     "The cougar paces around the room.",}),0 );
   set_achats(50,
    ({ "Black cougar growls!.",
     "Black cougar snarls!.",
     "Black cougar bares his teeth!.",}) );
   set("aggressive", (: call_other,this_object(), "attack" :) );
   x = 0;
   w = 0;
}
int attack(object who){
object mon;
   if(who->is_player()) {
     who2  = who;
     e = member_array(who,who_entered);
     if(e == -1){
       who_entered += ({who});
       call_out("attack2",2,this_player());
       return 0;
     }
     else {
     call_out("attack3",2,this_player());
     }
   }
return 0;
}
int attack3(){
      d = e;
    if( (this_object()->query_property("master")) != 0){
      if(present( (this_object()->query_property("master")) ))
         call_other(present(query_property("master")),"insult");
    }
}
int attack2(){
int num;
    if( present(query_property("master")) ){
      mon = present(query_property("master") );
      num = sizeof(who_entered);
      while(w <= (num - 1)){
       if(present(who_entered[w])){
          target = (who_entered[w]->query_cap_name());
          call_other(mon,"intro",target);
       if(present("chain",mon)){
         tell_room(environment(this_object()),mon->query_cap_name()+
           " drops the chain holding the wolf.");
         present("chain",mon)->remove();      
       }
       tell_object(who_entered[w],"The cougar leaps for your throat!");
       tell_room(environment(this_object()),"The black cougar growls and "
       "leaps "
       "for "+who_entered[w]->query_name()+"'s throat.",who_entered[w]);
       this_object()->force_me("kill "+who_entered[w]->query_name());
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
  if(present(mon)){
    mon->force_me("say You have killed my favorite cougar!");
    mon->force_me("say I shall avenge his death!!");
    y = sizeof(who_attacked);
    z = 0;
    while(z <= (y-1)){
     if(present(who_attacked[z])){
        target =  (who_attacked[z]->query_name() );
       switch(random(2)){
        case 0: 
         call_other(mon,"throw_axe", target);
        break;
        case 1: 
         call_other(mon,"throw_dagger",target );
        break;
       }

     }
     z = z + 1;
    }
  ::die(who);
  return;
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




