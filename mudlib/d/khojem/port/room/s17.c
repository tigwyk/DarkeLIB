//      Wizard:  Khojem
//      s17.c

#include <std.h>
inherit ROOM;

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

void reset(){
  ::reset();
  if(!present("peon")) {
    if(check_mobs()<5)
      new("/d/khojem/port/mon/peon")->move(this_object());
  }
}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","down");
      add_action("no_exit","northeast");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
    set("short", " 0 0 0\n  \\|/ \n0--@--0\n    \n   \n	North West East SouthVo'Sangor Square");
    set("long", "North West East SouthVo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "to the west. Dock Street extends east from here and borders the harbor "+
      "to the south.  This corner of the square is constructed of wooden boards "+
      "and supported above the harbor's water by timbers. "+
      "A ladder is here that leads down to the water's surface.\n 0 0 0\n  \\|/ \n0--@--0\n    \n   \n	"  
    );
    add_exit("/d/khojem/port/room/s16","north");
    add_exit("/d/khojem/port/room/s09","west");
    add_exit("/d/khojem/port/room/s19","east");
    add_exit("/d/khojem/port/room/s08","northwest");
    add_exit("/d/khojem/port/room/tp","northeast");
    add_exit("/d/khojem/port/room/h1","down");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
     ({ "ladder" }) :
        "It is a simple wooden ladder that leads down from the edge of the "+
        "dock to the water's surface a few feet below.",
     ({ "square","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Dock Street","dock street","dock" }) :
        "Dock Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.\n"+
      "Waves in the harbor lap against the dock's pilings.");
}

int go_down() {
    write("Khojem suddenly materializes from the air and says,\n"+
      "     'I haven't implemented the water code yet.  Hang on!'\n");
    return 0;
}

