//      Wizard:  Khojem
//      Camp Center
//      center.c

#include <std.h>

inherit ROOM;

int check_peasant();
int no_exit() { return 1;}
int zopen,zflag;
object ob;

void init() {
    ::init();
    add_action("do_open", "open");
    add_action("do_close", "close");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","northeast");
      add_action("no_exit","east");
      add_action("no_exit","southeast");
    }
}

void reset() {
   ::reset();
  if(!present("basket")) {
    ob = new("/d/khojem/nomad/obj/sand_key");
    ob->set_name("basket");
    ob->set_short("a straw basket (closed)");
    ob->set_long("A large round basket made from the reeds that grow "
      "wild near the oasis.  The reeds are dried and bleached white "
      "by the hot desert sun.  The basket stands a few feet high and "
      "has a matching cover that fits securely on top.");
    ob->set_weight(10000);
    ob->move(this_object());
  }
  zopen = 0;
  zflag = 0;   
  if(check_peasant()<10) {
    new("/d/khojem/nomad/mon/peasant")->move(this_object());
    new("/d/khojem/nomad/mon/peasant")->move(this_object());
  }    
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set_property("night light",2);
    set("short", "nomad camp center");
    set("day long",
      "The shade from the palm trees protect you from the hot sun.  "+
      "This is the center of camp.  A fire burns here.  The desert breeze "+
      "whips the smoke into the tents that surround it.  The area is "+
      "is littered with tents of various size.  Small dogs run loose "+
      "between the tents.  Children play and run all about.\n"
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "This is the center of camp.  A fire burns here.  The desert breeze "+
      "whips the smoke into the tents that surround it.  The area is "+
      "is littered with tents of various size.  Small dogs run loose "+
      "between the tents.  Several of the tents are lit by torchlight.\n"
    );
    add_exit("/d/khojem/nomad/camp/entry","west");
    add_exit("/d/khojem/nomad/camp/chief_tent","east");
    add_exit("/d/khojem/nomad/camp/shaman","northeast");
    add_exit("/d/khojem/nomad/camp/warrior_tent","north");
    add_exit("/d/khojem/nomad/camp/tent1","northwest");
    add_exit("/d/khojem/nomad/camp/stable","southwest");
    add_exit("/d/khojem/nomad/camp/shop","south");
    add_exit("/d/khojem/nomad/camp/hareem1","southeast");   
    set_items(([
     ({ "camp" , "nomad camp" }) :
        "The camp is a sprawl of canvas tents with low-sloped roofs.  "+
        "There doesn't appear to be any order to there placement.  They "+
        "appear to be pitched at random spots near the oasis.",
     ({ "sand dunes","dunes" }) :
        "The sand dunes form a small hollow and surround the camp.",
     ({ "fire" }) :  "A small fire burns here and sends its smoke whirling "+
        "up and into your eyes.",
     ({ "tent", "tents"  }) :  
        "The tents are made from canvas and range in size, shape and color.  "+
        "All have guidelines that present tripping hazards and poles that "+
        "jut out at odd angles to support the tent's roof.",
     ({ "dog", "dogs", "small dogs" }) :
        "The dogs are mangy, dirty little beasts.  They are poorly feed and "+
        "their rib bones protrude from lack of food.  They bark and fight "+
        "with each other for scraps of food.  They are wary of your presence "+
        "and keep a safe distance from you.",
     ({ "children" }) :  
        "The children are dirty, ill-kept little retches with dirty faces and "+
        "clothing.  Their dirty, matted hair hangs down across their faces."  
    ]));
    set_smell("default", "The smell of burning grease and smoke is everywhere.");
    set_listen("default", "The camp is noisy.  People shouting and dogs barking.");
 }

int check_peasant() {
  object *all;

  all = filter_array(livings(), "my_peasant_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_peasant_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/peasant")  
    return 1;                                        
  return 0;
}                            

int do_open(string str) {
  int num;
  object obj;
  if(str !=  "basket" && str != "straw basket")  { return 0;}
  if(!present("basket")) { return 0;}
  if(zopen) {
    write("It is already open!");
    return 1;
  }
  zopen = 1;
  ob->set_short("a straw basket (open)");
  write("You open a straw basket.");
  message("info",this_player()->query_cap_name()+" opens a "
    "staw basket.",this_object(),this_player());
  if(zflag) {
    write("You look into the basket and find it empty.");
    return 1;
  }
  zflag = 1;
  num=random(100);
  if(num==0) {
    num=random(1000) + 100;
    write("Wow, your lucky day!  You found "+num+" gold "
      "in the bottom of the basket.");
    message("info",this_player()->query_cap_name()+" found some "
      "gold in the basket and quickly pockets it.",this_object(),
      this_player());
    obj=new("std/obj/coins");
    obj->set_money("gold",num);
    obj->move(this_player());
    return 1;
  }
  if(num>1 && num<6) {
    write("You find a compass in the basket and fetch it up.");
    message("info",this_player()->query_cap_name()+" retrieves a "
      "compass from the bottom of the basket.",this_object(),
      this_player());
    obj=new("/d/khojem/nomad/obj/compass");
    obj->move(this_player());
    return 1;
  }
  if(num>5 && num<11) {
    obj=new("/d/khojem/nomad/armor/sunvisor");
    obj->move(this_player());
    write("You find a handy sunvisor and grab it from the basket.");
    message("info",this_player()->query_cap_name()+" grabs a sunvisor "
      "from the basket.",this_object(),this_player());
    return 1;
  }
  if(num>10 && num<90) {
    write("As you open the basket, a big fuckin' cobra springs out at you!\n");
    message("info","As "+this_player()->query_cap_name()+" opens the straw "
      "basket.  A big cobra spring out and attacks "+this_player()->query_cap_name()+
      ".\n",this_object(),this_player());
    obj=new("/d/khojem/nomad/mon/cobra");
    obj->move(this_object());
    return 1; 
  }
  if(num>89) {
    write("You look into the basket and find it empty.");
    return 1;
  }
}

int do_close(string str) {
  if(str != "basket" && str != "straw basket") {return 0;}
  if(!present("basket")) {return 0;}
  if(!zopen) {
    write("It is already closed!");
    return 1;
  }
  ob->set_short("a straw basket (closed)");
  write("You close a straw basket.");
  message("info",this_player()->query_cap_name()+" closes a "
    "straw basket.",this_object(),this_player());
  zopen = 0;
  return 1;
}

