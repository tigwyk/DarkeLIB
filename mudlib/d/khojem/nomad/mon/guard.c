//  Wizard:   Khojem
//  Monster:  nomad guard
//  File:     guard.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int    mod;
  ::create();
    set_name("nomad guard");
    set_id( ({ "nomad guard", "guard" }) );
    set_level(8);
    set_short("[8]nomad guard");
    set_long("The nomad guard is one of the nameless high-man who help "+
      "protect this small camp.  He is devoted to his sergeant and obeys "+
      "all his sergeant's orders.  Obvious a drone to the man."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", random(10));
    set_emotes(5, ({
	  "The guard leaps at you!",
	  "The guard waves his scimitar in the air.",
	  "A guard circles around behind you!",
	  "The guard starts to foam at the mouth!  He is starting to like the
fight."
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
      if(ob1) {
         if((interact("guard", b)) || (interact("sergeant",b))) {
           tell_room(environment(this_object()),
             "Nomad Guard shouts, Sarge!  We are under attack!  "+
             "Death to "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
         }
      }
   }   
}

