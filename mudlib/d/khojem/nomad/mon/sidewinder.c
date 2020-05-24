//  Wizard:   Khojem
//  Monster:  sidewinder
//  File:     sidewinder.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void create() {
  ::create();
  set_name("sidewinder");
  set_id( ({ "sidewinder", "snake" }) );
  set_short("[5]slithering sidewinder");
  set_long("The sidewinder moves quickly across the desert sand.");
  set("race", "serpent");
  set_property("melee damage", ([ "impaling" : 15 ]));
  set_level(5);
  set_body_type("serpent");
  set_gender("male");
  set_speed(170);
  set_moving(1);
  set("aggressive", (: this_object(), "not_other_monsters" :) );
  set_emotes(10,({
      "The sidewinder swiftly moves past you!",
      "The sidewinder hisses and sprays venom at you!",
      "The sidewinder springs and misses a strike at your feet!",
      "A sidewinder coils for a strike and displays its fangs.",
      "The sidewinder briefly retreats."
    }),1);    
// new("/d/khojem/nomad/weapon/snake_fang")->move(this_object());
// force_me("wield fang in tail");
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}

// void die(object who) {
//  object ob;

//  ob = present("fang", this_object());
//  if(ob)ob->remove();
//  ::die(who);
//  return;
//}


