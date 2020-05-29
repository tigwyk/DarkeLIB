//  The fabeled castle shop!

#include <security.h>
#include <rooms.h>
#define CASTLE_D "/daemon/castle_d"
#define MAX_SOUTH 79
#define MAX_EAST 39
#define DOORS ([ "wood door" : 20000, "iron door" : 81000, "steel door" : 540000, \
        "reinforced door" : 1160000, "vault door" : 2750000 ])
#define FEATURES ([ "no scry" : 470000, "no teleport" : 280000, \
        "no summon" : 370000, "healing room" : 90000, \
        "special exits" : 50000 ])

inherit "/std/room";

int pay(object tp, int plat);

int pay(object tp, int plat) {
  plat = to_int(to_float(plat) * currency_rate("mithril"));
  if((int)tp->query_money("mithril") < plat) {
    message("info", "You do not have enough mithril for that.",
          tp);
    return 0;
  }
  tp->add_money("mithril", -1*plat);
  return 1;
}

void reset() {
  ::reset();
  if(!present("key rack"))
    new("/d/damned/akkad/obj/misc/castle_key_rack")->move(this_object());
  if(!present("sansef"))
    new("/d/damned/akkad/obj/mon/sansef")->move(this_object());
}

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("The Castle Shop");
add_exit("/d/daybreak/room/dbcc2", "east");
  set("long",
  "This is the Castle Shop.  Here you may buy plots of land "
  "upon which to build castles as well as many castle items.  "
  "Castles save chests in the same way inns do.  There is a "
  "large sign on the wall.");
  add_item("sign", (: call_other, this_object(), "read_sign" :));
  return;
}

int read_sign() {
  string tmp;

  tmp =
"Welcome to the Castle Shop!\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-\n"
"In order to buy a castle, you must first select a plot of "
"land on the world map which does not already contain a castle.  "
"The plot comes with a free room.  Once you have selected a plot, "
"You may buy additional rooms (up to 20), doors, or features for "
"your castle.  You install these by going to your castle and "
"typing 'help castle'.\n\n"+
sprintf("plot of land               %d mithril (one free room!)\n", to_int(3020000.0*currency_rate("mithril")))+
sprintf("castle room                %d mithril\n", to_int(420000.0*currency_rate("mithril")))+
sprintf("wood door                  %d mithril\n", to_int(20000.0*currency_rate("mithril")))+
sprintf("iron door                  %d mithril\n", to_int(81000.0*currency_rate("mithril")))+
sprintf("steel door                 %d mithril\n", to_int(540000.0*currency_rate("mithril")))+
sprintf("reinforced door            %d mithril\n", to_int(1160000.0*currency_rate("mithril")))+
sprintf("vault door                 %d mithril\n", to_int(2750000.0*currency_rate("mithril")))+
"\n"
"Castle special features (good for one room only!):\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
sprintf("no scry                    %d mithril\n", to_int(470000.0*currency_rate("mithril")))+
"  ^ You cannot be scried in that room\n"+
sprintf("no teleport                %d mithril\n", to_int(280000.0*currency_rate("mithril")))+
"  ^ No one can teleport to that room.\n"+
sprintf("no summon                  %d mithril\n", to_int(370000.0*currency_rate("mithril")))+
"  ^ No one can be summoned from that room.\n"+
sprintf("healing room               %d mithril\n", to_int(90000.0*currency_rate("mithril")))+
"  ^ Any PLAYER in the room heals mp and hp at double rate.\n"+
sprintf("special exits              %d mithril\n", to_int(50000.0*currency_rate("mithril")))+
"  ^ Teleport exits to various useful places (church, shop, etc.)\n"
"\n"
"Buy any item with 'buy <item>'\n"
"\nNEW and IMPORTANT\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"Castle Upkeep!  You must now pay a monthly fee for your castle, which increases "
"if you have more rooms.  You may pay up to three months in advance (real time, "
"not mud months).  If you will be unable to play for more than three months, "
"contact an arch.\n"
"\n"
"upkeep cost................Tells you the monthly cost (in gold) of your upkeep.\n"
"upkeep time................Tells you the time left on your current payment.\n"
"                           If this time expires, your castle will be torn down.\n"
"                           NO reimbursement will be given unless you contacted\n"
"                           an arch IN ADVANCE with an explanation as to why\n"
"                           you couldn't pay the castle fees.  This rule is\n"
"                           NOT flexible.  If the castle is torn down, all\n"
"                           contents will be lost.\n"
"upkeep pay.................Pay one month's worth of castle upkeep.  Only gold\n"
"                           is accepted.\n";
  this_player()->more(explode(wrap(tmp, (int)this_player()->getenv("SCREEN")), "\n"));
  return 1;
}

void init() {
  ::init();
  add_action("buy_item", "buy");
  add_action("read_it", "read");
  add_action("upkeep_action", "upkeep");
  return;
}

