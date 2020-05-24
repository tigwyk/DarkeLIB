//      Wizard:  Khojem
//      earl's vault
//      e7.c

#include <std.h>

inherit VAULT;

void reset(){
  ::reset();
  if(!present("demi-dragon"))
    new("/d/khojem/port/mon/demi-dragon")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A large vault");
    set("long", "This large room serves as a vault for the Earl of Vo'Sangor.  "+
      "The massive stone walls and heavy brass door make forced entry unlikely."
    );
    add_exit("/d/khojem/port/room/e4","west");
    set_pre_exit_functions(({ "west"}),({"go_west"}));
    set_door("brass door","/d/khojem/port/room/e4","west",
      "earl_vault_key");
    set_func("brass door","open","do_open");
    set_func("brass door","close","do_close");
    set_items(([
     ({ "brass door", "door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "basement","hallway", "walls", "wall", "floor" }) :
        "The stone walls and floor are sturdy and firm.  No secret passageways "+
        "here.",
    ]));
    set_smell("default", "A putrid smell fills the air.");
    new("/d/khojem/port/obj/pchest")->move(this_object());
}

void look_at_door() {
  if(query_open("brass door")) 
    write("The brass door is wide open.\n");
  else 
    write("The brass door is closed.\n");
  say(this_player()->query_cap_name()+" examines a brass door.\n");
}

int do_open() {
  if(present("demi-dragon") && !(this_player()->query_ghost())) {
    write("\nThe brass opens partially, but then the demi-dragon "+
      "lets out an angry growl and slams the door shut!\n");
    say(this_player()->query_cap_name()+" attempts to open the door "+
      "but the angry demi-dragon growls and slams the brass door shut!\n");
    tell_room("/d/khojem/port/room/e4", "The brass door opens "+
      "partially before it is slammed shut!\n");
    return 0;
  }
  remove_invis_exit("west");
  "/d/khojem/port/room/e4"->remove_invis_exit("east");
  write("A brass door swings wide open.\n");
  say(this_player()->query_cap_name()+" opens a brass door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("west");
  "/d/khojem/port/room/e4"->add_invis_exit("east");
  write("A brass door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a brass door shut.\n");
  return 1;
}

