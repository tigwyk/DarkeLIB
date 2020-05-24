//  Wizard:   Khojem
//  Monster:  Earl of Vo'Sangor
//  File:     earl.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

int wielding;
void wield_sword();
void check_unwield();

void init() {
  ::init();
  if(this_player()->is_player() && !wielding)
  {
    wielding = 1;
    delayed_call("wield_sword", 4);
  }
  return;
}

create() {
  int zlevel;
  ::create();
    set_name("earl");
    set_id( ({ "earl", "earl of vo'sangor" }) );
    set_level(22);
    set_short("[22]Earl of Vo'Sangor");
    set_long("The Earl of Vo'Sangor is aged but appears still a fit fighter."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
	set_class("fighter");
	new("/d/khojem/port/weapon/khojem_sword")->move(this_object());
}

void wield_sword() {
  force_me("wield khojem sword in right hand");
  delayed_call("check_unwield", 60);
  return;
}

void check_unwield() {
  object *inv;

  if(!environment()) return;
  if(query_current_attacker()) return;
  inv = filter_array(all_inventory(environment()),
    (: (call_other($1, $2) || call_other($1, $3)) :),
    "is_player", "is_pet");
 /*
  * Gets the inventory of the room, cuts out all that is not a
  * player or a pet.
  */

  if(inv && sizeof(inv)) {
    delayed_call("check_unwield", 60);
    return;
  }
  force_me("unwield khojem sword");
  wielded = 0;
  return;
}

int query_kho_mon() { return 1;}

