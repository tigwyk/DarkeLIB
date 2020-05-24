//   Wizard:  Khojem
//   Vo'Sangor's Caravan Shop
//   droblek_shop.c

#include <std.h>

inherit VAULT;

private int open;

int no_exit() { return 1;}

void init() {
    ::init();
     add_action("do_read","read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
    }
}

void reset(){
  :: reset();
  set_open("storeroom door",0);
  set_locked("storeroom door",1);
  "/d/khojem/port/shop/droblek_store"->set_open("storeroom door",0);
  "/d/khojem/port/shop/droblek_store"->set_locked("storeroom door",1);
  add_invis_exit("north");
  "/d/khojem/port/shop/droblek_store"->add_invis_exit("south");
   seteuid(getuid());
   if(!present("droblek") && open) {
      new("/d/khojem/port/shop/droblek")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   set("short","Droblek's Caravan Outfitters");
   set("long",
     "Droblek's Caravan Outfitters provides all the necessary items for the hostile "+
     "world of DarkeMud.  The goods unloaded at "+
     "the docks needs to be transported overland by caravans.  Here is where both "+
     "the caravan captain and the adventure come to acquire goods.  "+
     "Above the counter is a sign to help customers."
   );
   set_items( ([
     ({ "storeroom door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     "sign": "It looks like a brass sign.  Perhaps you should read it?\n",
     ({ "wall", "walls" }) :
       "Not much to see.  Droblek keeps a simple shop and does not adorn the walls. "+
       "A door can be seen on the north wall.",
     ({ "south door" })   : "It is a large wooden door.",
     ({ "door" }) : "There is an south door and a storeroom door",
    ]));
   add_exit("/d/khojem/port/room/s03", "south");
   add_exit("/d/khojem/port/shop/droblek_store", "north");
   add_invis_exit("north");
   set_door("storeroom door","/d/khojem/port/shop/droblek_store",
     "north","droblek key");
   set_property("magic hold",70);
   set_lock_level("storeroom door", 29);
   set_open("storeroom door",0);
   set_locked("storeroom door",1);
   set_func("storeroom door","open","do_open");
   set_func("storeroom door","close","do_close");
   open = 1;
   set_door("south door", "/d/khojem/port/room/s03", "south",
	    "a non-existent key");
   set_open("south door", 1);
   set_locked("south door", 0);
   set_open_function("open_door", "06:15:00");
   set_close_function("close_door", "22:15:00");
}

int do_read(string str){
  if(!str) {
    notify_fail("What is it you want to read?\n");
    return 0;
  }
  if(str != "sign") {return 0;}
  write("The brass sign reads:\n"+
    "Droblek's Caravan Outfitters\n"+
    "The choice to meet all your shopping needs.\n"+
    "'say droblek, help' for assistance.\n"
  );
  say(this_player()->query_cap_name()+" reads a sign.\n",this_player());
  return 1;
}

void open_door() {
  set_locked("south door", 0);
  set_open("south door", 1);
  call_other("/d/khojem/port/room/s03", "set_locked",
	"north door", 0);
  call_other("/d/khojem/port/room/s03", "set_open",
	"north door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("droblek", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave now!", inv[i]);
      inv[i]->move(find_object_or_load("/d/khojem/port/room/s03"));
    }
  }
  set_open("south door", 0);
  set_locked("south door", 1);
  call_other("/d/khojem/port/room/s03", "set_open", 
    "north door", 0);
  call_other("/d/khojem/port/room/s03", "set_locked", 
    "north door", 1);
  open = 0;
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
  "/d/khojem/port/shop/droblek_store"->remove_invis_exit("south");
  write("The storeroom door swings open.\n");
  say(this_player()->query_cap_name()+" opens a storeroom door on the north wall.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/port/shop/droblek_store"->add_invis_exit("south");
  write("A storeroom door is closed.\n");
  say(this_player()->query_cap_name()+" closes a storeroom door.\n");
  return 1;
}

