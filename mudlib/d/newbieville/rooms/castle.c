#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
  object ob;    

    ::create();

  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "castle board", "bets"}) );
  ob->set_board_id("newbieville_castle_board");
  ob->set_max_posts(50);
  ob->set_location(ROOMS+"castle");
  ob->set("short","Newbieville Bulletin Board");
  ob->set("long",@TEXT
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This board is meant to help newbies out as they first begin their journeys
in Daybreak Ridge. Post guild tips, directions, or anything else that you
think will come in handy for them. You can also post advertisements for
wares or other services which may be appropriate for newbies.

Thanks!

-The Newbieville Management
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

TEXT
);

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Castle of Tailwind");
    set("long", "This is the Castle of Lord Tailwind. You see a bulletin board in the center of the room, a staircase leading upwards, and nothing else.");
    add_exit(ROOMS+"upperfloor", "up");
    add_exit(ROOMS+"townsquare", "out");

call_out("load_rooms", 1);
}

int no_exit() { return 1; }


void load_rooms() {
	find_object_or_load("/d/newbieville/rooms/upperfloor");
	find_object_or_load("/d/newbieville/rooms/upperfloor2");
}
