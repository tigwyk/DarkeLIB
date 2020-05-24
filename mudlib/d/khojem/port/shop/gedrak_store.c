//  Wizard:  Khojem
//  Gedrak's Storage Room
//  gedrak_store.c

#include <std.h>
#define MY_INV ({ "pack", "sextant", "vial", "press", "torch" })
#define MAX_INV 25

#include <std.h>

inherit VAULT;

void clone_once();

void create() {
  ::create();
  set("short","If you get caught here!");
  set("long","This is Gedrak's storage room.  He keeps a good inventory of goods.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_property("no scry", 1);
  set_property("no summon", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
  add_exit("/d/khojem/port/shop/gedrak_shop", "east");
  add_invis_exit("east");
  set_door("storeroom door", "/d/khojem/port/shop/gedrak_shop", "east",
	   "a key that does not exist");
  set_open("storeroom door", 0);
  set_locked("storeroom door", 1);
  set_lock_level("storeroom door", 25);
  set_func("storeroom door","open","do_open");
  set_func("storeroom door","close","do_close");
  return;
}

int my_inv_filter(object item) {
  int i;

  i = sizeof(MY_INV);
  while(i--) if(item->id(MY_INV[i])) return 1;
  return 0;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) ==
this_object()) inv[i]->remove();
  return;
}

void reset() {
  object bob, *inv;
  int i;

  ::reset();
  seteuid(getuid());
  inv = filter_array(all_inventory(this_object()), "my_inv_filter",
      this_object());
  call_out("remove_all", 5, inv);
  inv = all_inventory(this_object());
  if(sizeof(inv) > MAX_INV) {
    for(i=MAX_INV-1;i<sizeof(inv);i++) inv[i]->remove();
  }
  bob = present("shopkeeper", 
                find_object_or_load("/d/damned/akkad/ak_shop4"));
  if(bob) {
   message("info", "Gedrak says in Common: Wait a second while I check my inventory.  "+
	    "I have many fine goods for you...", environment(bob));
    call_out("finish_deliver", 8, bob);
  }
  clone_once();
  return;
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Gedrak says in Common: Ahh...  My inventory should please you...",
	    environment(bob));
  return;
}

void clone_once() {
  object ob;
  int i;

  seteuid(getuid());
  for(i=1; i <= 10; i++) {
    ob = new("/std/obj/torch");
    ob->move(this_object());
    ob = new("/wizards/diewarzau/obj/misc/small_vial");
    ob->move(this_object());
    ob = new("/wizards/shadowraith/obj/misc/oil");
    ob->move(this_object());
    if(i <= 7) {
      ob = new("/wizards/diewarzau/obj/misc/rations_pack");
      ob->set_rations(10, 0);
      ob->move(this_object());
      ob = new("/wizards/diewarzau/obj/misc/rations_pack");
      ob->set_rations(5, 1);
      ob->move(this_object());
      ob = new("/wizards/diewarzau/obj/misc/sextant");
      ob->move(this_object());
    }
    if(i <= 5) {
      ob = new("/wizards/diewarzau/obj/misc/herb_press");
      ob->move(this_object());
      ob = new("/wizards/shadowraith/obj/misc/lantern");
      ob->move(this_object());
      ob = new("/d/khojem/new/obj/waterskin");
      ob->move(this_object());
    }
  }
  return;
}

int do_open() {
  remove_invis_exit("east");
  "/d/khojem/port/shop/gedrak_shop"->remove_invis_exit("west");
  say(this_player()->query_cap_name()+" opens a storeroom door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("east");
  "/d/khojem/port/shop/gedrak_shop"->add_invis_exit("west");
  say(this_player()->query_cap_name()+" slams a storeroom door shut.\n");
  return 1;
}

