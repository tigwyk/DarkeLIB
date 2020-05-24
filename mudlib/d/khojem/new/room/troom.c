//      Wizard:  Khojem
//      Half-Orc Treasure Room
//      troom.c

#include <std.h>

inherit VAULT;

void create() {
    int    amt;
    object money;
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "An underground vault");
    set("long", "This is a very small chamber.  Stone walls "+ 
      "surround the small vault.  The air is dank and stale.  "+
      "Several cobwebs hang from the stone ceiling and water "+
      "seeps through the north wall and trails a small pool "+
      "across the stone floor."
    );
    add_exit("orc7","south");
    set_door("stone door","/d/khojem/new/room/orc7","south","chieftain's key");
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
        "would be an impossible task.",
     ({ "cobweb", "cobwebs", "web", "webs" }) :
        "The sticky, silklike threads hang from the ceiling.  Dust covers "+
        "the web.  This tomb probably yielded few catches for the spider "+
        "that abandoned this web.",
     ({ "water", "seepage" }) :
        "What little water that managed to seep through the wall over time "+
        "has trailed across the dusty floor.  The dust has turned the water "+
        "into a sticky, undrinkable paste."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
    amt = random(10)*200+400;
    money = new("std/obj/coins");
    money->set_money("silver",amt);
    money->move(this_object());
}

void look_at_door() {
  if(query_open("stone door")) 
    write("The stone door is open wide.  From beyond the hallway's "+
      "faint light is quickly doused in this cavern.\n");
  else 
    write("The stone door is closed.  It blends into the stone wall.\n");
  say(this_player()->query_cap_name()+" carefully examines the stone wall.\n");
}

int do_open() {
  remove_invis_exit("south");
  "/d/khojem/new/room/orc7"->remove_invis_exit("north");
  write("With considerable effort you manage to open the door.\n"+
    "The stone door's hinges moan and creak as the door opens.\n"+
    "Even the stale air from the hallway seems fresh compared to\n"+
    "the air in this dank tomb.\n");
  say(this_player()->query_cap_name()+" leans and pushes against the "+
    "stone door.  With a moan the door slowly swings open.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("south");
  "/d/khojem/new/room/orc7"->add_invis_exit("north");
  write("The weight of the stone door makes it difficult to close.\n"+
    "It creaks and moans but finally slams shut with a hollow rumble.\n"+
    "You are sealed up in this tomb-like cavern.\n");
  say(this_player()->query_cap_name()+" struggles against the weight "+
    "of the stone door but manages to close it.  The door slams shut "+
    "with a deep, rumble.\n");
  return 1;
}
