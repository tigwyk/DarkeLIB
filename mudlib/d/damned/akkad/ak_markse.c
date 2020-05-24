inherit "std/vault";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_victory4", "west");
    add_exit("/d/damned/akkad/ak_shop6", "east");
    add_exit("/d/damned/akkad/ak_haven5", "north"); 
    add_exit("/d/damned/akkad/ak_shop5", "south");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nSoutheast corner of Market Square");
    set("long",@ext You are standing on the southeast corner of Market Square. 
	There are shops to the south and east of you.  The salesmen are 
	surprisingly quiet here.  Possibly the mark of quality establishments?
    0   
    |   
 0--@--S
    |
    S
	There are two signs here. 
ext);
    add_item("sign 1", "This sign points south.\n"
    "*************************\n"
    "        Magic Shop\n"
    "*************************\n");
    add_item("sign 2", "This sign points east.\n"
    "*********************************\n"
    "          The Chest Shop\n"
    "*********************************\n");
    add_item("door", "There is an east door and a south door.");
    add_item("doors", "There is an east door and a south door.");
    add_item("east door", "It looks pretty sturdy.");
    add_item("south door", "It looks pretty sturdy.");
    set_door("east door", "/d/damned/akkad/ak_shop6", "east",
	     "ak shop7");
	  set_open("east door", 1);
	  set_locked("east door", 0);
	  set_door("south door", "/d/damned/akkad/ak_shop5", "south",
	     "ak shop7");
	  set_open("south door", 1);
	  set_locked("south door", 0);
    set_open_function("open_door", "5:30:00");
    set_close_function("close_door", "16:30:00");
}

void close_door() {
  call_other("/d/damned/akkad/ak_shop6", "close_door");
  call_other("/d/damned/akkad/ak_shop5", "close_door");
  return;
}

void open_door() {
  call_other("/d/damned/akkad/ak_shop6", "open_door");
  call_other("/d/damned/akkad/ak_shop5", "open_door");
  return;
}


void reset() {
  ::reset();
  if(!present("key rack"))
        new("/d/damned/akkad/obj/misc/key_rack")->move(this_object());
  return;
}
