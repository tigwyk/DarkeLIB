//   Wizard:  Khojem
//   Camp Shop
//   shop.c

#include <std.h>

inherit ROOM;

int check_peasant();

void init(){
     ::init();
     add_action("do_read","read");
}

void reset() {
   ::reset();
    if(check_peasant()<10) {
      new("/d/khojem/nomad/mon/peasant")->move(this_object());
      new("/d/khojem/nomad/mon/peasant")->move(this_object());
    }      
   if(!present("akmed")) {
      new("/d/khojem/nomad/mon/akmed")->move(this_object());
   }
   if(!present("coco")) {
      new("/d/khojem/nomad/mon/coco")->move(this_object());
   }
   if(!present("merz")) {
      new("/d/khojem/nomad/mon/merz")->move(this_object());
   }
   if(!present("shopguard")) {
      new("/d/khojem/nomad/mon/shopguard")->move(this_object());
      new("/d/khojem/nomad/mon/shopguard")->move(this_object());
      new("/d/khojem/nomad/mon/shopguard")->move(this_object());
      new("/d/khojem/nomad/mon/shopguard")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_property("no castle", 1);
   add_exit("/d/khojem/nomad/camp/center", "north");
   add_exit("/d/khojem/nomad/camp/pub", "south");
   set("short","Nomad's Bazaar");
   set("long",
     "This appears to be a bazaar for the nomads.  Inside this large tent "+
     "goods are stored for purchase.  The sand is covered with well-worn "+
     "rugs.  Tapestries hang from the tent's ceiling.  "+
     "Above the counter is a sign to help customers."
   );
   set_items( ([
   ({ "tent" }) :
     "The tent is a simple structure made of canvass.  A few wooden posts "+
     "help support the tent's ceiling.\n",
   ({ "goods", "good" }) :
     "Merchants keeps a watchful eye out for thieves and shoplifters.  The goods "+
     "may be scattered about the shop you doubt you could take them unnoticed.\n",
   ({ "sand", "rugs", "floor" }) :
     "Merchants has thought to place rugs on the sandy floor to prevent added dust "+
     "and sand in the room to ruin the goods.",
   ({ "tapestries", "ceiling" }) :
     "The tent's ceiling is criss-crossed with a series of ropes.  From these "+
     "ropes numerous colorful tapestries depicting nomad warriors on horseback "+
     "and prepared for battle.  The tapestries serve as room dividers.\n",
     "sign": "It looks like a brass sign.  Perhaps you should read it?\n"
    ]));
}

int do_read(string str){
  if(!str) { return 0; }
  if(str != "sign") {return 0;}
  write("The brass sign reads:\n"+
    "Nomad's Bazaar\n"+
    "Merchants offer the best available for the camp.\n"+
    "'say <shopkeeper's name>, help' for assistance.\n"
  );
  say(this_player()->query_cap_name()+" reads the brass sign.\n",this_player());
  return 1;
}

int check_peasant() {
  object *all;

  all = filter_array(livings(), "my_peasant_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_peasant_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/peasant")  
    return 1;                                        
  return 0;
}                                      
