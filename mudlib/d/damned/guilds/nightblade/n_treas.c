inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/nightblade/train_room", "east");
   set("short","The Nightblade Treasury");
   set("long",
"This is the Nightblade Treasury.  Any nightblade may store items here, "
"but they are open to use by any other nightblade.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");
}

