inherit "/std/vault_locker_room.c";

void create()
{
    ::create();
    set_property("light", 5);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("indoors",1);
    set_property("indoors", 0);
     set("short", "The workroom of a new immortal");
    set("long", "This inherits from /std/vault_locker_room.c");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");
    set_exits( ({ "/wizards/honspron/workroom.c"}), ({"north"}) );

	   if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
	 if (!present("storage locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	 }
}

/*void reset()
{
    ::reset();
}*/