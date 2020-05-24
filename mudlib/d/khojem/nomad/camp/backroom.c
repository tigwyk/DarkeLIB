//      Wizard:  Khojem
//      backroom
//      backroom.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

void init() {
    ::init();
}

void reset() {
    ::reset();
   if(!present("gambler")) {
      new("/d/khojem/nomad/mon/gambler")->move(this_object());
   }
   if(!present("pit boss")) {
      new("/d/khojem/nomad/mon/pit_boss")->move(this_object());
   }
}

void create() {
  object obj;
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set_property("night light",0);
    set("day long",
      "The daytime sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "+
      "Night or day...  Babba always keeps his backroom dark.  The patrons like "+
      "it that way.  Dark heavy smoke layers down from the tent's ceiling.  It "+
      "appears this is the local gambling hall."
   );
    set("night long",
      "The torchlight sends odd, flickering shadows across the room.  "+
      "Night or day...  Babba always keeps his backroom dark.  The patrons like "+
      "it that way.  Dark heavy smoke layers down from the tent's ceiling.  It "+
      "appears this is the local gambling hall."
    );
    add_exit("/d/khojem/nomad/camp/pub","northeast");
    set_door("curtain","/d/khojem/nomad/camp/pub","northeast",0);
    set_func("curtain","open","do_open");
    set_func("curtain","close","do_close");
    set_items(([
     ({ "flap", "tent flap" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "canvas" }) :
        "The canvas is soiled and sooty from many nights of torch smoke.",
     ({ "floor", "sand" }) :
        "The tent was setup on a bare sandy floor.  The bedrolls are layed "+
        "out on the sand."
    ]));
    set_smell("default", "The strong smell of burning tobacco fills the tent.");
    set_listen("default", "The din from the hash house can be heard in the distance.");
    obj=new("/d/khojem/nomad/obj/roulette_wheel");
    obj->move(this_object());
}

void look_at_door() {
  if(query_open("curtain")) 
    write("The curtain is open and the tent extents on to the northeast.");
  else 
    write("The curtain is closed.\n");
  say(this_player()->query_cap_name()+" looks at the curtain.\n");
}

int do_open() {
  remove_invis_exit("northeast");
  "/d/khojem/nomad/camp/pub"->remove_invis_exit("southwest");
  write("The curtain flows away as you open it.");
  say(this_player()->query_cap_name()+" opens a curtain.");
  return 1;
}
 
int do_close() {
  add_invis_exit("northeast");
  "/d/khojem/nomad/camp/pub"->add_invis_exit("southwest");
  write("A curtain falls limpy to the floor.\n");
  say(this_player()->query_cap_name()+" closes a curtain.\n");
  return 1;
}
