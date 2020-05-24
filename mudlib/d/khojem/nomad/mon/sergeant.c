//  Wizard:   Khojem
//  Monster:  nomad sergeant at arms
//  File:     sergeant.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("nomad sergeant");
    set_id( ({ "nomad sergeant at arms", "sergeant at arms", "sergeant" }) );
    set_level(10);
    set_short("[10]nomad sergeant at arms");
    set_long("The nomad sergeant at arms is a tall, dark haired high-man.  "+
      "He is bearded and appears to be a good fighter.  You can see he is well "+
      "liked by his men."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver",random(30));
    set("aggressive", (: call_other, this_object(), "attack_bob" :) );
    set_emotes(5, ({
	  "The nomad sergeant leaps at you in a fit of frenzy!",
	  "The nomad sergeant whirls his scimitar in the air over his head.",
	  "The sergeant waves to his men and encourages them to quicken the battle.",
	  "The nomad spits tobacco juice in your face!"
	}),1);
	set_class("fighter");
	new("/d/damned/virtual/scimitar_6.weapon")->move(this_object());
	force_me("wield scimitar in right hand");
	new("/d/khojem/nomad/armor/sunvisor")->move(this_object());
	force_me("wear visor");
}

int query_kho_mon() { return 1;}

int attack_drill(object who) {
  who->init();
  tell_room(environment(this_object()),
    "Nomad Sergeant at Arms says, Greetings "+(who->query_cap_name())+"!\n",
    ({ this_object() }));
  return 1;
}

int attack_bob(object who) {
	if (!who->is_player()) return 0;
	call_out( "attack_drill",1,who );
	return 0;
}
 
void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("guard", b)) {
           tell_room(environment(this_object()),
             "Nomad Sergeant at Arms shouts, Guards we are under attack!  "+
             "Death to "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
         }
      }
   }   
}
