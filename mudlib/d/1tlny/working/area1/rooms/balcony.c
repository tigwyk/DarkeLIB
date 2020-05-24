// balcony

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "A sturdy balcony");
    set("long", "You are standing on a balcony overlooking the "+
      "mansion garden and forest below.  A doorway to the west "+
      "leads back inside of the mansion.  Far in the distance you "+
      "can also see the graveyard of Akkad."
  );
    add_item("wall","You see writing on the wall.");
    add_item("graveyard","The graveyard looks quiet and motionless.");
    add_item("garden","You can see a garden path leading to a gazebo.");
    add_item("writing","It is written in blood.");
    add_item("blood","All you can seem to make out is: 'They did it'.");
    add_exit("uehall2","west");

    set_smell("default", "You smell smoke.");
    set_listen("default", "You hear creaking wood.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("raven"))
      new(A1MON+"raven")->move(this_object());
      new(A1MON+"raven")->move(this_object());
      new(A1MON+"raven")->move(this_object());
      new(A1MON+"raven")->move(this_object());
   if(!present("man"))
      new(A1OBJ+"deadman2")->move(this_object());
}
