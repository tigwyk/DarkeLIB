inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_haven6", "west");
    add_exit("/d/damned/akkad/ak_egate", "east");
    set("short","   \n    \n0--@--0\n    \n   \n Haven Street west of Iron Trail");

    set("long", "You are on Haven Street west of Iron Trail, where" +
        " the fighting guilds reside.\n   \n    \n0--@--0\n    \n   \n ");
}
