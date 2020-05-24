//      Wizard:  Khojem
//      ngate
//      ngate.c

#include <std.h>
inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("do_read","read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
    }
}

void reset() {
    ::reset();
    if(!present("gatekeeper")) {
      new("/d/khojem/port/mon/gatekeeper")->move(this_object());
      new("/d/khojem/port/mon/gatekeeper")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light",2);
    set_property("indoors", 1);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n   W \n   @--0\n   | \n   0\nThe north gate");
    set("day long",
      "An arched gateway, made from roughly-hewned stone, forms a small "+
      "alcove that protects the town's gatekeepers during their long duty "+
      "tour.  A dirt road extends to the south and the rest of the port town "+
      "of Vo'Sangor can be seen.  A brass sign is securely fastened to the wall.\n   \n   W \n   @--0\n   | \n   0\n"
   );
    set("night long",
      "An arched gateway, made from roughly-hewned stone, forms a small "+
      "alcove that protects the town's gatekeepers during their long duty "+
      "tour.  A dirt road extends to the south and a torch provides light.  "+
      "A brass sign is securely fastened to the wall."
    );
    add_exit("/d/damned/virtual/room_13_9.world","north");
    set_pre_exit_functions(({"north"}),({"exit_city"}));
    add_exit("/d/khojem/port/room/constable","east");
    add_exit("/d/khojem/port/room/s06","south");
    set_items(([
     ({ "arch","gateway" }) :
        "The stones of the arch are massive and superbly crafted.\n",
     ({ "road","dirt road" }) :
        "The dirt road is packed hard from constand traffic.\n",
     ({ "torch" }) :
        "A lone, oil-dampened torch provides the only light for the area.\n"
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town can be heard to the south.");
}

int do_read(string str){
  if(!str) {
    notify_fail("What is it you want to read?\n");
    return 0;
  }
  if(str != "sign") {return 0;}
  write("The shiney brass sign reads:\n"+
    "Welcome to Vo'Sangor\n\n"+
    "All must abide by the laws of the Earl of Vo'Sangor.\n"+
    "Criminals and thieves are punished by death!\n\n"+
    "This area brought to you by Mentor Wizard Khojem\n"
  );
  say(this_player()->query_cap_name()+" reads a sign.\n",this_player());
  return 1;
}


int exit_city() {
  int num_attackers;
  object *attackers;
  if(this_player()->query_ghost()) { return 1; }
  if(present("gatekeeper")) {
    attackers = (object *)this_player()->query_attackers();
    num_attackers = sizeof(attackers);
    if(num_attackers == 0) { return 1; }
    write("The gatekeeper drops his halberd and blocks your exit.\n");
    say("The gatekeeper momentarily drops his halberd and blocks "+
      this_player()->query_cap_name()+"'s exit.\n");
    return 0;
  }
  else return 1;
}
