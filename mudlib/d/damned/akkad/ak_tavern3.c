inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_tavern2", "north");
    add_exit("/d/damned/akkad/mine_shop1", "east");
    add_exit("/d/damned/guilds/join_rooms/child_join", "west");
    add_exit("/d/damned/akkad/ak_haven1", "south");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nOn Tavern Street north of Haven");
    set("long",@ext You are on Tavern Street, the drinking and sleeping quarter
of the city.  Immediately south of you is an intersection with Haven
Street. Further south, this street continues on as Research Parkway
where mages reside.
To the east is the Mine Builders Shop.
    0   
    |   
 0--@--S
    |
    0
ext);
    
}

