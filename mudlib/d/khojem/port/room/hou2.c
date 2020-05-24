//      Wizard:  Khojem
//      hou2.c

#include <std.h>

inherit VAULT;

int check_mobs();
int my_mob_filter(object mob);

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/port/mon/citizen")  
    return 1;                                        
  return 0;
}

void reset(){
  ::reset();
  if(!present("citizen")) {
    if(check_mobs()<5)
      new("/d/khojem/port/mon/citizen")->move(this_object());
  }
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A small house");
    set("long", "This small, little house is in bad need of repair.  It is dark "+
      "and damp.  The years of neglect have allowed the moist, salt air to work "+
      "its way into the woodwork of a once fine house."
    );
    add_exit("/d/khojem/port/room/s01","north");
    set_door("red door","/d/khojem/port/room/s01","north",0);
    set_func("red door","open","do_open");
    set_func("red door","close","do_close");
    set_items(([
     ({ "red door", "door", "north door" }) :
        (: call_other, this_object(), "look_at_door" :)
    ]));
    set_smell("default", "A musty smell fills the air.");
    set_listen("default", "The house is quiet.");
}

void look_at_door() {
  if(query_open("red door"))
    write("The red door is wide open.\n");
  else 
    write("The red door is closed.\n");
  say(this_player()->query_cap_name()+" examines a red door.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/port/room/s02"->remove_invis_exit("south");
  write("A red door swings wide open.\n");
  say(this_player()->query_cap_name()+" opens a red door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/port/room/s02"->add_invis_exit("south");
  write("A red door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a red door shut.\n");
  return 1;
}

