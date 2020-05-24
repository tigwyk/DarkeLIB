inherit "std/room";
#define BASE "/wizards/avatar/tyranid/rooms/"
void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Lungs");
    set("long",
      "You have reached what must be the lungs of the hive.  The 'tunnels' here\n"
      +"are much less distinct...they are more accurately described as areas\n"
      +"where the huge pillow-like masses of wet spongy material is thinner than\n"
      +"usual.  The only good thing about the howling winds which blow through\n"
      +"this area is that they give you a breath of fresh, breathable air now\n"
      +"and again.  A pail yellow luminesence seems to shine down from somewhere\n"
      +"above you.\n"
#ifdef NORTH
    "\n   N\n   |\n"
#endif
#ifdef WEST
    "W-"
#endif
#ifdef EAST
    "   -E "
#endif
#ifdef SOUTH
    "\n   | \n   S"
#endif
#ifdef UP
    "      up"
#endif
#ifdef DOWN
    "      down"
#endif
);
    set_exits( ([
#ifdef NORTH
	"north": BASE + NORTH,
#endif
#ifdef SOUTH
	"south": BASE + SOUTH,
#endif
#ifdef EAST
	"east": BASE + EAST,
#endif
#ifdef WEST
	"west": BASE + WEST,
#endif
#ifdef UP
	"up": BASE + UP,
#endif
#ifdef DOWN
	"down": BASE + DOWN,
#endif
      ]) );
}

void reset() {
    ::reset();
    if(!present("tyranid"))
    {
	new("/wizards/avatar/tyranid/mon/zoanthrope1")->move(this_object());
    }
}
