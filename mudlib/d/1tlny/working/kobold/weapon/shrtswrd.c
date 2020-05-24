/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("kobold shortsword");
   set("id", ({"sword", "shortsword", "kobold shortsword"}) );
   set("short", "kobold shortsword");
   set("long",
   "This kobold shortsword looks as though it was hastily crafted by "
   "a poorly-skilled blacksmith.  Its blade is fairly sharp, though."
   );
   set_weight(300);
   set_value(75);
   set_type("blade");
   set_wc(12, "cutting");
   set_wc(12, "impaling");
   set_ac(3);
   set_quality(3);
}
