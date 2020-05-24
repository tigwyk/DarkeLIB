// music secret

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "A secret room");
    set("long", @ext There doesn't seem to be much to this room.  Maybe 
      the owner of the mansion planned on adding something later. 
      You see many shelves holding tabulature, and a secret exit 
       to the south.

    @
    |
    0
ext);
    add_item("shelves","The wooden shelves look old.");
    add_item("tabulature","There is a passage behind it!");
    add_exit("music","south");
 
    set_smell("default", "You sniff some dust and nearly sneeze.");
    set_listen("default", "You hear a few musical notes.");
}
