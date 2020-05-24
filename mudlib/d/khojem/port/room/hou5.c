//      Wizard:  Khojem
//      hou5.c

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
  if(base_name(mob) == "/d/khojem/port/mon/citizen2")  
    return 1;                                        
  return 0;
}

void reset(){
  ::reset();
  if(!present("citizen")) {
    if(check_mobs()<5)
      new("/d/khojem/port/mon/citizen2")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A small house");
    set("long", "This small, little house is clean and well maintained.  "+
      "The woodwork is well cared for and cleaned regularly.  The individual "+
      "owning this home must be wealthy enough to afford the expensive maintaince."
    );
    add_exit("/d/khojem/port/room/s15","north");
    set_door("acqua door","/d/khojem/port/room/s15","north",0);
    set_func("acqua door","open","do_open");
    set_func("acqua door","close","do_close");
    set_items(([
     ({ "acqua door", "door" }) :
        (: call_other, this_object(), "look_at_door" :)
    ]));
    set_smell("default", "A musty smell fills the air.");
    set_listen("default", "The house is quiet.");
}

void look_at_door() {
  if(query_open("acqua door")) 
    write("The acqua door is wide open.\n");
  else 
    write("The acqua door is closed.\n");
  say(this_player()->query_cap_name()+" examines a acqua door.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/port/room/s15"->remove_invis_exit("south");
  write("A acqua door swings wide open.\n");
  say(this_player()->query_cap_name()+" opens a acqua door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/port/room/s15"->add_invis_exit("south");
  write("A acqua door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a acqua door shut.\n");
  return 1;
}

