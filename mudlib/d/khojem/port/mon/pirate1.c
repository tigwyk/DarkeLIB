//  Wizard:   Khojem
//  Monster:  pirate
//  File:     pirate1.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  int zlevel;
  object obj;
  ::create();
    zlevel = 8 + random(3);
	set_overall_ac((zlevel-2));
    set_level(zlevel);
    zlevel = 2400 * zlevel;
    set_exp(zlevel);
    zlevel = random(4);
    switch(zlevel) {
      case(0) : set_name("scuffy pirate"); break;
      case(1) : set_name("toothless pirate"); break;
      case(2) : set_name("cheroot-smoking pirate"); break;
      case(3) : set_name("bearded pirate"); break;
      default : set_name("another sailor"); break;
    }
    set_id( ({ "pirate", "mob" }) );
    set_short("pirate");
    set_long("The skin of the pirate's face has been roughened by "+
      "years of exposure to sun and sea."
      );
    set("race", "dwarf");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", (900+random(99)));
	set_class("fighter");
	set_wielding_limbs(({"right hand"}));
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
	zlevel = random(10);
	if(zlevel==0){
	    zlevel = 3 + random(3);
	    obj = new("//d/damned/virtual/short-sword_"+zlevel+".weapon");
	    obj->set_name("cutlass");
	    obj->set_id(({ "cutlass", "sword", "blade" }));
	    obj->set_short("cutlass");
	    obj->set_long("The cutlass is a curved short sword.  It is "+
	      "ideally suited for close-quarters fighting on deck.\n");
	    obj->set_weight(40);
	    obj->set_value(110);
	    obj->set_wc(9,"cutting");
	    obj->set_wc(6,"impaling");
	    obj->set_ac(4);
	    obj->move(this_object());
	    command("wield cutlass in right hand");
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
	    zlevel = 2 + random(3);
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


int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 80) { return 0; }
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}

