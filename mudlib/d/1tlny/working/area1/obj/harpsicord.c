// harpsicord

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a harpsicord");
    set_id( ({ "harpsicord" }) );
    set_short("a fine harpsicord");
    set_long("You see a beautiful harpsicord setting against the "+
    "east wall.  It looks as though someone has played it recently.");
    set_weight(9999);
    set_value(0);
}
