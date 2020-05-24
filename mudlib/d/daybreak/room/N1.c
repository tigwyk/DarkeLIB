#include <config.h>
#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"db_square", "out");
    add_exit("/d/damned/virtual/room_9_7.world", "goblin");
    add_exit("/d/damned/virtual/room_8_12.world", "kuril"); 
    add_exit("/d/damned/virtual/room_5_9.world", "akkad");
    add_exit("/d/damned/virtual/room_11_9.world", "vo");
    add_exit("/d/damned/virtual/room_25_15.world", "canyon");
    add_exit("/d/damned/virtual/room_5_13.world", "kobold");
    add_exit("/d/damned/virtual/room_13_16.world", "fir");
    add_exit("/d/damned/virtual/room_25_23.world", "catacombs");
    add_exit("/d/damned/virtual/room_71_13.world", "mansion");
    add_exit("/d/damned/virtual/room_70_13.world", "dwarf");
    add_exit("/d/damned/virtual/room_8_22.world", "cave");
    add_exit("/d/damned/virtual/room_50_25.world", "bir");
    add_exit("/d/damned/virtual/room_6_35.world", "forest");
    add_exit("/d/damned/virtual/room_70_70.world", "ancient");
    add_exit("/d/damned/virtual/room_10_10.world", "nomad");


  
 
    set("short","Portal");
    set("long", "Portal before you go to Town Square.");
}

void reset(){
  ::reset();
    if(!present("fountain")){
    new(OBJ+"fountain.c")->move(this_object());
    }
}
