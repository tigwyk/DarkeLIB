//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
#include <rooms.h>
#include <security.h>


#define WEAPONS ({ "long-sword", "short-sword", "bastard-sword", \
  "two-handed-sword", "halberd", "glaive", "dagger", "footman's-mace", \
  "footman's-flail", "quarter-staff", "great-axe", "hand-axe", \
  "morning-star" })
#define TORSO_ARMOUR ({ "breast-plate", "leather-jacket", "chain-mail", "studded-leather-jacket", "corslet", "leather-vest" })
#define LEG_ARMOUR ({ "chain-greaves", "iron-greaves", "scale-greaves", "leather-pants", "studded-leather-pants" })
#define HEAD_ARMOUR ({ "great-helm", "chain-coif" })
#define SHIELDS ({ "large-shield", "buckler-shield", "small-shield" })
#define FEET_ARMOUR ({ "metal-boots" })

inherit "/std/vault";

void clone_once();

//inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. You see before you scattered many pieces of leather armour left by other adventures.\n%^B_RED%^If you are a new player you should wait and%^YELLOW%^look%^RESET%^%^RESET%^\nAfter you gather the armour and other supplies\n%^B_RED%^you should go%^YELLOW%^d to the bottom floor and read the board%^RESET%^%^RESET%^\n\n you can also%^YELLOW%^'look sign'%^RESET%^for further directions");
    add_exit("/d/newbieville/rooms/upperfloor", "down");
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
"This sign is to help you get all items and equip\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"You can type%^YELLOW%^'get (item)'%^RESET%^to pick up a item\n\n"
"Once you have a item you can type%^YELLOW%^'equip'%^RESET%^or wear armour in a certain limb such as right hand or left hand for gloves\n\n"
"You can also type%^YELLOW%^'get all'%^RESET%^ to gather all the items in the room\n\n"
"for better light as a new player you can type%^YELLOW%^'light lantern'%^RESET%^ to provide you a better light sorce during the night. Be aware it only has so much fuel before you need more oil to refuel it.\n\n"
"You also have rations for food type%^YELLOW%^'get ration from pack'%^RESET%^to get the food from the pack and type%^YELLOW%^'eat ration'%^RESET%^to consume it\n\n"
"If this room is Empty and does not have any items in it wait for it to respawn or message a Wizard or Arche with%^YELLOW%^who%^RESET%^ then type%^YELLOW%^tell (person) msg%^RESET%^\n\n"

"You can also type%^YELLOW%^help newbie%^RESET%^and read the helpfile while you wait";
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
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
if(!present("rations_pack"))
ob = new("/std/diewarzau/obj/misc/rations_pack");
ob->set_rations(5, 1);
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/rations_pack");
ob->set_rations(5, 1);
ob->move(this_object());
if(!present("chain-coif"))
ob = new("/d/damned/virtual/chain-coif.armour");
    ob->move(this_object());
if(!present("leather-vest"))
ob = new("/d/damned/virtual/leather-vest.armour");
    ob->move(this_object());
if(!present("iron-bracer"))
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
if(!present("iron-bracer"))
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
if(!present("padded-glove"))
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
if(!present("padded-glove"))
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
if(!present("leather-pants"))
    ob = new("/d/damned/virtual/leather-pants.armour");
    ob->move(this_object());
if(!present("leather-boots"))
    ob = new("/d/damned/virtual/leather-boots.armour");
    ob->move(this_object());
if(!present("lantern"))
    ob = new("/std/obj/lantern");
    ob->move(this_object());
}
