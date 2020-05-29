//  Wizard:   Khojem
//  Monster:  nomad captain of the guard
//  File:     captain.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

int zalign;

create() {
  int    mod;
  ::create();
    set_name("nomad captain");
    set_id( ({ "nomad captain", "captain", "guard" }) );
    set_level(10);
    set_short("nomad captain");
    set_long("The nomad captain of the guard is a tall, dark haired high-man.  "+
      "He is bearded and appears to be a good fighter.  You can see he is well "+
      "liked by his men."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_alignment(200);
    set("aggressive", (: call_other, this_object(), "attack_bob" :) );
    set_emotes(5, ({
	  "The nomad captain leaps at you in a fit of frenzy!",
	  "The nomad captain whirls his scimitar in the air over his head.",
	  "The captain waves to his men and encourages them to quicken the battle.",
	  "The nomad spits tobacco juice in your face!"
	}),1);
	set_class("fighter");
	new("/d/damned/virtual/scimitar_6.weapon")->move(this_object());
	force_me("wield scimitar in right hand");

}

int query_kho_mon() { return 1;}

int attack_drill(object who) {
  who->init();
  if(zalign<-750) { 
    tell_room(environment(this_object()),
      (who->query_cap_name())+" is evil!  Guards!  ATTACK!\n",
      ({ this_object() }));
    return 1;
  } 
  tell_room(environment(this_object()),
    "Nomad Captain say, Greetings "+(who->query_cap_name())+"!\n",
    ({ this_object() }));
  return 1;
}


int attack_bob(object who) {
	if (!who->is_player()) return 0;
    zalign = (who->query_alignment());	
	call_out( "attack_drill",1,who );
	if(zalign<-750) { return 1; }
	return 0;
}

