//	An example guildmaster for fighters.
//
//	DarkeLIB 0.1
//	Diewarzau 8/8/95

inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create() {
  object ob;

  ::create();

  //  The one difference is the following line:
  set_join_room("/d/damned/guilds/join_rooms/assassin_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", "Zak Dathah, the Assassin Guildmaster");
  set("long", 
"This gerudan's feline features are obscured by a thick cloak.  "
"Even though you make no eye contact, you sense that he is aware of "
"your presence.");
  set_level(18);
  set_max_hp(5000);
  set_hp(5000);
  set_property("base mp regen", 90);
  set_property("base hp regen", 90);
  set_gender("male");
  set("race", "gerudan");
  set_body_type("human");
  set_id(({ "zak", "guildmaster", "assassin", "assassin guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
  //  The name MUST be set to guildmaster if you want tell's to work.
  set_property("melee damage", ([ "crushing" : 50 ]));
  set_overall_ac(50);
  set_skill("magery", 85);
  set_skill("body alteration", 85);
  set_skill("illusionism", 85);
  set_spell_level("body disruption", 6);
  set_max_mp(5000);
  set_mp(5000);
  set_spell_level("area poison", 6);
  add_spell("area poison", "", 1);
  add_sight_bonus(4);
  add_spell("mirror image", "$(ME)", 1, 240);
  set_spell_level("mirror image", 6);
  add_spell("blur", "$(ME)", 1, 240);
  set_spell_level("improved invisibility", 6);
  add_spell("improved invisibility", "$(ME)", 1, 360);
  add_spell("body disruption", "$A");
  set_skill("melee", 60);
  set_skill("perception", 250);
  set_skill("dodge", 200);
  set_skill("parry", 150);
  set_skill("knife", 180);
  set_stats("strength", 150);
   set_stats("wisdom", 100);
  set_skill("attack", 160);
  set_stats("dexterity", 145);
  set_skill("steal", 200);
  set_languages(({ "common", "middle-english", "yin", "treefolk", "catfolk", "elvish",
		"dwarvish", "drow", "pix" }));
  set_property("ambidextry", 1);
  seteuid(getuid());
  ob = new("/d/damned/guilds/assassin/gm_sword");
  ob->move(this_object());
  ob = new("/d/damned/virtual/studded-leather-jacket.armour");
  ob->set_property("enchantment", 10);
  ob->move(this_object());
  ob = new("/d/damned/virtual/leather-pants.armour");
  ob->move(this_object());
  force_me("wear pants");
  force_me("wear jacket");
  force_me("wield sword in right hand");
  return;
}

int query_num_rounds() { return 4; }

void heart_beat() {
  object *inv, pick;
  object ob;

  inv = filter_array(all_inventory(environment()), "not_assassin", this_object());
  if(random(100) < 5 && inv && sizeof(inv)) {
    pick = inv[random(sizeof(inv))];
    ob = new("/std/skills/steal");
    ob->set_property("skill level", 95);
    ob->do_skill(this_object(), (string)pick->query_name());
  }
  ::heart_beat();
  return;
}

int not_assassin(object item) {
  if(!living(item) || !objectp(item) || (string)item->query_class() ==
     "assassin") return 0;
  return 1;
}

  
