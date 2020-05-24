//  Wizard:  Khojem
//  Nomad Camp - Shop Storage Room
//  shop_store.c

#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_short("Akmed wouldn't like it if he caught you in his backroom!");
  set_long(
	   "Akmed wouldn't like it if he caught you in his backroom!  "+
	   "Not much to speak of here.  Just a backroom used for storage.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_property("storage room", 1);
  return;
}

void reset() {
  object *inv, akmed;
  int i;
  ::reset();
  
  seteuid(getuid());
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) if(!living(inv[i])) inv[i]->remove();
  akmed = present("shopkeeper", 
		find_object_or_load("/d/khojem/nomad/camp/shop"));
  if(akmed) {
    message("info", "Akmed says in Common:  Effendi... Effendi, I have the best goods "+
	    "for you.  I will get them for you!", environment(akmed));
    call_out("finish_deliver", 20, akmed);
  }
  for(i = 1; i <=10; i++) {
    call_out("clone_ten", 2*i);
  }
  for(i = 1; i <=4; i++) {
    call_out("clone_four", 2*i);
  }
  return;
}

void finish_deliver(object akmed) {
  if(akmed)
    message("info", "Akmed says in Common:  The best of goods for you, effendi.",
	    environment(akmed));
  return;
}

void clone_ten() {
  object ob;

  ob = new("/wizards/diewarzau/obj/misc/rations_pack");
  ob->set_rations(10, 0);
}

void clone_four() {
  object ob;

  ob = new("/d/khojem/nomad/obj/compass");
  ob->move(this_object());
  ob = new("/d/damned/virtual/scimitar_5.weapon");
  ob->move(this_object());
  ob = new("/d/damned/virtual/scimitar_6.weapon");
  ob->move(this_object());
}
