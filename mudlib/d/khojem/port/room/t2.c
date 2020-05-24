//      Wizard:  Khojem
//      t2.c

#include <std.h>

inherit ROOM;
void reset(){
  :: reset();
  if(!present("wolf"))
    new("/d/khojem/port/mon/wolf")->move(this_object());
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
    add_exit("/d/khojem/port/room/t1","down");
    add_exit("/d/khojem/port/room/t3","up");
    set_pre_exit_functions(({"up"}),({"go_up"}));
    set_items(([
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

int go_up() {
  if(!present("wolf")) return 1;
  write("A silvery wolf quickly blocks your exit!\n");
  say("A silvery wolf blocks "+this_player()->query_cap_name()+
    "'s attempt to exit up the staircase.\n");
  if(this_player()->is_player()) {
    if(((int)this_player()->query_level()) < 15) {
      write("\nThe wolf howls:  "+this_player()->query_cap_name()+"!  "+  
        "You have strayed young adventurer!  Do not venture "+
        "forth!  My master will react unkindly towards unwanted vistors.\n");
      return 0;
    }
    write("\nThe wolf howls:  "+this_player()->query_cap_name()+"!  "+  
      "You appear to be a veteran adventurer!  I warn "+
      "thee... my master will react harsely to your interruption.  He enjoys "+
      "his solitude.\n");
  }
  return 0;
}

