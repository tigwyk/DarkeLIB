//   Wizard:  Khojem
//   Wood-Elf Fresh Grocer - Barkfir
//   grocery_shop.c

#include <std.h>

inherit ROOM;

void init(){
     ::init();
     add_action("do_read","read");
}

void reset() {
   ::reset();
   if(!present("barkfir")) {
      new("/d/khojem/new/shop/barkfir")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/khojem/new/room/plat5", "south");
   set("short","Barkfir's Fresh Grocery & Goods");
   set("long",
     "This must be the market for Fir'nvillee's elves.  The racks are "+
     "filled with produce and goods on sale here for the village's farmers "+
     "and tradesmen.  The establishment is clean and well maintained.  "+
     "Above the counter is a sign to help customers."
   );
   set_items( ([
   ({ "rack","racks" }) :
     "They are simple wooden racks to hold goods for sale.\n"+
     "Barkfir keeps a close eye on his goods to avoid loss.\n",
     "counter" : "A simple, wooden countertop to package goods once sold.\n",
     "sign": "It looks like a wooden sign.  Perhaps you should read it?\n"
    ]));
}

int do_read(string str){
  if(!str) {
    notify_fail("What is it you want to read?\n");
    return 0;
  }
  if(str != "sign") {return 0;}
  write("The wooden sign reads:\n"+
    "Barkfir's Fresh Grocery & Goods\n"+
    "Fir'nvillee's best choice to meet all your shopping needs.\n"+
    "'say barkfir, help' for assistance.\n"
  );
  say(this_player()->query_cap_name()+" reads a sign.\n",this_player());
  return 1;
}
