//      Wizard:  Khojem
//      r2.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "rock face");
    set("long", "  You are high up on the cliffside.  The escarpment towers "+
      "above you.  Its sheer face makes climbing practically impossible.  "+
      "Below is a long drop and would hurt if you fell from this height.  "+
      "In the distance the town of Vo'Sangor stretches out beneath you."
    );
    add_exit("/d/khojem/port/room/r3","up");
    set_pre_exit_functions(({ "up" }),({"do_up"}));
    add_invis_exit("up");
    add_exit("/d/khojem/port/room/r1","down");
    set_pre_exit_functions(({ "down" }),({"do_dn"}));
    add_invis_exit("down");
    set_items(([
     ({ "street","dirt street","Noble Street","noble street" }) :
        "Its a dusty little road.",
     ({ "wall", "escarpment", "canyon" ,"walls"}) :
        "The city's north and west walls are fixed to a massive rock formation "+
        "with sheer cliffs that tower above you.",
     ({ "town", "vo'sangor", "Vo'Sangor", "buildings", "building" }) :
        "The small port town of Vo'Sangor with all its small buildings "+
        "can be seen below."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town is below you.");
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
  this_player()->add_hp(-100);
  write("After a few feet you slip and land in a heap on the ground below.\n");
  tell_room("/d/khojem/port/room/r1",
    this_player()->query_cap_name()+" falls from above and "+
     "elegantly lands flat on his face beside you.\n");
  find_object_or_load("/d/khojem/port/room/r1");
  this_player()->move_player("/d/khojem/port/room/r1");
  return 0;
}

int do_dn() {
  int zstat;
  if(this_player()->query_flying()){
    write("You glide down the face of the high tower.\n");
    return 1;
  }
  zstat=((int)this_player()->query_stats("dexterity"));
  if(random(100)<zstat) {
    write("You struggle greatly, but manage to decend the rock face.\n");
    return 1;
  }
  this_player()->add_hp(-50);
  write("After a few feet you slip and land in a heap on the ground below.\n");
  tell_room("/d/khojem/port/room/r1",
    this_player()->query_cap_name()+" falls from above and "+
     "elegantly lands flat on his face beside you.\n");
  return 1;
}

