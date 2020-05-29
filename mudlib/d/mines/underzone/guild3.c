//Maxwell's Underground mudlib
//Guild Zone

#include <std.h>
#include "under.h"
inherit ROOM;

mixed *inv;
void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a smooth tunnel.\n");
  set("long", "You have entered a circular chamber. Painted on the "
      "walls and ceiling are huge murals of gory battle fields "
      "and fallen warriors. Large columns stretch up and lock "
      "against huge metal bands that line the ceiling between "
      "the murals.\nAttached to the walls are several steel "
      "rings. Below one of the rings is a large steel plate.");
  set_exits( ({ GUILDR+"guild2"}),
            ({ "northwest"}) );
  inv = ({});
  set_items( ([
    "ring" : "The ring is smooth to the touch.",
    "rings" : "The thick rings are worn down and very smooth.",
    "murals" : "The paintings are very large and very gory.",
    "plate" : "It is an oddly shaped steel plate attached to the floor.",
  ]) );
  set_search("plate", "The plate is looks like it was designed to be "
             "lifted on its hinges.");
  set_search("ring", "The smooth ring looks like it has been turned often.");
}
init(){
   ::init();
   add_action("turn_ring","turn");
   add_action("check_room","lift");
}
int check_room(string str){
int y;
    if(!str){
      write("Lift what?");
      return 1;
    }
    if(str == "plate"){
      write("You lift the plate and glance down into the dungeon below.");
      inv = filter_array(all_inventory(find_object_or_load(GUILDR+"guild4")),
            "is_living",this_object());
      if(sizeof(inv) == 0)
        write("The dungeon is empty.");
      else {
        write("The dungeon is occupied by "+sizeof(inv)+" living beings.");
         y = 0;
         while(y < sizeof(inv)){
             write(inv[y]->query_cap_name());
             y = y + 1;
         }
      }
      return 1;
    }
}
int is_living(object str){
       return living(str);
}

mixed query_occupants(){
    return inv;
}
int turn_ring(string str){
string limb;
int lmd,lcd,dam;
    if(str == "ring"){
      if(this_player()->query_class() == "necromancer"){
        write("You grasp the ring and turn it! It makes a solid "
              "click and the wall in front of you slides open! You "
              "quickly step into the opening and the wall slides "
              "shut behind you."); 
        say(this_player()->query_cap_name()+" grasps one of the steel "
         "rings on the wall and steps into a secret opening!");
        this_player()->move("/d/damned/guilds/necromancer/n_treas");
        return 1;
       }
       write("You feel the floor vibrate slightly and suddenly your "
             "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
             "up you see the opening you fell through slide shut!");
       limb = (this_player()->return_target_limb());
       lmd =  (this_player()->query_max_dam(limb));
       lcd =  (this_player()->query_dm(limb));   
       dam = (random(4)+3);       
       this_player()->do_damage(limb,((lmd-lcd)/dam) );
       write("You smashed your "+limb+" during the fall. Ouch!");
       say(this_player()->query_cap_name()+" grasps one of the steel "
         "rings on the wall. Suddenly a gaping hole opens underneath "
         +this_player()->query_possessive()+" feet!\n"
         +this_player()->query_cap_name()+" drops out of sight and "
         +this_player()->query_possessive()+" scream is silenced as the "
         "floor slides back into place!");
        this_player()->move(GUILDR+"guild4");
        tell_room(GUILDR+"guild4","You hear a scream above you!\n"
         +this_player()->query_cap_name()+" falls through the opening in "
         "the ceiling and slams into the hard stone floor in a cloud "
         "of straw and dust!",this_player());
        return 1;
   }
}
