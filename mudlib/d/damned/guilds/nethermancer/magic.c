#include <daybreak.h>
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("warsten")) {
      new("/d/damned/guilds/nethermancer/warsten")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/nethermancer/nexus_room", "north");
   add_exit("d/damned/guilds/nethermancer/magic_store", "west");
   set_door("wooden door", "d/damned/guilds/magic_store", "west","ak shop5 store");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   set_lock_level("wooden door", 22);
   set("short","The Magic Shop");
   set("long","This is the Magic Shop.  Several magical wares can be seen "
"lying about.  There is a sign on the wall\n"
"To the west is a sturdy wooden door.");
   set_items( (["sign": (: call_other, this_object(), "read_sign" :),
              "wooden door" : "It looks very sturdy.",
              "south door" : "It is a large wooden door.",
              "door" : "There is an south door and a wooden door" ]) );
}

int read_sign() {
  write("Welcome to Karsten's World o' Magic!\n"
  "\nHere, you may buy figurines for summoning spells and vials for "
   "potion spells.\n\n"
  "Also, if you are too lazy to make a potion yourself, we offer two "
  "varieties of healing potions here!\n");
  write("White potion - 100hp heal.\nAlabaster potion - 200 hp + remove poison\n"+
      "Purple potion - helps regen magic points but lowers casting chance temporarily.");
  return 1;
}

