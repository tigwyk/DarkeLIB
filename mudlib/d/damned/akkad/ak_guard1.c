inherit "std/room";

void reset() {
::reset();
if(!present("sentinal")){
new("/d/damned/akkad/obj/mon/sentinal")->move(this_object());
}
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_sgate", "east");
    set("short","   \n    \n   @--0\n    \n   \nCity Guard training grounds");
    set("long","The city guards train here.  The city guards watch the " +
	"entrance to Akkad and prevent monsters from entering the city. \n   \n    \n   @--0\n    \n   \n");
    
}
