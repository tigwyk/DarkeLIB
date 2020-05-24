//      Wizard:  Khojem
//      desert oasis
//      oasis.c

#include <std.h>

inherit ROOM;

int search_count;
object ob;

void init() {
    ::init();
    add_action("do_drink","drink");
}

void reset() {
    ::reset();
    search_count = 0;
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "A shady oasis in the desert");
    set("day long",
      "The palm trees here protect you from the hot sun.  "+
      "You notice a few scattered tracks in the sand that lead out.  "+
      "The sand is more firm here near the water.  Good thing you "+
      "found this oasis.  The breeze forces the palms to blow hot, dry "+
      "air into face and stirs up the sand a bit.  Occasionally, some "+
      "sand gets in your eye.  In the distance you can still see the "+
      "the sand dunes that surround this oasis in the desert."
   );
    set("night long",
      "The palm trees here seem to make the night air colder.  "+
      "You notice a few scattered tracks in the sand that lead out.  "+
      "The sand is more firm here near the water.  Good thing you "+
      "found this oasis.  The breeze forces the palms to blow the chill, dry "+
      "air into face and stirs up the sand a bit.  Occasionally, some "+
      "sand gets in your eye.  In the distance you can still see the "+
      "the sand dunes that surround this oasis in the desert."
    );
    add_exit("/d/khojem/nomad/room/s1","south");
    add_exit("/d/khojem/nomad/room/d11","northwest");
    add_exit("/d/khojem/nomad/room/e1","northeast");
    add_exit("/d/khojem/nomad/room/d10","southwest");
    add_exit("/d/khojem/nomad/room/d5","west");
    set_items(([
     ({ "track","tracks" }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
     ({ "palm","palm tree","palm trees","tree","trees","palms","palmes" }) :
        "Numerous palm trees grow close to this small oasis.  They flourish "+
        "from its water.  The leaves are high up in the tree."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "You hear the palms sway in the breeze above.");
    set_search("default",(: call_other, this_object(),"do_search" :));
    new("/d/khojem/nomad/obj/oasis")->move(this_object());
    new("/d/khojem/nomad/obj/mono2")->move(this_object());
}

int do_drink(string str) {
  if(!str) {
    notify_fail("What do you want to drink?\n");
    return 0;
  }
  if(str!="water" && str!="oasis" && str!="pool" && str!="oasis pool") {
    return 0;
  }    
  this_player()->add_quenched(5);
  write("You bend down and drink the clear water from the oasis.\n");
  say(this_player()->query_cap_name()+" sips water from the oasis.\n",
    this_player());
  return 1;
}


void do_search() {
  int skill;
  string zplayer;
  object money;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "about the oasis.\n");
  skill=((int)this_player()->query_skill("perception"))-20;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\nYou discover a thief!");
    zplayer=(this_player()->query_cap_name());
    ob=new("/d/khojem/nomad/mon/thief");
    ob->move(this_object());
    ob->kill_ob(this_player(),0);
  }
  else
    write("Your search yields nothing.");
  return;
}

