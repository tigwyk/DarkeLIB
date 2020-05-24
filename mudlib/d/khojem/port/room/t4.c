//      Wizard:  Khojem
//      t3.c

#include <std.h>

inherit VAULT;

void reset(){
  if(!present("mage")) {
    new("/d/khojem/port/mon/mage")->move(this_object());
  }
  if(!present("dervish")) {
    new("/d/khojem/port/mon/dervish")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light",0);
    set_property("indoors", 0);
    set("short", "Mage's Study");
    set("long", "A small, circular study forms the pinnacle of this stoney "+
      "tower.  Here is a great mage's workshop and library.  Through the stone "+
      "walls, small vertical windows open at the cardinal points of the "+
      "compass.  The stone floor is filled with discarded parchments and "+
      "dust.  Several books lay open on a few rustic tabletops."
    );
    add_exit("/d/khojem/port/room/t3","down");
    set_door("iron trapdoor","/d/khojem/port/room/t3","down",0);
    set_open("iron trapdoor",0);
    set_locked("iron trapdoor",0);
    set_func("iron trapdoor","open","do_open");
    set_func("iron trapdoor","close","do_close");
    set_items(([
     ({ "iron trapdoor" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "stoney tower", "tower", "study" }) :
        "The study of the tower is constructed of rough, hewned stones "+
        "built in a circle.  Some light from outside can be seen through "+
        "the windows in the tower's walls.",
     ({ "floor", "cobweb", "cobwebs", "dust" }) :
        "The floor of the study is constructed of stone.  Cobwebs and dust "+
        "cover its surface and corners.",
     ({ "window", "windows" }) :
        "High, narrow windows in the stone walls of the study allow a view "+
        "of the skies, but not of the surrounding land around the tower.",
     ({ "workshop", "library", "parchments", "books", "book", "parchment" }) :
        "The books and parchments are old and discolored from many years "+
        "of use.  The writings are cryptic and unreadable.",
    ]));
    set_smell("default", "A wet dankness fills the air.");
    set_listen("default", "It is quiet here.");
}

void look_at_door() {
  if(query_open("iron trapdoor")) 
    write("The ancient iron trapdoor is open.  A stone staircase leads down.\n");
  else 
    write("The ancient iron trapdoor is closed.\n");
  say(this_player()->query_cap_name()+" examines an iron trapdoor.\n");
}

int do_open() {
  if(this_player()->query_ghost()) { return 1; }
  if(present("dervish") && random(8) != 0) {
    write("As you start to open the iron trapdoor the dervish whirls about "+
      "the room, passes over the iron trapdoor, and violently slams it shut!\n");
    say(this_player()->query_cap_name()+" attempts to open the iron trapdoor, "+
      "but the dervish whirled across the trapdoor and slammed it shut!\n");
    tell_room("/d/khojem/port/room/t3","The iron trapdoor opens partially "+
      "before it is slammed shut!\n");
    return 0;
  }
  write("The iron trapdoor creaks on rusty hinges.\n");
  say(this_player()->query_cap_name()+" opens an iron trapdoor.  It makes "+
    "a creaking noise from years of non-use.\n");
  return 1;
}
 
int do_close() {
  write("An iron trapdoor is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams an iron trapdoor shut.\n");
  return 1;
}

