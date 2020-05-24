//      Wizard:  Khojem
//      temple t09-perimeter
//      t09.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "temple entry");
    set("day long",
      "The temple's crumpling roof protects you from the hot sun.  "+
      "You are standing on a broad stone walkway that stretches around "+
      "the perimeter of the ruined temple.  The temple's darke stone walls "+
      "are to the north and stretch far to the east and west.  Numerous "+
      "columns parallel the wall and border the stone walk.  They support "+
      "the temple's roof overhang above.  In the distance you can see "+
      "sand dunes that stretch out beyond the lip of the ravine.\n"
   );
    set("night long",
      "The temple's crumpling roof blocks much of the night sky.  "+
      "You are standing on a broad stone walkway that stretches around "+
      "the perimeter of the ruined temple.  The temple's darke stone walls "+
      "are to the north and stretch far to the east and west.  Numerous "+
      "columns parallel the wall and border the stone walk.  They support "+
      "the temple's roof overhang above.  In the distance you can see "+
      "sand dunes that stretch out beyond the lip of the ravine.\n"
    );
    add_exit("/d/khojem/nomad/temple/t01","east");
    add_exit("/d/khojem/nomad/temple/t08","west");
    set_items(([
     ({ "temple" , "structure" }) :
        "The structure appears it may have been a temple at one time.  Sculptured "+
        "columns form the building's perimeter.  A few of the columns have fallen "+ 
        "and rubbled around the base of the structure.  Much of the structure's "+
        "roof has collapsed from lack of support.  The walls that parallel the "+
        "columns around the structure are breached at numerous points.\n",
     ({ "floor", "walkway", "stone walkway" }) :
        "The stone walkway is smooth and covered with a fine layer of sand that "+
        "has blown in from the surrounding desert.  The stones are precision-cut "+
        "and rest against each other without mortar for binding.\n",
     ({ "wall", "stone wall", "stone", "rubble" }) :
        "The stones were once a smooth, black marble-like stone.  The years have "+
        "turned them to a grey chalky color.  The stones must have been "+
        "transported here at great expense since you can't see any similar stones "+
        "nor a quarry.  The wall stretches to the east and west.\n",
     ({ "columns" }) :
        "The once strong, straight columns now sag and crumble at various points "+
        "around the structure.\n", 
     ({ "roof", "overhang" }) :
        "High above, the temple's stone roof is supported by the inner wall on one "+
        "side of the walkway and by the columns on the other side of the walkway.  "+
        "At a few spots the roof has rubbled away and the sky can be seen through "+
        "the gaps in the roof.\n",
     ({ "sand dunes", "dunes", "ravine" }) :
        "Far to the south is the rocky ravine and beyond are the dunes of "+
        "the Wastelands of Bir'Barrutt."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The desert wind howls through the temple's columns.");
 }

