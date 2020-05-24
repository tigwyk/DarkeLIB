/*  /wizards/canute/Sssarth-Nir/sn_gtower1.c
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
    set_short("tower");
    set_long (
" You are at the base of a guard tower.  It is contructed primarly out of "
" some sort of wood, which is tough to make out because of the many layers"
"of animal hides that cover it, obviously there to help resist fire damage"
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "up" : "/wizards/canute/Sssarth-Nir/sn_platform1.c",
      "east" : "/wizards/canute/Sssarth-Nir/sn_gate4.c",
      "south" : "/wizards/canute/Sssarth-Nir/sn_trail8.c"
    ]) );
}
