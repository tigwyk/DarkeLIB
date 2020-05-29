// /wizards/excelsior/rooms/street5.3
// this room has a generic torch


inherit "std/room";

int ok;

void reset() {
::reset();
ok = 0;
}

void init() {
::init();
add_action("get_torch","grab");
}

void create() {
::create();
set_property("light",1);
set_property("indoors",0);
set("short","Outside the tunnel");
set("long","South of here the street you are on enters a large tunnel, "+
"and the outcast quarter. The outcast quarter is an area where non-"+
"human residents of the city are forced to live. You shudder to think "+
"of what the conditions must be like there. You shudder so hard you "+
"almost turn and run right out of the city, but you regain control and "+
"remain where you are. There are several torches here shining proudly "+
"and doing there best to light up the area, because little light gets "+
"here from above. There is also a sign here. Perhaps you should look "+
"at these things more closely.");
set_items( ([ ({"street","tunnel"}):"The street enters a tunnel.",
"sign":"The sign informs you that you are on street 27d","torches":
"One of the torches looks loose. You could probably grab it." ]) );
set_exits( (["north":"/wizards/excelsior/rooms/inter3","south":
"/wizards/excelsior/rooms/street5.2" ]) );
}

int get_torch(string str) {
string name;
name = this_player()->query_cap_name();
if ( str == "torch" ) {
if ( ok == 0 ) {
write("You grab the torch and pull it off for yourself. As you pull it, "+
"it goes out.");
tell_room( this_object(), name+" grabs a torch for himself.",
({this_player()}) );
ok = 1;
new("/std/obj/torch")->move( this_player() );
return 1;
}
else
{
write("Hmm. It appears that the torch is not as loose as it looked. "+
"You might try again later.");
return 1;
}
}
write("What do you want to grab? C'mon, THINK!");
return 1;
}
