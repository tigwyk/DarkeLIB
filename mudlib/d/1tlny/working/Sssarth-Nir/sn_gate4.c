/*  /wizards/canute/Sssarth-Nir/sn_gate4.c
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
    set_property("indoors",1);
    set_short("gate");
    set_long (
"you are in a small guard room to the west of the main gate leading out of the"
"village.  To the east, and open archway leads out to the main gate.  To the"
"east of this room is one of the guard towers that flank the gate.  \n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "east" : "/wizards/canute/Sssarth-Nir/sn_gate2.c",
      "west" : "/wizards/canute/Sssarth-Nir/sn_gtower1.c"
    ]) );
}
