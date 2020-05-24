//      From Maxwell's Underground mudlib
//      16th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

object *rooms;
int x,y,z;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in the river  on the edge of a huge "
        "waterfall.");
    set("long",@ext 
You are floating in the river next the edge of a huge waterfall. 
Thousands of gallons of water are flowing by you, trying to push you off 
over the falls.
You can't see what is at the base of the waterfall, but there is a small 
path that leads down along the side.   
        upstream   
    @    path
        downstream          
ext);
    set_exits( ({ UNDER+"dm16",UNDER+"dm45",UNDER+"dm47" }),
      ({ "upstream","path","downstream" })
       );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "rocks" : "The large rocks stick out only a few inches above"
"the surface, but could easily break the raft to pieces.",
      ]) );
    set_smell("default", "The murky water fills the air with the "
"smell of wet mold.");
    set_listen("default", "The roaring sound of the waterfall fills your "
"ears.");
    set_pre_exit_functions( ({"downstream","path" }), ({"waterfall",
     "mob_check"}) );
    x = 0;
    z = 0;
    rooms = ({UNDER+"dm49",UNDER+"dm51",UNDER+"dm45",UNDER+"dm48"});
}
int waterfall(){
int lmd,lcd;
string limb;
    y = sizeof(rooms);
    if(this_player()->query_flying()){
       write("The water pushes you over the edge of the falls!\nYou slowly "
       "float down and land gently in the river below.\n");
       say(this_player()->query_cap_name()+" is swept over the edge of the "
       "waterfall!");   
       tell_room(UNDER+"dm47",this_player()->query_cap_name()+" slowly "
       "floats down from the top of the waterfall and lands into the pool "
       "with a quiet splash.");
      while(z < y){
      tell_room(rooms[z],this_player()->query_cap_name()+" is swept off "
     "the top of the waterfall and slowly floats down into the river far "
     "below!");
       z = z + 1;
      }
      z = 0;
    return 1;      
 
    }
    write("The water pushes you over the edge of the falls!!\nThe water "
    "pounds into you as you fall down!\ndown..\ndown..\ndown..\ndown.."
    "\ndown...\nSPLASH!!!\n");
    say(this_player()->query_cap_name()+" is swept over the edge of the "
    "waterfall!");
    tell_room(UNDER+"dm47",this_player()->query_cap_name()+" falls toward "
    "you from the top of the waterfall, smashing into the river with a "
    "loud splash a few moments later!");
      while(x < y){
      tell_room(rooms[x],this_player()->query_cap_name()+" is swept off "
     "the top of the waterfall and falls down into the river far below!!");
       x = x + 1;
      }
      x = 0;
    limb = this_player()->return_target_limb();
    lmd =  this_player()->query_max_dam(limb);
    lcd =  this_player()->query_dm(limb);
    this_player()->do_damage(limb,((lmd-lcd)/8));
    write("As you rise back to the surface you realize that you hurt "
    "your "+limb+" in the fall.\n");
    return 1;
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You climb out of the water.");
       return 1;       
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks out over the path.");
    return 0;
}
       

