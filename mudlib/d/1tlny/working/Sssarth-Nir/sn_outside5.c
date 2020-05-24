/*  /wizards/canute/Sssarth-Nir/sn_outside5.c
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
    set_property("light", -1);
    set_property("outdoors",1);
    set_short("swamp");
    set_long (
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "northeast" : "/wizards/canute/Sssarth-Nir/sn_outside4.c",
      "southeast" : "/d/damned/virtual/room_18_33.world",
      "southwest" : "/wizards/canute/Sssarth-Nir/sn_outside6.c"
    ]) );
}
