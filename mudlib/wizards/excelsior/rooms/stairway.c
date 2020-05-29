// /wizards/excelsior/rooms/stairway
// excelsior

inherit "std/room";

void init() {
::init();
add_action("lick_it","lick");
}

void create() {
::create();
set_property("light",2);
set_property("indoors",1);
set("short","The back stairway");
set("long","You have made your way into a back stairway of the "+
"hospital, carefully ignoring a sign posted here that says '"+
"employees only'. The stairway goes both directions- up and down "+
"for those who couldn't figure that out. You can also leave through "+
"a door that leads to the main area of the hospital.");
set_items( (["stairway":"A mighty fine looking stairway that appears "+
"to be in full operational order.","sign":"You carefully ignore it.",
"door":"It appears to lead back to the main area of the hospital. "+
"There is some gum stuck to it.","gum":"Perhaps you could 'lick' it?"]));
set_exits( (["up":"/wizards/excelsior/rooms/stairway_1","down":
"/wizards/excelsior/rooms/stairway-1","out":
"/wizards/excelsior/rooms/hospital" ]) );
add_pre_exit_function("down","sorry");
}

int lick_it(string str) {
if ( str == "gum" ) {
write("Yum yum!");
return 1;
}
write("You lick yourself.");
return 1;
}
int sorry() {
	write("A hospital guard informs you that this area of the city is still being built.");
return 0;
}
