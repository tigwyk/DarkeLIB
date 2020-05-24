//      Wizard:  Khojem
//      Babba's Pub and Hashish House
//      pub.c

#include <std.h>

inherit VAULT;

void init() {
    ::init();
    add_action("read", "read");
    add_action("do_look","look");
}

void reset() {
  ::reset();
  if(!present("babba")) {
    new("/d/khojem/nomad/mon/babba")->move(this_object());
  }
  if(!present("bouncer")) {
    new("/d/khojem/nomad/mon/bouncer")->move(this_object());
    new("/d/khojem/nomad/mon/bouncer")->move(this_object());
    new("/d/khojem/nomad/mon/bouncer")->move(this_object());
  }
  if(query_open("curtain")) {
    set_open("curtain",0);
    set_locked("curtain",0);
    "/d/khojem/nomad/camp/backroom"->set_open("tent flap",0);
    "/d/khojem/nomad/camp/backroom"->set_locked("tent flap",0);
    add_invis_exit("southwest");
    "/d/khojem/nomad/camp/backroom"->add_invis_exit("northeast");
  }   
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Babba's Pub and Hashish House");
    set("long",
	"The room is filled with a vile smoke that drifts down lazily from the "+
	"ceiling.  As you smell the smoke you notice its intoxicating effect "+
    "immediately.  Not only is this a bar but an hashish house, too.  "+
    "A place where controban drugs are available for a high price.  "+
    "Against the east wall of the tent is a small table with assorted "+
	"spirits. Scattered about the floor of the tent are large pillows for "+
	"lounging.  Numerous, customers can be seen lying about with glazed eyes.\n"+
	"A sign hangs on the wall."
	);
    set_items(([
     ({ "tent" }) :
        "The tent is dark and badly soiled.  To the southwest "+
        "you can make out a curtain that hangs from the tent's ceiling",
     ({ "curtain" }) : 
        (: this_object(), "look_at_door" :),
     ({ "pub", "alehouse" }) :
        "You can have a rockin' good time here.",
     ({ "pillow", "pillows" }) :
        "The patrons are content to just lounge on the floor on these "+
        "pillows and watch the floor show.  The appear comfortable.",
     ({ "table", "spirits" }) : 
        "The table is filled with many bottles.  They are yours for a price.",
     ({ "sign" }) : "Maybe you should read it.",
     ({ "smoke" }) : "The smoke is suspended in the air and decends from "+
        "ceiling in layers.  It fills and irritates your lungs as you breath",
     ({ "wall", "walls" }) : 
        "The tent's walls are sooted from years of smoke in the air.",
     ({ "customers", "customer" }) :
        "The nomad customers lay about the establishment.  Most are drugged "+
        "from Babba's fine hash, some sleep, others are watching the dancer "+
        "through glazed lustful eyes.",
	 ({ "fire", "fireplace", "stone hearth", "hearth" }) :
	    "A fire burns a large log in a stone hearth."
	]));
    add_exit("/d/khojem/nomad/camp/shop","north");
    add_exit("/d/khojem/nomad/camp/backroom","southwest");
    add_invis_exit("southwest");
    set_door("curtain","/d/khojem/nomad/camp/backroom","southwest",0);
    set_open("curtain",0);
    set_locked("curtain",0);
    set_func("curtain","open","do_open");
    set_func("curtain","close","do_close");
    set_smell("default", "The fragrant smell of hashish smoke fills the room.");
    set_listen("default", "You hear a lively band playing for the dancer.");
    new("/d/khojem/nomad/mon/belly_dancer")->move(this_object());
}

int do_look(string str) {
  if(str=="ruby" || str=="ruby jewel"){
    write("The belly dancer wears a large ruby in her navel.  "+
      "The ruby attracts light and refracts it with a fiery, red brillance.");
      say(this_player()->query_cap_name()+" looks over the ruby jewel.\n");
    return 1;
  }
  return 0;
} 

void look_at_door() {
  if(query_open("curtain")) 
    write("The curtain is open and the tent extents on to the southwest.\n");
  else 
    write("The curtain is closed.\n");
  say(this_player()->query_cap_name()+" looks at a curtain.\n");
}

int do_open() {
  remove_invis_exit("southwest");
  "/d/khojem/nomad/camp/backroom"->remove_invis_exit("northeast");
  write("You pull the curtain aside.");
  say(this_player()->query_cap_name()+" opens a curtain.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("southwest");
  "/d/khojem/nomad/camp/backroom"->add_invis_exit("northeast");
  write("The curtain is released and if falls closed.");
  say(this_player()->query_cap_name()+" closes a curtain.\n");
  return 1;
}

  int read(string str) {
    object ob;
    int i;
    
    ob = present("babba");
    if(!ob) {
      write("Babba's blood smeared on the sign makes it unreadable.");
	  return 1;
    }
    message("Ninfo", "The following classic drinks are served at Babba's!\n",
      this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "A firebreather\t\t\t\t"+
      (int)ob->get_price("firebreather")+" silver\n", this_player());
    message("Ninfo", "The liquified opium special\t\t"+(int)ob
      ->get_price("special")+" silver\n", this_player());
    message("Ninfo", "A dark nomad ale\t\t\t"+(int)ob
      ->get_price("ale")+" silver\n", this_player());
    message("Ninfo",
      "-----------------------------------------------------------\n",
      this_player());
    message("Ninfo", "<buy drink_name> gets you a drink.\n",
      this_player());
    return 1;
}
