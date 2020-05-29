//Maxwell's Underground mudlib
//Guild Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a dusty passage.\n");
  set("long", "You are standing in a dusty passage. The smooth "
      "ceiling arches down and joins with the block walls in "
      "segmented joints. It looks as though it was designed and "
      "built by highly skilled workers.\n");
  set_exits( ({ GUILDR+"guild2" }),({ "east" }) );
}


