#include <std.h>
#include <guildguard.h>
 
inherit MONSTER;
 
create() {
  ::create();
    set_name("guard");
    set_id( ({"guard", "Kir", "kir", "kir s'rinn", "Kir S'rinn"}) );
    set_short("Kir S'rinn, the treasury guard");
    set("race", "high-man");
    set_long(
"Kir S'rinn stands before you, arms crossed and with a stern look on his "
"face.  It is his job to guard the equipment lockers to the west.");
    set_body_type("human");
    set_level(GUARD_LEVEL);
    set_overall_ac(GUARD_AC);
    set_property("magic resistance", GUARD_RESIST);
    set_property("enhance criticals", GUARD_ENHCRIT);
    set_skill("block", 125);
    set_stats("strength", 300);
    set_property("handedness", "right hand");
    new("/d/damned/virtual/long-sword_5.weapon")->
      move(this_object());
    new("/d/damned/virtual/large-shield.armour")->
      move(this_object());
    new("/d/damned/virtual/chain-vest.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-greaves.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
    force_me("wear vest");
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
    force_me("wear greaves");
    force_me("wear bracer 2 on right arm");
    force_me("wear bracer on left arm");
}
 
void init() {
  ::init();
  add_action("block_exit", "west");
  return;
}
 
int block_exit() {
  int silv;
  string p_name;
  object join_room, *inv;
 
  if(wizardp(this_player())) return 0;
  if((string)this_player()->query_class() != "thief") {
    write("Kir S'rinn says in Common: Only thieves may pass.");
    return 1;
  }
  inv = filter_array(all_inventory(this_player()), "locker_filter",
        this_object());
  if(sizeof(inv)) {
    write("Kir S'rinn says in Common: We do not allow storage devices in here.");
    return 1;
  }
  silv = 5 * (int)this_player()->query_level();
  if((int)this_player()->query_money("silver") < silv) {
    write("Kir S'rinn says in Common: A donation of "+silv+" silver is required for passage.");
    return 1;
  }
  join_room = find_object_or_load("/d/damned/guilds/join_rooms/thief_join");
  p_name = (string)this_player()->query_name();
  if(member_array("treasury restrict", (string *)join_room->
                  query_member_privs(p_name)) >= 0) {
    write("Kir S'rinn says in Common: You have been barred from the treasury by the Guildmaster.");
    return 1;
  }
  write("Kir S'rinn says in Common: You may pass.");
  this_player()->add_money("silver", -1*silv);
  return 0;
}
 
int locker_filter(object item) { return (int)item->query_is_locker(); }
