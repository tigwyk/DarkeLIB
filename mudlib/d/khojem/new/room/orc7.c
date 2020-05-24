//      Wizard:  Khojem
//      orc7
//      orc7.c

#include <std.h>

inherit VAULT;

void reset(){
  if(query_open("stone door")) {
    set_open("stone door",0);
    set_locked("stone door",1);
    "/d/khojem/new/room/troom"->set_open("stone door",0);
    "/d/khojem/new/room/troom"->set_locked("stone door",1);
    add_invis_exit("north");
    "/d/khojem/new/room/troom"->add_invis_exit("south");
  }   
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "   \n    \n0--@--0\n    \n   \nAn underground passage");
    set("long", "You are in an underground passage.  Dirt walls "+ 
      "surround the small passage and the dirt floor is hard and "+
      "smooth from repeated use.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("orc3","west");
    add_exit("orc8","east");
    add_exit("troom","north");
    add_invis_exit("north");
    set_door("stone door","/d/khojem/new/room/troom","north","chieftain's key");
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
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}

void look_at_door() {
  if(query_open("stone door")) 
    write("The stone door is open wide and beyond is nothing but darkness.\n");
  else 
    write("The stone door is closed.  You can barely make out the door's "+
      "seams.\nUsually such craftwork is done only by dwarves.\n");
  say(this_player()->query_cap_name()+" carefully examines the stone wall "+
    "on the north side of the hallway.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/new/room/troom"->remove_invis_exit("south");
  write("With considerable effort you manage to open the door.\n"+
    "The stone door's hinges moan and creak as the door opens.\n");
  say(this_player()->query_cap_name()+" leans and pushes against the "+
    "stone door.  With a moan the door slowly swings open.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/new/room/troom"->add_invis_exit("south");
  write("The weight of the stone door makes it difficult to close.\n"+
    "It creaks and moans but finally slams shut with a hollow rumble.\n");
  say(this_player()->query_cap_name()+" struggles against the weight "+
    "of the stone door but manages to close it.  The door slams shut "+
    "and a deep, rumble echos down the cavern hallway.\n");
  return 1;
}
