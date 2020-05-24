//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
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
    set("long", "This is the upper floor of the castle. All the walls are made of glass, making it a giant window allowing you a marvelous view on the town below. You see before you scatter many pieces of leather armour left bt other adventures.");
    add_exit("/d/newbieville/rooms/upperfloor", "down");
set_items((["window" :
"You peer down.
  #     B: Bar
 B#A    A: Armor Shop
##T##   W: Weapon Shop
 G#W    G: General Store
  #     T: Town Square/Castle
"]));
return;
}
void reset() {
  object *inv, *tmp;
int i, max;

  ::reset();
max = -1 * sizeof(all_inventory(this_object()))/3 + 1;
  if(sizeof(inv = all_inventory(this_object())) > 1) {
    tmp = ({});
    for(i = 1;i < sizeof(inv); i++) if(!living(inv[i])) tmp += ({ inv[i]
});
    call_out("remove_all", 5, tmp);
  } else
  if(max >= 1) {
    for(i = 1;i <= max;i++)
      call_out("clone_once", i*2);
  }
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && environment(inv[i]) == this_object())
inv[i]->remove();
  return;
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Dakkon says in Common: It's all here now.",
            environment(bob));
  return;
}

void clone_once() {
  object ob;
  int i;

  seteuid(getuid());
for(i=1;i <=1; i++) {
   ob = new("/std/diewarzau/obj/misc/rations_pack");
      ob->set_rations(5, 1);
  if(i <= 1) {
   ob = new("/std/diewarzau/obj/misc/rations_pack");
     ob->set_rations(5, 1);
  ob->move(this_object());
    ob = new("/d/damned/virtual/studded-leather-glove.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/chain-coif.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/leather-vest.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/leather-pants.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/leather-boots.armour");
    ob->move(this_object());
  }
}
  return;
}  
