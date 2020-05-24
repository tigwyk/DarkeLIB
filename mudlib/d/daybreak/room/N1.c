#include <config.h>
#include "../daybreak.h"
inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"db_square", "out");

//level 0
    add_exit("/d/damned/virtual/room_10_10.world", "newbie");
//Cities and level 5-15+ areas
    add_exit("/d/damned/virtual/room_8_12.world", "kuril"); 
    add_exit("/d/damned/virtual/room_4_9.world", "akkad");
    add_exit("/d/damned/virtual/room_13_9.world", "vo");
//Low level areas 1-10
    add_exit("/d/damned/virtual/room_9_7.world", "goblin");
    add_exit("/d/damned/virtual/room_4_13.world", "kobold");
    add_exit("/d/damned/virtual/room_6_7.world", "fir");
    add_exit("/d/damned/virtual/room_5_12.world", "bandits");
    add_exit("/d/damned/virtual/room_13_14.world", "caravan");
    add_exit("/d/damned/virtual/room_5_3.world", "ancient");
    add_exit("/d/damned/virtual/room_50_25.world", "bir");
//Level 15-25+ areas
    add_exit("/d/damned/virtual/room_12_4.world", "tyranid");
    add_exit("/d/damned/virtual/room_25_15.world", "canyon");
//level 20+
    add_exit("/d/damned/virtual/room_16_26.world", "dwarf");
    add_exit("/d/damned/virtual/room_8_22.world", "quarry");
//level 30+
    add_exit("/d/damned/virtual/room_43_10.world", "chaos");
//Level 40+ Needs to scale down majorly
    add_exit("/d/damned/virtual/room_24_6.world", "keep");
//Not yet sorted
    add_exit("/d/damned/virtual/room_4_23.world", "catacombs");
    add_exit("/d/damned/virtual/room_4_5.world", "mansion");
    add_exit("/d/damned/virtual/room_6_35.world", "forest");
    add_exit("/d/damned/virtual/room_13_6.world", "faeriedust");




 
    set("short","Portal");
   set( "long", @EndText 
    Portal before you go to DBR Town Square.
Level 0               [newbie]
Level 1-10+ areas     [goblin, kobold, fir, bandits, bir, caravan, ancient]
level 10-20+          [catacombs, mansion, faeriedust]
level 5-15+ cities    [kuril, vo, akkad]
Level 15-25+ areas    [tyranid, canyon]
level 25-30+ areas    [quarry, dwarf]
level 30-38+ areas    [chaos]  
level 40-60++         [keep]

* Other areas pending fixing/sorting [forest]
EndText
);

}

