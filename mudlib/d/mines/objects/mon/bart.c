//           Maxwell's Underground Mud Library
//                    Bossman Bart


#include <std.h>
#include "under.h"
inherit MONSTER;

object *list,*langs;
string *conv;
void create() {
    ::create();
   set_name("bart");
   set_id( ({ "bart","foreman","Foreman" }) );
   set_short("Bart the Dwarf Mine Foreman");
   set_level(30);
   set("long", "Bart is obviously a high ranked dwarf. He spends most of "
"his time buried behind paperwork though. Besides paper pushing he is also "
"in charge of ordering and processing equipment for all mine operations. "
"If one of the miners needed any sort of mining supplies they would "
"talk to Bart.");
   set_gender("male");
   set("race", "dwarf");
   set_exp(2000000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   set_overall_ac(35);
   set_emotes(10,
     ({ "Bart glances around the room.",
     "Bart scribbles something on a scrap of paper.",
     "Bart glances at you suspiciously.",
     "Bart frowns and scribbles something on a scrap of paper.",
     }),0 );
    set_achats(50,
    ({ "Bart loses his balance.",
     "Bart grunts.",
     "Bart smiles wickedly.",
     }) );
    set_languages( ({"common","Gods-tongue","middle-english","elvish"
    }) );
    force_me("speak common");
    conv = ({});
    list = ({ "crate","tube","dust","zikart","axe","quest","montar","Montar",
              "Axe","Quest","rope","supplies"});
    langs = ({"common","Gods-tongue","middle-english","elvish"});
// Spell Code
    set_combat_chance(80);
    add_spell("heal","$(ME)"); 
    set_spell_level("heal",6);
    add_spell("harm","$A");
    set_spell_level("harm",4);
    add_spell("internal flame","$A");
    set_spell_level("internal flame",3); 
// Skills For Spells and Combat
    set_skill("conjuration",95);
    set_skill("prayer",95);
    set_skill("resist stun",115);
    set_skill("two handed blunt",115);
    set_skill("two handed polearm",115);
    set_skill("two handed flail",115);
    set_skill("two handed blade",115);
    set_skill("parry",115);
    set_skill("defense",115);
    set_skill("dodge",120);  
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
        if(x >= 0 && x <= 3) { force_me("tell "+getuid(this_player())+
          " Hmm? You say something about a "
          "Zikert Dust Tube? I got some of those...but they ain't free."
          "Tell ya what..you go down to Section 69 and bring back a crate "
          "I left there. If you give me the crate I'll give you a tube "
          "of the Dust.");
          say("Bart mumbles something to "+this_player()->query_cap_name());
          return;
         }
        if(x >= 4 && x <= 9){
          force_me("tell "+getuid(this_player())+" You want to know "
        "about the axe? My family has searched for the Axe of Montar for "
        "hundreds of years! If only I could find it... I would greatly "
        "reward anyone who could bring me the fabled axe!");
          say("Bart's eyes glisten as he mumbles something to "+
              this_player()->query_cap_name());
          return;
        }
        if(x == 10){
          force_me("tell "+getuid(this_player())+" Eh? You need "
                   "some rope for something? I think "
                   "there is some in the Waterwheel Plant down by the "
                    "waterfall.");
          say("Bart's eyes gleam as he mentions something to "
              +this_player()->query_cap_name());
          return;
        }
        if(x == 11){
           force_me("tell "+getuid(this_player())+" You need "
             "supplies? I got some supplies.");
           say("Bart mumbles something to "+this_player()->query_cap_name());
           return;
        }
        else { 
          force_me("tell "+getuid(this_player())+" I don't have time "
          "for your idle chatter fool. What do you want?");
          say("Bart's face flushes as he tartly says something to "
             +this_player()->query_cap_name());
          conv = ({});
          return;
        }
}
void catch_tell(string str) {
  string a,b,lang,*name;
  object tp,ob,to;   
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
//    tell_room(environment(this_object()),b);
    a = lower_case(a);
    tp = present(a, environment(this_object()));    
    if(!tp) return;
    if(present("dynocrate") ){
      force_me("tell "+getuid(this_player())+" I see you have "
      "located my crate! I shall give a "
      "tube of the Zikert Dust for your efforts!.");
      say("Bart grins widely as he looks at the crate "
          +this_player()->query_cap_name()+" gave him.");
      present("dynocrate",this_object())->remove();
      new(UNWEAP+"dyno")->move(this_object());
      force_me("give tube to "+this_player()->query_name());
      return;
     }
    if(present("montar_quest_object") ){
      force_me("tell "+getuid(this_player())+" You have brought "
       "me the legendary Axe of Montar! Unbelievable! I'll will reward "
       "you greatly for giving me the axe!");
      say("Bart looks very excited as he glances at the axe! he carefully "
      "wraps it in a cloth and places it in one of the crates.");
      present("montar_quest_object")->remove();
      write("Axe of Montar Quest Completed!\nYou recieve 45 quest points!");
      this_player()->add_quest_points(45);
      write_file("/wizards/maxwell/objects/quest/axe_owner","nobody",1);
      return;
    }
    else { 
     force_me("tell "+getuid(this_player())+" Why would I want "
             "that??.\n");
     return ;
    }
  }
}

