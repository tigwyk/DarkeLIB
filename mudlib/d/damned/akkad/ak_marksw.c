inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_shop3", "west");
    add_exit("/d/damned/akkad/ak_victory4", "east");
    add_exit("/d/damned/akkad/ak_haven4", "north"); 
    add_exit("/d/damned/akkad/ak_shop4", "south");
set_property("no attack", 1);
set_property("no spell", 1);
    set("short","   0\n   | \n0--@--0\n   | \n   0\nSouthwest corner of Market Square");
    set("long",@ext You are standing on the southwest corner of Market Square.
	There are shops to the south and west of you.  The noisy salesmen
	are promising you special deals.  Yeah, I got your special deals 
	RIGHT HERE! 
    0   
    |   
 Q--@--0
    |
    S
	There are two signs here. 
ext);
    add_item("sign 2", "This sign points west.\n\n"
"******************\n"
"  The Quest Shop\n"
"******************\n");
  add_item("sign 1", "This sign points south.\n\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"  The Adventurer's General Store\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}
void reset() {
   ::reset();
    if(!present("Town Crier"))
      new("/d/damned/akkad/obj/mon/town_crier.c")->move(this_object());
}
