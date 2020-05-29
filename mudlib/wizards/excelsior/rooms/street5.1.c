// .wizards/excelsior/rooms/street5.1
// home of a fine bag
// impressive, no? -Excelsior!>([]


inherit "std/room";

void reset() {
::reset();
if (!present("bag")) {
new("/wizards/excelsior/obj/bag")->move( this_object() );
}
}

void create() {
::create();
set_property("light",-2);
set_property("night light",-3);
set_property("indoors",1);
set("short","Deep in the tunnel");
set("long","The tunnel is very dark here, as many of the torches "+
"that are supposed to be lit are out. You suppose that perhaps the "+
"guy who's job it is to keep this covered street lit is human, and "+
"humans don't like traveling into the outcast quarter. It is to "+
"dangerous. In fact, as you gawk at the many strange beings here, "+
"you understand why.");
set_items( (["tunnel":"It is as if the humans who run this city want "+
"to make the life of the nonhumans even more miserable y forcing them "+
"to live in a dark tunnel.","torches":"They are not lit, and not yours "+
"to take.","street":"It is covered. That is why is it dark.","beings":
"Centaurs, orcs, giants, elfs, werewolfs, you name it. Strangely, "+
"you don't see any gnomes."]) );
set_exits( (["north":"/wizards/excelsior/rooms/street5.2",
"south":"/wizards/excelsior/rooms/street4.4" ]) );
}
