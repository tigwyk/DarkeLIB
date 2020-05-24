//      Wizard:  Khojem
//      s09.c

#include <std.h>

inherit VAULT;

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
  if(base_name(mob) == "/d/khojem/port/mon/constable")  
    return 1;                                        
  return 0;
}

void init() {
    ::init();
    add_action("do_drink", "drink");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","tower");
    }
}

void reset(){
  set_open("iron door",0);
  set_locked("iron door",0);
  "/d/khojem/port/room/l1"->set_open("iron door",0);
  "/d/khojem/port/room/l1"->set_locked("iron door",0);
  add_invis_exit("tower");
  "/d/khojem/port/room/l1"->add_invis_exit("southwest");
  if(!present("constable")) {
    if(check_mobs()<4)
      new("/d/khojem/port/mon/constable")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", " 0 0 0\n  \\|/ \n0--@--0\n  /| \n 0 0\nVo'Sangor Square");
    set("long", "Vo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "here and reaches up high towards the sky.\n 0 0 0\n  \\|/ \n0--@--0\n  /| \n 0 0\n"  
    );
    add_exit("/d/khojem/port/room/s04","west");
    add_exit("/d/khojem/port/room/s17","east");
    add_exit("/d/khojem/port/room/s10","south");
    add_exit("/d/khojem/port/room/s08","north");
    add_exit("/d/khojem/port/room/s16","northeast");
    add_exit("/d/khojem/port/room/s03","northwest");
    add_exit("/d/khojem/port/room/s05","southwest");
    add_exit("/d/khojem/port/room/l3","up");
    add_invis_exit("up");
    set_pre_exit_functions(({ "up" }),({"do_go"}));
    add_exit("/d/khojem/port/room/l1","tower");
    add_invis_exit("tower");
    set_door("iron door","/d/khojem/port/room/l1","tower",0);
    set_open("iron door",0);
    set_locked("iron door",0);
    set_func("iron door","open","do_open");
    set_func("iron door","close","do_close");
    set_items(([
     ({ "iron door" }) : 
        (: call_other, this_object(), "look_at_door" :),
     ({ "square","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower with no visible windows.  "+
        "It appears the only means of entry is a large iron door at its base.",
     ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
    new("/d/khojem/port/obj/fountain1")->move(this_object());
}

void look_at_door() {
  if(query_open("iron door")) 
    write("The iron door is wide open.\n");
  else 
    write("The iron door is closed.\n");
  say(this_player()->query_cap_name()+" examines a iron door at the "+
    "base of the tower.\n");
}

int do_open() {
  remove_invis_exit("tower");
  "/d/khojem/port/room/l1"->remove_invis_exit("southwest");
  say(this_player()->query_cap_name()+" opens an iron door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("tower");
  "/d/khojem/port/room/l1"->add_invis_exit("southwest");
  say(this_player()->query_cap_name()+" slams a iron door shut.\n");
  return 1;
}

int do_drink(string str) {
  if(!str) {
    notify_fail("What do you want to drink?\n");
    return 0;
  }
  if(str!="water" && str!="fountain") {
    return 0;
  }    
  this_player()->add_quenched(-10);
  this_player()->add_poisoning(30);
  write("You bend down and drink the clear water from the fountain.\n"+
    "Your eyes bulge and you spit out the brackish, salt water!\n");
  say(this_player()->query_cap_name()+" starts chugging the water "+
    "from the fountain.  Suddenly, "+this_player()->query_cap_name()+
    "eyes start to bulge and spits the water out at your feet!.\n",
    this_player());
  return 1;
}


int do_go() {
  if(this_player()->query_flying()){
    write("You gently soar up the face of the high tower.\n");
    return 1;
  }
  return 0;
}

