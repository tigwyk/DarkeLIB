inherit "std/room";

void create() {
  object ob;
  ::create();
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "ts_board"}) );
  ob->set_board_id("ts_board");
  ob->set_max_posts(25);
  ob->set_location("/d/damned/akkad/ak_center");
  ob->set("short","Chat Board");
  ob->set("long","A board for players to post notes.\n");
    set_property("light",3);
    set_property("night light", 2);
// set_property("no scry", 1);
    add_exit("/d/damned/akkad/ak_haven5", "east");
    add_exit("/d/damned/akkad/ak_haven4", "west");
    add_exit("/d/damned/akkad/ak_victory4", "south");
    add_exit("/d/damned/akkad/ak_victory5", "north");
    add_exit("/d/damned/akkad/ak_tower", "tower");
//Basic mapping added by Tiny 1/20/2020
    set("short","   0\n   t \n0--@--0\n   | \n   0\nTranquility Square");
    set("long",@ext This is Tranquility Square, the center of Akkad.  It is a place 
commemorating the end of the Great War between the Ancient  
Races.  Justice Tower is here. There is a statue of Dranaxar, 
protector of this city and the first archmage, here.  You sense that this  is a great place of Peace. You notice a glowing %^YELLOW%^plaque%^RESET%^ at the base of the statue.
    0   
    |   
 0--@--0
    |    tower
    0
ext);
   add_item("tower","The Tower of Justice reaches into the sky here.  It "+
       "is constructed from white marble and polished so that climbing it "+
       "would seem nearly impossible.  It is rumored that the Council of "+
       "Guildmasters meet at its top to set law and mete out punishment.\n");
    add_item("statue","The statue of Dranaxar shows the elven mage in " +
	      "a pose of contemplation, one hand on his chin and the other "+
	      "gesturing as if to some unknown audience.\n");
    add_item("plaque",
"people who have donated!%^RESET%^\n\n"
    "See 'Help Donate' for info!");
}




void reset(){
  ::reset();
  if(!present("sentinal")){
new("/d/damned/akkad/obj/mon/sentinal")->move(this_object());
new("/d/damned/akkad/obj/mon/sentinal")->move(this_object());
}
  if(!present("fountain")){
     new("/d/damned/akkad/obj/misc/fountain")->move(this_object());
}  
}

