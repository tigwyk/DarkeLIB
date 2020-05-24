//Maxwell's Underground mudlib
//Guild Zone

#include <std.h>
#include <under.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a dark dungeon.\n");
  set("long", "You are standing in a dark dungeon. The slimy cold "
      "stone walls seem to close in on you. Sealing you into the "
      "darkness.\nThe wall to the west is totally dry.\n");
  set_items( ([
    "wall" : "The wall looks loose. There is a large crack running along "
             "the side.",
    "crack" : "The crack looks like you can push the stone out of the wall.",
  ]) );
}
void init(){
  ::init();
  add_action("push_stone","push");
}
int push_stone(string str){
    if(str == "stone"){
      write("You push against the stone and it slides into the wall!\n"
        "You can see light and smell the stench of the sewer!\n");
      say(this_player()->query_cap_name()+" pushes against a block and "
         "discovers an opening in the wall!");
      add_exit(UNTHIEF+"thief3","hole");
      return 1;
    }
}
void reset(){
   ::reset();
   remove_exit("hole");
}

