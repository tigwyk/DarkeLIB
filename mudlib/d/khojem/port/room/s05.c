//      Wizard:  Khojem
//      s05.c

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
  if(base_name(mob) == "/d/khojem/port/mon/peon")  
    return 1;                                        
  return 0;
}

void reset(){
  ::reset();
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
    set("short", "   0 0\n   |/ \n   @--0\n     \n    \nVo'Sangor Square");
    set("long", "Vo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "to the northeast.\n   0 0\n   |/ \n   @--0\n     \n    \n"  
    );
    add_exit("/d/khojem/port/room/s04","north");
    add_exit("/d/khojem/port/room/s10","east");
    add_exit("/d/khojem/port/room/s09","northeast");
    set_items(([
     ({ "square","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

