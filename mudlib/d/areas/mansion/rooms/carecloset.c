// carecloset

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "A cramped closet");
    set("long", @ext You now stand in the caretaker's private closet.  
      Darkness surrounds you, and the only thing that seems to be 
      stored here a couple boxes filled with old parchments.
  
    @
    |
    0  
ext);
    add_item("parchments","The old parchments crumble as you look "+
      "through them.  The only thing that you manage to read seems "+
      "to speak of raising the dead."
  );
    add_item("boxes","These old boxes hold many old parchments.");
    add_exit("carebed1","south");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear moaning.");
}
void reset() {
   if(!present("zombie"))
      new(A1MON+"zombie")->move(this_object());
}
