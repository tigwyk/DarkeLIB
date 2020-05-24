//      Wizard:  Khojem
//      clearing
//      clearing.c

#include <std.h>

inherit ROOM;

int search_count;

void init() {
    ::init();
    add_action("read_sign","read");
    add_action("do_search","search");
}

void reset() {
	::reset();
	if ( present("wood-elf warrior", this_object()) ) {
      if ( present("half-orc warrior" , this_object()) ) {
		present("wood-elf warrior" , this_object())->
		  force_me("kill half-orc warrior");
	  }
	}
}

void create() {
    ::create();
    search_count=0;
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   \n    \n0--@--0\n   | \n   0\nClearing");
    set("long", "You suddenly find yourself in a small clearing surrounded "+
      "by a dense forest.  A thick, waist-high yellowed wild grass fills "+
      "the clearing.  Exit into the forest is impossible, but trails "+
      "cut pathways through the forest out of the clearing.\n   \n    \n0--@--0\n   | \n   0\n"
    );
    add_exit("trail1","east");
    add_exit("trail3","west");
    add_exit("trail0","south");
    set_items(([
        "sign" : "The sign points to the west.\n"+
          "Maybe you should try to read it?",
     ({ "forest","trees", "woods", "growth" }) :
        "The trees are large, healthy trees filled with foliage.  "+
        "They grow densely around the clearing and block entry.",
     ({ "trail","path" }) :
        "The well travelled trails exit south, west and east.",
     ({ "grass", "wild grass", "clearing" }) :
        "The dead, yellow grass is very dense.  You can barely see "+
        "your feet in the mass.  An ambusher could be laying a few "+
        "feet away from you and you wouldn't see him."
    ]));
    set_smell("default", "The smell of rotting corpses is very strong.");
    set_listen("default", "You hear a battle raging.");
    set_search("default",(: this_object(),"do_search" :));
    new("/d/khojem/new/mon/elf_warrior")->move(this_object());
    new("/d/khojem/new/mon/orc_warrior")->move(this_object());
    new("/d/khojem/new/obj/sign")->move(this_object());
}

int read_sign(string str){
  if(str != "sign") return 0;
  write("The simple, wooden sign reads:  Fir'nvillee\n"+
    "It points off to the west.\n");
  return 1;
}

void do_search() {
  int skill;
  object money;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "the high grass.\n");
  skill=(int)this_player()->query_skill("perception");
  if((random(100)<skill) && search_count<3){
    search_count++;
    write("Your search is successful.");
    switch(random(11)){
      case 0:new("/d/damned/virtual/two-handed-sword_6.weapon")->
                 move(this_object());
             write("You found a two-handed sword.");
             break;
      case 1:new("/d/damned/virtual/spear_6.weapon")->
                 move(this_object());
             write("You found a spear.");
             break;
      case 2:new("/d/damned/virtual/broad-sword_6.weapon")->
                 move(this_object());
             write("You found a broad sword.");
             break;
      case 3:new("/d/damned/virtual/battle-axe_6.weapon")->
                 move(this_object());
             write("You found a battle axe.");
             break;
      case 4:new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_object());
             write("You found a dagger.");
             break;
      case 5:new("/d/damned/virtual/quarter-staff_6.weapon")->
                 move(this_object());
             write("You found a quarter staff.");
             break;
      case 6:new("/d/damned/virtual/great-axe_6.weapon")->
                 move(this_object());
             write("You found a great axe.");
             break;
      case 7:new("/d/damned/virtual/hammer_6.weapon")->
                 move(this_object());
             write("You found a hammer.");
             break;
      case 8:new("/d/damned/virtual/war-hammer_6.weapon")->
                 move(this_object());
             write("You found a war hammer.");
             break;
      case 9:skill = random(10)*200+80;
             money = new("std/obj/coins");
             money->set_money("silver",skill);
             money->move(this_object());
             write("You found a pile of gold coins.");
             break;
    }
  }
  else
    write("Your search yields nothing.");
  return;
}
