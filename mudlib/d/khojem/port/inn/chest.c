// Khojem
// stolen from Akkad
// Vo'Sangor Chest Shop
// chest.c

inherit "/std/vault";

private int open;

void init() {
    ::init();
  add_action("do_button","push");
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("Dovan") && open) {
      new("/d/khojem/port/inn/dovan")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/khojem/port/inn/chest_store", "west");
   set_door("wooden door", "/d/khojem/port/inn/chest_store", 
     "west","port_chest_store");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   set_lock_level("wooden door", 40);
   add_exit("/d/khojem/port/inn/main_room", "south");
   set_door("south door", "/d/khojem/port/inn/main_room",
     "south","port_chest_shop");
   set_open("south door", 1);
   set_locked("south door", 0);
   open = 1;
   set("short","The Vo'Sangor Chest Shop");
   set("long",
     "This is the Vo'Sangor Chest Shop.  "
     "Many of DarkeMud's Adventures purchase chests and safes "
     "here to store items past reboots.  You must store "
     "the chests in special rooms that save items (ex. the inn).  "
     "Chests must be closed to store items.  There is a sign "
     "on the wall\n"
   );
   set_items( ([
     "sign": (: call_other, this_object(), "read_sign" :),
     "wooden door" : "It made of aged teak and very sturdy.",
     "south door" : "It is a large, weatherbeaten wooden door.",
     "door" : "There is an south door and a wooden door"
   ]) );
   set_open_function("open_door","04:30:00");
   set_close_function("close_door", "19:00:00");
}

int read_sign() {
  string msg;

  msg =
"The following chests are available:\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"Small Chest          Stores 5 items (2000 coins weight)\n"
"Large Chest          Stores 8 items (3200 coins weight)\n"
"Storage Locker       Stores 25 items (15000 coins weight)\n"
"                     Can be used to store inventory of shops\n"
"Safe                 Can store about 100,000 coins (money only)\n"
"\n'say dovan, help' for assistance.\n";
  this_player()->more(explode(msg, "\n"));
  return 1;
}

void open_door() {
  set_locked("south door", 0);
  set_open("south door", 1);
  call_other("/d/khojem/port/inn/main_room", 
    "set_locked","north door", 0);
  call_other("/d/khojem/port/inn/main_room",
    "set_open","north door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("dovan", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave.", inv[i]);
      find_object_or_load("/d/khojem/port/inn/main_room");
      inv[i]->move_player("/d/khojem/port/inn/main_room");
    }
  }
  set_open("south door", 0);
  set_locked("south door", 1);
  call_other("/d/khojem/port/inn/main_room",
    "set_open","north door", 0);
  call_other("/d/khojem/port/inn/main_room",
    "set_locked","north door", 1);
   open = 0;
}
int do_button(string str) {
  if(str != "button") { return 0; }
   find_object_or_load("/d/khojem/port/inn/locksmith");
   this_player()->move_player("/d/khojem/port/inn/locksmith");
   return 1;
}

