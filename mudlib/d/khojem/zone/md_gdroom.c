//      Wizard:  Khojem
//      MD-Guard Room
//      md_gdroom.c

#include <std.h>

inherit VAULT;

void reset() {
   ::reset();
   if (!present("sentry")) {
      new("/d/khojem/zone/mon/ksentry")->move(this_object());
   }
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Guard Room");
    set("long", "You are here in a alcove just within the gate. "+
      "This is a place commonly frequented by guards during "+
      "their routine duties.  The dirt floor is trampled to a "+
      "hard clay, but the moisture from the damp walls makes your "+
      "footing unsure against its smooth compactness."
   );
   add_exit("md_gdgate","north");
   add_exit("md_nmksq","south");
   add_exit("md_gdbrks","west");
   add_exit("md_gdpost","east");
      set_items(([
      ({ "gate", "gates", "stone gate", "stone gates" }) : 
        (: call_other, this_object(), "look_at_gate" :)
      ]));
   set_door("gate","/d/khojem/zone/md_gdgate","north","sentry gate key");
   set_string("gate","open","You hear the gate's hinges creak as it opens.");
   set_smell("default", "A horrible, rotten smell permeates the air.");
   set_listen("default", "All around you are the sounds of slow dripping water.");
}

void look_at_gate() {
    write("The gate is very large and appears strong.\n"
          "There is a small keyhole.\n");
    if(query_open("gate")) write("The gate is open.\n");
    else write("The gate is closed.\n");
}
