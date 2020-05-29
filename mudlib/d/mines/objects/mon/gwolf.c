//           Maxwell's Underground Mud Library
//                     Wolf Guard


#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

string play,play1,play2,name,race,race1; 
object money,here;

create() {
    ::create();
   set_name("Mikarty");
   set_id( ({ "Mikarty","dwarf","guard","mikarty" }) );
   set_short("Mine guard Mikarty");
   set_level(20);
   set("long", "Mikarty is standing before you wearing the traditional "
    "uniform of a Dwarf security officer.");
   set_gender("male");
   set("race", "dwarf");
   set_max_hp(2500);
   set_hp(2500);
   set_alignment(0);
   set("aggressive", 0);
   set_exp(400000);
   set_body_type("human");
   set_overall_ac(25);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set("gang bang", 0);
   set_languages(({ "common" }));
   set_lang_prof("common",10);
   force_me("speak common");
   set_emotes(10,
     ({ "Mikarty glances at his wolf.",
     "Mikarty mumbles something about tresspassers in the other tunnel.",
     "Mikarty picks at something under his nail.",}),0 );
   set_achats(50,
    ({ "Mikarty loses his balance.",
     "Mikarty grunts.",
     "Mikarty smiles wickedly.",}) );
// Spell Code
    set_combat_chance(80);
    add_spell("heal","$(ME)"); 
    set_spell_level("heal",6);
    add_spell("harm","$A");
    set_spell_level("harm",4);
//    add_spell("internal flame","$A");
//    set_spell_level("internal flame",2); 
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
//Equipment Code
    wield_hand = "right hand";
    mob = this_object();
}
int throw_dagger(string incoming){
object mob;
  mob = this_object();
  here = environment(this_object());
  tell_room(here,"\nMikarty's face colors deeply and he screams!!\n");
  mob->force_me("tell "+incoming+" It is your fault "+incoming+"!!");
  tell_room(here,"\nMikarty yells I will kill you all!!\n");
  if(!present("guard dagger")){
    if((mob->query_weapon("left hand"))==0 ||
       (mob->query_weapon("right hand")) == 0){
    new(UNWEAP+"gdagger")->move(this_object());
    mob->force_me("throw guard dagger at "+incoming);
    }
  }
  mob->force_me("kill "+incoming);
  return 1;
}
int throw_axe(string incoming){
object mob;
  mob = this_object();
  here = environment(this_object());
  tell_room(here,"\nMikarty's face colors deeply and he screams!!\n");
  mob->force_me("tell "+incoming+" You are to blame for this "+incoming+"!!");
  tell_room(here,"\nMikarty yells I will kill you all!!\n");
  if(!present("guard axe")){
    if((mob->query_weapon("left hand"))==0 ||
       (mob->query_weapon("right hand")) == 0){
    new(UNWEAP+"ghandaxe")->move(this_object());
    mob->force_me("throw guard axe at "+incoming);
    }
  }
  mob->force_me("kill "+incoming);
  return 1;
}
int intro(string target){
string *mess;
int pick;
   mess = ({ " You don't belong here!! Get em' boy!!!\n"," You know I hate "
          "unwanted guests!! Rip them lungs out fella!\n" });    
   pick = random(sizeof(mess));
   this_object()->force_me("tell "+target+mess[pick]);
   return 1;
}
int insult(){
string *mess;
int pick;
   mess = ({ "Get them Cowards!\n","Did you think you would get away!\n",
           "Get that scaredy cat!\n" });
   here = environment(this_object());   
   pick = random(sizeof(mess));
   tell_room(here,"Mikarty screams "+mess[pick]);
   return 1;
}
void die(object who) {

  here = (environment(this_object()));
  tell_room(here,"\nMikarty moans I'll see you in hell!!\n");
 ::die(who);
 return;
}
