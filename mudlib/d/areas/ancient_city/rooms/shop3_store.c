
#include "../ruins.h/"
#include <std.h>
#define WEAPONS ({ "long-sword", "short-sword", "bastard-sword", "two-handed-sword", "halberd", "glaive", "dagger", "footman's-mace", "footman's-flail", "quarter-staff", "great-axe", "hand-axe", "morning-star" })

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long("This is the storage room for Smithy's Weapons Store. Lots of valuable looking wares lie about.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("storage room", 1);
  add_exit(ROOMS+"shop3", "west");
set_door("iron door", (ROOMS+"shop3"), "west","shop3 store");
set_open("iron door", 0);
set_locked("iron door", 1);
set_lock_level("iron door", 22);
  return;
}

void reset() {
  object *inv, bob, *tmp;
  int i, max;

  ::reset();
  seteuid(getuid());
  bob = present("shopkeeper", 
                find_object_or_load(ROOMS+"shop3"));
  if(bob) {
    message("info", "Smithy says in Common: Wait a second.  I've got a new
"+
            "shipment coming in...", environment(bob));
    call_out("finish_deliver", 12, bob);
  }
  max = -1 * sizeof(all_inventory(this_object()))/3 + 6;
  if(sizeof(inv = all_inventory(this_object())) > 30) {
    tmp = ({});
    for(i = 30;i < sizeof(inv); i++) if(!living(inv[i])) tmp += ({ inv[i]
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
    message("info", "Smithy says in Common: It's all here now.",
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
                     (random(3)+1+(random(9)/6)+random(9)/7+random(9)/8)));
    ob->move(this_object());
  }
  return;
}


