// massively stolen code by khojem

#include <security.h>
#include <std.h>
#define HIGH_FLOOR 2
#define ROOMS_PER_FLOOR 30

inherit VAULT;

mapping owners;

void save_this_room();
string *query_all_owners();
string query_owner(string room);
int query_room_num(string owner);
void new_owner(string who, string room, int time);
int get_next_room();

void save_this_room() {
  seteuid(UID_DAMNED_DATA);
  save_object("/d/damned/data/inn_room_bl");
  seteuid(getuid());
  return;
}

void new_owner(string who, string room, int time) {
  object ob;
  string r_num;

  if(!owners) owners = ([]);
  if(sscanf(room, "%*sinn_%s.inn", r_num) != 2) return;
  owners[room] = ([]);
  owners[room]["owner"] = who;
  owners[room]["time"] = time;
  ob = find_object(room);
  if(room)
    room->virtual_setup("inn_"+r_num);
  save_this_room();
  return;
}

int query_time_left(string owner) {
  string room_file;

  if(member_array(owner, query_all_owners()) < 0)
    return 0;
  room_file = sprintf("/d/khojem/port/virtual/inn_%d.inn",
    query_room_num(owner));
  if(!owners[room_file]) return 0;
  if(!mapp(owners[room_file]) || !owners[room_file]["time"]) {
    map_delete(owners, room_file);
    return 0;
  }
  return (int)owners[room_file]["time"] - time();
}

string query_owner(string room) {
  object room_obj;
  int i;

  if(!owners || !owners[room]) return 0;
  if(!mapp(owners[room]) || !owners[room]["time"] ||
     !owners[room]["owner"]) {
    map_delete(owners, room);
    save_this_room();
    return 0;
  }
  if(owners[room]["time"] >= time())
     return owners[room]["owner"];
  else {
    map_delete(owners, room);
    room_obj = load_object(room);
    call_out("move_all_inv", 4, room_obj);
    save_this_room();
    return 0;
  }
}

void move_all_inv(object room_obj) {
  object *inv;
  int i;
  
  if(room_obj) {
    inv = all_inventory(room_obj);
    i = sizeof(inv);
    while(i--)
      if(inv[i]->query_is_locker() && inv[i]->query_closed())
        inv[i]->toggle_closed();
    inv = deep_inventory(room_obj);
    i = sizeof(inv);
    while(i--) {
      if(base_name(inv[i]) == "/std/obj/coins") inv[i]->remove();
      else
        inv[i]->move(load_object("/d/khojem/port/inn/inn_store"));
    }
  }
  return;
}

int query_room_num(string owner) {
  string *room_keys;
  int i, num;

  if(!owners) return 0;
  room_keys = keys(owners);
  i = sizeof(room_keys);
  while(i--) {
    if(!mapp(owners[room_keys[i]]) || !owners[room_keys[i]]["owner"]) {
      map_delete(owners, room_keys[i]);
      save_this_room();
      continue;
    }
    if(owners[room_keys[i]]["owner"] == owner) {
      if(sscanf(room_keys[i], "%*sinn_%d.inn", num) != 2) return 0;
      else return num;
    }
  }
  return 0;
}

int get_next_room() {
  string *room_keys, num;
  int max, j;

  query_all_owners();
  max = HIGH_FLOOR * ROOMS_PER_FLOOR;
  for(j=0;j < max; j++) {
    num = sprintf("%d%2'0'd", j/ROOMS_PER_FLOOR + 1,j%ROOMS_PER_FLOOR);
    if(!owners ||
      !owners[sprintf("/d/khojem/port/virtual/inn_%s.inn", 
        num)])
    return atoi(num);
  }
  return 0;
}

string *query_all_owners() {
  string *ret, *room_keys;
  int i;

  if(!owners) return ({ });
  ret = ({});
  i = sizeof(room_keys = keys(owners));
  while(i--) {
    query_owner(room_keys[i]);
    if(owners[room_keys[i]])
      ret += ({ owners[room_keys[i]]["owner"] });
  }
  return ret;
}

void create() {
  ::create();
  owners = ([]);
  restore_object("/d/damned/data/inn_room_bl");
  set_property("indoors", 1);
  set_property("light", 2);
  set_property("no attack", 1);
  set_property("no spell", 1);
  set("short", "Front Desk of the Bonny Lass Inn");
  set("long",
      "This is the front desk of the Bonny Lass Inn.  "+
      "An inn clerk stands before you.  There is a sign on "+
      "the wall which has the inn's rates.  Try telling the "
      "clerk 'help' for info on renting rooms.\n");
  set_items(([ "sign" : "Try reading it." ]));
  add_exit("/d/khojem/port/inn/foyer", "northeast");
  add_exit("/d/khojem/port/room/s16","southwest");
  add_exit("/d/khojem/port/inn/chest","north");
  set_door("north door", "/d/khojem/port/inn/chest", 
    "north","port_chest_shop");
  this_object()->reset();
  return;
}

void init() {
  ::init();
    add_action("read", "read");
}

int read(string str) {
  if(str != "sign") return 0;
  write(
        "Prices for rooms:\n(Real time, not Mud time)\n"+
        "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
       "Daily Rate:        1300 silver\n"+
       "Weekly Rate:       410 gold\n"+
       "Monthly Rate:      1500 gold\n");
  return 1;
}

void reset() {
  object ob;
  
  ::reset();
  if(!present("clerk", this_object())) {
    seteuid(getuid());
    ob = new("/d/khojem/port/inn/inn_clerk");
    ob->move(this_object());
  }
  if(!present("trash can"))
    new("/wizards/mushroom/obj/misc/tcan")->move(this_object());
  return;
}