int upkeep_action(string str) {
  int utime, cost;

  if(str == "time") {
    if(!CASTLE_D->is_registered((string)this_player()->query_name())) {
      write("You do not have a castle.");
      return 1;
    }
    utime = (int)CASTLE_D->time_left((string)this_player()->query_name());
    if(utime <= 0) {
      write("Your upkeep payments are past due!  If your castle has not been "
          "destroyed already, you must pay rent immediately to avoid destruction "
          "of your castle.");
      return 1;
    }
    write(sprintf("You have %d weeks, %d days, and %d hours left on your upkeep payments.",
                  utime/604800, (utime%604800)/86400, (utime%86400)/3600));
    return 1;
  }
  if(str == "cost") {
    if(!CASTLE_D->is_registered((string)this_player()->query_name())) {
      write("You do not have a castle.");
      return 1;
    }
    write("Your monthly upkeep cost for your castle is "+sprintf("%d gold.",
          (int)CASTLE_D->upkeep_cost((string)this_player()->query_name())));
    return 1;
  }
  if(str == "pay") {
    if(!CASTLE_D->is_registered((string)this_player()->query_name())) {
      write("You do not have a castle.");
      return 1;
    }
    utime = (int)CASTLE_D->time_left((string)this_player()->query_name());
    if(utime >= 7776000) {
      write("You may only pay a maximum of three months in advance");
      return 1;
    }
    cost = (int)CASTLE_D->upkeep_cost((string)this_player()->query_name());
    write("Upkeep cost: "+cost+" gold.");
    if((int)this_player()->query_money("gold") < cost) {
      write("You do not have enough gold to pay the upkeep.");
      return 1;
    }
    this_player()->add_money("gold", -1*cost);
    write("One month upkeep paid.");
    CASTLE_D->add_upkeep((string)this_player()->query_name(),
      2592000);
    return 1;
  }
  notify_fail("Look at the sign for help.\n");
  return 0;
}

int buy_item(string str) {
  string *strp;

  if(!CASTLE_D->is_registered((string)this_player()->query_name())) {
    this_player()->remove_property("has castle");
    this_player()->remove_property("castle rooms");
  }
  str = lower_case(str);
  if(str == "plot of land") {
    if(this_player()->query_property("has castle")) {
      write("You already have a castle.");
      return 1;
    }
    write("Please choose a plot on which to drop your castle.\n"
          "Input the coordinates as <south>, <east>.  Example: 12,31\n"
          "(enter to abort)\n");
    printf("coordinates> ");
    input_to("pick_plot", 0, this_player());
    return 1;
  }
  if(!this_player()->query_property("has castle")) {
    write("The only item you can buy is a 'plot of land'.");
    return 1;
  }
  if(str == "castle room") {
    if(!pay(this_player(), 420000)) return 1;
    write("You purchase an extra room.");
    this_player()->set_property("castle rooms", 1+
        (int)this_player()->query_property("castle rooms"));
    return 1;
  }
  if(member_array(str, keys(DOORS)) >= 0) {
    if(!pay(this_player(), DOORS[str])) return 1;
    strp = (string *)this_player()->query_property("castle doors");
    if(!strp) strp = ({});
    strp += ({ str });
    this_player()->set_property("castle doors", strp);
    write("You have purchased a "+str+".");
    return 1;
  }
  if(member_array(str, keys(FEATURES)) >= 0) {
    if(!pay(this_player(), FEATURES[str])) return 1;
    strp = (string *)this_player()->query_property("castle features");
    if(!strp) strp = ({});
    strp += ({ str });
    this_player()->set_property("castle features", strp);
    write("You have purchased the feature: "+str+".");
    return 1;
  }
  notify_fail("Look at the sign for a list of inventory.\n");
  return 0;
}

void pick_plot(string coords, object tp) {
  int south, east;
  object room, *inv;
  string name;
  int i;

  if(!coords || coords == "") {
    write("Aborted.");
    return;
  }
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
  if(member_array("castle", (string *)room->query_exits()) >= 0) {
    message("info", "There is already a castle there.", tp);
    printf("coordinates> ");
    input_to("pick_plot", 0, tp);
    return;
  }
  if(!pay(tp, 820000)) return;
  seteuid(UID_DAMNED_DATA);
  write_file("/d/damned/data/world_items.db",
      sprintf("%d_%d:/d/damned/virtual/%s_room_1.castle:castle:%s's Castle\n",
          east, south, (string)tp->query_name(),
          capitalize((string)tp->query_name())));
  inv = all_inventory(room);
  message("info", "With blinding speed, a gang of dwarves assemble a castle here!",
      room);
  i = sizeof(inv);
  while(i--) if(inv[i]) inv[i]->move(ROOM_VOID);
  name = base_name(room);
  seteuid(UID_ROOT);
  destruct(room);
  seteuid(getuid());
  i = sizeof(inv);
  while(i--) if(inv[i]) inv[i]->move(name);
  tp->set_property("has castle", 1);
  tp->set_property("castle rooms", 1);
  CASTLE_D->register_castle((string)this_player()->query_name(),
    sprintf("/d/damned/virtual/room_%d_%d.world", east, south));
  tp->save_player((string)tp->query_name());
  call_other(sprintf("/d/damned/virtual/%s_room_1.castle", (string)tp->query_name()),
	"add_exit", sprintf("/d/damned/virtual/room_%d_%d.world", east, south),
	"out");
  call_other(sprintf("/d/damned/virtual/%s_room_1.castle", (string)tp->query_name()),
	"rewrite_castle");
  message("info", "Your castle is built.", tp);
  return;
}

   int read_it(string str) {
      if(str == "sign") {
         read_sign();
         return 1;
       }
       return 0;
   }
