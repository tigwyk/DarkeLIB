//      Wizard:  Khojem
//      Hareem Room 1
//      hareem.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    ::reset();
   if(!present("eunuch")) {
      new("/d/khojem/nomad/mon/eunuch")->move(this_object());
      new("/d/khojem/nomad/mon/eunuch")->move(this_object());
  }   
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("night light",2);
    set("short", "outer hareem");
    set("day long",
      "This is a large meeting area or maybe a foyer.  The tent is well "+
      "ventilated and lit.  Many carpets form the floor of the tent and "+
      "any sand tracked in from the camp is quickly swept away.\n"
   );
    set("night long",
      "The chill night air is warmed by the many lit torches.  "+
      "This is a large meeting area or maybe a foyer.  The tent is well "+
      "ventilated and lit.  Many carpets form the floor of the tent and "+
      "any sand tracked in from the camp is quickly swept away.\n"
    );
    add_exit("/d/khojem/nomad/camp/center","northwest");
    add_exit("/d/khojem/nomad/camp/hareem2","south");   
    set_pre_exit_functions(({"south"}),({"go_south"}));
    set_items(([
     ({ "tent" }) :
        "It looks like a clean well maintained canvas tent.",
     ({ "carpet","carpets" }) :
        "Fine woven carpets make a thatchwork of the floor.  They are large "+
        "and too heavy for you to lift and pilfer.",
     ({ "torch", "torches" }) :  "A number of torches light the room."
    ]));
    set_smell("default", "The air is fresh and kinda smells good.");
    set_listen("default", "The noise from the camp is muffled here.  You "+
      "occasionally hear the muffled sounds of female voices and laughter.");
}

int go_south() {
  if(!present("eunuch")) return 1;
  if(this_player()->query_invis()) return 1;
  if(this_player()->query_hiding() > 80) return 1;
  if(this_player()->query_stealth() > 70) return 1;
  write("An oiled eunuch blocks your exit.\n");
  return 0;
}
