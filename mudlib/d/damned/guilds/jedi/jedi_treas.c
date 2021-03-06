inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/jedi/train_room", "west");
   set("short","Treasury of the Jedi");
   set("long",
	"Unlike the rest of the dungeon, this room appears to "+
		"have been dug. "+
"This is the Jedi Treasury.  Any jedi may store items here, "
"but they are open to use by any other jedi.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
if (!present("locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	}
}
