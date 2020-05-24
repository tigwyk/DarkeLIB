inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_res2", "south");
    add_exit("/d/damned/akkad/ak_haven1", "north");
    //add_exit("/d/damned/guilds/join_rooms/elementalist_join", "west");
    set("short","   0\n   | \n   @   \n   | \n   0\nResearch Parkway south of Haven Street");
    set("long",@ext This is the scholarly side of town with the various mage 
	guilds located here.  The city library is also on this street. 
	West is the Elementalists Guild and east are the Moon-Mages. 
	Further south are the Arch-Mages and Enchanters.
    0   
    |   
    @
    |
    0
ext);
    
}
int guild_check(){
    write("The Moon-Mages Guild is currently not created. Watch the "
    "news for updates");
    return 0;
}
