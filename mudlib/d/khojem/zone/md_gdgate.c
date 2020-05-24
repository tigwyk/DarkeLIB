//      Wizard:  Khojem
//      MD-Guard Gate
//      md_gdgate.c

#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Gate Sentry Post");
    set("long", "It is lighter here and you can see more.  You stand before "+
      "a set of large stone gates.  Except for the gate your surroundings "+
      "are cloaked in darkness."
   );
   set_items(([
      ({ "gate", "gates", "stone gate", "stone gates" }) : 
        (: call_other, this_object(), "look_at_gate" :)
      ]));
   add_exit("md_entry","north");
   add_exit("md_gdroom","south");
   set_door("gate","/d/khojem/zone/md_gdroom","south","sentry gate key");
   set_pre_exit_functions(({ "south" }),({ "go_south" }));
   set_smell("default", "A horrible, rotten smell permeates the air.");
   set_listen("default", "All around you are the sounds of slow dripping water.");
   new("/d/khojem/zone/mon/ksentry")->move(this_object());
   set_open("gate",0);
   set_locked("gate",1);
   "/d/khojem/zone/md_gdroom"->set_open("gate",0);
   "/d/khojem/zone/md_gdroom"->set_locked("gate",1);
}

void look_at_gate() {
    write("The gate is very large and appears strong.\n"
          "There is a small keyhole.\n");
    if(query_open("gate")) write("The gate is open.\n");
    else write("The gate is closed.\n");
}

int go_south() {
  if(present("sentry")){
    write("The sentry blocks your exit.");
    return 0;
  }
  else return 1;
}

