
#include "../ruins.h"
#include <std.h>

inherit VAULT;

void create() {
    ::create();
set_property("light", 1);
set_property("indoors", 0);
set("short", "The Hallway Of An Ancient Basement");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues west. There is a%^YELLOW%^door%^RESET%^to the south
 
0--@
ext);
set("night long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a small passage. The passage
way continues west. There is a%^YELLOW%^door%^RESET%^to the south

 0--@
ext);
add_exit(ROOMS+"basement1.c", "west");
add_exit(ROOMS+"basement8.c", "south");
set_door("stone door", (ROOMS+"basement8"), "south", "rat-man's key");
    set_func("stone door","open","do_open");
    set_func("stone door","close","do_close");
    set_property("magic hold",30);
    set_items(([
     ({ "door", "stone door", "stone" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "cave","cavern", "vault" }) :
        "The cavern is very narrow and small.   You feel cramped.",
     ({ "walls", "floor", "wall" }) :
        "The walls and floor are made of cold, hard stone.  Digging out "+
        "would be an impossible task."
    ]));
    set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "There is a sound of rats coming from the west");
 
    
}

void look_at_door() {
  if(query_open("stone door")) 
    write("The stone door is open wide.  From beyond the hallway's faint
light is quickly doused in this cavern.");
  else 
    write("The stone door is closed.  It blends into the stone wall.\n");
  say(this_player()->query_cap_name()+" carefully examines the stone
wall.");
}
int do_open() {
  remove_invis_exit("south");
(ROOMS+"basement8.c")->remove_invis_exit("north");
  write("With considerable effort you manage to open the door. The stone
door's hinges moan and creak as the door opens. Even the stale air from the
hallway seems fresh compared to the air in this dank tomb.");
  say(this_player()->query_cap_name()+" leans and pushes against the stone
door.  With a moan the door slowly swings open.");
  return 1;
}
 
int do_close() {
  add_invis_exit("south");
(ROOMS+"basement8.c")->add_invis_exit("north");
  write("The weight of the stone door makes it difficult to close. It
creaks and moans but finally slams shut with a hollow rumble. You are
sealed up in this tomb-like cavern.");
  say(this_player()->query_cap_name()+" struggles against the weight of the
stone door but manages to close it.  The door slams shut with a deep,
rumble.");
  return 1;
}

