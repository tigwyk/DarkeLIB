// Wizard:  Khojem
// zalrag's magic shop
// zalrag_shop.c

inherit "/std/vault";

private int open;

void init() {
   ::init();
   add_action("read_sign","read");
}

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("zalrag") && open) {
      new("/d/khojem/port/shop/zalrag")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   add_exit("/d/khojem/port/room/t1", "west");
   add_exit("/d/khojem/port/shop/zalrag_store", "south");
   set_door("wooden door", "/d/khojem/port/shop/zalrag_store", "south",
	    "a non-existent key");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_door("west door", "/d/khojem/port/room/t1", "west",
	    "a non-existent key");
   set_open("west door", 1);
   set_locked("west door", 0);
   set_lock_level("wooden door", 22);
   set("short","Zalrag's House of Magic");
   set_long(
     "This is Zalrag's House of Magic.  The entire place is in disarray.  "+
     "Dusty, spent potion flasks and vials line the shelves.  Many are covered "+
     "with cobwebs.  There is a sign on the wall\n"
     "To the south is a sturdy wooden door.");
   set_items(([
   ({ "sign" }) :
        "The sign is old and covered with dust.  Maybe you can read it?",
   ({ "wooden door" }) : "It looks very sturdy.",
   ({ "west door" })   : "It is a large wooden door.",
   ({ "door" }) : "There is an west door and a wooden door" ]) );
   set_open_function("open_door", "20:30:00");
   set_close_function("close_door", "06:30:00");
}

void open_door() {
  set_locked("west door", 0);
  set_open("west door", 1);
  call_other("/d/khojem/port/room/t1", "set_locked",
	"east door", 0);
  call_other("/d/khojem/port/room/t1", "set_open",
	"east door", 1);
  open = 1;
  this_object()->reset();
  return;
}

int read_sign(string str) {
  if(str!="sign") { return 0; }
  write("Zalrag's House of Magic\n"
  "\nHere you can buy scrolls, vials, and potions.\n");
  return 1;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("zalrag", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You gotta go!", inv[i]);
      inv[i]->move(find_object_or_load("/d/khojem/port/room/t1"));
    }
  }
  set_open("west door", 0);
  set_locked("west door", 1);
  call_other("/d/khojem/port/room/t1", "set_open", 
    "east door", 0);
  call_other("/d/khojem/port/room/t1", "set_locked", 
    "east door", 1);
  open = 0;
}

