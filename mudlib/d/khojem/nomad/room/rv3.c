//      Wizard:  Khojem
//      ravine 3
//      rv3.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","up");
    }
}

void reset() {
    ::reset();
    if(!present("hyena")){
      new("/d/khojem/nomad/mon/hyena")->move(this_object());
      new("/d/khojem/nomad/mon/hyena")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("night light",0);
    set("short", "A deep ravine");
    set("day long",
      "You are standing at the base of the ravine.  The walls of the "+
      "ravine are narrow and frequently its sharp rocks protrude forcing "+
      "you to avoid them as you walk.  The ravine's base is very dark and "+
      "you can only see a few feet ahead.  High above you see a bright streak "+
      "of light against the darkness.  "
   );

    set("night long",
      "You are standing at the base of the ravine.  The walls of the "+
      "ravine are narrow and frequently its sharp rocks protrude forcing "+
      "you to avoid them as you walk.  The ravine's base is very dark and "+
      "you can only see a few feet ahead.  "
    );
    add_exit("/d/khojem/nomad/room/rv4","east");
    add_exit("/d/khojem/nomad/room/rv2","up");
    set_pre_exit_functions(({ "up" }),({ "go_up" }));
    set_items(([
     ({ "rocks", "rock" }) :
        "The rocks are razor-sharp.  Climbing down or up is your only "+
        "choice.", 
     ({ "ravine" }) :
        "The steep, jagged rocks line the walls of this narrow ravine.  "+
        "The ravine's floor is coated with a soft, layer of fine sand."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "You here animals closeby and approaching you.");
}


int go_up(){
  if(this_player()->query_flying()){
    write("You fly up the face of the deep ravine a ways.\n");
    tell_room("/d/khojem/nomad/room/rv2",
      this_player()->query_cap_name()+" gracefully flys up from below.\n");
    return 1;
    }
  write("You struggle against gravity.  You can climb down without "+
    "falling, but the rocks seriously cut and gash you.\n");
  say(this_player()->query_cap_name()+", with great difficulty, climbs up "+
    "and disappears from sight as he passes a rocky outcrop.\n");
   this_player()->add_hp(-(random(50)+50));
  return 1;
}

