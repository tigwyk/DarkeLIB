inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/paladin/train_room", "east");
   add_exit("/d/damned/guilds/paladin/proom/special_room", "west");
   set("short","The Paladin Treasury");
   set("long",
"This is the Paladin Treasury.  Any paladin may store items here, "
"but they are open to use by any other paladin.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
if (!present("locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	}
}
