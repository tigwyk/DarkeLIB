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
    set("long", "This is the upper floor of the castle. All the walls are made of glass, making it a giant window allowing you a marvelous view on the town below. You see before you scatter many weapons left bt other adventures.");
    add_exit("/d/newbieville/rooms/castle", "down");
    add_exit("/d/newbieville/rooms/upperfloor2", "up");
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
max = -1 * sizeof(all_inventory(this_object()))/3 + 4;
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
  int i, j;

  seteuid(getuid());
  for(j=1; j <= 3; j++) {
    i = random(sizeof(WEAPONS));
    ob = new(sprintf("/d/damned/virtual/%s_%d.weapon", WEAPONS[i],
                     (random(1)+1)));
    ob->move(this_object());
  }
  return;
}  
