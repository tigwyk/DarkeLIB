//  Wizard:   Khojem
//  Monster:  legionnaire
//  File:     legion3.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

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
    set_long("A massive, stone faced legionnaire stands glaring down at you."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set("gang bang",1);
    set_wimpy(0);
    add_money("silver", (200+random(99)));
	set_class("fighter");
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
}

int query_kho_mon() { return 1;}

