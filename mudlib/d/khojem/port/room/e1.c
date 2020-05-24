//      Wizard:  Khojem
//      earl's mansion
//      e1.c

#include <std.h>

inherit VAULT;

void reset(){
  ::reset();
  if(!present("legionnaire"))
    new("/d/khojem/port/mon/legion1")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "A massive mansion");
    set("long", "This fine mansion is elaborately furnished with heavy slate "+
      "floors and mahogany furniture.  The walls are paneled in english oak and "+
      "a large crystal chandelier is suspended from a high ceiling.  The Earl of "+
      "Vo'Sangor must use this mansion for many affairs of state.  A wide, slate "+
      "staircase leads to the second floor.  A smaller exit reveals steps leading "+
      "down into the basement."
    );
    add_exit("/d/khojem/port/room/e2","north");
    add_exit("/d/khojem/port/room/e3","up");
    add_exit("/d/khojem/port/room/e4","down");
    add_exit("/d/khojem/port/room/s20","southwest");
    add_invis_exit("southwest");
    set_pre_exit_functions(({"up"}),({"go_up"}));
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_door("teal door","/d/khojem/port/room/s20","southwest",
      "sangor key");
    set_func("teal door","open","do_open");
    set_func("teal door","close","do_close");
    set_items(([
     ({ "mansion" }) : "It's a hell of a pad!",
     ({ "crystal chandelier", "chandelier", "ceiling" }) :
        "Gazing upwards at the momentarily awed by the crystal chandelier's "+
        "exquisite beauty.  Never before have you seen such finely crafted "+
        "work.",
     ({ "furniture", "mahogany furniture" }) :
        "The mahogany furniture was probably imported.  It's wood is highly "+
        "polished.",
     ({ "floors", "slate floors", "floor" }) :
        "The slate floors are finely crafted and well maintained.",
     ({ "walls", "wall", "english oak", "english oak walls", "paneling" }):
        "The english oak wall paneling is highly polished and of the finest "+
        "quality.  It is exquisitely molded with fine details and scrollwork.",
     ({ "stairs", "staircase", "steps", "slate staircase" }) :
        "A wide slate staircase leads upwards and a narrow set of steps lead down.",
     ({ "teal door", "door" }) :
        (: call_other, this_object(), "look_at_door" :)
    ]));
    set_smell("default", "A musty smell fills the air.");
    set_listen("default", "The house is quiet.");
}

void look_at_door() {
  if(query_open("teal door")) 
    write("The teal door is wide open.\n");
  else 
    write("The teal door is closed.\n");
  say(this_player()->query_cap_name()+" examines a teal door.\n");
}

int do_open() {
  remove_invis_exit("southwest");
  "/d/khojem/port/room/s20"->remove_invis_exit("northeast");
  write("A teal door swings wide open.\n");
  say(this_player()->query_cap_name()+" opens a teal door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("southwest");
  "/d/khojem/port/room/s20"->add_invis_exit("northeast");
  write("A teal door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a teal door shut.\n");
  return 1;
}

int go_up() {
  if(present("legion")) {
    write("The legionnaire humilates you as you attempt to climb the steps.\n");
    say("The legionnaire humilates "+this_player()->query_cap_name()+
      " by blocking the path to the staircase.\n");
    return 0;
  }
  else return 1;
}

int go_down() {
  if(present("legion")) {
    write("The legionnaire humilates you as you attempt to decend the steps.\n");
    say("The legionnaire humilates "+this_player()->query_cap_name()+
      " by blocking the path to the steps leading down.\n");
    return 0;
  }
  else return 1;
}
