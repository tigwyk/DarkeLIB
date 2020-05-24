//	An example guildmaster for arch magi.
//
//	DarkeLIB 0.1
//	Diewarzau 8/8/95

inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create() {
  object ob;

  ::create();

  //  The one difference is the following line:
  set_join_room("/d/damned/guilds/join_rooms/elemental-mage_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", "Bolus, the Elemental-mage Guildmaster");
  set("long", 
"Bouls is an old, wise high-elf clad in elaborate robes.  He moves slowly, "
"but you detect strong magical prowess within him.");
  set_level(20);
  set_max_hp(3000);
  set_hp(3000);
  set_max_mp(2000);
  set_mp(2000);
  set_property("base mp regen", 140);
  set_property("base hp regen", 50);
  set_gender("male");
  set("race", "high-elf");
  set_body_type("human");
  set_overall_ac(60);
  set_skill("elementalism", 90);
  set_id(({ "solus", "guildmaster", "elemental-mage", "elemental-mage guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
  //  The name MUST be set to guildmaster if you want tell's to work.
  set_property("melee damage", ([ "crushing" : 50,"impact" : 50, "fire" : 10 ]));
  set_skill("perception", 150);
  set_skill("melee", 200);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("blunt", 87);
  set_stats("strength", 79);
  set_stats("intelligence", 140);
  set_skill("attack", 200);
  set_skill("two handed staff", 200);
  set_languages(({ "common", "serra", "yin", "treefolk", "catfolk", "elvish",
		"dwarvish", "drow", "undead-tongue", "middle-english", "stormspeak" }));
  set_spell_level("greater elemental bolt", 6);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental storm", 6);
  add_spell("greater elemental storm", "");
  set_spell_level("greater elemental strike", 4);
  add_spell("greater elemental strike", "$A");
  set_combat_chance(150);
  set_property("ambidextry", 1);
  ob = new("/d/damned/guilds/elemental-mage/gm_amulet");
  ob->move(this_object());
  force_me("wear amulet");
//LIKE THEY NEED A STAFF TOO? parnell 020199
ob = new("/d/damned/guilds/elemental-mage/gm_staff");
ob->move(this_object());
force_me("wield staff in right hand and left hand");
//  ob->move(this_object());
// force_me("wield staff in right hand and left hand");
  return;
}

string query_element() {
  string *tmp;

  tmp = ({ "fire", "wind", "chaos", "gravity", "vacid", "water" });
  return tmp[random(sizeof(tmp))];
}

