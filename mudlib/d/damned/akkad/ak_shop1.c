#include <daemons.h>
#define CURRS ({ "mithril", "gold", "electrum", "copper", \
                "silver" })

inherit "/std/vault";

private int open;

void init() {
   add_action("read", "read");
   ::init();
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("silas") && open) {
      new("/d/damned/akkad/obj/mon/silas")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/akkad/ak_marknw", "east");
   add_exit("/d/damned/akkad/shops/shop1_store", "north");
   set_door("vault door", "/d/damned/akkad/shops/shop2_store", "north",
	    "ak shop1 store");
   set_open("vault door", 0);
   set_locked("vault door", 1);
   open = 1;
   set_door("west door", "/d/damned/akkad/ak_marknw", "east",
	    "ak shop2");
   set_open("west door", 1);
   set_locked("west door", 0);
   set_lock_level("vault door", 27);
   set("short","   0\n   | \n   @--0\n     \n    \nThe Money Changer");
   set("long",
"This is the office of the Money Changer.  A thin, pensive-looking "
"half-elf eyes you from behind a desk laiden with parchments.  "
"There is a large sign on the west wall, and a huge vault door "
"crafted of fine metal is seen to the north.\n   0\n   | \n   @--0\n     \n    \n");
   set_items( (["sign": (: call_other, this_object(), "money_rates" :),
              "vault door" : "It looks almost impregnable."]) );
   set_open_function("open_door", "2:00:00");
   set_close_function("close_door", "18:00:00");
}

void money_rates() {
  int i, tmp;
  string line;
  float rate;

  write("The sign is titled 'Current Exchange Rates of Major "+
        "Currencies'.  It reads:\n");
  for(i=0; i<sizeof(CURRS); i++) {
    rate = ECONOMY_D->__Query(CURRS[i], "rate");
    if(rate < (float)ECONOMY_D->__Query("gold", "rate"))
      line = sprintf("%-30'.'s%-5.1f gold", capitalize(CURRS[i])+":",
                     (float)ECONOMY_D->__Query("gold", "rate")/rate);
    else
      line = sprintf("%-30'.'s%-5.1f copper", capitalize(CURRS[i])+":",
                     (float)ECONOMY_D->__Query("copper", "rate")/rate);
    write(line);
  }
   write("\nType 'help money' for help on exchanging.\n"
   "NOTE: Due to the flooded market, platinum is no "+
   "longer carried here.");
  return;
}

void open_door() {
  set_locked("west door", 0);
  set_open("west door", 1);
  call_other("/d/damned/akkad/ak_marknw", "set_locked",
	     "west door", 0);
  call_other("/d/damned/akkad/ak_marknw", "set_open",
	     "west door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("silas", this_object());
  if(ob) ob->remove();
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave.", inv[i]);
      inv[i]->move(find_object_or_load("/d/damned/akkad/ak_marknw"));
    }
  }
  set_open("west door", 0);
  set_locked("west door", 1);
  call_other("/d/damned/akkad/ak_marknw", "set_open", 
		"west door", 0);
  call_other("/d/damned/akkad/ak_marknw", "set_locked", 
		"west door", 1);
   open = 0;
}

int read(string str) {
   if(str == "sign") {
      money_rates();
      return 1;
   }
   else
      return 0;
}
