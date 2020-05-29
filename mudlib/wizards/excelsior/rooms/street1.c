// /wizards/excelsior/rooms/street1
// after this, I have reached my goal for the day. woo!

inherit "std/room";

void create() {
::create();
set_property("light",1);
set_property("indoors",0);
set("short","On a street");
set("long","The street here is fairly busy as it is so close to the town "+
"square. The shops seem to be doing fairly well, but they interest you "+
"little. Maybe if you go east to the square you will find something a "+
"little more to your liking. Beside, the Excelsior Emporium is that way.");
set_items( (["street":"I really bugs me that I end up describing a "+
"street in every single one of my room.","shops":"The are doing "+
"fairly well at this location.","square":"It is to the east. I hate "+
"repeating myself. Bog."]) );
set_exits( (["east":"/wizards/excelsior/rooms/square",
"west":"/wizards/excelsior/rooms/street1_cont" ]) );
}
