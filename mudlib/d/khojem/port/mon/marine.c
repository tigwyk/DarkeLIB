//  Wizard:   Khojem
//  Monster:  marine
//  File:     marine.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  int zlevel;
  object obj;
  ::create();
    zlevel = 12 + random(2);
	set_overall_ac((zlevel-2));
if (zlevel == 12) set_short("[12]marine");
else 
if (zlevel == 13) set_short("[13]marine");
else
if (zlevel == 14) set_short("[14]marine");
else
if (zlevel == 15) set_short("[15]marine");
else set_short("[11]marine");
    set_level(zlevel);
    zlevel = random(4);
    switch(zlevel) {
      case(0) : set_name("square-jawed marine"); break;
      case(1) : set_name("veteran marine"); break;
      case(2) : set_name("burley marine"); break;
      case(3) : set_name("bearded marine"); break;
      default : set_name("another marine"); break;
    }
    set_id( ({ "marine", "mob" }) );
    set_long("The marine looks like he ready to tangle."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
   set_skill("blunt",110);
   set_skill("blade",110);
   set_stats("strength",110);
   set_skill("two handed polearm",110);
    add_money("silver", (900+random(99)));
	set_class("fighter");
	zlevel = random(10);
	if(zlevel == 0) {
	    obj = new("//d/damned/virtual/short-sword_6.weapon");
	    obj->set_name("cutlass");
	    obj->set_id(({ "cutlass", "sword", "blade" }));
	    obj->set_short("cutlass");
	    obj->set_long("The cutlass is a curved short sword.  It is "+
	      "ideally suited for close-quarters fighting on deck.\n");
	    obj->set_weight(40);
	    obj->set_value(110);
            obj->set_wc(12,"cutting");
	    obj->set_wc(6,"impaling");
	    obj->set_ac(4);
	    obj->move(this_object());
	    command("wield cutlass in right hand");
	}
	if((zlevel > 0) && (zlevel < 7)) {
	    zlevel = 4 + random(3);
	    obj = new("/d/damned/virtual/footman's-mace_"+zlevel+".weapon");
	    obj->set_id(({ "baton", "wood baton", "blunt" }));
            obj->set_wc(12,"crushing");
	    obj->set("short","wood baton");
	    obj->set("long","A long wooden baton with a handle at on end.");
	    obj->set_verb("bludgeon");
	    obj->set_material("/wood/oak");
	    obj->move(this_object());
	    command("wield baton in right hand");
	  }
	  if(zlevel > 6) {
	    zlevel = 4 + random(3);
	    obj = new("/d/damned/virtual/spear_"+zlevel+".weapon");
	    obj->move(this_object());
	    command("wield spear in right hand and left hand");
	  }
}

int query_kho_mon() { return 1;}

