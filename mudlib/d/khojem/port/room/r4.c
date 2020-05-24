//      Wizard:  Khojem
//      r4.c

#include <std.h>
inherit ROOM;

void reset(){
  ::reset();
  if(!present("giant"))
      new("/d/khojem/port/mon/giant")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light",2);
    set_property("indoors", 0);
    set("short", "high atop the escarpment");
    set("long", "This is the pinnacle of a steep escarpment.  From this vantage "+
      "point you can see the surrounding area.  Off to the southeast is the "+
      "small town of Vo'Sangor and its harbor.  The vast open sea can be seen "+
      "to the east and south.  Mountains raise up towards the north and a desert "+
      "can be seen to the northwest."  
    );
    add_exit("/d/khojem/port/room/r3","down");
    set_pre_exit_functions(({ "down" }),({"do_dn"}));
    add_invis_exit("down");
    set_items(([
     ({ "desert" }) :
        "At this distance the desert lacks descriptive features.  You just "+
        "realize a desert spans to the horizon.",
     ({ "mountains" }) :
        "Just beyond the haze of the horizon you can barely make out the "+
        "peaks of a few mountains far to the north.",
     ({ "harbor", "water", "sea" }) :
        "The harbor can be seen in the distance.  It is border on the east "+
        "by a reef and island and on the south by a rocky breakwater.",
     ({ "breakwater" }) :
        "The breakwater is too far off to make out any details of it.",
     ({ "reef" }) :
        "The reef is too far off to make out any details about it.",
     ({ "island" }) :
        "Other than the fact is has trees on it you can't make out any "+
        "details.  It is too far away.",
     ({ "town", "vo'sangor", "Vo'Sangor", "buildings", "building" }) :
        "The small port town of Vo'Sangor with all its small buildings "+
        "can be seen far below.",
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road and it is far below you.",
     ({ "wall", "escarpment", "canyon" ,"walls"}) :
        "The city's north and west walls are fixed to a massive rock formation "+
        "with sheer cliffs that drop off below you.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The wind ruffles you hair.");
}

int do_dn() {
  int zstats;
  if(this_player()->query_flying()){
    write("You glide down the face of the high tower.\n");
    return 1;
  }
  zstats=((int)this_player()->query_stats("dexterity"));
  if(random(120)<zstats) {
    write("You struggle greatly, but manage to decend the rock face.\n");
    return 1;
  }
  this_player()->add_hp(-200);
  write("After a few feet you slip and tumble downward.\n"+
    "After a long fall you land in a heap on the ground below.\n");
  tell_room("/d/khojem/port/room/r1",
    this_player()->query_cap_name()+" falls from above and "+
     "crashes down on his face beside you.  You hear the sound "+
     "of breaking bones.\n");
  find_object_or_load("/d/khojem/port/room/r1");
  this_player()->move_player("/d/khojem/port/room/r1");
  return 0;
}

