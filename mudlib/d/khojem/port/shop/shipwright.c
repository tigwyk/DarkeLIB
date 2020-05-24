//   Wizard:  Khojem
//   Vo'Sangor's Shipwright Shop
//   shipwright.c

#include <std.h>

inherit VAULT;

void init(){
     ::init();
     add_action("do_read","read");
}

void reset(){
  :: reset();
  set_open("storeroom door",0);
  set_locked("storeroom door",1);
  "/d/khojem/port/shop/ship_store"->set_open("storeroom door",0);
  "/d/khojem/port/shop/ship_store"->set_locked("storeroom door",1);
  add_invis_exit("north");
  "/d/khojem/port/shop/ship_store"->add_invis_exit("north");
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
//Basic mapping added by Tiny 1/20/2020
   set("short","   \n    \n   @--0\n    \n   \n Vo'Sangor Shipwright");
   set("long",
     "This is the shop of the Vo'Sangor Shipwright.  Here many fine vessels "+
     "are crafted and their keels layed down.   The interior of this room is hugh.  "
     "Its ceiling is vaulted and the room reaches back quite a ways.  A shipwright "+
     "must need alot of space to do his work.  Above the counter is a sign.\n   \n    \n   @--0\n    \n   \n "
   );
   set_items( ([
     ({ "storeroom door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     "sign": "It is a simple sign.  Perhaps you should read it?\n",
     ({ "wall", "walls", "ceiling" }) :
       "The walls are magnificently trussed with large timber that reach up to a "+
       "arched timber frame ceiling."
    ]));
   add_exit("/d/khojem/port/room/s12", "east");
   add_exit("/d/khojem/port/shop/ship_store", "north");
   add_invis_exit("north");
   set_door("storeroom door","/d/khojem/port/shop/ship_store",
     "north","key that does not exist");
   set_property("magic hold",70);
   set_lock_level("storeroom door", 22);
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
    "Vo'Sangor Shipwright is on vacation.\n"+
    "Try again later.\n"
  );
  say(this_player()->query_cap_name()+" reads a sign.\n",this_player());
  return 1;
}


void look_at_door() {
  if(query_open("storeroom door")) 
    write("The storeroom door is wide open.\n");
  else 
    write("The storeroom door is closed.\n");
  say(this_player()->query_cap_name()+" examines a storeroom door to the north.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/port/shop/ship_store"->remove_invis_exit("south");
  write("The storeroom door swings open.\n");
  say(this_player()->query_cap_name()+" opens a storeroom door on the north wall.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/port/shop/ship_store"->add_invis_exit("south");
  write("A storeroom door is closed.\n");
  say(this_player()->query_cap_name()+" closes a storeroom door.\n");
  return 1;
}

