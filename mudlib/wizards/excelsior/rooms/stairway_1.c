// /wizards/excelsior/rooms/stairway_1
// climbing the stairs
inherit "std/room";

void create() {
::create();
set_property("light",2);
set_property("indoors",1);
set("short","Climbing the hospital stairs");
set("long","You have found your way to the second story of the hospital. "+
"Here everything is nice and clean, as it is clear only a few people "+
"use these stairs. A door here leads into some kind of doctors office.");
set_items( (["stairs":"Yes, stairs, that great device that allows one "+
"to travel up and down certain things. They are kind of like ladders, "+
"but not as steep. You don't have to use your hands to climb stairs. "+
"All you have to do is put one foot in front of the other, each step on "+
"a different stair, and because the stairs are progressively higher "+
"and higher, you will make your way upwards or downwards, whichever the "+
"case may be. What a great invention!","door":"Doors connect rooms "+
"to each other. They do this by providing a hole in walls. Walls by "+
"themselves are very difficult to walk through." ]) );
set_exits( (["up":"/wizards/excelsior/rooms/stairway_2","down":
"/wizards/excelsior/rooms/stairway","door":
"/wizards/excelsior/rooms/office" ]) );
add_pre_exit_function(
"up","sorry");
}

int sorry() {
	write("You are informed by a passing doctor that the part of the hospital you wish to enter is still being built.");
return 0;
}
