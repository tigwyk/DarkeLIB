/* TINKER -- Join Room
 */
inherit "/std/guilds/join_room";

// void init() {
//   ::init();
//   add_action("class_check","west");
//   add_action("class_check","up");
// }

void create() {
  object ob;
  set_class_name("tinker");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_related_guilds(({ "fighter", "enchanter" }));
  set("short", "Guild of Tinkers, Hall of Craftsmen");
  set("long", @TEXT
  
You have found your way into a finely detailed meeting hall. There is
an iron spiral staircase leading up from here. All about the room are
strange and wonderful things crafted by the greatest tinkers of all
time. You feel a great heat coming from a back room to the west, and
feel it may not be so comfortable in that direction.  There are some
large poster-sized lists and a sign on one wall.

TEXT
);

  set_items( ([
   "staircase":"It is crafted out of iron and looks very proffesionally done.",
   "things":"There is a sign nearby that says 'Look with your eyes not your hands.'",
   "mineral list":
   "Element      Hardness   Type           WC Bonus  AC Bonus%^RESET%^  \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "Eog             10     Nullification     XXX        XX\n"  
   "Eonmite         5      Time               XX         \n"
   "Iysaughton      6      Chaos              XX         \n"
   "Laen            9      Reflection                  XXX\n"
   "Neorolite       4      Limb Severer        X\n"
   "Mabril          4      Stunning            X\n"
   "Platnite        5      Electricity        XX\n"
   "Mithril         7      Flaming            XX        XX\n"
   "Elrodnite       6      Frost              XX\n"
   "Inniculmoid     7      Force              XX        XX\n"
   "Raysorite       6      Singing            XX\n"
   "Catoetine       4      Quickness           X        XX\n"         
   "Javednite       5      Bone Breaker        X\n"
   "Davistone       5      Weapon Breaker      X\n"
   "Mcgrail         4      Darkness            X\n"
   "Boernerine      3      Light               X\n"
   "Steel           2      None              \n"
   "Iron            1      None                 \n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^Note: This list is from most powerful to least.%^RESET%^\n",
   ({"sign","list","lists","poster-sized lists"}):
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "The following lists are posted around the room:\n"
   "     weapon list   --  list of weapon types\n"
   "     armour list   --  list of armour types\n"
   "     clothes list  --  list of clothing types\n"
   "     mineral list  --  list of mineral types\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "weapon list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^    Any of these weapons can be made by tinkers.%^RESET%^\n\n"
   "   war-hammer       two-handed-sword   great-axe\n"
   "   footman's-flail  bastard-sword      battle-axe\n"
   "   morning-star     broad-sword        hand-axe\n"
   "   footman's-mace   long-sword         halberd\n"
   "   hammer           scimitar           glaive\n"
   "                    short-sword        military-fork\n"
   "   quarter-staff    dagger             trident\n"
   "   military-pick                       spear\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "armour list" :
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^     Any of these armours can be made by tinkers.%^RESET%^\n\n"
   "     breast-plate    wall-shield     scale-mail\n"
   "     corslet         large-shield    chain-mail\n"
   "     chain-coif      small-shield\n"
   "                     buckler-shield  great-helm\n"
   "     scale-greaves\n"
   "     iron-greaves    gauntlet        iron-bracer\n"
   "     chain-greaves   chain-glove     metal-boots\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
   "clothes list":
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n"
   "%^GREEN%^     Any of these armours can be made by tinkers.%^RESET%^\n\n"
   "     leather-vest                        cloak\n"
   "     leather-jacket               leather-belt\n"
   "     leather-pants        studded-leather-vest\n"
   "     leather-glove        studded-leather-pants\n"
   "     leather-boots        studded-leather-glove\n"
   "%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n",
    ]));

  ob = new("std/bboard");
  ob->set_name("book");
  ob->set_id( ({"book", "tinker book", "work order book"}) );
  ob->set_board_id("tinker_book");
  ob->set_max_posts(50);
  ob->set_edit_ok( ({"/d/damned/guilds/join_rooms/tinker_join"->query_all_members() }) );
  ob->set_location("d/damned/guilds/join_rooms/tinker_join");
  ob->set("short","Work Order Book");
  ob->set("long",@TEXT%^BLUE%^
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^
This ledger contains all the work requests and work-in-progress annotations
requarding projects, jobs, or customer service.

Customers should feel free to post a work request according to guidelines
set forth in the INSTRUCTIONS entry.  Information reguarding what services
are provided and prices can be found in the CATALOG entry.%^BLUE%^
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^

TEXT
);
  new("d/damned/guilds/join_rooms/tcan")->move(this_object());
  set_exits( ([
    "east" : "/d/daybreak/room/dbcc7",
    "up" : "/d/damned/guilds/tinker/train_room",
    "west" : "d/damned/guilds/tinker/tinker_shop",
  ]) );

//Class Check added by Maxwell 7/96

  set("guildmaster", "/d/damned/guilds/tinker/tinker_gm");
  set_guild_obj("/d/damned/guilds/tinker/tinker_obj");

  set_property("base hp regen", 7);
  set_property("base mp regen", 2);

  set_property("hp advance", 40);
  set_property("mp advance", 8);

  set_property("guild mods", ([ "strength" :  15, "constitution" : 5 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}
int class_check(){
   if( (string)this_player()->query_class() == "tinker" ||
       wizardp(this_player()) ){
     return 0;
   }
   else
     write("You are not permitted to exit in this direction.");
     return 1;
}
