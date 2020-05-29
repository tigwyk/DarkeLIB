// /wizards/excelsior/rooms/emporium/board

#include <config.h>

inherit "/std/room";

void create() {
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The New Faerie Dust board room");
    set("long",
        "This is where explorers of New Faerie Dust can post their problems, "+
        	"comments, suggestions, or even (gasp) complaints. You then see "+
        	"a small wastebasket here, which may be an even better place to post "+
        	"those complaints.");
	set_items(([({"trash can","waste basket","basket"}):"You just can't seem to "+
		"figure out how to post something on it!"
		]));
    add_exit("/wizards/excelsior/rooms/emporium/foyer", "south");

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "comment board" }) );
    ob->set_board_id("comments");
    ob->set_max_posts(30);
    ob->set_location("/wizards/excelsior/rooms/emporium/board");
    ob->set("short", "Comments Board");
    ob->set("long", "Posts any problems, comments, suggestions or complaints here.\n");
    set_property("no steal", 1);
}
