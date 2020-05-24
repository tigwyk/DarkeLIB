// music

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The music room");
    set("long", "This large room is sparsely decorated, and has a "+
      "harpsicord set against the eastern wall.  To the north you can "+
      "see a bookshelf, and to the west lies a doorway to an atrium.");
    add_item("bookshelf","There is a passage behind it!");
    add_exit("musicsecret","north");
    add_exit("whall3","south");
    add_exit("atrium","west");
 
    set_invis_exits( ({"north"}) );
    set_smell("default", "You sniff some dust and nearly sneeze.");
    set_listen("default", "You hear nothing.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("harpsicord"))
      new(A1OBJ+"harpsicord")->move(this_object());
}
