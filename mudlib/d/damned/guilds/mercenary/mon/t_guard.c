//      Edited by Tailwind

//

//      Blessed ReturnLIB

//      Tailwind 10/28/98



#include <std.h>

#include <../merc.h>



inherit MONSTER;



create() {

  ::create();

    set_name("guard");

    set_id( ({ "guard" }) );

    set_short("A big, burly guard");

     set("race", "high-man");

    set_long(

"The guard stands in front of the east exit.");

    set_body_type("human");

   set_level(15);

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

  add_action("block_exit", "east");

  return;

}



int block_exit() {

  int gld;

  string p_name;

  object join_room, *inv;



  if(wizardp(this_player())) return 0;

   if((string)this_player()->query_class() != "mercenary") {

     write("The Guard says in Common: Only mercenaries may pass");

    return 1;

  }

  inv = filter_array(all_inventory(this_player()), "locker_filter",

        this_object());

  if(sizeof(inv)) {

    write("The Guard says in Common: We do not allow storage devices in here.");

    return 1;

  }

  gld = 5 * (int)this_player()->query_level();

  if((int)this_player()->query_money("silver") < gld) {

    write("The Guard says in Common: A donation of "+gld+" silver is required for passage.");

    return 1;

  }

 join_room = find_object_or_load(ROOMS+"merc_join");

  p_name = (string)this_player()->query_name();

  if(member_array("treasury restrict", (string *)join_room->

                  query_member_privs(p_name)) >= 0) {

    write("The Guard says in Common: You have been barred from the treasury by the Guildmaster.");

    return 1;

  }

  write("The Guard says in Common: You may pass.");

  this_player()->add_money("silver", -1*gld);

  return 0;

}



int locker_filter(object item) { return (int)item->query_is_locker(); }

