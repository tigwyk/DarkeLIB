//      Wizard:  Khojem
//      darke temple
//      temple.c

#include <std.h>

inherit ROOM;


void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "Near the temple ruins");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You are standing before the ruins of an ancient structure.  "+
      "Years of wear and exposure to the desert winds and sand have "+
      "turned the once darke, black stones to a darke gray.  "+
      "Several of the stones have cracked or fallen to the ground in rubble.  "+
      "From here the structure appears abandoned.  As if held back by some force "+
      "huge, steep sand dunes form a circle around the structure on this side "+
      "of the ravine.  Passage up the slopes of the dunes appears impossible."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing before the ruins of an ancient structure.  "+
      "Years of wear and exposure to the desert winds and sand have "+
      "turned the once darke, black stones to a darke gray.  "+
      "Several of the stones have cracked or fallen to the ground in rubble.  "+
      "From here the structure appears abandoned.  As if held back by some force "+
      "huge, steep sand dunes form a circle around the structure on this side "+
      "of the ravine.  Passage up the slopes of the dunes appears impossible."
    );
    add_exit("/d/khojem/nomad/room/rv10","south");
    set_items(([
     ({ "structure","ancient structure" }) :
        "The structure appears it may have been a temple at one time.  Sculptured "+
        "columns form the building's perimeter.  A few of the columns have fallen "+ 
        "and rubbled around the base of the structure.  Much of the structure's "+
        "roof has collapsed from lack of support.  The walls that parallel the "+
        "columns around the structure are breached at numerous points.\n",
     ({ "stones", "stone", "rubble" }) :
        "The stones were once a smooth, black marble-like stone.  The years have "+
        "turned them to a grey chalky color.  The stones must have been "+
        "transported here at great expense since you can't see any similar stones "+
        "nor a quarry.\n",
     ({ "columns" }) :
        "The once strong, straight columns now sag and crumble at various points "+
        "around the structure.\n", 
     ({ "sand","sand dunes","dunes","slopes" }) :
        "The massive sand dunes block your view to the west, north and east.\n",
     ({ "ravine" }) :
        "The ravine appears as a slit in the distance.  It runs from east/west.\n",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The desert wind howls down the steep dune slopes.");
    new("/d/khojem/nomad/obj/mono3")->move(this_object());
}
