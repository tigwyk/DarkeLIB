//      Wizard:  Khojem
//      Chief Tent
//      chief_tent.c

#include <std.h>

inherit ROOM;

int stick_count;

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("do_touch","touch");
    add_action("get_glowstick","get");
}

void reset() {
    ::reset();
   stick_count = 3;
   if(!present("moped")) {
      new("/d/khojem/nomad/mon/moped")->move(this_object());
   }
   if(!present("guard")) {
      new("/d/khojem/nomad/mon/guard2")->move(this_object());
      new("/d/khojem/nomad/mon/guard2")->move(this_object());
   }
}

void create() {
  object obj;
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("night light",2);
    set("day long",
      "The sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "+
      "In the center of the tent is a thone which is flanked by two fires.  "+
      "Smoke fires the fires slowly drifts up through two holes in the large tent.  "+
      "Soft sand forms the floor of the tent."
    );
    set("night long",
      "The chill night air is warmed by the burning fires.  "+
      "In the center of the tent is a thone which is flanked by two fires.  "+
      "Smoke from the fire slowly drifts up through two holes in the large tent.  "+
      "Soft sand forms the floor of the tent."
    );
    add_exit("/d/khojem/nomad/camp/center","west");
    set_items(([
     ({ "tent"  }) :  
        "The tent has a low-pitch roof and trussed with some timber bracing along "+
        "the roof's center.  A bedroll is rolled up and stored in one corner of the tent.",
     ({ "timber", "roof" }) :  
        "A few wooden struts, bleached white from the sun, support the roof.",
     ({ "throne" }) :
        "The throne is deeply padded and looks comfortable.  The seat is shaped "+
        "to fit the large butt of Chief Moped.",
     ({ "fire", "fires" }) :
        "The fires are small and burn a blue flame.  The small logs glow blue.",
     ({ "log", "logs" }) :
        "The small logs glow a bright blue in the fire.",
     ({ "hole", "holes" }) :
        "Two circular holes cut into the tent's roof allows smoke from the "+
        "fires to escape out of the roof.",
     ({ "canvas" }) :
        "The canvas is soiled and sooty from many nights of torch smoke.",
     ({ "bedroll" }) :  "Nothing much.  It appears worthless.",
     ({ "floor", "sand" }) :
        "The tent was setup on a bare sandy floor.  A bedroll is stored in the far corner."
    ]));
    set_smell("default", "A musty smell fills the tent.");
    set_listen("default", "The clamour from the rest of the camp is far to the south.");
    obj=new("/d/khojem/nomad/obj/vault");
    obj->move(this_object());
    obj->toggle_closed();
    obj->set_lock("locked");
    obj->set_lock_level(22);
    obj->set_trap_func("/wizards/diewarzau/obj/misc/trap_func","fire_trap");
    obj->set_trap_level(18);
}

int do_touch(string str){
  if(str=="fire" || str=="fires" || str=="flame" || str=="log"
    || str=="logs" || str=="stick" || str=="glowstick"){
      say(this_player()->query_cap_name()+" reaches out and touches one of the "+
        "glowing blue logs in the fire.\n");
      write("You reach out and touch a blue, glowing log in the fire.  To your "+
        "amazement the log is cool and doesn't burn you.\n");
      return 1;
  }
  write("Touch what?");
  return 0;
}

int get_glowstick(string str) {
  object ob;
  string a,b;
  if(sscanf(str, "%s from %s", a, b) == 2) {
    if((a=="log" || a=="logs" || a=="stick" || a=="glowstick") &&
      (b=="fire" || b=="fires" || b=="flame")){ 
      if(stick_count>0){
        stick_count--;
        ob=new("/d/khojem/nomad/obj/glowstick");
        ob->move(this_player());
        write("You fetch a glowstick from the fire.\n");
        return 1;
      }
      write("It appears the fire is short of usable glowsticks.\n");
      return 1;
    }
  }
  return 0;
}


