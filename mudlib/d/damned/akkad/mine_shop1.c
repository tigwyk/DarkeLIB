//    Mine shop.
//    -Diewarzau 1/29/96
//    DarkeLIB 1.0
#define MINE_D "/daemon/mine_d"
#define MAX_SOUTH 98
#define MAX_EAST 98
#include <rooms.h>
#include <security.h>

inherit "/std/room";

string has_mine(object who);
int pay(object tp, int plat);

int pay(object tp, int plat) {
  plat = to_int(to_float(plat) * currency_rate("gold"));
  if((int)tp->query_money("gold") < plat) {
    message("info", "You do not have enough gold for that.",
          tp);
    return 0;
  }
  tp->add_money("gold", -1*plat);
  return 1;
}

void reset() {
  ::reset();
  if(!present("goff"))
    new("/d/damned/akkad/obj/mon/goff")->move(this_object());
  if(!present("key rack"))
    new("/d/damned/akkad/obj/misc/mine_key_rack")->move(this_object());
  return;
}

void create() {
  ::create();
  add_exit("/d/damned/akkad/ak_tavern3", "west");
  set_short("The Mine Shop");
  set_long(
  "This small shack is the mine shop.  Here you may buy a mine somewhere "
  "on the world map and hire workers for it.  Mining tools lie about and "
  "there is a sign on the wall.");
  set_items(([ ({ "tools", "mining tools" }) : "They are various picks, hammers, etc.",
      "sign" : (: call_other, this_object(), "read_sign" :) ]) );
  set_property("light", 1);
  set_property("indoors", 1);
  return;
}

int read_sign() {
  string tmp;

  tmp =
"Welcome to the Mine Shop.\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"Here, you may buy a mine on the world map as well as hire \n"
"mine workers.  As time passes, depending on where the mine is\n"
"built, certain minerals will be stocked in the mineral chest, and\n"
"may be removed by you.  If you fail to pay your staff for the\n"
"coming month before the current month is up, your mine WILL BE\n"
"LOST.  You may only own one mine at a time.\n"
"\n"
"Item     Description                         Cost\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
sprintf("mine     mine built on a plot + 1 month      %d gold\n", to_int(98000.0*currency_rate("gold")))+
"         (real time) worker fees.\n"
"\n"+
sprintf("workers  A month (real time) of worker fees  %d gold\n", to_int(42000.0*currency_rate("gold")))+
"         (last week of month only)\n"
"\n\nYou may type 'buy <item>' to buy one of the above, \n"
"or type 'remove mine' to have your current mine destroyed.\n"
"'time left' tells you how many days and hours of time you\n"
"have left on your workers' salaries.\n";

  this_player()->more(explode(tmp, "\n"));
  return 1;
}

void init() {
  ::init();
  add_action("destroy_mine", "remove");
  add_action("read_it", "read");
  add_action("buy_item", "buy");
  add_action("time_left", "time");
  return;
}

int buy_item(string str) {
  string file;

  if(str == "workers") {
    if(wizardp(this_player())) {
      write("Wizards may not keep up mines.");
      return 1;
    }
    if(!(file = has_mine(this_player()))) {
      write("You must buy a mine first.");
      return 1;
    }
    if(((int)MINE_D->time_left(file) / 86400) >= 7) {
      write("You must wait until the last week of the salary period "+
          "to pay the workers.");
      return 1;
    }
    if(!pay(this_player(), 42000)) return 1;
    MINE_D->register_mine(file);
    write("Your workers have been paid for an additional month.");
    return 1;
  }
  if(str == "mine") {
    if(wizardp(this_player())) {
      write("Wizards may not buy mines.");
      return 1;
    }
    if(has_mine(this_player())) {
      write("You may only own one mine at a time.");
      return 1;
    }
    write("Please choose a plot on which to drop your mine.\n"
          "Input the coordinates as <south>, <east>.  Example: 12,31");
    printf("coordinates> ");
    input_to("pick_plot", 0, this_player());
    return 1;
  }
  write("Look at the sign for the items you can buy.");
  return 1;
}

