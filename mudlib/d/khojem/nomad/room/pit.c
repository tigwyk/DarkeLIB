//      Wizard:  Khojem
//      the pit
//      pit.c

#include <std.h>

inherit VAULT;

void init() {
    ::init();
    add_action("do_ooze","get");
    add_action("do_ooze","touch");
}

void reset() {
    ::reset();
    if(!present("worm")) {
      new("/d/khojem/nomad/mon/sand_worm")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A deep, dark chamber");
    set("long", "You are standing in a dark chamber under the tomb.  Sandstone walls "+
      "form the room into a circle.  A small pit is in the chamber's center.  "+
      "Above you the chamber's ceiling rises upward to the center.  A trapdoor "+
      "can be seen above."
    );
    add_exit("/d/khojem/nomad/room/tomb","up");
    set_door("trapdoor","/d/khojem/nomad/room/tomb","up",0);
    set_func("trapdoor","open","do_trap_open");
    set_func("trapdoor","close","do_trap_close");
    set_items(([
     ({ "trapdoor" }) : 
        (: call_other, this_object(), "look_at_trapdoor" :),
     ({ "pit" }) :
        (: call_other, this_object(), "look_at_pit" :),
     ({ "ooze" }) :
        (: call_other, this_object(), "look_at_ooze" :),
     ({ "floor", "sand" }) :
        "The sandy floor is filled with foul excrement and waste.  A pit "+
        "is in the center.",
     ({ "wall", "walls" }) :
        "The sandstone walls are hard to the touch and crumbles slightly "+
        "to your touch.",
     ({ "ceiling" }) :
        "The sandstone ceiling slopes upward to a trapdoor in the center.",
     ({ "chamber" }) :
        "A small, circular room with sand floors and sandstone walls."
    ]));
    set_smell("default", "A foul, rank smell fills the chamber.");
    set_listen("default", "Your every move caused the sound you generate "+
      "to reflect off the sandstone walls.");
}

void look_at_pit(){
  if(present("worm"))
    write("Protruding from the pit is a nasty looking sand worm.\n");
  else
    write("A deep pit opens in the center of the chamber.  "+
      "Foul-smelling ooze coats the pit's wall and bottom.\n");
  say(this_player()->query_cap_name()+" glances at the pit in the "+
    "center of the room.\n");
  return;
}

int look_at_ooze(){
  if(!present("worm")){
    write("It is a pasty, yellow muck which smells awful!  "+
      "Now you know where that retched smell was coming from!  "+
      "It coats the sides of the pit.\n");
    say(this_player()->query_cap_name()+" looks over the ooze.\n");
    return 1;
  }
  write("The worm is covered in dripping ooze!\n");
  say(this_player()->query_cap_name()+" looks over the ooze.\n");
  return 1;
}

int do_ooze(string str){
  if(str!="ooze") return 0;
  if(!present("worm")){
    say(this_player()->query_cap_name()+" whelps in pain after reaching "+
      "and touching the yellow ooze.\n");
    write("Owww!  You are badly burned by the acidic ooze!  "+
      "You decide it best to leave it alone.\n");
    this_player()->add_hp(-150);
    return 1;
  }
  write("The worm quickly turns towards you an bites your hand.\n");
  say(this_player()->query_cap_name()+" gets bitten on the hand by the "+
    "worm.\n");
  this_player()->add_hp(-50);
  return 1;
}

void look_at_trapdoor() {
  if(query_open("trapdoor")) 
    write("The trapdoor is open above your head.\n");
  else 
    write("The trapdoor is closed shut.\n");
  say(this_player()->query_cap_name()+" checks the trapdoor.\n");
}

int do_trap_open() {
  remove_invis_exit("up");
  "/d/khojem/nomad/room/tomb"->remove_invis_exit("down");
  write("The trapdoor's rusty hinges creak as you open it.\n");
  say(this_player()->query_cap_name()+" stretches up and opens the "+
    "trapdoor.  Its rusty hinges creak and moan.\n");
  return 1;
}
 
int do_trap_close() {
  add_invis_exit("up");
  "/d/khojem/nomad/room/tomb"->add_invis_exit("down");
  write("The trapdoor's rusty hinges creak as you close it.\n");
  say(this_player()->query_cap_name()+" stretches up and closes the "+
    "trapdoor.  Its rusty hinges creak and moan.\n");
  return 1;
}
