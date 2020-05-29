inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/cleric/train_room", "east");
   set("short","His Sacred Reserve");
   set("long", @TEXT
You have entered the His sacred reserve.  Within these walls you
may find that there are treasures and bounty that the flock have
left in a spirit of unity and communal love.  Any priest of the
faith may store items here for themselves and others.  Several
lockers and chest are available for use to store such possessions.

You feel an unmistakable impression that should you leave any
chest or locker open, all items contained therein would be
given unto our God.
TEXT
);
}

