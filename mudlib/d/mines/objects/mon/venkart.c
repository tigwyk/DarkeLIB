//           Maxwell's Underground Mud Library
//                 Guardian of Silver Altar


#include <std.h>
#include "under.h"
inherit MONSTER;

object money,name2,player,player2,*who_attacked,*been_told;
object *been_reminded,who2;
object here;
int w,z,num2;
object *langs,me;
string *conv,*list,*list2;

create() {
    ::create();
   set_name("venkart");
   set_id( ({ "venkart","Dwarven Mage","mage","dwarven mage" }) );
   set_short("The Dwarven Mage Venkart is standing here");
   set_level(25);
   set_max_hp(5000);
   set_hp(5000);
   who_attacked = ({});
   been_told = ({});
   been_reminded = ({});
   w = 0;
   z = 0;
   add_skill("two handed polearm",150);
   set("long", "Venkart is here in front of you, wearing a hooded "
   "long flowing robe. His face is in the shadow of the hood, but you "
   "can see his eyes glowing in the shadows with magical fire.");
   set_gender("male");
   set("race", "dwarf");
   set_alignment(0);
   set_body_type("human");
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_emotes(10,
     ({ "Venkart glances at you and mumbles to himself.",
     "Venkart grips his staff tightly.",}),0 );
//   set("aggressive", (: call_other,this_object(), "speech" :) );
    set_languages( ({"common","Gods-tongue","middle-english","elvish"}) );
    force_me("speak common");
    conv = ({});
    list = ({ "axe","quest","tomb","montar","Montar"});
    list2 = ({"accept"});
    langs = ({"common","Gods-tongue","middle-english","elvish"});

}
void init(){
     ::init();
     me = this_object();
     player = this_player();
     here = (environment(this_object()));

}

int directed_message(object from,string str) {
int i,x,y,w,mlang;
string plang;


        plang = this_player()->query_primary_lang();
        mlang = member_array(plang,langs);
        if( mlang  != -1)
	  force_me("speak "+this_player()->query_primary_lang() );
        else
          force_me("speak common");
        str = lower_case(str);
        conv = explode(str," ");
        i = sizeof(conv);
        y = 0;
        w = -1;
        x = -1;
        while( y < i){
          if(x == -1) x = member_array(conv[y],list);
          if(w == -1) w = member_array(conv[y],list2);
          y = y + 1;
        }
        if(x != -1 && w == -1) { tell_room(here,"\nVenkart mumbles "
          "So you want to know about "
          "the Axe of Montar? I suppose that you're here seeking its power "
          "for yourself. You adventures are so predictable and persistant! "
          "As much as I would like to send you away and seal the temple "
          "forever, I vowed to the Duke of Montar that I would protect "
          "the axe until he returned or a worthy adversary came to earn it. "
          "The Duke has a left a message for you, I advise that you heed "
          "his wisdom.\n");
          if(!present("scroll",environment(this_object())) ) {
             tell_room(here,"Venkart pounds his staff on the cold stone "
             "floor. A scroll suddenly appears, nailed to the wall beside "
             "you!\n");
             new(UNETC+"mscroll")->move(here);
          }
          tell_room(here,"\nVenakart says Read the scroll and decide your "
          "fate!\n");
          return 1;
        }
        if(w != -1){ tell_room(here,"Your acceptance of the Duke's Challenge "
          "is noted "+getuid(this_player())+". I shall prepare the Temple "
          "for your task. Your first "
          "challenger is waiting for you in the room at the end of the "
          "southwest passage!\n");
          write_file(UNQST+"duke_accept",""+getuid(this_player())+
             " accepted the challenge at "+ctime(time())+"\n");
          if(present("scroll")){
            tell_room(here,"The scroll glows brightly and then "
            "disappears.");
            (present("scroll"))->remove();            
          }
          tell_room(here,"\nVenkart spins his staff and dissappears in a "
          "puff of black smoke.");
          (find_object_or_load(UNDER+"dm35"));
          (UNDER+"dm35")->set_property("x",2);
          this_object()->remove();
          return 1;
        }
        else { 
          tell_room(here,"\nVenkart says I don't have time for your "
          "foolish babbling "+getuid(this_player())+"! "
          "What do you want? If you aren't here to earn the Axe, leave "
          "the temple!\n");
          conv = ({});
          return 1;
        }
}
//void catch_tell(string str) {
//int num3;
//object name3;
//string tmp,name;
//
////   if(sscanf(str, "%s casts a spell.",name)) {
//     tell_room(here,"Venkart spins his staff and mumbles something. A "
//   "large dimmensional shift opens next to him and he steps into it, "
//    "disappearing from view as it closes behind him!");
//    move("/wizards/maxwell/workroom");
//    call_out("attack1",2,this_object());
//    return;
//  }
//}
//int attack1(){
//   tell_room(here,"Venkart's evil laughter echoes through the chamber.");
//   tell_room(here,"Fools did you think I was stupid enough to wait around "
//   "for you to cast your silly little spells?");
//   call_out("stall",6,this_object());
//   return 1;
//}
int kill_ob(object who,int i) {
int b;
	::kill_ob(who,i);
	b=member_array(who,who_attacked);     
	if(b == -1){
  who_attacked += ({who});
  here=(environment(this_object()));
  tell_room(here,"Venkart says in Dwarvish: So you have made your "
  "choice feeble one?.");
  tell_room(here,"Come back when your ready to accept the Duke's Challenge!!");
  tell_room(here,"Venkart mumbles something and disappears in a cloud of "
  "black posionous gas!");
  tell_object(this_player(),"The acidic gas burns the inside of your "
  "lungs as you choke on it!");
  this_player()->add_hp(-(random(100)));
  player = this_player();
  this_object()->remove();
//  move("/wizards/maxwell/workroom");
//  call_out("rid",1,this_object());
  }
  return 1;
}
//int rid(){
//  tell_room(here,"Venkart's evil laugh echoes through the room "
//  "as "+player->query_cap_name()+" hits only air.",player);
//  tell_object(player,"Venkart's evil laugh echoes through the chamber "
// "as you aim for the cloud of poisonous gas but hit nothing.");
//  call_out("stall",5,this_object());
//  return 1;
//}
//int stall(){
//  tell_room(here,"Venkart voice seems to whisper through the chamber.\n"
//"'You are not worthy of the Silver Blade... I'm too old to fight you, "
//"but the tomb declares that you must be tested anyway. If you are "
//"successful in my challenge you shall earn posession of my "
//"blade'.\n'Now for your task..'");
// call_out("stall2",9,this_object());
// return 1;
//}
//int stall2(){
//object mon1;
//tell_room(here,"'I shall summon a guardian demon to destroy your "
//"very Soul!!'\n");
// tell_room(here,"There is a burst of bright light! A large warrior "
// "materializes before you!");
//  mon1 = new("/wizards/maxwell/objects/mon/sguard");
//  mon1->move(here);
//  (new("/wizards/maxwell/objects/weapons/scythe")->move(mon1));
//  mon1->force_me("wield scythe in right hand and left hand");  
//  remove();
//  return 1;
//}

  
