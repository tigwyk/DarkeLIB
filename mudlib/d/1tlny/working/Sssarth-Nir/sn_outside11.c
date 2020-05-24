/*  /wizards/canute/Sssarth-Nir/sn_outside11.c
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
      "northeast" : "/wizards/canute/Sssarth-Nir/sn_outside12.c",
      "west" : "/d/damned/virtual/room_16_33.world",
      "south" : "/wizards/canute/Sssarth-Nir/sn_outside10.c"
    ]) );
}
