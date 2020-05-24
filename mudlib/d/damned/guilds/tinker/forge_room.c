inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);

//_-=added below to fix the exits commented out old exits=-_ (TINY)
  set_exits( ([ "north" : "/d/damned/guilds/tinker/ti_treas",
	     "east" : "/d/damned/guilds/tinker/train_room" ]));

   //add_exit("/d/damned/guilds/tinker/ti_treas", "north");
   //add_exit("/d/damned/guilds/tinker/train_room", "east");
   set("short","The Forge Room");
   set("long",
"This room is very hot with the fires of several forges. "+
  "You see some tinkers hammering away, making wondrous items. The Tinker Treasury is to the north.");
}
void reset() {
object forge;
::reset();
//_-=Fixed forge it was Broken room works NOW! TINY=-_
if(!present("forge")) {
forge = new("/d/excelsior/tinker/greater_forge");
        forge->set_weight(100000000);
        forge->move(this_object());
}

if(!present("guard")) {
    new("/d/damned/guilds/tinker/t_guard")->move(this_object());
}
if(!present("can")) {
    new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
}

}
