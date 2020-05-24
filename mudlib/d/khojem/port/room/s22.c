//      Wizard:  Khojem
//      s22.c

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
  if(base_name(mob) == "/d/hojem/port/mon/citizen2")  
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
    set("short", "   0\n   | \n   @   \n   | \n   0\nNoble Street");
    set("long", "Noble Street extends north and south.  "+
      "The street's dry dirt sends up small swirls of dust with every "+
      "footstep.  A railing to the east protects travelers from falling into the "+
      "harbor's water.  Farther east you can see the backside of the Rusty "+
      "Parrot that is supported above the water by many timber stilts.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("/d/khojem/port/room/s21","north");
    add_exit("/d/khojem/port/room/s23","south");
    set_items(([
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road.",
     ({ "mansion" }) :
        "A large house with mustard colored paint and a sloping roof.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

