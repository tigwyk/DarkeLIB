inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/elemental-mage/skill_room", "east");
   set("short","The Elemental-mage Treasury");
   set("long",
"This storage room is cluttered with many items. In the past the master "
"elemental-mage would leave items for their younger guild brothers and "
"sisters to use. You can do the same and leave useful items in the "
"lockers and chests that lie about. All around you see magical items, "
"and weapons that aid the elemental-mage. You can borrow them, but please "
"put them back.\n\nMAKE SURE you close a chest after using it!\n");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
if (!present("locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	}
}

