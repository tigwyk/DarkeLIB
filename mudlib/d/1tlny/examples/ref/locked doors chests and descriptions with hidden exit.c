//      Wizard:  Khojem
//      sand pit 3
//      sp3.c

#include <std.h>

inherit VAULT;

int exit_found;

void init(){
     ::init();
}

void reset(){
  if(!present("spider")) {
    new("/d/khojem/nomad/mon/king_spider")->move(this_object());
  }
  if(exit_found){
    remove_invis_exit("north");
    remove_exit("north");
    exit_found=0;
  }
  if(query_open("sandstone door")) {
    set_open("sandstone door",0);
    set_locked("sandstone door",1);
    "/d/khojem/nomad/room/tomb"->set_open("sandstone door",0);
    "/d/khojem/nomad/room/tomb"->set_locked("sandstone door",1);
    add_invis_exit("east");
    "/d/khojem/nomad/room/tomb"->add_invis_exit("west");
  }   
}

void create() {
    object obj;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "A dark sand pit");
    set("long",
      "You are in a dimly lit chamber.  The ceiling is very low and old cobwebs "+
      "dangle from it just above your head.  The sand floor muffles your "+
      "footsteps but any noise you make echos off the sandstone walls."
   );
    add_exit("/d/khojem/nomad/room/sp2","south");
    add_exit("/d/khojem/nomad/room/tomb","east");
    add_invis_exit("east");
    set_door("sandstone door","/d/khojem/nomad/room/tomb","east",
      "sand key");
    set_open("sandstone door",0);
    set_locked("sandstone door",1);
    set_func("sandstone door","open","do_open");
    set_func("sandstone door","close","do_close");
    set_property("magic hold",70);
    set_items(([
     ({ "door", "sandstone door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "cave","cavern", "chamber" }) :
        "The chamber is void of comforts.",
     ({ "walls", "floor", "sand" }) :
        "The floor is composed of soft, silky sand.  The walls are a hard, crumbly "+
        "sandstone."
    ]));
    set_smell("default", "It smells awful here, but you can't figure out the smell.");
    set_listen("default", "You hear the sound of some small animals skirting about "+
      "on the sandy floor.");
    set_search("default",(: call_other, this_object(),"do_search" :));
    obj=new("/d/khojem/nomad/obj/spider_chest");
    obj->move(this_object());
    obj->toggle_closed();
    obj->set_lock("locked");
    exit_found=0;
}

void look_at_door() {
  if(query_open("sandstone door")) 
    write("The sandstone door is open wide and beyond is nothing but darkness.\n");
  else 
    write("The sandstone door is closed.  You can barely see the outline of the door "+
      "in the sandstone wall to the east.\n");
  say(this_player()->query_cap_name()+" carefully examines the sandstone wall "+
    "on the east wall of the chamber.\n");
}

int do_open() {
  remove_invis_exit("east");
  "/d/khojem/nomad/room/tomb"->remove_invis_exit("west");
  write("The sandstone door makes a grinding noise as it opens.\n"+
    "Sand falls from the door's sill and dusts you in sand.\n");
  say(this_player()->query_cap_name()+" slowly opens the sandstone door to "+
    "the east.  It makes a grinding noise and sand falls from its sill.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("east");
  "/d/khojem/nomad/room/tomb"->add_invis_exit("west");
  write("The sandstone door makes a grinding sound as it closes shut.\n");
  say(this_player()->query_cap_name()+" closes the sandstone door.  It makes "+
    "a grinding sound as it closes.\n");
  return 1;
}
void do_search() {
  int skill;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "the chamber.\n");
  skill=((int)this_player()->query_skill("perception"))-20;
  if(random(100)<skill){
    write("Your search is successful.\n"+
      "You discover a secret exit in the north wall!");
    add_exit("/d/khojem/nomad/room/rv4","north");
    add_invis_exit("north");
    exit_found=1;
  }
  else
    write("Your search yields nothing.");
  return;
}
