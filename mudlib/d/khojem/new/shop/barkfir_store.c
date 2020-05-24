//  Wizard:  Khojem
//  Fresh Grocer Storage
//  backfir_store.c

#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_short("If you get caught here!");
  set_long(
	   "The grocer stores his goods here.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("storage room", 1);
  return;
}

void reset() {
  object *inv, barkfir;
  int i;
  ::reset();
  
  seteuid(getuid());
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) if(!living(inv[i])) inv[i]->remove();
  barkfir = present("shopkeeper", 
		find_object_or_load("/d/khojem/new/shop/grocery_shop"));
  if(barkfir) {
    message("info", "Barkfir says in Common: Wait a second.  I've got a lot "+
	    "fresh food & goods for you...", environment(barkfir));
    call_out("finish_deliver", 20, barkfir);
  }
  for(i = 1; i <=10; i++) {
    call_out("clone_ten", 2*i);
  }
  for(i = 1; i <=4; i++) {
    call_out("clone_four", 2*i);
  }
  return;
}

void finish_deliver(object barkfir) {
  if(barkfir)
    message("info", "Barkfir says in Common: Ahh...  Here comes the fresh goods...",
	    environment(barkfir));
  return;
}

void clone_ten() {
  object ob;

  ob = new("/d/khojem/new/obj/melon");
  ob->move(this_object());
  ob = new("/d/khojem/new/obj/bread");
  ob->move(this_object());
  ob = new("/d/khojem/new/obj/berries");
  ob->move(this_object());
  ob = new("/std/obj/torch");
  ob->move(this_object());
}

void clone_four() {
  object ob;

  ob = new("/d/khojem/new/obj/mutton");
  ob->move(this_object());
  ob = new("/d/khojem/new/obj/pigsfeet");
  ob->move(this_object());
  ob = new("/d/khojem/new/obj/waterskin");
  ob->move(this_object());
}
