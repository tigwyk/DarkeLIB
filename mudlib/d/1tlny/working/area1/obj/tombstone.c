// tombstone

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a tombstone");
    set_id( ({ "tombstone" }) );
    set_short("a large tombstone");
    set_long("You see a tombstone carved out of granite.  There seems "+
    "to be some writing on it that has recently been chipped away.");
    set_weight(9999);
    set_value(0);
}