void pick_plot(string coords, object tp) {
  int south, east;
  object room, *inv;
  string name;
  int i;

  if(sscanf(coords, "%d,%d", south, east) != 2) {
    message("info", "Please input in the form <south>, <east>.", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  if(east > MAX_EAST || south > MAX_SOUTH) {
    message("info", "Those coordinates are off the map!", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  room = find_object_or_load(sprintf("/d/damned/virtual/room_%d_%d.world", east, south));
  if(!room) {
    message("info", "Those coordinates are off the map!", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  if(lower_case((string)room->query_terrain()) == "w") {
    message("info", "That is in the middle of the water!", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  if(member_array("mine", (string *)room->query_exits()) >= 0) {
    message("info", "There is already a mine there.", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  if(!pay(tp, 98000)) return;
  seteuid(UID_DAMNED_DATA);
  write_file("/d/damned/data/world_items.db",
      sprintf("%d_%d:/d/damned/virtual/%s_mine1_%d_%d.mine:mine:The entrance to %s's Mine\n",
          east, south, (string)tp->query_name(), east, south,
          capitalize((string)tp->query_name())));
  inv = all_inventory(room);
  message("info", "With blinding speed, a gang of dwarves assemble a new mine here!",
      room);
  i = sizeof(inv);
  while(i--) if(inv[i]) inv[i]->move(ROOM_VOID);
  name = base_name(room);
  seteuid(UID_ROOT);
  destruct(room);
  seteuid(getuid());
  i = sizeof(inv);
  while(i--) if(inv[i]) inv[i]->move(name);
  tp->set_property("has mine", sprintf("/d/damned/virtual/%s_mine2_%d_%d.mine",
                                  (string)tp->query_name(), east, south));
  tp->save_player((string)tp->query_name());
  MINE_D->register_mine(sprintf("/d/damned/virtual/%s_mine2_%d_%d.mine",
                                  (string)tp->query_name(), east, south));
  message("info", "Your mine is built.", tp);
  return;
}

int destroy_mine(string str) {
  string file;
  
  if(str != "mine") return 0;
  if(!(file=has_mine(this_player()))) {
    write("You do not have a mine.");
    return 1;
  }
  if((int)MINE_D->time_left(file) <= 0) {
    write("That mine is already scheduled to be destroyed.");
    return 1;
  }
  MINE_D->destroy_mine(file);
  write("Your mine will be dismantled on the next update no more than "+
      "8 hours from now.  If you change your mind before then, you can "
      "pay your workers and the mine will not be destroyed.");
  return 1;
}

int time_left(string str) {
  string file;
  int time;
  
  if(str != "left") return 0;
  if(!(file = has_mine(this_player()))) {
    write("You do not have a mine.");
    return 1;
  }
  if((time=(int)MINE_D->time_left(file)) < 0) {
    write("That mine is scheduled to be destroyed!  Pay the workers as soon "+
        "as possible to avoid losing the mine.");
    return 1;
  }
  write("You have "+sprintf("%d day%s and %d hour%s ",
        (time/86400), ((time/86400)==1)?"":"s",
        ((time%86400)/3600), (((time%86400)/3600)==1)?"":"s")+
        "left on your mine workers' salaries.");
  if((time/86400) < 7)
    write("You may pay them for an additional month if you wish.");
  return 1;
}

string has_mine(object who) {
  string file;
  object room;
  int x, y;

  if(!(file = (string)who->query_property("has mine")))
    return 0;
  if(sscanf(file, "/d/damned/virtual/%*s_mine2_%d_%d.mine", x, y) != 3) {
    who->remove_property("has mine");
    return 0;
  }
room = find_object_or_load(sprintf("/d/damned/virtual/room_%d_%d.world", x, y));
  if((string)room->query_exit("mine") != sprintf("/d/damned/virtual/%s_mine1_%d_%d.mine",
            (string)who->query_name(), x, y)) {
    who->remove_property("has mine");
    return 0;
  }
  return file;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
}
