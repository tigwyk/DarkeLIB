#include <std.h>
#include "../a1.h"

inherit ROOM;

void reset() {
        ::reset();
if (!present("miner")) 
new(MON+"miner.c")->move(this_object());
//new(MON+"worker1.c")->move(this_object());
}

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "tunnel" );
    set( "day long", @EndText
    Even though the sun shines bright outside as you venture deeper into the tunnels the light grows darker you hear dwarven workers busily hauling minerals through out the area
  
 0--@
EndText
);
    set( "night long", @EndText
   Night time make this room even darker then you can imagine you hear dwarven workers busily hauling minerals through out the area
EndText
);
set_exits( ({ 
//PATH+"r11.c", 
//PATH+"r3.c", 
//PATH+"r12.c",
PATH+"r10.c", 
}), ({ 
//"north", 
//"south", 
//"east", 
"west", 
}) );
}

