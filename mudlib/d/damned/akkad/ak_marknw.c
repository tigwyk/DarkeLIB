inherit "std/vault";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_shop1", "west");
    set_door("west door", "/d/damned/akkad/ak_shop1", "west", "ak shop1");
    set_open("west door", 1);
    set_locked("west door", 0);
    add_exit("/d/damned/akkad/ak_victory5", "east");
//    add_exit("/d/damned/akkad/ak_shop2", "north"); 
//	  set_open("north door", 1);
//	  set_locked("north door", 0);
	  set_open("west door", 1);
	  set_locked("west door", 0);
	  set_open_function("open_door", "2:00:00");
    set_close_function("close_door", "18:00:00");
    add_exit("/d/damned/akkad/ak_haven4", "south");
    set("short","   \n    \n0--@--0\n   | \n   0\nNorthwest corner of Market Square");
    set("long",@ext You are standing on the northwest corner of Market Square.
	There are shops to the north and west of you.  The noisy salesmen 
	are pestering you to come inside and take a look.
  
 S--@--0
    |
    0
	There are two signs here. 
ext);
//    add_item("sign 1", "This sign points north.\n\n"
//"General Store has moved to the southwest corner.");
    add_item("sign 2", "This sign points west.\n"
"******************\n"
"  The Moneychanger\n"
"******************\n");
}

void close_door() {
  call_other("/d/damned/akkad/ak_shop1", "close_door");
  return;
}

void open_door() {
  call_other("/d/damned/akkad/ak_shop1", "open_door");
  return;
}
