//      Wizard:  Khojem
//      Paladin Parapet
//      parapet.c

#include <std.h>

inherit ROOM;

void create() {
   ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set("short", "Paladin Parapet");
  set("long", 
    "The narrow parapet forms a small hallway.  The castle's outer "
    "wall is to the northeast and numerous narrow slits allow you "
    "to look down into the courtyard at the castle's entrance." 
  );
  add_exit("/d/damned/guilds/paladin/meeting","stairs");
  add_exit("/d/khojem/port/room/r1","down");
  add_invis_exit("down");
  set_pre_exit_functions(({"down"}),({"go_down"}));
}

int go_down() {
  if(this_player()->query_flying()){
    write("You gently soar down from the high parapet.\n");
    message("info",this_player()->query_cap_name()+"soars down "
        "from above.","/d/khojem/port/room/r1",this_player()
    );
    return 1;
  }
  write("That might not be a good idea.  It is kinda high.\n");
  return 0;
}


