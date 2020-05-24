/*  /wizards/canute/Sssarth-Nir/sn_platform6.c
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
    set_short("platform");
    set_long (
"You are at the top of the guard tower.   Your vision of the contryside is "
"heavily obscured by fog.  The town down below you is easy to make out, with "
"the help of numorous torches that burn constaly to help melt away the fog. "
"With the shelter provided to you by this tower, with the proper weapon, you "
"could fight here forever without risk of harm from oponets"
"\n");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_exits( ([
      "down" : "/wizards/canute/Sssarth-Nir/sn_gtower6.c"
    ]) );
}
