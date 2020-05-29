// /wizards/excelsior/rooms/inter3
// excelsior!

inherit "std/room";

void create() {
::create();
set_property("light",1);
set_property("indoors",0);
set("short","A busy intersection");
set("day long","This is a busy intersection. People are everywhere "+
"going about their own personal business. You suppose some are going "+
"to the store, others to work, and still others to amusement areas "+
"like the Excelsior Emporium. Even some upper-class looking people "+
"travel here in the depths of the city. You figure that the higher in "+
"the towers you climb, the more expensive the property becomes. Man it "+
"must be nice up there! Think of the view! Looking up you see far above "+
"a bridge over the intersection. You do not see the tops of any "+
"buildings. 'This city is definitely a monument to human architectural "+
"accomplishment' you think. To the east is the city theatre company, "+
"to the west you see a ramp of some kind, and two roads travel to the "+
"south and southeast.");
set("night long","At night this area is alive with excitement and fun. "+
"Half-orc police men and women have swept the lower class people away "+
"so that the rich who travel this way at night don't have to poison "+
"their eyes with the sight of poor. And the rich are everywhere. They "+
"come in groves at night to the two major attractions this level of "+
"the- The New Faerie Dust Theatre Company to the "+
"east and the Excelsior Emporium, which can be reached by following "+
"a road southeast.");
set_items( ([({"rich","upper-class"}):"You wonder if they aren't living "+
"in ignorance to "+
"the fact that this city contains poor. You wonder if the powers of "+
"the city have the police (made up mostly of non human creatures) sweep "+
"away the poor so that they continue this life of ignorance. Then you "+
"think of your childhood stories, of how you never heard of any poor in "+
"New Faerie Dust. Hmm.","police":"Only the officers are human. You "+
"wonder what the oppressed brothers these police must have in the outcast "+
"quarter of the city appreciate their 'betrayal'. The outcast quarter "+
"can be found to the south.","people":"They all seem so busy. With "+
"people like this, how can this city be in such bad shape?","towers":
"As you look at them all you can utter is 'Man'! You then shrink "+
"into the shadows of embarrassment from your archaic use of slang.",
"bridge":"It is hundreds of feet above you.","ramp":"Go west and "+
"see.","theatre":"Go east and check it out.","roads":"Great for "+
"traveling on." ]) );
set_exits( (["east":"/wizards/excelsior/rooms/theatre_ent","west":
"/wizards/excelsior/rooms/road_up1","south":
"/wizards/excelsior/rooms/street5.3","southeast":
"/wizards/excelsior/rooms/street1_cont" ]) );
}
