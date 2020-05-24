//      Wizard:  Khojem
//      ravine 2
//      rv2.c

#include <std.h>

inherit ROOM;

void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "A ravine wall");
    set("day long",
      "Now, shielded by the sun's rays you feel cooler, but you don't "+
      "feel more comfortable.  You are clinging to the ravine's wall.  "+
      "The sharp rock cuts deep into your body.  Your hands are cut "+
      "severely and gaining a firm grip and maintaining your foothold "+
      "is getting more difficult."
   );
    set("night long",
      "Maybe attempting this climb at night was not a good idea.  "+
      "You are clinging to the ravine's wall.  "+
      "The sharp rock cuts deep into your body.  Your hands are cut "+
      "severely and gaining a firm grip and maintaining your foothold "+
      "is getting more difficult."
    );
    add_exit("/d/khojem/nomad/room/rv1","up");
    add_exit("/d/khojem/nomad/room/rv3","down");
    set_pre_exit_functions(({ "down", "up" }),
      ({ "go_down", "go_up" }));
    set_items(([

     ({ "rocks", "rocky precipice", "precipice", "rock" }) :
        "The rocks are razor-sharp.  Climbing down or up is your only "+
        "choice.", 
     ({ "ravine" }) :
        "The steep, jagged rocks extend downward into the dark, abyss below.",
     ({ "rope-bridge", "rope bridge", "bridge" }) :
        "High above, silhouetted against the sky you see the rope-bridge "+
        "spanning the ravine."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "Far below you can make out the muffled, "+
      "sounds of wild animals.  They seem to be pacing about.");
}

int go_down(){
  if(this_player()->query_flying()){
    write("You fly down into the deep ravine a ways.\n");
    tell_room("/d/khojem/nomad/room/rv3",
      this_player()->query_cap_name()+" gracefully flys down from above.\n");
    return 1;
    }
  write("Maybe this wasn't such a good idea?  You can climb down without "+
    "falling, but the rocks seriously cut and gash you.\n");
  say(this_player()->query_cap_name()+" foolishly attempts to climb down "+
    "into the darkness of the ravine.\n");
  this_player()->add_hp(-(random(50)+50));
  return 1;
}


int go_up(){
  if(this_player()->query_flying()){
    write("You fly up the face of the deep ravine a ways.\n");
    tell_room("/d/khojem/nomad/room/rv1",
      this_player()->query_cap_name()+" gracefully flys up from "+
        "the ravine below.\n");
    return 1;
    }
  write("You struggle against gravity.  You can climb down without "+
    "falling, but the rocks seriously cut and gash you.\n");
  say(this_player()->query_cap_name()+", with great difficulty, climbs up "+
    "and disappears from sight as he passes a rocky outcrop.\n");
   this_player()->add_hp(-(random(50)+50));
  return 1;
}

