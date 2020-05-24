//   Wizard:  Khojem
//   Vo'Sangor's Main Shop
//   gedrak_shop.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
     add_action("do_read","read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","west");
    }
}

void reset(){
  :: reset();
  set_open("storeroom door",0);
  set_locked("storeroom door",1);
  "/d/khojem/port/shop/gedrak_store"->set_open("storeroom door",0);
  "/d/khojem/port/shop/gedrak_store"->set_locked("storeroom door",1);
  add_invis_exit("west");
  "/d/khojem/port/shop/gedrak_store"->add_invis_exit("east");
   if(!present("gedrak")) {
      new("/d/khojem/port/shop/gedrak")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   set("short","Gedrak's Goods and Supplies");
   set("long",
     "Gedrak's Goods and Supplies is the spot to shop in Vo'Sangor.  Here "+
     "is where much of the trade from the port is sold.  Many goods from far away "+
     "lands can be purchased at this shop.  The racks are filled and items are on "+
     "display for your examination.  "+
     "Above the counter is a sign to help customers."
   );
   set_items( ([
   ({ "rack","racks" }) :
     "They are simple wooden racks to hold goods for sale.\n"+
     "Gedrak keeps a close eye on his goods to avoid loss.\n",
     "counter" : "A simple, wooden countertop to package goods once sold.\n",
     ({ "storeroom door" }) : 
// TLNY 2020 Removed bad call_other error room works now
        //(: call_other, this_object(), "look_at_door" :),
    // "sign": "It looks like a brass sign.  Perhaps you should read it?\n",
     //({ "wall", "walls" }) :
       "Not much to see.  Gedrak keeps a simple shop and does not adorn the walls. "+
       "A door can be seen on the west wall."
    ]));
   add_exit("/d/khojem/port/room/s03", "east");
   add_exit("/d/khojem/port/shop/gedrak_store", "west");
   add_invis_exit("west");
   set_door("storeroom door","/d/khojem/port/shop/gedrak_store",
     "west","gedrak key");
   set_property("magic hold",60);
   set_lock_level("storeroom door", 25);
   set_open("storeroom door",0);
   set_locked("storeroom door",1);
   set_func("storeroom door","open","do_open");
   set_func("storeroom door","close","do_close");
}

int do_read(string str){
  if(!str) {
    notify_fail("What is it you want to read?\n");
    return 0;
  }
  if(str != "sign") {return 0;}
  write("The brass sign reads:\n"+
    "Gedraks's Goods and Supplies\n"+
    "The choice to meet all your shopping needs.\n"+
    "'say gedrak, help' for assistance.\n"
  );
  say(this_player()->query_cap_name()+" reads a sign.\n",this_player());
  return 1;
}


void look_at_door() {
  if(query_open("storeroom door")) 
    write("The storeroom door is wide open.\n");
  else 
    write("The storeroom door is closed.\n");
  say(this_player()->query_cap_name()+" examines a storeroom door to the west.\n");
}

int do_open() {
  remove_invis_exit("west");
  "/d/khojem/port/shop/gedrak_store"->remove_invis_exit("east");
  write("The storeroom door swings open.\n");
  say(this_player()->query_cap_name()+" opens a storeroom door on the west wall.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("west");
  "/d/khojem/port/shop/gedrak_store"->add_invis_exit("east");
  write("A storeroom door is closed.\n");
  say(this_player()->query_cap_name()+" closes a storeroom door.\n");
  return 1;
}

