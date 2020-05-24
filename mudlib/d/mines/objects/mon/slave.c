//           Maxwell's Underground Mud Library
//                    Bossman Bart


#include <std.h>
#include "under.h"

inherit MONSTER;
object *list,*langs;
string *conv;
create() {
    ::create();
   set_name("slave");
   set_id( ({ "slave" }) );
   set_short("[1]haggard and dirty slave");
   set_level(1);
   set("gang bang",0);
   set("long", "This poor guy looks like he has suffered considerably. "
       "His beard is long and dirty and flows down over his torn and "
       "smelly clothing. You can see a wild look in his eyes that makes "
       "you question his sanity. ");
   set_gender("male");
   set("race", "dwarf");
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   set_emotes(10,
     ({ "The slave pulls against his chains.",
     "The slave grins madly and mutters under his breath that he knows "
     "a secret.",
     "The slave rattles his chains and laughs madly at you.",
     "The slave mumbles under his breath something about a combination.",
     }),0 );
    set_achats(50,
    ({ "The slave giggles madly.",
     "The slave grunts.",
     }) );
    set_languages( ({"common","Gods-tongue","middle-english","elvish"
    }) );
    force_me("speak common");
    conv = ({});
    list = ({ "secret","secret?","combination","combination?","heart"
               ,"jenkarb"});
    langs = ({"common","Gods-tongue","middle-english","elvish"});
}
void kill_ob(object who,int i) {
int b;
	::kill_ob(who,i);
        write("The slave grimaces as you prepare to strike him!");
        set_hp(1);
}
void directed_message(object from,string str) {
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
        x = -1;
        while( y < i){
          if(x == -1)
            x = member_array(conv[y],list);              
          y = y + 1;
        }
        if(x != -1) { force_me("tell "+getuid(this_player())+
          " eh? You want to my secret! "
          "Bring me the heart of Jenkarb and you shall find out his "
          "most hidden secret! Heh...HA HA HA!!! I bet you think I'm "
          "insane! I am!! HA HA HA!!");
          say("The slave mumbles something to "+this_player()->query_name()
          +" and bursts into a fit of mad laughter!");
          return;
        }      
        else { 
          force_me("tell "+getuid(this_player())+" Do I look like "
          "a reliable source of information?? "
          "Unless you want to know my secret! HA HA HA..cough..choke");
          say("The slave looks confused and giggles as he mumbles "
          "something to "+this_player()->query_name());
          conv = ({});
          return;
        }
}
void catch_tell(string str) {
  string a,b,lang;
  object tp,ob,to;   
  int combo;
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    a = lower_case(a);
    tp = present(a, environment(this_object()));    
    to = present(b,this_object()); 
    if(!tp) return;
    if(present("jheart", this_object()) ){
      if(present("safe",find_object_or_load(UNDER+"dm54")) )
        combo = (present("safe",find_object_or_load(UNDER+"dm54"))
                ->query_combo());
      else 
        combo = (present("safe",find_object_or_load(UNDER+"dminv"))
                ->query_combo());      
      force_me("tell "+getuid(this_player())+" Lemmie see that "
      "thing..<sniff sniff>. Smells like "
      "his heart!! Feel how cold it is? HA HA..I think it is the heart "
      "of that sorry bastard! You still want to know my secret? It is "
      "the combination of the safe in his office. That moron couldn't "
      "keep anything quiet! The combo is..you writing this down?\n"
      +combo );
      say("The slave eyes grow wide with excitement! He whispers something "
        "to "+this_player()->query_name()+" and then bursts into fit "
        "giggles and choking.");
      return;
    }
    else { 
     force_me("say eh? What the hell is that??\n");
     force_me("drop "+b);
     return ;
    }
  }
}

