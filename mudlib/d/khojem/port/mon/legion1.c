//  Wizard:   Khojem
//  Monster:  legionnaire
//  File:     legion1.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("legionnaire");
    set_id( ({ "legionnaire", "guard", "legion" }) );
    set_level(17);
    set_exp(200000);
    set_short("[17]legionnaire");
    set_long("A massive, stone faced legionnaire guards the mansion "+
      "from intruders."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", (800+random(99)));
	set_class("fighter");
	new("/d/khojem/port/weapon/falchion")->move(this_object());
	force_me("wield sword in right hand");
    new("/d/damned/virtual/corslet.armour")->move(this_object());
    force_me("wear corslet");
    new("/d/khojem/port/armor/legion_helm")->move(this_object());
    force_me("wear helmet");
    new("/d/khojem/port/armor/beaver")->move(this_object());
    force_me("wear beaver");    
}

int query_kho_mon() { return 1;}

void catch_tell(string str) {
  string a, b;
  object obj;
  if(sscanf(str,"%s attacks %s",a,b) == 2) {
    a = lower_case(a);
    obj = present(a,environment(this_object()));
    if(obj) {
      if(interact("legionnaire",b)) {
        obj -> add_follower(this_object());
        force_me("kill "+a);
        return;
      }
    }
  }
}
