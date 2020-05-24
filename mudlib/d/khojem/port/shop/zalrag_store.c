// Wizard:  Khojem
// Zalrag's Shop Storeroom
// zalrag_store.c

#include <std.h>

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long(
	   "This is the storage room for the Zalrag's House of Magic. Lots of "
	   "stuff lie about.");
  set_property("light", 0);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("storage room", 1);
  add_exit("/d/khojem/port/shop/zalrag_shop", "north");
  set_door("wooden door", "/d/khojem/port/shop/zalrag_shop", "north",
	   "a non-existent key");
  set_open("wooden door", 0);
  set_locked("wooden door", 1);
  set_lock_level("wooden door", 22);
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) ==
this_object()) inv[i]->remove();
  return;
}

void reset() {
  object *inv, bob, ob;
  int i;

  ::reset();
  seteuid(getuid());
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  bob = present("shopkeeper", 
		find_object_or_load("/d/khojem/port/shop/zalrag_shop"));
  if(bob) {
    message("info", "Zalrag says in Common: Yeah, yeah, yeah!  I've got a "+
	  "new shipment coming in...", environment(bob));
    call_out("finish_deliver",5, bob);
  }
  i = 5;
  while(i--) {
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a white potion", "healing_potion",
         "/wizards/diewarzau/obj/misc/heal_func",100);
    ob->set_value(480);
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/bag_of_holding");
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/wizards/diewarzau/obj/misc/herb_func",70);
    ob->set_value(50);
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/wizards/diewarzau/obj/misc/herb_func",70);
    ob->set_value(50);
    ob->move(this_object());
    new("/wizards/diewarzau/obj/misc/spell_scroll")->move(this_object());
    new("/wizards/diewarzau/obj/misc/small_vial")->move(this_object());
    if(i==1) {
      ob=new("/wizards/duridian/magic/misc/strength_potion");
      ob->move(this_object());
      ob=new("/wizards/duridian/poison/plants/elven_ash");
      ob->move(this_object());
      ob=new("/wizards/duridian/poison/plants/choker_vine");
      ob->move(this_object());
    }
  }
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Zalrag says in Common: Ok, sport.  It's all here now.",
	    environment(bob));
  return;
}

