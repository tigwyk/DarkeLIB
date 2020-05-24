//      Wizard:  Khojem
//      Warrior Tent
//      warrior_tent.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
    }
}

void reset() {
    ::reset();
  if(query_open("tent flap")) {
    set_open("tent flap",0);
    set_locked("tent flap",0);
    "/d/khojem/nomad/camp/captain_tent"->set_open("tent flap",0);
    "/d/khojem/nomad/camp/captain_tent"->set_locked("tent flap",0);
    add_invis_exit("north");
    "/d/khojem/nomad/camp/captain_tent"->add_invis_exit("south");
  }   
}

void create() {
  object obj;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("night light",1);
    set("day long",
      "The daytime sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "
      "The tent serves as the lodgings for the camp's warriors.  Furnishing "+
      "is sparce here except for a few bunks and chairs.  The nomad warriors "+
      "aren't much at housekeeping.  The tent is large and made from a stiff, "+
      "sturdy canvas.  The tent is equipped to barracks about 30-40 warriors, "+
      "but it is strange you haven't seen any in camp.  Maybe they are off on "+
      "maneuvers or some other military-type activity."
   );
    set("night long",
      "The torchlight sends odd, flickering shadows across the room.  "+
      "The tent serves as the lodgings for the camp's warriors.  Furnishing "+
      "is sparce here except for a few tables and chairs.  The nomad warriors "+
      "aren't much at housekeeping.  The tent is large and made from a stiff, "+
      "sturdy canvas.  The tent is equipped to barracks about 30-40 warriors, "+
      "but it is strange you haven't seen any in camp.  Maybe they are off on "+
      "maneuvers or some other military-type activity."
    );
    add_exit("/d/khojem/nomad/camp/center","south");
    add_exit("/d/khojem/nomad/camp/captain_tent","north");
    add_invis_exit("north");
    set_door("tent flap","/d/khojem/nomad/camp/captain_tent","north",0);
    set_open("tent flap",0);
    set_locked("tent flap",0);
    set_func("tent flap","open","do_open");
    set_func("tent flap","close","do_close");
    set_items(([
     ({ "flap", "tent flap" }) : 
        (: this_object(), "look_at_door" :),
     ({ "tent", "barracks"  }) :  
        "The tent has a low-pitch roof and trussed with some timber bracing along "+
        "the roof's center.  Numerous bedrolls are arranged on the sandy floor.",
     ({ "table", "tables", "chair", "chairs" }) :
        "For a desert tribe these nomads seem to possess a fair amount of "+
        "wood constructed items.  The chairs are worn and cracked.  One is missing "+
        "a leg.  The tables are a small, square tables in the tent's corners.",
     ({ "canvas" }) :
        "The canvas is soiled and sooty from many nights of torch smoke.",
     ({ "floor", "sand" }) :
        "The tent was setup on a bare sandy floor.  The bedrolls are layed "+
        "out on the sand."
    ]));
    set_smell("default", "A musty smell fills the tent.");
    set_listen("default", "It is quieter here than out in the camp's center.");
    obj=new("/d/khojem/nomad/obj/warrior_locker");
    obj->move(this_object());
}

void look_at_door() {
  if(query_open("tent flap")) 
    write("The tent flap is open and the tent extents on to the north.\n");
  else 
    write("The tent flap is closed.\n");
  say(this_player()->query_cap_name()+" looks at the tent flap to the north.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/nomad/camp/captain_tent"->remove_invis_exit("south");
  write("The canvas tent flap folds away as you open it.\n");
  say(this_player()->query_cap_name()+" opens the tent flap on "+
    "the north wall.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/nomad/camp/captain_tent"->add_invis_exit("south");
  write("The tent flap falls limpy to the floor.\n");
  say(this_player()->query_cap_name()+" closes a tent flap on the north wall.\n");
  return 1;
}

