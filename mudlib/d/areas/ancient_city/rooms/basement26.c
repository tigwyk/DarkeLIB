
#include "../ruins.h"
#include <std.h>

inherit VAULT;

void reset() {
::reset();
if(!present("rat"))
{
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
}
}
void create() {
    ::create();
set_property("light", 1);
    set_property("indoors", 1);
set("short", "The Hallway Of An Ancient Basement");
set("day long", @ext The Hallway Of An Ancient Basement. The walls around you
look are fule of cracks and holes. The ceiling is also full of holes. There
is just enough light coming throw the holes in the ceiling for you to see.
To the north there is a stone%^YELLOW%^door%^RESET%^. The walls are lined with torches
    0   
    |   
    @
    |
    0
ext);
set("night long", @ext The Hallway Of An Ancient Basement. The walls around you
look are fule of cracks and holes. The ceiling is also full of holes. There
is just enough light coming throw the holes in the ceiling for you to see.
To the north there is a stone%^YELLOW%^door%^RESET%^. The walls are lined with torches
    0   
    |   
    @
    |
    0
ext);
add_exit(ROOMS+"basement27.c","south");
    add_exit(ROOMS+"basement24.c","north");
set_door("stone door",(ROOMS+"basement24.c"),"north","guard's key");
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
 set_listen("default", "The sound of rats fills the room");
 
    
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
  remove_invis_exit("north");
(ROOMS+"basement24.c")->remove_invis_exit("south");
  write("With considerable effort you manage to open the door. The stone
door's hinges moan and creak as the door opens. Even the stale air from the
hallway seems fresh compared to the air in this dank tomb.");
  say(this_player()->query_cap_name()+" leans and pushes against the stone
door.  With a moan the door slowly swings open.");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
(ROOMS+"basement24.c")->add_invis_exit("south");
  write("The weight of the stone door makes it difficult to close. It
creaks and moans but finally slams shut with a hollow rumble. You are
sealed up in this tomb-like cavern.");
  say(this_player()->query_cap_name()+" struggles against the weight of the
stone door but manages to close it.  The door slams shut with a deep,
rumble.");
  return 1;
}


