//  Wizard:   Khojem
//  Monster:  shopguard
//  File:     shopguard.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int    zlevel;
  ::create();
    set_name("shopguard");
    set_id( ({ "shopguard", "guard" }) );
    zlevel = 12 + random(4);

if (zlevel == 12) set_short("[12]shopguard");
else 
if (zlevel == 13) set_short("[13]shopguard");
else
if (zlevel == 14) set_short("[14]shopguard");
else
if (zlevel == 15) set_short("[15]shopguard");
else set_short("[16]shopguard");
	set_level(zlevel);
    set_long("This man was hired by the local merchants to protect the merchants "+
      "from thieves and vandals.  Looks like they must do a fair job since the "+
      "merchants appear well off and healthy."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
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
         if((interact("merchant", b)) || (interact("shopguard", b))) {
           tell_room(environment(this_object()),
             "A shopguard draws his scimitar and shouts, Death to "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
         }
      }
   }   
}
