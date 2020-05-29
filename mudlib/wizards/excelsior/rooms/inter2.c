// wizards/excelsior/rooms/inter2
// another basic room created for your enjoyment by Excelsior.
inherit "std/room.c";

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short","Another intersection");
   set("day long","The city around you bustles with activity at this "+
      "time of day.  Everywhere you look there are people going about their "+
      "personal business.  Many of the more 'well off' looking people "+
      "seem to completely ignore the many panhandlers who are here. "+
      "You wonder how they can.  Far above are the heights of the "+
      "New Faerie Dust towers. To the southwest is another intersection, "+
      "and the road you are on continues to the east.  You see a shop to "+
      "the north, which appears to be the center of much of the activity "+
      "here.");
   set("night long","At night this place is dead.  Few people move "+
      "about. You have to step over sleeping homeless people as you "+
      "walk about. You wonder if some of them aren't dead. You can't "+
      "see much in any direction,  but to the north is a well lit up shop "+
      "that appears to be open.");
   set_items( ([ "people":"Everyone of them is going about their business.",
            "towers":"They stretch waaaaay up there!","panhandlers":
            "Some manage to completely ignore them.","homeless":
            "They are sleeping on the streets.","shop":"A sign in the "+
            "window read 'Open 24 hours a day.'","road":"It curves around "+
            "to the east and southwest."]) );
   set_exits( (["southwest":"/wizards/excelsior/rooms/inter1",
            "north":"/wizards/excelsior/rooms/shops/generalstore",
 "east":"/wizards/excelsior/rooms/sewer_ent" ]) );
} 

