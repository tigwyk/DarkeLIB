/*  /wizards/canute/Sssarth-Nir/sn_gtower5.c
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
    set_short("tower");
    set_long (
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "up" : "/wizards/canute/Sssarth-Nir/.c",
      "northwest" : "/wizards/canute/Sssarth-Nir/sn_barracks3.c"
    ]) );
}
