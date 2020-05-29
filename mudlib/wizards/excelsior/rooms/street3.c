// /wizards/excelsior/rooms/street3
// a basic room with coins in it. oooooo. by excelsior

inherit "std/room";
object money;


void reset() {
   ::reset();
if (!all_inventory(this_object())) {
   money = new("/std/obj/coins");
   money->set_money("platinum", 1);
   money->set_money("copper", 234);
   money->move(this_object());
}
}

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short","A disgusting street");
   set("long","This dank and disgusting street serves as the home for "+
      "the poor.  Chawls are built here by greedy land lords,  and families "+
      "move to them, one room per family, to work in the landlord's factories. "+
      "They live in cramped environments and make a few extra coins by "+
      "renting out a corner or some floor space, for there are many who would "+
      "take it. Out on the streets are people who are even worse off, they have "+
      "nothing of their own, not even a room.");
   set_items( (["chawls":"They are on either side of the street. You do not "+
            "wish to go in them, make public housing look like the Hyatt.",
            "people":"People are everywhere.","streets":"Looking at the street "+
            "you get very tired of all these useless item descriptions." ]) );
   set_exits( (["south":"/wizards/excelsior/rooms/street3_cont",
            "north":"/wizards/excelsior/rooms/inter1" ]) );
}
