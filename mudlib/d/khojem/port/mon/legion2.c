//  Wizard:   Khojem
//  Monster:  legionnaire
//  File:     legion2.c

#include <std.h>
inherit MONSTER;

int is_followed;

int query_kho_mon();
int query_follower();

create() {
  int zlevel;
  ::create();
    set_name("legionnaire");
    set_id( ({ "legionnaire", "guard", "legion" }) );
    zlevel = 16 + random(5);
if (zlevel == 16) set_short("[16]legionnaire");
else 
if (zlevel == 17) set_short("[17]legionnaire");
else
if (zlevel == 18) set_short("[18]legionnaire");
else
if (zlevel == 19) set_short("[19]legionnaire");
else
if (zlevel == 20) set_short("[20]legionnaire");
else set_short("[21]legionnaire");
    set_level(zlevel);
    zlevel = 200000 + (5000*zlevel);
    set_exp(zlevel);
    set_long("A massive, stone faced legionnaire stands glaring down at you."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", (200+random(99)));
	set_class("fighter");
	set_overall_ac(20);
	set_wielding_limbs(({ "right hand", "left hand" }));
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
	zlevel = random(3);
    if(zlevel == 0) {
   	  new("/d/khojem/port/weapon/flail")->move(this_object());
	  force_me("wield flail in right hand");
	}
    if(zlevel == 1) {
	  new("/d/khojem/port/weapon/trident")->move(this_object());
	  force_me("wield trident in right hand and left hand");
	}
    if(zlevel == 2) {
	  new("/d/khojem/port/weapon/falchion")->move(this_object());
	  force_me("wield falchion in right hand");
	 }
    new("/d/damned/virtual/corslet.armour")->move(this_object());
    force_me("wear corslet");
    new("/d/khojem/port/armor/legion_helm")->move(this_object());
    force_me("wear helmet");
    new("/d/khojem/port/armor/beaver")->move(this_object());
    force_me("wear beaver");
    is_followed = 0;   
}

int query_kho_mon() { return 1;}

int query_follower() { return is_followed; }

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 90) { return 0; }
    this_player() -> add_follower(this_object());
    is_followed = 1;
    this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}
