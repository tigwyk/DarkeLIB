//      Wizard:  Khojem
//      Captain Tent
//      captain_tent.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
}

void reset() {
    ::reset();
}

void create() {
  object obj;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("night light",1);
    set("day long",
      "The daytime sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "+
      "The tent serves as the lodgings for the camp's captain.  It is furnished "+
      "with a bunk, desk, and chair.  The captain, unlike the nomad warriors "+
      "keeps a neat and orderly tent.  This tent is smaller than the large "+
      "barracks tent to the south."
   );
    set("night long",
      "The torchlight sends odd, flickering shadows across the room.  "+
      "The tent serves as the lodgings for the camp's captain.  It is furnished "+
      "with a bunk, desk, and chair.  The captain, unlike the nomad warriors "+
      "keeps a neat and orderly tent.  This tent is smaller than the large "+
      "barracks tent to the south."
    );
    add_exit("/d/khojem/nomad/camp/warrior_tent","south");
    set_door("tent flap","/d/khojem/nomad/camp/warrior_tent","south",0);
    set_func("tent flap","open","do_open");
    set_func("tent flap","close","do_close");
    set_items(([
     ({ "flap", "tent flap" }) : 
        (: this_object(), "look_at_door" :),
     ({ "tent", "barracks"  }) :  
        "The tent has a low-pitch roof and trussed with some timber bracing along "+
        "the roof's center.",
     ({ "table", "tables", "chair", "chairs" }) :
        "The chair is worn and cracked.",
     ({ "canvas" }) :
        "The canvas is soiled and sooty from many nights of torch smoke.",
     ({ "floor", "sand" }) :
        "The tent was setup on a bare sandy floor."
    ]));
    set_smell("default", "A musty smell fills the tent.");
    set_listen("default", "The clamour from the rest of the camp is far to the south.");
    obj=new("/d/khojem/nomad/obj/desk");
    obj->move(this_object());
}

void look_at_door() {
  if(query_open("tent flap")) 
    write("The tent flap is open and the tent extents on to the south.\n");
  else 
    write("The tent flap is closed.\n");
  say(this_player()->query_cap_name()+" looks at the tent flap to the south.\n");
}

int do_open() {
  remove_invis_exit("south");
  "/d/khojem/nomad/camp/warrior_tent"->remove_invis_exit("north");
  write("The canvas tent flap folds away as you open it.\n");
  say(this_player()->query_cap_name()+" easily opens the tent flap on "+
    "the south wall.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/nomad/camp/warrior_tent"->add_invis_exit("north");
  write("The tent flap falls limpy to the floor.\n");
  say(this_player()->query_cap_name()+" closes a tent flap to the north.\n");
  return 1;
}

