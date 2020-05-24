/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   You are overcome by the loud banging that echoes in the small chamber 
   of the catacombs.  The origin of the sound is not apparent, although 
   the clanging seems loudest in the southern part of the room, for some 
   reason.
   
    @
   / 
  0    
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "You hear loud banging.");
   set_search("default", "There is light coming from a crack in the southeastern part of the wall.");
   set_items( ([
                "banging":
        "How does one look at a sound?"
                ]) );
   set_exits( ([
                "southwest": PATH+"catac030",
                "southeast": PATH+"catac032",
                ]) );
   set_invis_exits(({"southeast"}));
}
 
void reset() {
   object ob;
   ::reset();
 
   if(!present("silver skeleton")) {
      ob = new(MON_PATH+"silvskel");
      ob->move(this_object());
   }
}
 
