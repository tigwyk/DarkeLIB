
#include "../ruins.h"
#include <std.h>

inherit VAULT;

void reset() {
::reset();
if(!present("rat"))
{
new(MON+"rat_demon_key.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
new(MON+"rat_demon.c")->move(this_object());
}
if(query_open("stone door")) {
    set_open("stone door",0);
    set_locked("stone door",1);
  (ROOMS+"basement28.c")->set_open("stone door",0);
  (ROOMS+"basement28.c")->set_locked("stone door",1);
    add_invis_exit("south");
   (ROOMS+"basement28.c")->add_invis_exit("north");
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
There is a stone%^YELLOW%^door%^RESET%^to the south. Torches line the walls
    0   
    |   
    @
    |
    0
ext);
set("night long", @ext The Hallway Of An Ancient Basement. The walls around you
look are fule of cracks and holes. The ceiling is also full of holes. There
is just enough light coming throw the holes in the ceiling for you to see.
There is a stone%^YELLOW%^door%^RESET%^to the south. Torches line the walls
    0   
    |   
    @
    |
    0
ext);
add_exit(ROOMS+"basement26.c","north");
    add_exit(ROOMS+"basement28.c","south");
    add_invis_exit("south");
set_door("stone door",(ROOMS+"basement28.c"),"south", "demon's key");
    set_open("stone door",0);
    set_locked("stone door",1);
    set_func("stone door","open","do_open");
    set_func("stone door","close","do_close");
    set_property("magic hold",50);
    set_items(([
     ({ "door", "stone door", "stone" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "cave","cavern", "passage" }) :
        "The is very narrow and you feel cramped.",
     ({ "walls", "floor" }) :
"The walls and floor are very hard, dry clay.  Digging out would be an
impossible task."
]));
    set_smell("default", "The smell of rat guano fills your nostrils");
 set_listen("default", "The sound of rats fills the room");
}
void look_at_door() {
  if(query_open("stone door")) 
write("The stone door is open wide and beyond is nothing but darkness.");
  else 
    write("The stone door is closed.  You can barely make out the door's
seams. Usually such craftwork is done only by dwarves.");
say(this_player()->query_cap_name()+" carefully examines the northern stone
wall.");
}

int do_open() {
  remove_invis_exit("south");
 (ROOMS+"basement28.c")->remove_invis_exit("north");
write("With considerable effort you manage to open the door. The stone
door's hinges moan and creak as the door opens.");
  say(this_player()->query_cap_name()+" leans and pushes against the stone
door.  With a moan the door slowly swings open.");
  return 1;
}
 
int do_close() {
  add_invis_exit("south");
  (ROOMS+"basement28.c")->add_invis_exit("north");
write("The weight of the stone door makes it difficult to close. It creaks
and moans but finally slams shut with a hollow rumble.");
say(this_player()->query_cap_name()+" struggles against the weight of the
stone door but manages to close it.  The door slams shut and a deep, rumble
echos down the cavern hallway.");
  return 1;
}

