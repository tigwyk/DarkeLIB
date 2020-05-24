//  Wizard:   Khojem
//  Monster:  pit viper
//  File:     pit_viper.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void create() {
  ::create();
  set_name("pit viper");
  set_id( ({ "pit viper", "viper", "snake" }) );
  set_short("[8]pit viper");
  set_long("It is a huge, hooded pit viper.  Its truck is a thick as a "+
    "storm-giant's upper arm!");
  set("race", "serpent");
  set_property("melee damage", ([ "impaling" : 15 ]));
  set_level(8);
  set_body_type("serpent");
  set_gender("male");
  set_speed(260);
  set_moving(1);
  set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
  set_emotes(10,({
      "The hooded pit viper strikes at you!",
      "The pit viper hisses and sprays venom at you!",
      "The viper rises up and sways from side to side determining your distance!",
      "A pit viper hisses and displays its fangs.",
      "The pit viper briefly retreats."
    }),1);    

  new("/d/khojem/nomad/weapon/snake_fang")->move(this_object());
  force_me("wield fang in tail");
}

int query_kho_mon() { return 1;}

int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}

void die(object who) {
  object ob;

  ob = present("fang", this_object());
  if(ob)ob->remove();
  ::die(who);
  return;
}
