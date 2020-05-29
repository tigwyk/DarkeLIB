// /wizards/excelsior/rooms/street1_cont
// a boring street

inherit "std/room";

void create() {
::create();
set_property("light",1);
set_property("indoors",0);
set("short","Nothing is happening here");
set("day long","You have come to a rather boring and uneventful "+
"street. Shops on either side of the road are closed. You "+
"suppose they open at night when the crowds come. Even if the were "+
"open however, you don't think they're your type of store. To the "+
"north you see the theatre company.");
set("day long","This road would be very boring if it weren't for the "+
"people going in and out of the expensive tailor shops to the south. "+
"These stores don't interest you so you decide to move along.");
set_items( ([({"road","street","shops","people"}):"Boring.","theatre":
"You don't see a way in from here." ]) );
set_exits( (["east":"/wizards/excelsior/rooms/street1",
"northwest":"/wizards/excelsior/rooms/inter3"]));
}

