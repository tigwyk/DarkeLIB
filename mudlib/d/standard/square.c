#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("pray", "pray");
}

void create() {
    ::create();
    set("short", "Akkad Church");
    set("long",
      "This is the ornate church of Akkad.  Here you may pray for "
      "resurrection.  Clerics and other clergy mill about the room.  "
      "The post office lies beneath a trap door in the church.  "+
      "To the north is Blessing Way.\nThere are a northern and a southern "
      "world map and a city map tacked to the wall.");
    set_exits( 
      ([ "south" : "/d/daybreak/room/dbbw1",
      "down" : "/d/standard/post",
      "west":"/d/standard/hospital" ]));
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);
    set_items( ([ "northern world map" : (: call_other, this_object(),
"read_world_map" :),
       "southern world map" : (: call_other, this_object(), "read_world\
_map2" :),
      "city map" : (: call_other, this_object(), "read_city_map" :),
      "map" : "There is a 'city map', a 'northern world map', "
              "and a 'southern world map'.",
      "maps" : "There is a 'city map', a 'northern world map'."
              "and a 'southern world map'.",
       ]) );
}

int pray() {
    if(!this_player()->query_ghost()) {
	notify_fail("You are already alive.\n");
	return 0;
    }
    this_player()->revive();
    this_player()->set_hp(10);
    this_player()->set_heart_beat(1);
    return 1;
}


int read_city_map() {
    this_player()->more("/wizards/mikus/city_map");
    return 1;
}

int read_world_map() {
    this_player()->more("/wizards/mikus/world_map");
    return 1;
}

int read_world_map2() {
    this_player()->more("/wizards/mikus/world_map2");
    return 1;
}
