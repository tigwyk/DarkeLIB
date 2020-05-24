#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
        ::create();
        set_property("indoors", 2);
        set_property("light", 3);
        set("short", "    \n   u \n   @   \n     \n    \nA mystical chamber of light.");
        set("long", "This is a strange room, light seems to get to every where in this room, even though there are objects that would usually create shadows. In the middle of the room is a sword, maybe something that could help newbies out.\n     \n   u \n   @   \n     \n    \n");
set_exits( ({(ROOMS+"room2")}), ({"up"}));
new(MON+"blob.c")->move(this_object());
}

void reset() {
   int num;
   ::reset();
   num=random(4);
   if(!present("cube")&& (num==3)) new(MON+"blob.c")->move(this_object());
}
