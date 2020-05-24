//      Wizard:  Khojem
//      l2.c

#include <std.h>
inherit ROOM;

object obj;
int open_count,zopen;

void init() {
    ::init();
    add_action("do_open",  "open");
    add_action("do_close", "close");
}

void reset() {
    ::reset();
  if(!present("coffin")) {
    obj=new("/d/khojem/port/obj/earl_desk_key");
    obj->set_name("coffin");
    obj->set_short("a wooden coffin (closed)");
    obj->set_long("A heavy wooden coffin rests here.  Its wood has petrified from "+
      "years of exposure to the salt air.");
    obj->set_weight(10000);
    obj->move(this_object());
  }
  open_count = 0;
  zopen = 0;
}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set("short", "tower");
    set("long","The spiraling staircase pauses briefly at this wide landing.  "+
      "The iron staircase leads downward into darkness and upwards towards some "+
      "light in the distance.  The walls are bare and "+
      "the old paint is beginning to peel and flake at numerous points."
    );
    add_exit("/d/khojem/port/room/l1","down");
    add_exit("/d/khojem/port/room/l3","up");
    set_items(([
     ({ "walls", "wall", "paint", "peel", "flake" }) :
        "The walls are of stone construction and surfaced in stucco.  At numerous "+
        "spots the the moist, salt air has eroded the stucco and crumbled the "+
        "wall's surface.  At one time the surface of the stucco was supplied with "+
        "paint, but now the paint is peeling and chipped.",
     ({ "wide landing", "landing" }) :
        "The landing is constructed of iron and cantilevered from the tower's "+
        "outer wall.  It provides a point for a brief rest on the long climb up "+
        "the tower's center.",
     ({ "staircase" }) :
        "The iron staircase follows the curve of the tower's outer wall.  Each "+
        "step is afixed to the wall and cantilevered towards the center of the "+
        "wide tower.  The steps are rusted, but appear strong enough to support "+
        "your weight."
    ]));
    set_smell("default", "A damp, musty smell fills the air.");
    set_listen("default", "You hear the wind howling from high above in the tower.");
}

int do_open(string str) {
  object obj2;
  if(str != "coffin") { return 0; }
  if(!present("coffin")) { return 0; }
  zopen = 1;
  obj->set_short("a wooden coffin (open)");
  write("You open a wooden coffin (open).");
  say(this_player()->query_cap_name()+" opens a wooden coffin (open).");
  if(open_count == 0) {
    open_count=1;
    write("A frightful wight springs forth from the open coffin!");
    say("A frightful wight springs up from the coffin!\n");
    obj2 = new("/d/khojem/port/mon/wight");
    obj2 ->move(this_object());
    obj2 ->kill_ob(this_player(),0);
  }
  return 1;
}

int do_close(string str) {
  if(str != "coffin") { return 0; }
  if(!present("coffin")) { return 0; }
  obj->set_short("a wooden coffin (closed)");
  write("You close a wooden coffin (closed).");
  say(this_player()->query_cap_name()+" closes a wooden coffin (closed).");
  zopen = 0;
  return 1;
}
