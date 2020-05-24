//      Wizard:  Khojem
//      r3.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
    set("short", "rock face");
    set("long", "You are high up on the cliffside.  The escarpment drops "+
      "off below you.  Its sheer face makes climbing practically impossible.  "+
      "It would certainly injure you greatly if you fell from this height.  "+
      "In the distance the town of Vo'Sangor stretches out beneath you.  "+
      "In the distance you can see Vo'Sangor's harbor."
    );
    add_exit("/d/khojem/port/room/r4","up");
    set_pre_exit_functions(({ "up" }),({"do_up"}));
    add_invis_exit("up");
    add_exit("/d/khojem/port/room/r2","down");
    set_pre_exit_functions(({ "down" }),({"do_dn"}));
    add_invis_exit("down");
    set_items(([
     ({ "harbor", "water" }) :
        "The harbor can be seen in the distance.  It is bordered on the east "+
        "by a reef and island and on the south by a rocky breakwater.",
     ({ "breakwater" }) :
        "The breakwater is too far off to make out any details of it.",
     ({ "reef" }) :
        "The reef is too far off to make out any details about it.",
     ({ "island" }) :
        "Other than the fact is has trees on it you can't make out any "+
        "details.  It is too far away.",
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road and it is far below you.",
     ({ "town", "vo'sangor", "Vo'Sangor", "buildings", "building" }) :
        "The small port town of Vo'Sangor with all its small buildings "+
        "can be seen far below.",
     ({ "wall", "escarpment", "canyon" ,"walls"}) :
        "The city's north and west walls are fixed to a massive rock formation "+
        "with sheer cliffs that drop off below you."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The wind ruffles you hair.");
}

int do_up() {
  int zstats;
  if(this_player()->query_flying()){
    write("You gently sore up the face of the high tower.\n");
    return 1;
  }
  zstats=((int)this_player()->query_stats("dexterity"));
  if(random(100)<zstats) {
    write("You struggle greatly, but manage to climb the rock face.\n");
    return 1;
  }
  this_player()->add_hp(-150);
  write("After a few feet you slip and tumble downward.\n"+
    "After a long fall you land in a heap on the ground below.\n");
  tell_room("/d/khojem/port/room/r1",
    this_player()->query_cap_name()+" falls from above and "+
     "crashes down on his face beside you.\n");
  find_object_or_load("/d/khojem/port/room/r1");
  this_player()->move_player("/d/khojem/port/room/r1");
    move(find_object_or_load("/d/khojem/port/room/r1"));
  return 0;
}

int do_dn() {
  int zstats;
  if(this_player()->query_flying()){
    write("You glide down the face of the high tower.\n");
    return 1;
  }
  zstats=((int)this_player()->query_stats("dexterity"));
  if(random(100)<zstats) {
    write("You struggle greatly, but manage to decend the rock face.\n");
    return 1;
  }
  this_player()->add_hp(-100);
  write("After a few feet you slip and tumble downward.\n"+
    "After a long fall you land in a heap on the ground below.\n");
  tell_room("/d/khojem/port/room/r1",
    this_player()->query_cap_name()+" falls from above and "+
     "crashes down on his face beside you.\n");
  find_object_or_load("/d/khojem/port/room/r1");
  this_player()->move_player("/d/khojem/port/room/r1");
  return 0;
}

