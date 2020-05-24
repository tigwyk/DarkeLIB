//  Wizard:   Khojem
//  Monster:  cobra
//  File:     cobra.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void init() {
  :: init();
  if(this_player()->is_player()) {
    write("You are impaled by the cobra!\nIt injected you with poison!\n");
    message("info",this_player()->query_cap_name()+
      " is poisoned by the cobra's "
      "first strike.",this_object(),this_player());
    this_player()->add_poisoning(120);
    this_object()->kill_ob(this_player(),0);
  }
}
  
void create() {
  ::create();
  set_name("cobra");
  set_id( ({ "cobra", "snake", "king cobra" }) );
  set_short("[12]king cobra");
  set_long("The king cobra is pissed that you woke him up.");
  set("race", "serpent");
   set_property("melee damage", ([ "impaling" : 20 ]));
  set_level(12);
  set_body_type("serpent");
  set_gender("male");
  set_emotes(10,({
      "The cobra swiftly moves past you!",
      "The cobra hisses and sprays venom at you!",
      "The cobra springs and misses a strike at your feet!",
      "The cobra coils for a strike and displays its fangs.",
      "The cobra arches up into the air and fans his hood."
    }),1);    
}

int query_kho_mon() { return 1;}

