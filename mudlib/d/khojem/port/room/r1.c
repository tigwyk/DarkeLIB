//      Wizard:  Khojem
//      r1.c

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
    add_action("do_drink","drink");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","up");
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light",1);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/202
    set("short", "  \n     \n   @--0\n    \n   \nBox Canyon");
    set("long", "Noble Street terminates here at a small box-like canyon.  "+
      "The ground is dry dirt that sends up small swirls of dust with every "+
      "footstep.  The great north and west walls of Vo'Sangor connects to a massive "+
      "escarpment.  The escarpment towers above you.  "+
      "Its sheer face makes climbing it very difficult.\n  \n     \n   @--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/r2","up");
    add_invis_exit("up");
    set_pre_exit_functions(({ "up" }),({"do_go"}));
    add_exit("/d/khojem/port/room/s06","east");
    set_items(([
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road.",
     ({ "wall", "escarpment", "canyon" ,"walls"}) :
        "The city's north and west walls are fixed to a massive rock formation "+
        "with sheer cliffs that tower above you.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
    new("/d/khojem/port/obj/fountain2")->move(this_object());

}

int do_go() {
  int zstat;
  if(this_player()->query_flying()){
    write("You gently sore up the face of the high tower.\n");
    return 1;
  }
  zstat=((int)this_player()->query_stats("dexterity"));
  if(random(100)<zstat) {
    write("You struggle greatly, but manage to climb the rock face.\n");
    return 1;
  }
  write("You try to climb the rock face, but slip back down to the ground "+
    "after only a few feet.\n");
  say(this_player()->query_cap_name()+" attempts to climb the rock face, "+
    "but fails miserably\n");
  return 0;
}


int do_drink(string str) {
  if(!str) {
    notify_fail("What do you want to drink?\n");
    return 0;
  }
  if(str!="water" && str!="fountain") {
    return 0;
  }    
  this_player()->add_quenched(5);
  write("You bend down and drink the clear water from the fountain.\n");
  say(this_player()->query_cap_name()+" drinks some water.\n",
    this_player());
  return 1;
}

