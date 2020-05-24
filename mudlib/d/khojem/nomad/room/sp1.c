//      Wizard:  Khojem
//      sp1
//      sp1.c

#include <std.h>

inherit ROOM;

int search_count;

void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A dark sand pit");
    set("long",
      "You sense you are in a deep cavern.  All noise echos off walls "+
      "in the distance that you cannot see.  Some of the sand "+
      "from above continues to sift down onto you."
   );
    add_exit("/d/khojem/nomad/room/sp2","north");
    add_invis_exit("north");
    set_items(([
     ({ "cave","cavern", "chamber", "pit" }) :
        "All you can see is the floor you are standing on and a few feet "+
        "of the floor around you.  Everything beyond is engulfed in darkness.",
     ({ "ceiling" }) :
        "The chamber's ceiling is too high to see in this darkness.  "+
        "As you look up the sifting sand falling from above gets in your eye.",
     ({ "floor", "sand" }) :
        "The floor is composed of soft, silky sand.",
     ({ "wall", "walls" }) :
        "You can't see any walls from here, but all noise reflects from them "+
        "somewhere in the distance.",
    ]));
    set_smell("default", "It smells awful here, but you can't figure out the smell.");
    set_listen("default", "You think you can hear the soft patter of an animal "+
      "off in the distance, but can't determine what direction.");
    set_search("sand",(: call_other, this_object(),"do_search" :));
    search_count=0;
}

void do_search() {
  int skill;
  object ob;
  //string zplayer;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "around in the sand.\n");
  skill=((int)this_player()->query_skill("perception"))-60;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
      "You discovered a key.\n");
    ob=new("/d/khojem/nomad/obj/sand_key");
    ob->move(this_object());
  }
  else
    write("Your search yields nothing.");
  return;
}

