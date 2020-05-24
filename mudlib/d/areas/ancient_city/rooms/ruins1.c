
#include "../ruins.h"
#include <std.h>
inherit "std/vault";
 void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
set_exits( ([
"north":ROOMS+"ruins2.c",
]) );
 add_exit("/d/damned/virtual/room_5_3.world", "out");
set("short", "Runes Of An Ancient City");
set("day long", @ext The Ruins Of An Ancient City. This is the entrance of the
Ancient City. There is a wall all around the city but at this point. There
is an archway built into the wall in which to enter the city with. The
ground is covered in grass. The grass has been flattened in the middle of
the entrance which shows that some one or some thing has walked throw the
grass recently. To the south there is a forest which surrounding the city.
The grass path continues north. There is a sign here cover with a glowing
light.
    0   
    |   
    @
    
    O
ext);
set("night long", @ext The Ruins Of An Ancient City. This is the entrance of
the Ancient City. There is a wall all around the city but at this point.
There is an archway built into the wall in which to enter the city with.
The ground is covered in grass. The grass has been flattened in the middle
of the entrance which shows that some one or some thing has walked throw
the grass recently. To the south there is a forest which surrounding the
city. The grass path continues north. There is a sign here cover with a
glowing light.
    0   
    |   
    @
    
    O
ext);
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
set_items(([
({ "sign" }) :
"Please help.\n"
"\n"
"This ancient city was abandoned because it was over run by rat-men clan
called the skaven. Cat-men where sent in to stop the infestation over 20
years ago. The rat-men have only seem to have gotten stronger and they have
started digging up the city looking for ancient artifacts. The cat-men that
where sent in to kill the rat-men have disappeared and have been thought to
be leading the rat-men to a greater victory over the humans the rule there
plans. Some citizens have stayed behind to help adventures take out the
rat-men. Please go to there stores and for help if you need equipment and
goods for your journey.\n"
"\n"
"Please help us stop the rat-men infestation and take out the cat-men
before the whole world is doomed.\n"
"\n"
"The rat-men in the basements of the house in this city should be a start.
The entrance to the basements are 2n 2w 1s of this sign.\n"
"\n"
"The sewers have been over run with rat-men. The rat-men there have groan
to strong for lower level citizens. If you think you can take then out
please do so. The entrance is 2n 2w of this sign. But The sewer hole is blocked.\n"
"\n"
"The tunnel is to be believed as the rat-men strong hold. Be warned if you
go in you may never come out. If you think you are strong enough to take
out the rat-men strong hold then please continue down and take out the
cat-men before the cat-men can stage a counter attack. The entrance to the
tunnel is 4n. But there is a bolder in the way of the enterence.\n"
"\n"
"Please help us.\n"
"\n"
"signed citizens of the ancient city.\n",
({ "arch", "archway", "enterence" }) : 
"The archway is cover in thick vines.",
({ "grass", "grass road", "road", "passage" }) :
"The grass has grown to one foot off the ground. The grass also has been
flattened in the middle of the entrance showing that some one or some thing
has walked on the grass recently."
]));
new(ITEM+"sign.c")->move(this_object());
}

