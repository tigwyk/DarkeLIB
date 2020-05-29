//Maxwell's Underground mudlib
//Thief Guild

#include <std.h>
#include <under.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a slimy stone passage.\n");
  set("long", "You are standing in a slimy stone passage. The cold stone "
      "walls stretch in front of you toward the east. The center "
      "of the passage is sumerged with a dark smelly liquid.\n"
      "A long ladder is here, stretching up into a tunnel above you.\n");
  set_exits( ({ "/d/daybreak/room/db_slum",UNTHIEF+"thief2" }),({ "ladder","east" }) );
  set_items( ([
    "walls" : "The cold stone walls are wet with running water.",
    "passage" : "The passage leads off into the darkness to the east.",
    "liquid" : "The nasty smelling liquid is filling most of the passage.",
  ]) );
  set_smell("default", "The smell of the foul liquid fills your nose.");
  set_listen("default","The only sound you can here is the beat of your "
    "heart and the oozing of the liquid.");
}


