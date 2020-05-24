//      Wizard:  Khojem
//      t3.c

#include <std.h>

inherit VAULT;

void reset(){
  set_open("iron trapdoor",0);
  set_locked("iron trapdoor",0);
  "/d/khojem/port/room/t4"->set_open("iron trapdoor",0);
  "/d/khojem/port/room/t4"->set_locked("iron trapdoor",0);
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("night light",-1);
    set_property("indoors", 1);
    set("short", "Mage's Keep");
    set("long", "This is a small, stone landing on a spiral, stone stairway that "+
      "leads upwards and downwards in this circular, stone tower.  A small, "+
      "vertical window is towards the south and adds some light to an otherwise "+
      "darkened landing.  You perceive that the tower has greatly narrowed its "+
      "diameter at this level compared with that at the tower's base."
    );
    add_exit("/d/khojem/port/room/t2","down");
    add_exit("/d/khojem/port/room/t4","up");
    set_door("iron trapdoor","/d/khojem/port/room/t4","up",0);
    set_open("iron trapdoor",0);
    set_locked("iron trapdoor",0);
    set_func("iron trapdoor","open","do_open");
    set_func("iron trapdoor","close","do_close");
    set_items(([
     ({ "iron trapdoor" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "stone tower", "tower" }) :
        "The landing of the tower is constructed of rough, hewned stones "+
        "built in a circle.  Some light from outside can be seen through "+
        "the window in the south wall of the tower.",
     ({ "staircase", "stone staircase", "stairs", "stairway", "landing" }) :
        "The stone staircase is very dark and spirals up and down from "+
        "from this landing in the tower.  Its steps are worn from repeated "+
        "use, but many cobwebs can be seen draped across its path.",
     ({ "steps", "cobweb", "cobwebs" }) :
        "The steps lead upwards into the tower.  The once silvery cobwebs "+
        "are coated with much dust.  Obviously, the staircase has not been "+
        "used recently.",
     ({ "window" }) :
        "Through the narrow opening you can see a vertical drop down the "+
        "tower to the sea below.",
     ({ "waves", "wave", "sea" }) :
        "The rough, savage waves pound against the tower's base.",
    ]));
    set_smell("default", "A wet dankness fills the air.");
    set_listen("default", "It is quiet here.");
}

void look_at_door() {
  if(query_open("iron trapdoor")) 
    write("The ancient iron trapdoor is open.\n");
  else 
    write("The ancient iron trapdoor is closed.\n");
  say(this_player()->query_cap_name()+" examines an iron trapdoor.\n");
}

int do_open() {
  write("The iron trapdoor creaks on rusty hinges and some flakes of "+
    "rust fall into your eyes.\n");
  say(this_player()->query_cap_name()+" opens an iron trapdoor.  It makes "+
    "a creaking noise from years of non-use.\n");
  return 1;
}
 
int do_close() {
  write("An iron trapdoor is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams an iron trapdoor shut.\n");
  return 1;
}
