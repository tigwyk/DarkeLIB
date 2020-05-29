// /wizards/excelsior/rooms/street4.1
// a quick room -Excelsior!>([]

inherit "std/room";

void create() {
::create();
set_property("light",1);
set_property("indoors",0);
set("short","A street in the city");
set("day long","You are entering the Outcast quarter of New "+
"Faerie Dust. This is where the humans who run the place have "+
"shunned all the non-huminoid beings of the city. It is five times "+
"more overcrowded then anything you've seen so far. The center of "+
"this quarter is off to the west. There you see the street goes into "+
"a deep, dark tunnel. To the east is the city hospital, and to the "+
"north is a large behemoth of a building. You see no where in from "+
"here. At street level on the two sides here are uninteresting novelty "+
"shops run by non-humans. You are sure there are much more useful "+
"shops elsewhere.");
set("night long","At night this street is empty, save for a few thranx "+
"sleeping leaning against the closed shops on either side of the "+
"street here. They look like under their hard exoskeleton they have "+
"no meat what so ever, it being withered away by their work as half "+
"slaves for their human employees. You imagine that they are in high "+
"demand in factories and mines because of their extra appendages and "+
"super strength. To the west the street enters a tunnel.");
set_items( (["beings":"There are non-humans everywhere you look.",
"tunnel":"The street becomes covered ahead, and it is apparent that "+
"there is another street directly above it.","hospital":"It is "+
"east.","building":"A very large building that seems to reach up into "+
"heaven.","shops":"Not interesting. Move on.","thranx":"They look "+
"old and worn out. If you are a thranx, you should feel sorry for "+
"your brothers. If you aren't, well, you still should." ]) );
set_exits( (["east":"/wizards/excelsior/rooms/hospital_ent",
"west":"/wizards/excelsior/rooms/street4.2" ]) );
}
