// Wizard:  Khojem
// captain's diary
// diary.c

#include <move.h>

inherit "/std/Object";

void init() {
     ::init();
  add_action("do_read","read");
}

void create() {
  ::create();
  set_name("captain's diary");
  set_id(({ "captain's diary", "diary" }) );
  set_short("a captain's diary");
  set_long("The captain's diary is a small, leather backed log of some sort.  "+
    "It's parchment appears fresh and appears to be relatively new.  "+  
    "Perhaps you can make out the captain's scrawl?"
  );
}

int do_read(string str) {
  if(str == "diary" || str == "captain's diary") { 
    this_player()->more("/d/khojem/nomad/obj/diary_text");
    return 1;
  }
  return 0;
}

