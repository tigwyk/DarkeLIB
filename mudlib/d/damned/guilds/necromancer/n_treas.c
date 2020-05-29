inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/necromancer/train_room", "west");
   set("short", "The Vault of the Dead");
   set("long",
"This is the Vault of the Dead.  A room where any necromancer may store their items.  The room is a barren room made of stone and granite, only a few candles light the side of the room, which accentuates the hidden darkness of this room.
There are two lockers in this room for any necromancer to store their dastardly items.  After each use of the lockers REMEMBER to close the lockers, or else the crypt keeper will confiscate the items for his own personal use.
");
new("/d/damned/guilds/necromancer/shovel")->move(this_object());
new("/d/damned/guilds/necromancer/shovel")->move(this_object());

}

