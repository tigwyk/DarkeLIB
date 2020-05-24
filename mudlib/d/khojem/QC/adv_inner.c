#include <config.h>

inherit "/std/room";

void create() {
    object ob;
    
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Hall of the Immortals");
    set("long",
        "This is the main wizard meeting room in DarkeMUD.  Here general "
        "plans for the mud are discussed.  Also, from here, all other "
        "wiz board rooms may ba accessed.  Projects details projects that "
        "need to be carried out here.  LPC is a board for code discussion "
        "Domains is for discussing domain themes with one another. "
        "Damned is a special board dedicated to the Lost and the Damned "
        "domain.");
    set_exits( 
    add_exit("/d/standard/boards/projects", "projects");
    add_exit("/d/standard/boards/LPC","LPC");
    add_exit("/d/standard/boards/damned","damned");
    add_exit("/d/standard/adv_main", "darke");
    add_exit("/d/standard/square", "square");
    add_exit("/d/khojem/QC/QC","qc");

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "reality board" }) );
    ob->set_board_id("immortal");
    ob->set_max_posts(30);
    ob->set_location("d/standard/adv_inner");
    ob->set("short", "Immortal's Reality Board");
    ob->set("long", "Posts any notes concerning the mud which do "
            "not belong out in a public forum among players "
            "here for immortal discussion.\n");
    set_property("no steal", 1);
}

int receive_objects() {

  if(!previous_object()->is_player())
    return 1;
  if(!wizardp(previous_object())) {
    message("my_action", "You cannot penetrate the force of "
            "the blue force shield.", this_player());
    return 0;
  }
  return 1;
}
