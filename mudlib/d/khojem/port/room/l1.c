//      Wizard:  Khojem
//      l1.c

#include <std.h>

inherit VAULT;

void reset(){
  ::reset();
  if(!present("assassin"))
    new("/d/khojem/port/mon/assassin")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", -2);
    set_property("indoors", 1);
    set("short", "A small house");
    set("long", "It is very dark at the base of this tower.  You can just "+
      "make out the details of the darkened room.  The walls are bare and "+
      "the old paint is beginning to peel and flake at numerous points.  "+
      "An iron staircase is on the other side of the room and it spirals "+
      "upward into the darkness."
    );
    add_exit("/d/khojem/port/room/l2","up");
    add_exit("/d/khojem/port/room/s09","southwest");
    set_door("iron door","/d/khojem/port/room/s09","southwest",0);
    set_func("iron door","open","do_open");
    set_func("iron door","close","do_close");
    set_items(([
     ({ "iron door" }) : 
        (: call_other, this_object(), "look_at_door" :)
    ]));
    set_smell("default", "A damp, musty smell fills the air.");
    set_listen("default", "You hear the wind howling from high above in the tower.");
}

void look_at_door() {
  if(query_open("iron door")) 
    write("The iron door has been left open.\n");
  else 
    write("The iron door is closed.\n");
  say(this_player()->query_cap_name()+" examines a iron door.\n");
}

int do_open() {
  remove_invis_exit("southwest");
  "/d/khojem/port/room/s09"->remove_invis_exit("tower");
  return 1;
}
 
int do_close() {
  add_invis_exit("southwest");
  "/d/khojem/port/room/s09"->add_invis_exit("tower");
  return 1;
}

