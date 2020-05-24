/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This secret chamber would appear to be the holding room for a small 
   chest of sorts.  The room is very dark, as no torches are on the 
   walls of this room.  The only apparent exit from this room is 
   through the crack in the southern wall.

    @
    |
    0   
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"southern wall", "crack"}):
        "The crack is in the southern wall.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ]) );
   set_exits( ([
                "south": PATH+"catac128",
                ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(present("large chest"))
      present("large chest")->remove();
   ob = new(MISC_PATH+"catchest");
   ob->move(this_object());
   ob->toggle_closed();
   ob->set_lock("unlocked");
   new(MISC_PATH+"elixir")->move(ob);
   ob->toggle_closed();
   ob->set_lock("locked");
}
