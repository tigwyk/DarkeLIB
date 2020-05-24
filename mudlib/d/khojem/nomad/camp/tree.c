//      Wizard:  Khojem
//      tree
//      tree.c

#include <std.h>

inherit ROOM;

void create() {
   ::create();
  set_property("light", 4);
  set_property("indoors", 0);
  set_property("night light",2);
  set_property("no attack", 1);
  set_property("no spell", 1);
  set_property("no scry", 1);
  set_property("no steal", 1);
  set("short", "high up a palm tree");
  set("day long",
    "The bright, hot sun burns down on the back of your neck.  "
    "You are high atop a palm tree.  Below you is the camp and "
    "oasis.  In the distance you see the rolling dunes that "
    "stretch to the horizen."
  );
  set("night long",
    "The night air chills your bones and robs you of body heat.  "
    "You are high atop a palm tree.  Below, you can see the camp's "
    " fires.  Sand and darkness surround the small oasis."
  );
  add_exit("/d/khojem/nomad/camp/stable","down");
  set_items(([
    ({ "camp" , "nomad camp" }) :
      "The camp is sprawled out below you in an array of tents of "
      "varying size.",
    ({ "oasis" }) :  
      "The oasis is a small patch of green surrounded by a sea "
      "of sand that stretches to the horizon.",
    ({ "sand dunes","dunes" }) :
      "The sand dunes surround the camp.",
    ({ "fires" }) :  
      "Small fires dot the nomad camp. ",
    ({ "tent", "tents"  }) :  
      "Tents of varying size are scattered out below you.",
    ({ "palm tree", "trees", "tree", "palms", "palm" }) :
      "The palm tree you stand in appears sturdy.  The leaves of a "
      "number of other palm trees are nearby and block your view "
      "of portions of the oasis and camp."
    ]));
    set_smell("default", "The arid air dries your nasal membranes.");
    set_listen("default", "The desert wind howls strongly here.");
}
