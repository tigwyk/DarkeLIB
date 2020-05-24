#include <std.h>

inherit "/std/vault";

create() {
  string rn, fn, *tmp;
  int i;

  ::create();
  tmp = explode(file_name(this_object()), "/");
  fn = tmp[sizeof(tmp) -1];
  set_property("indoors", 1);
  set_property("light", 2);
  set("short", "A short hallway");
  set("long",
      "This is a short hallway with the entrances to ten rooms along "+
      "the walls.  Each door is numbered 'door #'.\n");
  if(!sscanf(fn, "hall_%d", rn)) {
    set("long", "Inn hall bug!!!!!\n");
    return;
  }
  for(i = rn*10; i < (rn*10+10); i++) {
    add_exit(sprintf("/d/khojem/port/virtual/inn_%d.inn", i),
             sprintf("room%d", i));
    set_door(sprintf("door %d", i), 
      sprintf("/d/khojem/port/virtual/inn_%d.inn", i),
             sprintf("room%d", i), sprintf("bl_key %d", i));
    set_open(sprintf("door %d", i), 0);
    set_locked(sprintf("door %d", i), 1);
    set_lock_level(sprintf("door %d", i), 18);
  }
  add_exit("/d/khojem/port/inn/foyer", "south");
  return;
}

