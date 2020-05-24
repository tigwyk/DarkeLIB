/*  /wizards/canute/Sssarth-Nir/sn_enter.c
 *  Made for DarkeMUD
 *  Created by Canute 032096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    replace_program(ROOM);
    set_property("light", 1);		// very foggy 
    set_property("night light", -2);		// very foggy
    set_property("outdoors",1);
    set_short("Murky Path");
    set_long(
"You continue to follow the murky path, stranges footsteps litter the"
"area, the path continues south, deeper into the swamps.  The thick pea-soup"
"fog seems to close in around you, making it nearly impossible to see" );
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "north" : "/d/damned/virtual/room_17_33.world",
      "east" : "/d/damned/virtual/room_17_33.world",
      "west" : "/d/damned/virtual/room_17_33.world",
      "south" : "/wizards/canute/Sssarth-Nir/sn_enter1.c"
    ]) );
}
