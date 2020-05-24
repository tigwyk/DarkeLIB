/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This chamber is filled with the stench of rotting flesh.  There are 
   several bones on the ground, along with small pieces of flesh.  The 
   room is surprisingly non-descript, and the northernmost wall is 
   highly polished for some unknown reason.
  
    @
     \
      0  
ext);
   set_smell("default", "It smells of rotting flesh here.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                "flesh":
       "There are bits of rotting flesh on the ground.",
                ({"bone", "bones"}):
       "There are several bones laying on the ground.",
                ({"wall", "north wall", "northern wall"}):
       "Upon closer examination of the northern wall, you realize that is "
       "an illusion!",
                ]) );
   set_exits( ([
                "north": PATH+"catac035",
                "southeast": PATH+"catac005",
                ]) );
   set_invis_exits( ({"north"}) );
   set_search("default",
        "As you search the northern wall, your hand passes through the rock!  "
        "The wall is an illusion!"
              );
}
 
void reset() {
   object ob;
   ::reset();
 
   if (!present("zombie")) {
      ob = new(MON_PATH+"zombie");
      ob->move(this_object());
   }
}
 
