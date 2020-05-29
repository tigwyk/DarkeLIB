//      From Maxwell's Underground mudlib
//         4th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short","The tunnel begins to bend to the southwest here. It "
"appears that it is leading deeper underground.");
    set("long", 
"The tunnel begins to bend to the southwest here. It appears that it "
"is leading deeper underground. The track begins to slope down and the "
"tunnel size has expanded. You notice large piles of granite dust along "
"the side of the tracks. The miners must have to sweep the dust off the "
"tracks so the carts can roll over them." 
       );
    set_exits( ({ UNDER+"dm3",UNDER+"dm5" }),
      ({ "southeast","southwest" })
    );
    set_items( ([
       "track" : "The steel track makes a sharp bend here.",
       "dust" : "The dust is thick and filled with shattered peices of granite.",
      ]) );
       
//    set_smell("default", "It smells like a new immortal in here.");
//    set_listen("default", "You hear the sounds of code creation.");
}
void reset() {
 object mon,mon2,itm;

 ::reset();
   if(!present("mikarty")) {
     mon = new(UNMON+"gwolf");
     mon->move(this_object());
     mon->weapon_code_midlevel();
     mon->armour_total_midlevel();
     new(UNETC+"chain")->move(mon);
   }
   else
     mon = present("mikarty");
   if(!present("wolf")) {    
     mon2 = new(UNMON+"wolf");
     mon2->move(this_object());
     mon2->set_property("master",mon);
     itm = new(UNETC+"chain");
     itm->move(mon2);    
   }   
}
