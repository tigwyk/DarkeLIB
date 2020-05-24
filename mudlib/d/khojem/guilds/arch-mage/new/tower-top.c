//      Wizard:  Khojem
//      Arch-Mage Tower Roof
//      tower-top.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set("short", "Arch-Mage Tower Spy Post");
  set("long", 
    "This is the top of the tower.  You can see for miles in any "
    "direction.  The wind blows fairly briskly up here.  A set of "
    "steps lead down in the center of the stone floor.\n" 
  );
  add_exit("/d/damned/guilds/arch-mage/gm-room","down");
  add_exit("/d/damned/virtual/room_35_16.world","north");
  add_exit("/d/damned/virtual/room_36_17.world","norteast");
  add_exit("/d/khojem/port/room/s09","east");
  add_exit("/d/damned/virtual/room_35_18.world","west");
  add_exit("/d/damned/virtual/room_35_17.world","northwest");
  add_invis_exit("north");
  add_invis_exit("northeast");
  add_invis_exit("east");
  add_invis_exit("west");
  add_invis_exit("northwest");
  set_pre_exit_functions(({"north"}),({"go_north"}));
  set_pre_exit_functions(({"east"}),({"go_north"}));
  set_pre_exit_functions(({"northeast"}),({"go_north"}));
  set_pre_exit_functions(({"west"}),({"go_north"}));
  set_pre_exit_functions(({"northwest"}),({"go_north"}));
  set_items(([
    ({ "floor", "wall", "walls", "basalt blocks" }) :
       "The walls are unadorned.  The large blocks of basalt that "
       "are fitted to form the half wall bordering the tower's edge "
       "and floor appear old.  This tower appears to be eons old.",
  ]));
}

int go_north() {
  if(this_player()->query_flying()){
    write("You gently soar down from the high tower.\n");
    return 1;
  }
  write("That would be a bad idea.  A fall from this height is death.\n");
  say(this_player()->query_cap_name()+" foolishly thinks about jumping "
    "but reconsiders.\n");
  return 0;
}

