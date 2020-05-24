inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   add_exit("/d/damned/guilds/chaotic-lord/chaotic-lord_train_room", "east");
   set("short","The Chaotic Lord Treasury");
   set("long",
"This is the Chaotic Lord Treasury.  Any Chaotic Lord may store items here, "
"but they are open to use by any other Chaotic Lord.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
if (!present("locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	}
}
