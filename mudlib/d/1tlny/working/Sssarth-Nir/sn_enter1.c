/*  /wizards/canute/Sssarth-Nir/sn_enter1.c
 *  Made for DarkeMUD
 *  Created by Canute 031296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    replace_program(ROOM);
    set_property("light", 0);
    set_property("night light", -2);
    set_property("outdoors",1);
    set_short("Murky Path");
    set_long(
"You are on a path, or at least what you think is a path.  All around you is "
"swamp, swamp and fog.  To the south, the path continues deeper into the swamp "
"the fog to the south is exceptionally thick, and you can not tell were the "
"path leads.");
    set_smell("default", "The air is heavy with the stench of decay");
    set_exits( ([
      "north" : "/wizards/canute/Sssarth-Nir/sn_enter.c",
      "east" : "/d/damned/virtual/room_17_33.world",
      "west" : "/d/damned/virtual/room_17_33.world",
      "south" : "/wizards/canute/Sssarth-Nir/sn_gate1.c"
    ]) );
}
