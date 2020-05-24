// guest bed 

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A guest bedroom");
    set("long", "This comfortable bedroom is made for one.  A small "+
      "bed sits against the wall, and a large painting decorates the "+
      "room from above.  To the south you can see a doorway leading "+
      "to a quiet hallway.");
    add_item("painting","You see a painting of elves and orcs in "+
      "combat.");
    add_exit("nhall3","south");
 
    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear a distant footsteps.");
}
void reset() {
  object mon;
   ::reset();
   if(!present("zombie")) 
      new(A1MON+"zombie")->move(this_object());
   if(!present("bed")) 
      new(A1OBJ+"smallbed")->move(this_object());
}
