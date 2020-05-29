// /wizards/excelsior/rooms/street4.4
// /wizards/excelsior/rooms/street4.4
// excelsior- what else can I say?

inherit "std/room";

void create() {
::create();
set_property("light",-2);
set_property("night light",-3);
set_property("indoors",1);
set("short","Deep in the outcast quarter");
set("long","You have come to the center of the outcast quarter. Here it "+
"is very dark, due to the lack of lit torches. All about different "+
"creatures are doing their normal everyday chores. They seem to be "+
"used to the dark and thus none of them seem to notice the absence of "+
"light. The conditions here are horrible. Overcrowded, diseased and "+
"filthy. You could imagine people just snapping and going on a violent "+
"rampage after living here for a while. To the southwest a small shack "+
"catches your eye. The tunnel bends here, to the north and the east.");
set_items( (["torches":"They all seem to be out.","creatures":
"Thranxs, centaurs, giants- just about every non-human race you can "+
"name.","conditions":"Quite filthy. Babies playing in dirty allies that "+
"are often used instead of latrines etc.","shack" :"It is to the "+
"southwest and it looks quite interesting." ]) );
set_exits( (["east":"/wizards/excelsior/rooms/street4.3","north":
"/wizards/excelsior/rooms/street5.1","southwest":
"/wizards/excelsior/rooms/ent_shack" ]) );
}
// excelsior- what else can I say?

