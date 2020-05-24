/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext 
   This gigantic chamber leads down from the crypt on the surface.  
   Passageways leave this area to the north and south, winding their 
   way further into the dark catacombs.  The air is very still and 
   not a sound is to be heard.
    0   
    |   up   
    @
    |
    0   
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
              ({"stairs", "staircase"}):
     "The stairs lead up to the surface.",
                "catacombs":
     "This appears to be some sort of system of catacombs below the surface.",
              ({"passageway", "passageways"}):
     "The passageways lead north and south from this area.",
               ]) );
   set_exits( ([
                "up": PATH+"catac000",
                "north": PATH+"catac002",
                "south": PATH+"catac003",
               ]) );
}
 
void reset() {
   object ob;
 
   ::reset();
   if(!present("skeleton") && !present("torch")) {
      ob = new(MON_PATH+"skeleton");
      ob->move(this_object());
      new("/std/obj/torch")->move(ob);
      new("/std/obj/torch")->move(ob);
      new("/std/obj/torch")->move(ob);
      ob->force_me("light torch");
   }
}
