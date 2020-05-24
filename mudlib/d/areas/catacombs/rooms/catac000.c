/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Entrance to Dark Catacombs");
   set("long",@ext 
   This is the inside of a small crumbling crypt.  In the center of the 
   room is a stone coffin, on top of which are written strange runes.
   The area is very dusty and you sneeze several times, kicking up even 
   more dust.  Cobwebs are strewn from one corner to the other, and you 
   catch sight of a spider now and then.  It is very quiet in this creepy 
   building.
       
        out   
    @
              
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence in the crypt.");
   set_items( ([
                "runes":
     "The runes are unlike any you have seen before.",
                "cobwebs":
     "The cobwebs hang from every corner of the room.",
                "spider":
     "The spider scurries away before you get a good look.",
                "dust":
     "You examine the dust more closely and sneeze repeatedly.",
                "lid":
     "The coffin's lid looks very heavy.",
               ]) );
   set_exits( ([
                "out": PATH+"forst000",
                "down": PATH+"catac001",
               ]) );
   set_search("default", "Behind the coffin you find a small staircase leading down!");
   set_invis_exits( ({"down"}) );
   new(MISC_PATH+"coffin")->move(this_object());
}
 
