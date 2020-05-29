//  Wizard:   Khojem
//  Monster:  pub bouncer
//  File:     bouncer.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int    zlevel;
  ::create();
    set_name("bouncer");
    set_id( ({ "bouncer", "guard" }) );
    zlevel = 14 + random(4);
    set_level(zlevel);
    set_short("bouncer");
    set_long("This man was hired by Babba to keep peace in his establishment.  "+
      "Between the thieves looking for easy money and the fights he stays busy.  "
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_emotes(2, ({
	  "The bouncer shouts and lunges at towards you!",
	  "The bouncer checks to see if any pretty girls are checking him out.",
	  "A bouncer circles around behind you!",
	  "The bouncer cracks an ale bottle on your head!  Ouch!",
	  "The bouncer looks for Babba and wonders if he's earned a free drink yet."
	}),1);
	set_class("fighter");
	new("/d/damned/virtual/scimitar_5.weapon")->move(this_object());
	force_me("wield scimitar in right hand");
}

int query_kho_mon() { return 1;}
 
void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s slaps %s", c, b) == 2) {
      a = lower_case(b);
      write("a="+a+"  b="+b+"  c="+c);
      if(c=="dancer") {
        tell_room(environment(this_object()),
          "A bouncer draws his scimitar and shouts, "+c+"!  No fighting here!\n",
            ({ this_object() }));
          force_me("kill "+a);
          return;
      }
   }
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if((interact("babba", b)) || (interact("dancer", b)) ||
           (interact("bouncer", b))) {
           tell_room(environment(this_object()),
             "A bouncer draws his scimitar and shouts, "+c+"!  No fighting here!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
         }
      }
   }   
}
