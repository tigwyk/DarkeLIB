//      From Maxwell's Underground mudlib
//        40th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small chamber. In the center "
"of the chamber is a large gold altar.");
   set("long",@ext 
You are standing in a small chamber at the end of the north 
corridor. In the center of the room is a large altar. Beutiful 
murals of the dwarven forests are painted on the walls of the 
chamber. Carved into the floor are several strange looking 
geometric shapes.
Along the wall are several burn marks. It appears that a great 
battle may have occured here involving strong sorcery.
  
    @
    |
    0
ext);
    set_exits( ({ UNDER+"dm37"}),
      ({ "south" }));
    set_items( ([
"murals" : "The colorful murals describe the history of the Dwarves."]));
    set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
    new(UNMON+"gguard")->move(this_object());
}
void reset() {
   object ob;
   ::reset();
   if(present("altar")) return;
   ob = new(UNQST"galtar");
   ob->move(this_object());
   }

