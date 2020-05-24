#include <daybreak.h>
#include <std.h>

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long("This is the storage room for the Magic Shop. Lots of "
           "valuable looking wares lie about.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("storage room", 1);
  add_exit("/d/damned/guilds/nethermancer/magic", "east");
  set_door("wooden door", "/d/damned/guilds/nethermancer/magic", "east","ak shop6 store");
  set_open("wooden door", 0);
  set_locked("wooden door", 1);
  set_lock_level("wooden door", 22);
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) ==
this_object()) inv[i]->remove();
  return;
}

void reset() {
  object *inv, bob, ob;
  int i;

  ::reset();
  seteuid(getuid());
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  bob = present("shopkeeper", find_object_or_load("/d/damned/guilds/nethermancer/magic"));
  if(bob) {
    message("info", "Warsten says in Common: Wait a second.  I've got a new"+
            "shipment coming in...", environment(bob));
    call_out("finish_deliver",5, bob);
  }
  i = 5;
  while(i--) {
   /*
 ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a white potion", "healing_potion",
               "/std/diewarzau/obj/misc/heal_func",
               100);
    ob->set_value(670);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/bag_of_holding");
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("an alabaster potion", "alabaster_potion",
               "/std/diewarzau/obj/misc/heal_func",
               200);
    ob->set_value(3200);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/std/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/std/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
*/
    //new("/d/damned/guilds/nethermancer/misc/soul_orb")->move(this_object());
   // ob->set_value(50);
   // ob->move(this_object());

    ob = new("/d/damned/guilds/nethermancer/misc/soul_orb");
    ob->set_value(1);
    ob->move(this_object());
    //new("/d/damned/guilds/nethermancer/misc/soul_orb")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/soul_crystal")->move(this_object());
    //new("/d/damned/guilds/nethermancer/misc/master_nexus")->move(this_object());
   // new("/d/damned/guilds/nethermancer/misc/greater_nexus")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/large_ring")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/huge_ring")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/gigantic_ring")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/marble_slab")->move(this_object());
    new("/d/damned/guilds/nethermancer/misc/owedquarian_diamond")->move(this_object());
    //new("/std/diewarzau/obj/misc/golden_figurine")->move(this_object());
    //new("/std/diewarzau/obj/misc/platinum_figurine")->move(this_object());
    //new("/std/diewarzau/obj/misc/jeweled_figurine")->move(this_object());
    //new("/std/diewarzau/obj/misc/skill_ring")->move(this_object());
    //new("/std/diewarzau/obj/misc/power_stone")->move(this_object());
    //ob = new("/std/diewarzau/obj/misc/power_stone");
    //ob->set_max(100);
    //ob->move(this_object());
    //ob = new("/std/diewarzau/obj/misc/power_stone");
    //ob->set_max(500);
    //ob->move(this_object());
    //new("/std/diewarzau/obj/misc/spell_scroll")->move(this_object());
    //new("/std/diewarzau/obj/misc/small_vial")->move(this_object());    
  }
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Warsten says in Common: It's all here now.",
            environment(bob));
  return;
}
