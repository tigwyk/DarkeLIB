/*  /wizards/canute/Sssarth-Nir/sn_mounds1.c
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
    set_short("mounds");
    set_long (
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "west" : "/wizards/canute/Sssarth-Nir/sn_mounds2.c",
      "south" : "/wizards/canute/Sssarth-Nir/sn_trail6.c"
    ]) );
}
