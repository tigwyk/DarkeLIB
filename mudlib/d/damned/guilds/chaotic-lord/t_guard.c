#include <std.h>
#include <guildguard.h>

inherit MONSTER;

create() {
  ::create();
    set_name("guard");
    set_id( ({ "guard" }) );
    set_short("A big, burly guard");
     set("race", "high-man");
    set_long(
 "The guard stands in front of the west exit.");
    set_body_type("human");
    set_level(GUARD_LEVEL);
    set_overall_ac(GUARD_AC);
    set_property("magic resistance", GUARD_RESIST);
    set_property("enhance criticals", GUARD_ENHCRIT);
    set_skill("block", 125);
    set_stats("strength", 300);
    set_property("handedness", "right hand");
    set_languages(({ "common" }));
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
  int gld;
  string p_name;
  object join_room, *inv;

	 if(wizardp(this_player())) return 0;
    if(TP->is_pet()){
	p_name = TP->query_owner();
	if(find_player(p_name) && find_player(p_name)->query_class() == "chaotic-lord") return 0;
	     force_me("speak common");
     force_me("say I will not allow a pet named "+TP->query_name()+" from entering as you are not a Chaotic-Lord");		
		return 1;
    }

  if(wizardp(this_player())) return 0;
   if((string)this_player()->query_class() != "chaotic-lord") {
force_me("speak common");
     force_me("say Only chaotic-lords may pass.");
    return 1;
  }
  inv = filter_array(all_inventory(this_player()), "locker_filter",
        this_object());
  if(sizeof(inv)) {
    write("The Guard says in Common: We do not allow storage devices in here.");
    return 1;
  }
   join_room = find_object_or_load("/d/damned/guilds/join_rooms/chaotic-lord_join");
  p_name = (string)this_player()->query_name();
  if(member_array("treasury restrict", (string *)join_room->
                  query_member_privs(p_name)) >= 0) {
    write("The Guard says in Common: You have been barred from the treasury by the Guildmaster.");
    return 1;
  }
  return 0;
}

int locker_filter(object item) { return (int)item->query_is_locker(); }
