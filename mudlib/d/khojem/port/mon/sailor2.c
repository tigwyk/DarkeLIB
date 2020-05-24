//  Wizard:   Khojem
//  Monster:  sailor
//  File:     sailor1.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  int zlevel;
  object obj;
  ::create();
    zlevel = 9 + random(2);
	set_overall_ac((zlevel-2));
if (zlevel == 9) set_short("[9]sailor");
else 
if (zlevel == 10) set_short("[10]sailor");
else
if (zlevel == 11) set_short("[11]sailor");
else
if (zlevel == 12) set_short("[12]sailor");
else set_short("[13]sailor");
    set_level(zlevel);
    set_exp(20000 + random(8000));
    zlevel = random(4);
    switch(zlevel) {
      case(0) : set_name("clean-cut sailor"); break;
      case(1) : set_name("veteran sailor"); break;
      case(2) : set_name("pipe-smoking sailor"); break;
      case(3) : set_name("bearded sailor"); break;
      default : set_name("another sailor"); break;
    }
    set_id( ({ "sailor", "mob" }) );
    set_long("The skin of the sailor's face has been roughened by "+
      "years of exposure to sun and sea."
      );
    set("race", "dwarf");
    set_stats("strength",110);
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", (600+random(99)));
	set_class("fighter");
	zlevel = random(10);
	if(zlevel == 0) {
	    obj = new("/d/khojem/port/obj/coffin_key");
	    obj->set_name("wet mop");
	    obj->set_id(({ "mop" }));
	    obj->set_short("wet mop");
	    obj->set_long("The wet mop has a long wooden handle.  It is used "+
	          "to swab the deck.\n");
	    obj->set_weight(40);
	    obj->set_value(10);
	    obj->move(this_object());
	}
	if((zlevel > 0) && (zlevel < 7)) {
	    zlevel = 4 + random(3);
	    obj = new("/d/damned/virtual/footman's-mace_"+zlevel+".weapon");
	    obj->set_id(({ "pin", "belay", "belay pin", "blunt" }));
	    obj->set_wc(8,"crushing");
	    obj->set("short","belay pin");
	    obj->set("long","A long wooden pin with a handle at on end. It "+
	          "is used to secure ropes for sails, but makes a fine weapon.");
	    obj->set_verb("bludgeon");
	    obj->move(this_object());
	    command("wield pin in right hand");
	  }
	  if(zlevel > 6) {
	    zlevel = 4 + random(3);
	    obj = new("/d/damned/virtual/dagger_"+zlevel+".weapon");
	    obj->set_id(({ "knife" }));
	    obj->set_wc(6,"impaling");
	    obj->set("short","knife");
	    obj->set("long","This short knife has a broad, thick blade.  Sailors "+
	      "use it to cut rope and carve wood shavings.");
	    obj->set("throwable",0);
	    obj->set_parry_bonus(-20);
	    obj->move(this_object());
	    command("wield knife in right hand");
	  }
}

int query_kho_mon() { return 1;}

