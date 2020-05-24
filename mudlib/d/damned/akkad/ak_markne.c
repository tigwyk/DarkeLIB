inherit "std/vault";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_victory5", "west");
    add_exit("/d/damned/akkad/ak_shop7", "east");
    add_exit("/d/damned/akkad/ak_shop8", "north");
    set_door("north door", "/d/damned/akkad/ak_shop8", "north",
	     "ak shop8");
	  set_open("north door", 1);
	  set_locked("north door", 0);
	  set_door("east door", "/d/damned/akkad/ak_shop7", "east",
	     "ak shop7");
	  set_open("east door", 1);
	  set_locked("east door", 0);
          set_open_function("open_door", "5:00:00");
    set_close_function("close_door", "16:30:00");
    add_exit("/d/damned/akkad/ak_haven5", "south");
    set_items( ([ "east door": "It looks quite sturdy", "north door" : "It looks quite sturdy.",
	"door" : "There is an east door and a north door." ]));
    set("short","   0\n   | \n0--@--0\n    \n   \nNortheast corner of Market Square");
    set("long",@ext You are standing on the northeast corner of Market Square.
	There are shops to the north and east of you.  The noisy salesmen
	here have apparently been killed by the irate shopkeepers for driving 
	away business
    S   
    |   
 0--@--S
    
	There are two signs here. 
ext);
    add_item("sign 1", "This sign points north.\n"
"*********************\n"
" The Armoursmith Shop\n"
"*********************\n");
    add_item("sign 2", "This sign points east.\n"
"**************************\n"
"   The Weaponsmith Shop\n"
"**************************\n");
    return;
}

void close_door() {
  call_other("/d/damned/akkad/ak_shop8", "close_door");
  call_other("/d/damned/akkad/ak_shop7", "close_door");
  return;
}

void open_door() {
  call_other("/d/damned/akkad/ak_shop8", "open_door");
  call_other("/d/damned/akkad/ak_shop7", "open_door");
  return;
}

