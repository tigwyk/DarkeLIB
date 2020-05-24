//  Wizard:   Khojem
//  Monster:  hareem matron
//  File:     matron.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

int first_suggestion;

void init() {
  :: init();
  if(!this_player()->is_player()) { return; }
  if(this_player()->query_invis()) { return; }
  if(this_player()->query_stealth() > 90) { return; }
  delayed_call("do_it",2,this_player());
  return;    
}

create() {
  int    mod;
  ::create();
    set_name("matron");
    set_id( ({ "hareem matron", "matron" }) );
    mod=random(2);
    set_level(18);
    set_short("[18]hareem matron");
    set_long("She's a big, olde gal and she protects Chief Moped's "
      "hareem like a mother wolf protects her cubs!."
      );
    set("race", "high-man");
    set_gender("female");
    set_body_type("human");
    set_class("nightblade");
    set_overall_ac(18+(2*mod));
    set_melee_damage( (["crushing" : 70 ]) );
    set_property("enhance criticals",-2);
    set_skill("martial arts",80);
    set_property("magic resistance",70);
    set_wielding_limbs( ({ "right hand" }) );
    set_wimpy(0);
    add_money("silver", random(120));
    set_emotes(6, ({
      "The hareem matron spits blood and snarls at you!",
      "The hareem matron kicks you viciously in the groin!",
      "The hareem matron barely misses you with a roundhouse kick!",
      "The hareem matron does a somersault and just before both "
         "land, she viciously heels you in the shin."
    }),1);
    set_casting_chance(0);
    set_combat_chance(92);
    add_spell("blur","$ME");
    set_spell_level("blur",5);
    add_spell("suggestion","$A");
    set_spell_level("suggestion",6);
    set_skill("illusionism",100);
    set_skill("fast casting",80);
    set_skill("concentrate",90);
    force_me("use concentrate");
    force_me("use fast casting");
    first_suggestion = 0;
}

int query_kho_mon() { return 1;}

void do_it(object tp){
  if(!tp || !present(tp, environment())) { return; }
  if(!first_suggestion) {
    first_suggestion = 1;
    force_me("cast *6 suggestion at "+tp->query_name()+" with drop all");
  } 
  message("info","Lets loose a wail like a banshee and turns "
    "to attack you!\n",tp);
  message("info","Wails bitterly at "+tp->query_cap_name()+"!",
    environment(this_object()),tp);
  this_object()->kill_ob(tp,0);
  return;
}
