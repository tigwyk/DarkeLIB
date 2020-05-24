//      Wizard:  Khojem
//      s18.c

#include <std.h>
inherit ROOM;

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
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n    \n0--@--0\n    \n   \nNoble Street");
    set("long", "Noble Street extends east and west.  "+
      "The street's dry dirt sends up small swirls of dust with every "+
      "footstep.  From here you can see a large mansion to the east at the "+
      "turn of the street.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/s15","west");
    add_exit("/d/khojem/port/room/s20","east");
    set_items(([
     ({ "street","dirt street","Wharf Street","wharf street" }) :
        "Its a dusty little road.",
     ({ "mansion" }) :
        "A large house with mustard colored paint and a sloping roof.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

