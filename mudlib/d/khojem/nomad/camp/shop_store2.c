//  Wizard:  Khojem
//  Nomad Camp - Shop Storage Room 2
//  shop_store2.c

#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_short("Coco wouldn't like it if he caught you in his backroom!");
  set_long(
	   "Coco wouldn't like it if he caught you in his backroom!  "+
	   "Not much to speak of here.  Just a backroom used for storage.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_property("storage room", 1);
  return;
}

void reset() {
  object *inv, coco;
  int i;
  ::reset();
  
  seteuid(getuid());
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) if(!living(inv[i])) inv[i]->remove();
  coco = present("shopkeeper", 
		find_object_or_load("/d/khojem/nomad/camp/shop"));
  if(coco) {
    message("info", "Coco says in Common: Effendi! Don't buy from these other "+
	    "swine.  My goods are rare and of the finest quality!  You will see..."+
	    "wait while I get them arranged for you.",
	     environment(coco));
    call_out("finish_deliver", 20, coco);
  }
  for(i = 1; i <=10; i++) {
    call_out("clone_ten", 2*i);
  }
  for(i = 1; i <=4; i++) {
    call_out("clone_four", 2*i);
  }
  return;
}

void finish_deliver(object coco) {
  if(coco)
    message("info", "Coco says in Common:  Here they are, effendi.  "+
      "The finest goods... just for you!",
	    environment(coco));
  return;
}

void clone_ten() {
  object ob;

  ob = new("/std/obj/torch");
  ob->move(this_object());
  ob = new("/d/khojem/nomad/obj/glowstick");
  ob->move(this_object());
}

void clone_four() {
  object ob;

  ob = new("/d/damned/virtual/studded-leather-glove.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/gauntlet.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/iron-bracer.armour");
  ob->move(this_object());
}
