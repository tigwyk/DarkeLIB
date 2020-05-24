inherit "std/room";
#define BASE "/wizards/avatar/tyranid/rooms/"
void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Stomach");
    set("long",
      "You have definitely climbed a long way into the hive.  After passing\n"
      +"through the intestines, you appear to have arrived in the stomach.  The\n"
      +"general tunnel-like appearance of the place is the same, but the walls\n"
      +"and floor are much softer...rather like walking on huge soggy sponges,\n"
      +"dripping with corrosive acid.  A gentle wind blows through the whole\n"
      +"area, carrying with it clouds of stinging acid mist.  A pulsing orange\n"
      +"light fills this area.\n"
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

    set_items( ([
	"walls" : 
	"The stomach lining is oddly smooth and glistens slightly in the\n"
	+"light.  It appears to be covered with a slimy mucus, though you\n"
	+"find the idea of investigating more closely daunting.\n"] ) );
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
