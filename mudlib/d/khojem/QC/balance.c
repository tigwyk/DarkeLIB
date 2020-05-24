// Wizard:  Khojem/Duridian
// DarkeMud Balance Board Room

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Mud Balance Room");
    set("long","Wizards communicate DarkeMud balance problems here.");
    ob = new("/std/bboard");
    add_exit("/d/standard/adv_main", "hall");
    ob->set_name("board");
    ob->set_id( ({ "board", "balance board" }) );
    ob->set_board_id("balance");
    ob->set_max_posts(30);
    ob->set_location("/d/khojem/QC/balance");
    ob->set("short", "the DarkeMud Balance Board");
    ob->set("long", "Used to communicate DarkeMud balance issues.\n");
}
