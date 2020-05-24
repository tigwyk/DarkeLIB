//      Wizard:  Khojem
//      tp.c

#include <std.h>
inherit ROOM;

void init() {
    ::init();
    add_action("do_read","read");
    add_action("do_peer","peer");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no steal", 1);
    set("short", "Vo'Sangor Translocation Room");
    set("long","The hallway is quiet and you sense something religious or holy "+
      "about this place.  A few monks can be seen kneeling with their heads "+
      "bowed as they face the north towards a shimmering portal.  A map of the "+
      "known world is finely inlaid in the marble floor at your feet.  An "+
      "ancient script can be seen on the west wall."
    );
    add_exit("/d/khojem/port/room/s17","southwest");
    add_exit("/d/standard/square","portal");
    add_invis_exit("portal");
    set_pre_exit_functions(({"portal"}),({"go_venture"}));
    set_items(([
     ({ "hallway" }) :
        "The hallway is wide and constructed of highly polished marble.  "+
        "Miraculously, the marble seems to absorb all sound.",
     ({ "square","merchant square" }) :
        "The dusty square can be seen to the southwest.",
     ({ "monk", "monks" }) :
        "Robed monks are prostrate on the floor before the shimmering portal.  "+
        "Their heads are cloaked and you barely perceive a rhymical chanting.",
     ({ "shimmering portal","portal" }) :
        "The shimmering portal is unlike anything you have seen before.  The portal "+
        "extends from ceiling to floor and spans the entire width of the "+
        "hallway.  Small ripples dance across its surface and refract the "+
        "light creating a rainbow of colors.",
     ({ "floor", "wall" }) :
        "The walls and floor are made of a highly, polished marble.  Its surface "+
        "is smooth and flawless.  Inlaid in the floor is a map.  On the west wall "+
        "is an ancient script.",
     ({ "ancient script", "script" }) :
        "The script is composed of some ancient language.  Perhaps if you try "+
        "to 'read' it you can make out its message.",
        "map" : (: call_other, this_object(), "read_map" :),
    ]));
    set_smell("default", "The smell of incense fills the air.");
    set_listen("default", "A holy silence fills the hallway.");
}

int read_map() {
  this_player()->more("/wizards/mikus/world_map");
  say(this_player()->query_cap_name()+" looks at the inlaid map "+
    "on the marble floor.");
  return 1;
}

int do_read(string str) {
  if(str=="script" || str=="ancient script") {
    write("Mortal, before you is the holy portal of the gods.  Through "+
      "this portal you will be translocated to another realm of the world.\n\n"+
      "  'portal' - will translocate you\n\n"+
      "The church accepts a small tithe for this service.\n\n"+
      "  two times your mortal level in mithril coins\n"+
      "  forty times your mortal level in gold coins\n\n"+
      "Mortal levels less than four may travel at the church's blessing.\n"+
      "Members of the church may use this service for a reduced tithe.\n");
    say(this_player()->query_cap_name()+" examines the ancient script.");
    return 1;
  }
  return 0;
} 

int do_peer(string str) {
  if(str=="portal") {
    write("You see your reflection on the surface of the shimmering portal.");
    return 1;
  }
  return 0;
}

int go_venture() {
  int zlevel,offering,holy_type;
  string holy_str;
  if(this_player()->query_ghost()) {
    write("\nAn ancient female cleric whispers to you:  Venture forth "+
      "into the portal of the gods.  May the holy ones return you to "+
      "your mortal body.\n");
    say(this_player()->query_cap_name()+" disappears through a shimmering "+
      "portal.  The movement does not disturb the portal's surface."); 
    tell_room("/d/standard/square", "Suddenly, a shimmering portal appears!\n"+
      this_player()->query_cap_name()+" steps through the portal.\n"+
      "The shimmering portal disappears into vapor...\n");
    return 1;
  }
  if(this_player()->is_player()) {
  if(wizardp(this_player())) { return 1; }
  holy_str = (string)this_player()->query_class();
  if(holy_str=="cleric" || holy_str=="war-priest" || holy_str=="ley-healer") 
    holy_type=1;
  else holy_type=2;
  zlevel = (int)this_player()->query_level();
  if(zlevel > 3) {
    offering = ((holy_type * zlevel) * -1);
    if(((int)this_player()->query_money("mithril") + offering) >= 0) {
      this_player()->add_money("mithril",offering);
    }
    else {
      offering = (((holy_type * 20) * zlevel) * -1);
      if(((int)this_player()->query_money("gold") + offering) >= 0) {
        this_player()->add_money("gold",offering);
      }
      else {
        write("\nAn ancient female cleric whispers to you:  I am sorry my "+
          "child.  You lack the funds for the church's tithe.\n");
        say(this_player()->query_cap_name()+" attempts to enter the portal, "+
          "but is unable to do so.");
        return 0;
      }
    }
  }
  write("\nAn ancient female cleric whispers to you:  Venture forth my child "+
    "into the portal of the gods.  May the holy ones shine their blessings "+
    "upon you in your time of need.\n");
  say(this_player()->query_cap_name()+" disappears through a shimmering "+
    "portal.  The movement causes many waves to ripple across the portal's "+
    "surface."); 
  tell_room("/d/standard/square", "Suddenly, a shimmering portal appears!\n"+
    this_player()->query_cap_name()+" steps through the portal sending "+
    "gentle ripples across its surface.\nThe shimmering portal disappears "+
    "into vapor...\n");
  return 1;
  }
}

