//      Wizard:  Khojem
//      Bir'Barrutt Wastelands Tomb
//      tomb.c

#include <std.h>

inherit VAULT;

int trap_found;
 

void reset(){
  if(trap_found) trap_found=0;
  if(query_open("trapdoor")) {
    set_open("trapdoor",0);
    "/d/khojem/nomad/room/pit"->set_open("trapdoor",0);
    add_invis_exit("down");
  }
  if(!present("mummy")){
    new("/d/khojem/nomad/mon/mummy")->move(this_object());
  }   
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A dark tomb");
    set("long", "This very, dark cramped chamber serves as a tomb.  "+
      "The walls are made of sandstone and the floor of soft sand."
    );
    add_exit("/d/khojem/nomad/room/sp3","west");
    set_door("sandstone door","/d/khojem/nomad/room/sp3","west","sand key");
    set_func("sandstone door","open","do_open");
    set_func("sandstone door","close","do_close");
    set_property("magic hold",70);
    set_search("floor",(: call_other, this_object(),"do_search" :));
    set_search("sand",(: call_other, this_object(),"do_search" :));
    set_items(([
     ({ "door", "sandstone door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "trapdoor" }) :
        (: call_other, this_object(), "look_at_trapdoor" :),
     ({ "tomb", "vault" }) :
        "The tomb is very small and cramped.",
     ({ "sand" }) :  "The floor is covered with soft sand.",
     ({ "walls", "floor", "wall" }) :
        "The walls are made of sandstone and the floor is covered with soft sand.",
    ]));
    set_smell("default", "The rank smell of rotting flesh is strong here.");
    set_listen("default", "The tomb is very quiet.");
    trap_found = 0;
}

void look_at_door() {
  if(query_open("sandstone door")) 
    write("The sandstone door is open wide and beyond is nothing but darkness.\n");
  else 
    write("The sandstone door is closed.  You can barely see the outline of the door "+
      "in the sandstone wall to the west.\n");
  say(this_player()->query_cap_name()+" carefully examines the sandstone wall "+
    "on the west wall of the tomb.\n");
}

void look_at_trapdoor() {
  if(!trap_found) return 0;
  if(query_open("trapdoor")) 
    write("The wooden trapdoor is open.  A dark tunnel leads downward.\n");
  else 
    write("A few aged wooden planks form a trapdoor in the center of the sandy floor.\n");
  say(this_player()->query_cap_name()+" carefully examines the trapdoor "+
    "on the tomb's sandy floor.\n");
}

int do_open() {
  remove_invis_exit("west");
  "/d/khojem/nomad/room/sp3"->remove_invis_exit("east");
  write("The sandstone door makes a grinding noise as it opens.\n"+
    "Sand falls from the door's sill and dusts you in sand.\n");
  say(this_player()->query_cap_name()+" slowly opens the sandstone door to\n"+
    "the east.  It makes a grinding noise and sand falls from its sill.\n");
  return 1;
}

int do_close() {
  add_invis_exit("west");
  "/d/khojem/nomad/room/sp3"->add_invis_exit("east");
  write("The sandstone door makes a grinding sound as it closes shut.\n");
  say(this_player()->query_cap_name()+" closes the sandstone door.  It makes "+
    "a grinding sound as it closes.\n");
  return 1;
}

int do_trap_open() {
  if(!trap_found) return 0;
  remove_invis_exit("down");
  "/d/khojem/nomad/room/pit"->remove_invis_exit("up");
  write("The trapdoor opens.  Its rusty hinges creak.\n");
  say(this_player()->query_cap_name()+" opens a trapdoor in the floor.  "+
    "Its rusty hinges creak while opening.\n");
  return 1;
}
 
int do_trap_close() {
  if(!trap_found) return 0;
  add_invis_exit("down");
  "/d/khojem/nomad/room/pit"->add_invis_exit("up");
  write("The trapdoor closes.  Its rusty hinges creak.\n");
  say(this_player()->query_cap_name()+" closes a trapdoor.  The hinges "+
    "creak and moan.\n");
  return 1;
}

void do_search() {
  int skill;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "the tomb's floor.\n");
  skill=((int)this_player()->query_skill("perception"));
  if(random(100)<skill){
    write("While sifting through the sand on the floor you uncover "+
      "a trapdoor!");
    add_exit("/d/khojem/nomad/room/pit","down");
    set_door("trapdoor","/d/khojem/nomad/room/pit","down",0);
    set_func("trapdoor","open","do_trap_open");
    set_func("trapdoor","close","do_trap_close");
    trap_found=1;
  }
  else
    write("Your search yields nothing.");
  return;
}
