//  Wizard:  Khojem
//  Melon
//  melon.c
 
#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("melon");
    set_id( ({ "melon" }) );
    set_short("a gorgonizing melon");
    set_long("A huge, juicy, firm melon.");
    set_weight(30);
    set_strength(40);
    set_float_value(8.0);
    return;
}
