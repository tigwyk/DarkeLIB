//      From Maxwell's Underground mudlib
//        15th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large room boarding a river.");
    set("long",@ext 
You have entered a large room bordering an underground river. 
The water isn't moving very fast, but you can hear a tremendous 
roar coming from further downstream. There must be a large 
waterfall there. The sounds of the falling water echo through 
the chamber and hurt your ears. By the edge of the river is a dock 
of some sort. The heavy wooden platform reachs out into the river, 
connecting to two large wooden pillars submerged in the deep water.      
   
 0--@
       river
ext);
    set_exits( ({ UNDER+"dm14", UNDER+"dm16" }),
      ({ "west", "river" }) );
    set_items( ([
       "dock" : "The sturdy dock reachs out into the water.",
       "platform" : "The platform is made of oak timbers and steel bolts.",
       "pillars" : "The thick pillars support the underside of the dock.",
      ]) );       
    set_smell("default", "You can smell the mouldy water.");
    set_listen("default","You hear the pounding sound of falling water.");
    set_pre_exit_functions(({"river"}), ({"skill_mob_check"}) );
}
int skill_mob_check(){
int level;
    if(this_player()->is_player() || this_player()->is_pet()){
       level = this_player()->query_skill("swimming");
       if(level < 70) {
         write("The current is way too fast for your swimming ability.");
         return 0;
       }
       else {
         write("You jump into the cold water.\n");
         return 1;
       }
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks out over the river.");
    return 0;
}
