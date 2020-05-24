//      Wizard:  Khojem
//      nursery 6
//      nursery.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("child")) 
    new("/d/khojem/new/mon/child")->move(this_object());
    new("/d/khojem/new/mon/child")->move(this_object());
    new("/d/khojem/new/mon/child")->move(this_object());
    new("/d/khojem/new/mon/child")->move(this_object());
    new("/d/khojem/new/mon/child")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   0\n   | \n   @   \n     \n    \nA nursery");
    set("long", "You are in a small nursery for the elven children.  "+
      "The hut is well maintained and several small chairs and desks "+
      "are arranged here.\n   0\n   | \n   @   \n     \n    \n"
    );
    add_exit("/d/khojem/new/room/annex6","north");
    set_items(([
     ({ "hut","room", "nursery" }) :
        "The nursery is a small hut with clean floors.  Large windows allow  "+
        "plenty of light and fresh air for the youngsters.",
     ({ "chair" , "chairs", "desk", "desks", "table", "tables" }) :
        "The small, wooden chairs are made to accomodate the young wood-elves.",
     ({ "window", "windows" }) :
        "The windows supply plenty of light and fresh air.",
     ({ "trail","path" }) :
        "A path leads off to the north."
     ]));
    set_smell("default", "The room smells clean and fresh.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}

