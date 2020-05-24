/* A small pond
   Code ripped from Khojem's vats and stream
   -Duridian
*/
 
#include <move.h>
 
inherit "/std/Object";
 
int move(object desti) {
  if(living(desti)) return MOVE_NOT_ALLOWED;
    else return ::move(desti);
}
 
void create() {
  ::create();
  set_name("pond");
  set_id(({ "pond", "small pond" }) );
  set_short("a small, quiet pond");
  set_long("This small pond provides most of the water for the kobolds "
           "since they have not yet dug any wells.");
}
 
void init() {
  ::init();
  enable_commands();
  add_action("fill_vessel", "fill");
  return;
}
 
int fill_vessel(string str) {
  object ob;
 
  ob = present(str, this_player());
  if(!ob) {
    write("You don't have "+article(str)+".");
    return 1;
  }
  if(!ob->id("water skin")) {
    write("You can't fill "+article(str)+" with water!");
    return 1;
  }
  if(ob->full()) {
    write("That waterskin is full already.");
    return 1;
  }
  ob->fill("water", 5, 0);
  write("You fill the waterskin.");
  message("other_action", (string)this_player()->query_cap_name() +
        " fills a waterskin with water from the pond.",
        environment(this_player()), ({ this_player() }) );
  return 1;
}
 
int clean_up() { return 0; }
