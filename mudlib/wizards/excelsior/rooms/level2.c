// /wizards/excelsior/rooms/level2
// Excelsior made this

inherit "std/room";

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","The second level of the city");
	set("long","This is the second level of New Faerie Dust. You were "+
	"hoping that as you got higher in the city things would look "+
	"better- but not yet, you suppose. Here, as below, there is filth "+
	"everywhere. Squatters have set up makeshift homes along the sides "+
	"of he buildings . All in all, it is pretty bad. Above you "+
	"buildings tower- it doesn't appear as though you've made it any "+
	"closer to the top. You wonder if it is safe to walk around on "+
	"this level. To the northeast is a large dull structure. There is "+
	"a ramp here leading down and a road continues south.");
	set_items( (["ramp":"It leads down.","road":"It leads south.",
		"homes":"Rich people live in the higher levels of the city.",
	"filth":"This city is a very dark and depressing place.",
		"squatters":"They have no home of their own, so they build "+
		"little camps out of garbage.","buildings":"Still very "+
		"large. You notice a particularly boring one to the north"+
		"east.",({"building","structure"}):"To the northeast. It "+
		"appears to be very secure. Because you don't feel safe here, "+
		"it might be worth checking out." ]) );
	set_exits( (["down":"/wizards/excelsior/rooms/road_up1","south":
	"/wizards/excelsior/rooms/street6.1","northeast":
	"/wizards/excelsior/rooms/prison_ent"]) );
}
