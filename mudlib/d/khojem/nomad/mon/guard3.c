//  Wizard:   Khojem
//  Monster:  nomad guard 3 - mobile
//  File:     guard3.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int    mod;
  ::create();
    set_name("nomad guard");
    set_id( ({ "nomad guard", "guard" }) );
    set_level(7);
    set_short("nomad guard");
    set_long("The nomad guard is one of the nameless high-man who help "+
      "protect this small camp.  He is devoted to keeping the peace."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_moving(1);
    set_speed(240);
    add_money("silver", random(20));
    set_emotes(5, ({
	  "The guard leaps at you!",
	  "The guard waves his scimitar in the air.",
	  "A guard circles around behind you!",
	  "The guard spits blood onto the sand.",
	  "The guard starts to foam at the mouth!  He is starting to "+
        "like the fight."
	}),1);
	set_class("fighter");
	new("/d/damned/virtual/scimitar_5.weapon")->move(this_object());
	force_me("wield scimitar in right hand");
}

int query_kho_mon() { return 1;}
 
void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
      ob1 = present(a, environment(this_object()));
        tell_room(environment(this_object()),
          "Nomad Guard shouts, Hostiles in camp!  "+
             "Death to "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
   }   
}
