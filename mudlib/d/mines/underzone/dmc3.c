//      From Maxwell's Underground mudlib
//        3rd Room of Dwarf Crypt

#include <std.h>
#include "under.h"
inherit ROOM;

object player,*inv;
int y,z,t,n,factor;
string w,here;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small crypt.");
    set("long",@ext  
You are standing in a small crypt. The low ceiling is covered in dirty 
cobwebs. To the northeast, across a deep looking pool of green ooze, 
is a doorway.
   
        arch   
    @
        pool            
ext);
    set_exits( ({ UNDER+"dmc2",UNDER+"dmc4" }),
      ({ "arch","pool"})
    );
    set_items( ([
    "doorway" : "The short hallway leads to a sturdy looking door.", ]) );
       
//    set_smell("default", "It smells like a new immortal in here.");
//    set_listen("default", "You hear the sounds of code creation.");
   set_pre_exit_functions( ({"pool" }), ({"check_flying"}) );
   inv = ({});

}
void init() {
    ::init();
    add_action("check_objects","look");
    add_action("do_search","search");
}
int check_objects(string str){
     if(str == "ooze" || str == "pool" || str == "deep pool"){
      write("The deep pool of ooze is bubbling slightly. Some sort of "
"smelly gas is being released when the bubbles pop on the surface. The "
"deep pool blocks access to the doorway.");
      return 1;
     }
}
int check_flying(){
    here = file_name(environment(this_player()));
    if(this_player()->query_flying() == 0){
      write("You wade into the pool, sudddenly you are yanked violently "
     "under the surface!");
      say(this_player()->query_cap_name()+" wades into the pool of ooze "
"and is suddenly yanked under the surface!\nAll that remains behind is "
"a small ripple in the ooze where "+this_player()->query_cap_name()+" had "
"been standing only a moment before.");
      inv = all_inventory(this_player());
      y = sizeof(inv);
      z = 0;
      n = 1;
      while(z <=(y-1)){
        w = inv[z]->query_name();
      if(w == "torch"){
         t = inv[z]->query_lit();
         if(t == 1) write("Your torch "+n+" is snuffed out as it sinks "
         "with you.");
         inv[z]->silent_extinguish();
         inv[z]->extinguish("torch");
         n = n+1;
        }
        z = z + 1;
      }
      this_player()->move(UNDER+"dmc1");
      player = this_player();
      call_out("drown",3,this_player());
      return 0;
    }
    write("You float across the pool, landing safely on the other side.");
return 1;
}
int drown(){
    if(player->query_skill("swimming") <= 40 ){
       tell_object(player,"You try to swim to the surface, but you are "
"not skilled enough. You sink lower and lower into the pool.\nYou can "
"feel something pulling at you, a strong current pulls you faster down "
"into the bottom of the pool.\n");
     }
    if(player->query_skill("swimming") > 40 ){
      tell_object(player,"You fight the current that is pullin you down "
"deeper into the pool. You swim with all your might and skill.");
      factor = random(3);
      if(factor == 0 || factor == 1){
        tell_object(player,"You swim up and break the surface of the "
        "pool!\nYou quickly climb out and enter the next room");
     tell_room(here,player->query_cap_name()+" rises out from under the "
     "surface of the ooze, climbs out and enters the room "
     "across the pool.");
      player->move(UNDER+"dmc4");
      tell_room(environment(player),player->query_cap_name()+" rises out "
"from under the surface of the ooze and climbs out.",player);
        return 1;
      }
    }
     tell_object(player,"You are sucked into some sort of pipe and "
"then violently thrown out into empty space!!\nYou dive through "
"a huge wall of tumbling water and splash into the water at the base "
"of an immense waterfall.");
     player->move(UNDER+"dm47");
     tell_room(UNDER+"dm47",player->query_cap_name()+" dives out of the "
 "center of the waterfall and falls into the river with a loud "
 "splash!!",player);
}
