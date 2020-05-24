//      Wizard:  Khojem
//      s07.c

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
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n   @   \n   | \n   0\nWharf Street");
    set("long", "Wharf Street extends north and south.  "+
      "The street's dry dirt sends up small swirls of dust with every "+
      "footstep.  A tower of some sort and a large square can be seen to "+
      "the south.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("/d/khojem/port/room/s06","north");
    add_exit("/d/khojem/port/room/s08","south");
    set_items(([
     ({ "street","dirt street","Wharf Street","wharf street" }) :
        "Its a dusty little road.",
     ({ "square" }) :
        "It looks like a place where alot of people gather.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

