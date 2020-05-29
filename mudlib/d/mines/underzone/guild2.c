//Maxwell's Underground mudlib
//Guild Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a smooth tunnel.\n");
  set("long", "You are standing in a smooth stone passage. The "
      "walls are made of huge layered blocks. Some of the seams "
      "have cracked over the years from erosion and water damaged, "
      "but it still looks very stable\nThe passage continues to "
      "the southeast and the west.\n");
  set_exits( ({ GUILDR+"guild1",GUILDR+"guild3" }),({ "west","southeast" }) );
}


