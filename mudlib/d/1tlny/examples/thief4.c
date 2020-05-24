//Maxwell's Underground mudlib
//Thief Guild

#include <std.h>
#include <under.h>
inherit ROOM;

int x;
void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a slimy stone passage. The passage "
      "end here. There is a large grate in the flow into which the foul "
      "smelling liquid is draining.\n");
  set("long", "You are standing in a slimy stone passage. The cold stone "
      "walls stretches back to the east and stops at another wall to the "
      "west. The center of the passage is sumerged with a dark smelly "
      "liquid.\n"
      "The liquid is pouring into a huge grate in the floor.\n");
  set_exits( ({ UNTHIEF+"thief3" }),({ "east" }) );
  set_items( ([
    "walls" : "The cold stone walls are wet with running water.",
    "passage" : "The passage leads off into the darkness to the east.",
    "liquid" : "The nasty smelling liquid is filling most of the passage.",
    "grate" : "The large steel grate is rusty and covered with strange "
              "lichens and molds.",
  ]) );
  set_smell("default", "The smell of the foul liquid fills your nose.");
  set_listen("default","The sound of the draining liquid fills the "
             "passage.");
  set_search("grate","You find a small pullable steel lever hidden in the "
             "grate!");
  x = 0;
}
void init(){
   ::init();
   add_action("pull_lever","pull");
}
int pull_lever(string str){
string clas;
  if(!str){
    write("Pull what?");
    return 1;
  }
  if(str == "lever"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You pull the small lever..");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) ){
          tell_room(this_object(),"A secret door slides opens in the wall!");
          add_exit(STDTHIEF+"thief_join","doorway");
          delayed_call("close_door",10);
          x = 1;
        }
        else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
         tell_room(UNTHIEF+"thief_du","You hear a scream above you!\n"
          +this_player()->query_cap_name()+" falls through the opening in "
          "the ceiling and slams into the hard stone floor in a cloud "
          "of straw and dust!",this_player());
         this_player()->move(UNTHIEF+"thief_du");
         return 1;
        }
      }
      else {
       if(clas == "thief" || clas == "child" || wizardp(this_player()) ){
         write("You pull the lever and the secret door slides shut!");
         remove_exit("doorway");
         remove_delayed_call("close_door");
         x = 0;
       }
       else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
          this_player()->move(UNTHIEF+"thief_du");
          return 1;
        }
    }
    say(this_player()->query_cap_name()+" pulls on something in the "
       "grate.");
    return 1;
   }
}
void close_door(){
   remove_exit("doorway");
   tell_room(this_object(),"The secret doorway slides shut!\n");
   x = 0;
   return;
}
