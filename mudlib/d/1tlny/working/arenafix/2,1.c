/*  /d/damned/arena/2,1.c
 *  Made for DarkeMUD
 *  Created by Geldron 031296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    replace_program(ROOM);
    set_property("light", 2);
    set_property("night light", 1);
    set_short("East Block of Arena");
    set_long("This is the east block of the Arena.  The arena extends "
      "west, north, and south.");
    set_smell("default", "Blood and carcasses are scattered "
      "everywhere, filling up the arena with a nasty smell.");
    set_exits( ([
      "north" : "/d/damned/arena/2,2",
      "west" : "/d/damned/arena/1,1",
      "south" : "/d/damned/arena/2,0",
    ]) );
}
