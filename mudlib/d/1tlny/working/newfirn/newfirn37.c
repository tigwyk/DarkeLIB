//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn37.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
      set("short", "New Firn'Ville Room 37");
      set("long", "New Firn'Ville Room 37" );
    add_exit("newfirn38.c", "north");
    add_exit("newfirn43.c", "south");
    add_exit("chest_lock_shop.c", "west");
	 add_exit("thief_shop.c", "east");
    add_invis_exit("east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
