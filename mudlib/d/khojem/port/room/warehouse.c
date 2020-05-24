//      Wizard:  Khojem
//      warehouse.c

#include <std.h>
inherit ROOM;

int check_mobs();
int my_mob_filter(object mob);
int search_flag;

void reset() {
    ::reset();
  search_flag = 0;
  if(!present("worker")) {
    new("/d/khojem/port/mon/worker2")->move(this_object());
    new("/d/khojem/port/mon/worker2")->move(this_object());
  }
  if(check_mobs()<5) {
    new("/d/khojem/port/mon/worker1")->move(this_object());
    new("/d/khojem/port/mon/worker1")->move(this_object());
    new("/d/khojem/port/mon/worker1")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light",0);
    set_property("indoors", 1);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   \n    \n   @--0\n    \n   \nWarehouse on the Wharf");
    set("long","This is a dark warehouse.  Here items unloaded from merchant "+
      "vessels can be stored until a caravan is provisioned to move the "+
      "items inland.  Since the ships are unloading night and day, this "+
      "warehouse can stay very busy.  Many crates and boxes are stacked "+
      "here for storage.\n   \n    \n   @--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/s13","east");
    set_items(([
     ({ "warehouse" }) :
        "It looks like an old, weather-ravaged wooden warehouse.",
     ({ "items", "crates", "crate", "box", "boxes", "item" }) :
        "Numerous wooden crates and boxes are stacked about the warehouse.  "+
        "Many are imprinted with the names of merchants and faraway towns and "+
        "cities.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
    set_search("boxes",(: call_other, this_object(),"do_search" :));
    set_search("box",(: call_other, this_object(),"do_search" :));
    set_search("crates",(: call_other, this_object(),"do_search" :));
    set_search("crate",(: call_other, this_object(),"do_search" :));
    search_flag = 0;
}


void do_search() {
  int skill;
  object money;
  if(present("worker")) {
    write("A worker interrupts your search and asks you to leave.\n");
    return;
  }
  say(this_player()->query_cap_name()+" is searching the boxes and crates.");
  skill=(int)this_player()->query_skill("perception");
  if((random(100)<skill) && (search_flag == 0)){
    search_flag = 1;
    write("Your search is successful.");
    switch(random(11)){
      case 0:new("/d/damned/virtual/two-handed-sword_6.weapon")->
                 move(this_player());
             write("You found a two-handed sword.");
             break;
      case 1:new("/d/damned/virtual/spear_6.weapon")->
                 move(this_player());
             write("You found a spear.");
             break;
      case 2:new("/d/damned/virtual/broad-sword_6.weapon")->
                 move(this_player());
             write("You found a broad sword.");
             break;
      case 3:new("/d/damned/virtual/battle-axe_6.weapon")->
                 move(this_player());
             write("You found a battle axe.");
             break;
      case 4:new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_player());
             write("You found a dagger.");
             break;
      case 5:new("/d/damned/virtual/quarter-staff_6.weapon")->
                 move(this_player());
             write("You found a quarter staff.");
             break;
      case 6:new("/d/damned/virtual/great-axe_6.weapon")->
                 move(this_player());
             write("You found a great axe.");
             break;
      case 7:new("/d/damned/virtual/hammer_6.weapon")->
                 move(this_player());
             write("You found a hammer.");
             break;
      case 8:new("/d/damned/virtual/war-hammer_6.weapon")->
                 move(this_player());
             write("You found a war hammer.");
             break;
      case 9:skill = random(99) + 400;
             money = new("std/obj/coins");
             money->set_money("gold",skill);
             money->move(this_player());
             write("You found a pile of gold coins.");
             break;
    }
  }
  else
    write("Your search yields nothing.");
  return;
}

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/port/mon/worker1")  
    return 1;                                        
  return 0;
}

