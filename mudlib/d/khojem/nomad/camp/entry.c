//      Wizard:  Khojem
//      Camp Entry
//      entry.c

#include <std.h>

inherit ROOM;

int check_mobs();

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","oasis");
    }
}

void reset() {
    ::reset();
    if(!present("sergeant"))
      new("/d/khojem/nomad/mon/sergeant")->move(this_object());
    while(check_mobs()<5)
      new("/d/khojem/nomad/mon/guard")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "Nomad Camp - Entry");
    set("day long",
      "The shade from the palm trees protect you from the hot sun.  "+
      "You are standing at the entrance to a nomads' camp.  The nearby "+
      "oasis must have attracted them to camp here.  The area "+
      "is littered with tents of various size.  Small dogs run loose "+
      "between the tents.  Children play and run all about.\n"
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing at the entrance to a nomads' camp.  The nearby "+
      "oasis must have attracted them to camp here.  The area is "+
      "is littered with tents of various size.  Small dogs run loose "+
      "between the tents.  Several of the tents are lit by torchlight.\n"
    );
    add_exit("/d/khojem/nomad/camp/center","east");
    add_exit("/d/khojem/nomad/room/oasis","west");
    set_items(([
     ({ "camp" , "nomad camp", "nomad's camp" }) :
        "The camp is a sprawl of canvas tents with low-sloped roofs.  "+
        "There doesn't appear to be any order to there placement.  They "+
        "appear to be pitched at random spots near the oasis.",
     ({ "sand dunes","dunes" }) :
        "The sand dunes form a small hollow and surround the camp.",
     ({ "entrance" }) :  "It appears that guards frequently are posted here.  "+
        "This point appears to be centrally located to most parts of the camp.",
     ({ "oasis" }) :  "The oasis is just to the west and provides a water "+
        "source for the nomads.",
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
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The camp is noisy.  People shouting and dogs barking.");
    find_object_or_load("/d/khojem/nomad/camp/tent1");
    find_object_or_load("/d/khojem/nomad/camp/tent2");
    find_object_or_load("/d/khojem/nomad/camp/shop");
    find_object_or_load("/d/khojem/nomad/camp/center");
}

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/guard")  
    return 1;                                        
  return 0;
}

