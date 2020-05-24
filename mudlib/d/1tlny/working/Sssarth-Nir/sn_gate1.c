/*  /wizards/canute/Sssarth-Nir/sn_ogate.c
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
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors",1);
    set_short("Outside Gate");
    set_long(
"  You stand before an open gate that belongs to a rather imprisve wooden"
"palaiside.  The gate is flanked on either side by a guard tower.  The"
"platforms at the top of either tower are shielded from you're view.\n");

    set_smell("default", "the stench of rot and decay are everywhere");
    set_exits( ([
      "north" : "/wizards/canute/Sssarth-Nir/sn_enter1.c",
      "east" : "/wizards/canute/Sssarth-Nir/sn_outside1.c",
      "west" : "/wizards/canute/Sssarth-Nir/sn_outside14.c",
      "south" : "/wizards/canute/Sssarth-Nir/sn_gate2.c"
    ]) );
}
