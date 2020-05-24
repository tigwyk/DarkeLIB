//      Wizard:  Khojem
//      Donjon Room 1
//      md_donjon1.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   new("/d/khojem/zone/mon/plguard1")->move(this_object());
   new("/d/khojem/zone/mon/plguard1")->move(this_object());
   new("/d/khojem/zone/mon/plguard1")->move(this_object());
}

void create() {
    int i;
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Castle's Donjon");
    set("long", 
      "You have entered what appears to be the city's "+
      "donjon.  The cobblestones are worn smooth from years of "+
      "wear.  This appears to be the oldest structure in the city "+
      "that you have explored so far.  Stairs lead down and an "+
      "archway shows an exit to the east."
   );
    set_items(([
      ({ "cobblestones", "cobblestone", "stone" }) :
        "The cobblestones are of little interest to you.  They "+
        "are rough stones that where cut from a larger rock.  "+
        "Due to years of wear many of the rough edges are worn smooth.",
      ({ "stairs","stair" }) :
        "A series of stone masonery steps lead down into darkness.",
      ({ "doorway","arch", "archway" }) :
        "A curved stone archway leads into another room to the east.  "+
        "From this archway you hear the laughter men talking in a " +
        "tongue unfamilar to you." 
      ]));
    add_exit("md_way","west");
    add_exit("md_donjon2","east");
    add_exit("md_dung1","stairs");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear the sound of men laughing coming "+
      "from the east through an archway.");
}
      

