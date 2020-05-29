// /wizards/excelsior/rooms/office
// home of a psycho doctor. 

inherit "std/room";
void reset() {
object money;
::reset();
if (!present("doctor")) new("/wizards/excelsior/mon/doctor")->move(
this_object() );
money = new("std/obj/coins");
money->set_money("copper",790);
//money->move("/wizards/excelsior/mon/doctor");
}

void create() {
::create();
set_property("light",2);
set_property("indoors",1);
set("short","A doctors office");
set("long","As you enter this room you are overcome by the stench of "+
"dead bodies. You look around closer and find the source. Actually, "+
"it is not very hard to miss at all: bodies everywhere. They are "+
"stacked on tables, carts- some human, some giant, some god-knows-"+
"what. Some are dismembered, some are whole. On shelves are "+
"jars and containers filled with eye balls, fingers, ears, brains- "+
"the works. On a table is a book that appears to be a journal of some "+
"kind. "+
	"You realize with horror that all the "+
"dead of the hospital must be shipped up here to some strange lunatic.");
set_smell("default","You smell the stench of dead bodies.");
set_items( (["bodies":"You check to see if you know any of them.",
({"shelves","containers"}):"They hold various body parts.","book":
"It is long and boring but obviously a journal of a evolutionairy magician genetic engineer. "+
"One passage catches your eye: Project CULLING file #127","tools":
"Hmmmm"]) );
set_exits( (["west":"/wizards/excelsior/rooms/stairway_1"]) );
}
