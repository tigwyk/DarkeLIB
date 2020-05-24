//      Khojem's workroom

#include <std.h>

inherit ROOM;

void init()
{
   ::init();
   add_action("sit_me","sit");
   add_action("sit_me","rest");
   add_action("stand_me","stand");
}

void create() {
    object ob;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("creator", "Khojem");
    set("short", "Khojem's Workroom");
    set("long", 
      "It is a large room with a warm, comfortable fire burning in a "+
      "stone fireplace along the north wall.  A large wooden "+
      "conference table surrounded by comfortable leather chairs "+
      "dominates the room's center.  A desk rests along the room's "+
      "south wall.  On it lies a Mac 7100/80, monitor, and many notes."+
      "  A large, red Coleman cooler rests in the corner.  Against the"+
      " east wall stands a Grizzly bear on its hindlegs."
    );
    add_exit("/d/standard/square","square");
    add_exit("/d/standard/adv_main","hall");
    add_exit("/d/khojem/port/room/s09","port");
    add_exit("/d/khojem/new/room/entry","new");
    add_exit("/d/damned/akkad/ak_center","fountain");
    add_exit("/d/khojem/nomad/room/entry","nomad");
    set_items(([
      ({"notes","desk"}) :
        "The desk is littered with hurriedly scribbled notes about\n"
        "DarkeMUD and the LPCMud language.  The computer and monitor\n"
        "are on and the Mac's fan is humming away.\n",
      ({"computer","macintosh","mac","7100/80","monitor"}) :
        "The computer is on and its fan is humming away.\n",
      ({"table","conference"}) :
        "The conference table is made from a single piece of English Oak "+
        "and polished to a high gloss luster.\n",
      ({"chairs","chair"}) :
        "There appears to be quite a few available chairs. \n"
        "They appear to be very plush and comfortable.\n",
      ({"cooler","coleman","corner"}) :
        "This cooler is filled with iced down beer bottles.\n",
      ({"fire","fireplace"}) :
        "It is a large fire fueled by hardwood logs.\n"
        "The fire makes the room feel warm and comfortable.\n",
      ({"fountain","bear","grizzly","pool","liquid"}) : 
        "The bear looks menacing at least 10 feet high.\n"
        "You are glad that it is just a stuffed animal\n"
        "and not the real thing."
      ]));
    set_smell("default", "The room smells of burning hardwood and "+
      "stale smoke."
    );
    set_listen("default", "You hear the tranquil sound of water flowing and "+
      "a song from the Rolling Stones Stripped album playing in the background."
    );
}


int sit_me() {
 write("You grab one of the plush leather chairs and rest your weary feet.\n");
 return 1;
}

int stand_me() {
 write("You stand from the chair and clamor to your feet.\n");
 return 1;
}

