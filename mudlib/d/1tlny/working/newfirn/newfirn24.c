//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn24.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "New Firn'Ville Room 24");
    set("long", "New Firn'Ville Room 24" );
    add_exit("newfirn23.c", "north");
    add_exit("newfirn25.c", "south");
    add_exit("cleric_shop.c", "east");
    set_items(([
     ({ "dirt" }) :
        "This is dirt.",
     ({ "tower" }) :
        "This is a tower." ]));
    set_smell("default", "The air smells like shit.");
    set_listen("default", "You hear someone taking a dump.");
}
