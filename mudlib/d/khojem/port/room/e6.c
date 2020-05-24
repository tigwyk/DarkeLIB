//      Wizard:  Khojem
//      legionnaire's barracks
//      e6.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("legionnaire"))
    new("/d/khojem/port/mon/legion2")->move(this_object());
    new("/d/khojem/port/mon/legion2")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "legionnaires' barracks");
    set("long", "The Earl of Vo'Sangor but take his protection seriously.  "+
      "He quarters his own legionnaires within his own home.  These barracks "+
      "serve as the home and training yard of the town's finest fighters.  "+
      "Numerous straw-filled dummies serve as training targets.  The walls "+
      "are covered with posters of all known races with critical wound "+
      "points explicitly marked."
    );
    add_exit("/d/khojem/port/room/e2","south");
    set_pre_exit_functions(({ "south"}),({"go_south"}));
    set_items(([
     ({ "dummies", "dummy", "straw dummies", "straw dummy" }) :
        "Looks like another dummy!",
     ({ "posters", "poster", "wall", "walls" }) :
        "The posters diagram all the know races of DarkMud.",
    ]));
    set_smell("default", "A musty smell fills the air.");
    set_listen("default", "The house is quiet.");
}

int go_south() {
  object who;
  who = this_player();

  if(who->query_ghost()) { return 1; }
  if(!present("legionnaire")) return 1;
  if(who->query_invis()) { return 1; }
  if(who->query_hiding() >= 70)  { return 1; }
  if(who->query_stealth() >= 90) { return 1; }
  write("A legionnaire blocks your exit towards the south!\n"+
    "You are trapped!\n");
  say("A legionnaire blocks "+this_player()->query_cap_name()+
    "'s attempt to withdraw to the south.\n");
  return 0;
}
