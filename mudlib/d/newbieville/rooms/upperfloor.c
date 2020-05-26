//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
#define WEAPONS ({ "long-sword", "short-sword", "bastard-sword", \
  "two-handed-sword", "halberd", "glaive", "dagger", "footman's-mace", \
  "footman's-flail", "quarter-staff", "great-axe", "hand-axe", \
  "morning-star" })

inherit "/std/vault";

void clone_once();

//inherit ROOM;
void create() {

    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. You see before you scattered many weapons left by other adventures. %^B_RED%^If you are a new player you should wait and %^YELLOW%^read sign%^RESET%^. After you gather the weapon or weapons you need you should go %^YELLOW%^up or 'u' for short%^RESET%^. You can also %^YELLOW%^'look sign'%^RESET%^ for further directions.");
    add_exit("/d/newbieville/rooms/welcome_center", "down");
    add_exit("/d/newbieville/rooms/upperfloor2", "up");
set_items((["window" :
"You peer down.
  #     B: Bar
 B#A    A: Armor Shop
##T##   W: Weapon Shop
 G#W    G: General Store
  #     T: Town Square/Castle
"]));
set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg =
"This sign is to help you pick up items and equip\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"If this room is empty wait 30 secounds in this room it will respawn\n\n"
"You can type%^YELLOW%^'get (item)'%^RESET%^to pick up a weapon for example%^YELLOW%^'get sword'%^RESET%^\n\n"
"Once you have a item you can type%^YELLOW%^'equip'%^RESET%^or wield weapon in a certain hand example%^YELLOW%^'wield sword in right hand'%^RESET%^you should check what hand you prefer with%^YELLOW%^'score'%^RESET%^\n\n"
"Please note that you must have weapon skill such as blade, axe, or blunt to be of any use with that weapon type\n\n"
"You will need to join a guild in daybreak first to train weapon skills for now read the rooms description and follow directions\n\n"

"If this room is Empty and does not have any weapons wait for it to respawn or message a Wizard or Arche with%^YELLOW%^'who'%^RESET%^ then type%^YELLOW%^'tell (person) msg'%^RESET%^ example 'tell TLNY hi'\n\n"

"You can also type%^YELLOW%^'help newbie'%^RESET%^and read the helpfile while you wait";
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",30,this_player());
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
} 

void reset() {
object ob;
if(!present("vibrosword")) {
    ob = new("/d/damned/virtual/vibrosword_1.weapon");
    ob -> set("short", "newbie vibrosword");
    ob -> set("id", ({ "vibrosword","sword","newbie sword","newbie vibrosword"}));
    //ob -> set_wc(40,"cutting");
    //ob -> set_wc(20,"impaling");
    ob -> set_wc(40,"fire");
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/mithril");
    ob->move(this_object());
}

if(!present("vibroaxe")) {
  ob = new("/d/damned/virtual/vibroaxe_1.weapon");
  ob -> set("short", "newbie vibroaxe");
  ob -> set("id", ({ "vibroaxe","axe","newbie axe","newbie vibroaxe"}));
  //ob -> set_wc(40,"cutting");
  //ob -> set_wc(20,"impaling");
  ob -> set_wc(40,"fire");
  ob -> set_hit_bonus(50);
  ob -> set_parry_bonus(50);
  ob -> set_material("metal/mithril");
  ob->move(this_object());
}

}
