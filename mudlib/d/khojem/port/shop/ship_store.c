//  Wizard:  Khojem
//  Shipwright's Storage Room
//  ship_store.c

#include <std.h>

inherit VAULT;

void clone_once();

void create() {
  ::create();
  set("short","If you get caught here!");
  set("long","This is shipwright's storage room.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_property("no scry", 1);
  set_property("no summon", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
  add_exit("/d/khojem/port/shop/shipwright", "south");
  add_invis_exit("south");
  set_door("storeroom door","/d/khojem/port/shop/shipwright", "south",
	   "a key that does not exist");
  set_open("storeroom door", 0);
  set_locked("storeroom door", 1);
  set_lock_level("storeroom door", 22);
  set_func("storeroom door","open","do_open");
  set_func("storeroom door","close","do_close");
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
  object *inv, bob;
  int i;

  ::reset();
  seteuid(getuid());
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  bob = present("shopkeeper", 
		find_object_or_load("/d/khojem/port/shop/shipwright"));
  if(bob) {
    message("info", "Shipwright says in Common: Wait a second.  I've got a new
"+
	    "shipment coming in...", environment(bob));
//    call_out("finish_deliver", 12, bob);
  }
//  for(i = 1;i <= 3;i++)
//    call_out("clone_once", i*2);
//  return;
}

//void finish_deliver(object bob) {
//  if(bob)
//    message("info", "Shipwright says in Common: It's all here now.",
//	    environment(bob));
//  return;
//}

void clone_once() {
  object ob;
  int i,j;

  seteuid(getuid());
  for(i = 1; i <= 2; i++) {
    ob = new("/d/damned/virtual/studded-leather-glove.armour");
    ob->move(this_object());
  }
  return;
}

int do_open() {
  remove_invis_exit("south");
  "/d/khojem/port/shop/shipwrigth"->remove_invis_exit("north");
  say(this_player()->query_cap_name()+" opens a storeroom door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("south");
  "/d/khojem/port/shop/shipwright"->add_invis_exit("north");
  say(this_player()->query_cap_name()+" slams a storeroom door shut.\n");
  return 1;
}

