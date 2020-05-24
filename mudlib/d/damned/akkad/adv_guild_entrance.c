//    Advanturer's Guild where everyone can train.

inherit "/std/room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("no attack", 1);
    set_property("no magic", 1);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no summon", 1);
//Basic mapping added by Tiny 1/20/2020
    set("short", "   \n     \n   @--0\n   | \n   0\nThe Adventurer's Guild");
    set("long",
      "This is the foyer to the Adventurer's Guild.  Here, in "
      "exchange for the favor of the DemiUrge, all of the guilds have "
      "donated knowledge and manpower for the use of the general populace.  "
      "To the south are the vast training rooms which are legend throughout "
      "the land.\nThere is a sign on the west wall.\n   \n     \n   @--0\n   | \n   0\n");
    /*
      set_items(([ "sign" : (: call_other, this_object(), "read_sign" :) ]));
    */
    set_items(([ "sign" : "A very boring and uninteresting sign.", ]));
    add_exit("/d/damned/akkad/adv_guild_sk", "south");
    add_exit("/d/damned/akkad/ak_tavern3", "east");
    return;
}

