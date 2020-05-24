//Maxwell's Underground mudlib
//Thief Guild

#include <std.h>
#include <under.h>
inherit ROOM;

mixed *inv;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a small stone passage.\n");
  set("long", "You are standing in a small stone passage. The cracked "
      "stone walls stretch before you in both directions, broken "
      "only by the evenly spaced torches.\n"
      "There is a small plate on the floor here. Bolted into the stones "
      "above it are two iron rings");
  set_exits( ({ "/d/damned/guilds/join_rooms/thief_join" }),
             ({ "west" }) );
  set_items( ([
    "walls"   : "The cold stone walls are covered with cracks.",
    "passage" : "The passage leads off into the darkness to the north.",
    "torches" : "The small oil torches are bolted to the walls.",
    "ring"    : "The ring is smooth to the touch.",
    "rings"   : "The thick rings are worn down and very smooth.",
    "plate"   : "The metal plate looks loose.",
  ]) );
  set_smell("default", "The heavy dust clouds the air.");
  set_listen("default","You can hear nothing but the beat of your heart.");
  set_search("plate","The small plate has two hinges on the edge. It "
             "looks like you can lift it.");
}
void init() {
  ::init();
    add_action("turn_ring","turn");
    add_action("check_room","lift");
    return;
}
int turn_ring(string str){
string limb;
int lmd,lcd,dam;
    if(str == "ring"){
      if(this_player()->query_class() == "thief"){
        write("You grasp the ring and turn it! It makes a solid "
              "click and the wall in front of you slides open! You "
              "quickly step into the opening and the wall slides "
              "shut behind you."); 
        say(this_player()->query_cap_name()+" grasps one of the steel "
         "rings on the wall and steps into a secret opening!");
        this_player()->move(UNTHIEF+"thief6");
        tell_room(UNTHIEF+"thief6","The secret door slides open and "
         +this_player()->query_cap_name()+" walks in.",this_player());
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
        this_player()->move(UNTHIEF+"thief_du");
        tell_room(UNTHIEF+"thief_du","You hear a scream above you!\n"
         +this_player()->query_cap_name()+" falls through the opening in "
         "the ceiling and slams into the hard stone floor in a cloud "
         "of straw and dust!",this_player());
        return 1;
   }
}
int check_room(string str){
int y;
    if(!str){
      write("Lift what?");
      return 1;
    }
    if(str == "plate"){
      write("You lift the plate and glance down into the dungeon below.");
      say(this_player()->query_cap_name()+" lifts the plate and looks "
         "underneath it.");
      inv=filter_array(all_inventory(find_object_or_load(UNTHIEF+"thief_du")),
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
