/* Tattered piece of paper coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit "/std/Object";
 
object who;
 
void init() {
   ::init();
   add_action("read", "read");
   add_action("drop", "drop");
}
   
void create() {
   ::create();
   set("id", ({"paper", "tattered paper", "tattered piece of paper", "tattered paper"}) );
   set_name("tattered piece of paper");
   set("short", "a tattered piece of paper");
   set("long", "There is some faded writing on this tattered piece of paper.");
   set_weight(10);
   set("value", 0);
}
 
int read(string str) {
   if(!str) {
      return 0;
   }   
   if((str != "paper") && (str != "piece of paper") && (str != "tattered piece of paper")) {
      notify_fail("Read what?\n");
      return 0;
   }
   write("\nDay 22\n\n"
         "     I have yet been unable to find my way through these acursed\n"
         "passageways to the next level of the catacombs.  This maze has\n"
         "brought me nothing but headaches and despair.  The hairy zombies\n"
         "are a minor annoyance, while the metal-coated skeletons present\n"
         "a greater challenge.  I was badly wounded when I tried to destroy\n"
         "a bronze skeleton to the northeast, and the vile creature was\n"
         "hardly scathed.  I have heard horrible screams coming from that\n"
         "direction, although I am still skeptical that a lich really lives\n"
         "in these catacombs.\n\n"
         "     Rufus Tenderfoot\n\n"
         );
   return 1;
}
 
int drop(string str) {
   if(!str)
      return 0;
   if((str != "paper") && (str != "piece of paper") && (str != "tattered piece of paper"))
      return 0;
   write("The tattered piece of paper crumbles to dust when it hits the ground.");
   say(this_player()->query_cap_name()+" drops a piece of paper and it crumbles into dust.");
   this_object()->remove();
   return 1;
}
