//  Wizard:  Khojem
//  Pigsfeet
//  pigsfeet.c
 
#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("pigsfeet");
    set_id( ({ "pigsfeet", "pig's", "saucy", "pigs", "feet", "foot", "pig" }) );
    set_short("saucy pig's feet");
    set_long("A large, pig's foot covered in a tangy, red sauce.\n"+
      "The hoof(?) is still attached... yuck!");
    set_weight(15);
    set_strength(45);
    set_float_value(9.0);
    return;
}
