inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/arch-mage/train_room", "east");
   set("short","The Arch Mage Treasury");
   set("long",
"This is the Arch Mage Treasury.  Any arch-mage may store items here, "
"but they are open to use by any other arch-mage.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");
}

