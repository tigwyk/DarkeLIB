//  Wizard:  Khojem
//  Nomad Camp - Shop Storage Room 3
//  shop_store3.c

#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_short("Merz wouldn't like it if he caught you in his backroom!");
  set_long(
	   "Merz wouldn't like it if he caught you in his backroom!  "+
	   "Not much to speak of here.  Just a backroom used for storage.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_property("storage room", 1);
  return;
}

void reset() {
  object *inv, merz;
  int i;
  ::reset();
  
  seteuid(getuid());
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) if(!living(inv[i])) inv[i]->remove();
  merz = present("shopkeeper", 
		find_object_or_load("/d/khojem/nomad/camp/shop"));
  if(merz) {
    message("info", "Merz says in Common: Ahh!  Effendi, I have some goods "+
	    "just for you.  One moment while I fetch them!", environment(merz));
    call_out("finish_deliver", 20, merz);
  }
  for(i = 1; i <=10; i++) {
    call_out("clone_ten", 2*i);
  }
  for(i = 1; i <=4; i++) {
    call_out("clone_four", 2*i);
  }
  return;
}

void finish_deliver(object merz) {
  if(merz)
    message("info", "Merz says in Common:  Feast your eyes on this, effendi.",
	    environment(merz));
  return;
}

void clone_ten() {
  object ob;

  ob = new("/d/khojem/nomad/armor/sunvisor");
  ob->move(this_object());
  ob = new("/d/khojem/nomad/obj/bag");
  ob->move(this_object());
}

void clone_four() {
  object ob;
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a white potion", "healing_potion",
               "/wizards/diewarzau/obj/misc/heal_func",
               100);
    ob->set_value(480);
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("an alabaster potion", "alabaster_potion",
               "/wizards/diewarzau/obj/misc/heal_func",
               200);
    ob->set_value(2100);
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/wizards/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/wizards/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
}
