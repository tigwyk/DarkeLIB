inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_slum1", "north");
    add_exit("/d/damned/guilds/thief/thief","manhole");
    set("short","   0\n   | \n   @   \n     \n   \nDeeper inside the Slums");
    set("long","   0\n   | \n   @   \n     \n   \nYou are deeper inside the slums now.  You see some beggars "
	"lying by the side of the street. There are other people here "
	"that look like beggars, but there is something wrong "+
"about them. They are eyeing you suspiciously\n" 
        "In the center of the road is a large manhole.");
  set_invis_exits( ({"manhole"}) );
  set_items( ([
    "beggars" : "The dirty beggars are hiding in the shadows.",
    "manhole" : "The thick iron manhole is in the center of the slum.",
	"people":"They look very thievish. Perhaps you are not in a wise place."
  ]) );
  set_search("manhole","You notice several scratches along the edge. "
      "Looks like it has been moved recently.");
}

void init() {
	::init();
	add_action("open","open");
}

int open(string str) {
	if(str != "manhole") {
	notify_fail("Open what?\n");
	return 0;
}
write("You figure that if you exit 'manhole', something may happen!");
return 1
;
}
