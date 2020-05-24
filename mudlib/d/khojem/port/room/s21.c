//      Wizard:  Khojem
//      s21.c

#include <std.h>

inherit VAULT;

int no_exit() { return 1;}

int check_mobs();
int my_mob_filter(object mob);

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/port/mon/peon")  
    return 1;                                        
  return 0;
}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","west");
    }
}

void reset(){
  set_open("mauve door",0);
  set_locked("mauve door",0);
  "/d/khojem/port/room/hou6"->set_open("mauve door",0);
  "/d/khojem/port/room/hou6"->set_locked("mauve door",0);
  add_invis_exit("west");
  "/d/khojem/port/room/hou6"->add_invis_exit("west");
  if(!present("peon")) {
    if(check_mobs()<5)
      new("/d/khojem/port/mon/peon")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n   @   \n   | \n   0\nNoble Street");
    set("long", "Noble Street extends east and west.  Its dry, dirt road sends up "+
      "small swirls of dust with every footstep.  From here you can see a large mansion to the north at the "+
      "turn of the street.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("/d/khojem/port/room/s20","north");
    add_exit("/d/khojem/port/room/s22","south");
    add_exit("/d/khojem/port/room/hou6","west");
    add_invis_exit("west");
    set_door("mauve door","/d/khojem/port/room/hou6","west",0);
    set_open("mauve door",0);
    set_locked("mauve door",0);
    set_func("mauve door","open","do_open");
    set_func("mauve door","close","do_close");
    set_items(([
     ({ "mauve door", "door" }) :
        (: call_other, this_object(), "look_at_door" :),
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road.",
     ({ "mansion" }) :
        "A large house with mustard colored paint and a sloping roof.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

void look_at_door() {
  if(query_open("mauve door")) 
    write("The mauve door is wide open.\n");
  else 
    write("The mauve door is closed.\n");
  say(this_player()->query_cap_name()+" examines a mauve door to the west.\n");
}

int do_open() {
  remove_invis_exit("west");
  "/d/khojem/port/room/hou6"->remove_invis_exit("east");
  write("The mauve door easily swings open.\n");
  say(this_player()->query_cap_name()+" opens a mauve door to the west.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("west");
  "/d/khojem/port/room/hou6"->add_invis_exit("west");
  write("A mauve door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a mauve door shut.\n");
  return 1;
}

