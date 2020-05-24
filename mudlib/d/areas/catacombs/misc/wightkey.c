/* Wightkey coded by Duridian by DarkeMud.  Opens the chest located
   in ~duridian/catacombs/catac147.    */
 
#include "std.h"
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("fanged skull key");
   set("id", ({"fanged skull key", "key"}) );
   set("short", "fanged skull key");
   set("long",
   "This key, mysteriously enough, is made entirely of bone.  In the handle "
   "of the key is carved a skull with two long fangs protruding from its "
   "mouth.");
   set_weight(10);
   set("value", 5);
}
 
