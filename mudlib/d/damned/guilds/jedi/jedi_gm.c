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
  set_join_room("/d/damned/guilds/join_rooms/sword-mage_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", "Xira, the Sword Mage Guildmaster");
  set("long", 
"Xira is a strong-looking Seraph clad in robes and wielding an impressive sword.");
  set_level(20);
  set_max_hp(4000);
  set_hp(4000);
  set_max_mp(5000);
  set_mp(5000);
  set_property("base mp regen", 140);
  set_property("base hp regen", 70);
  set_gender("female");
  set("race", "half-elf");
  set_body_type("human");
  set_skill("conjuration", 150);
  set_skill("magery", 150);
  set_skill("sorcery", 150);
  set_skill("illusionism", 150);
  set_id(({ "xira", "guildmaster", "sword-mage", "sword-mage guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
  //  The name MUST be set to guildmaster if you want tell's to work.
  set_property("melee damage", ([ "crushing" : 50 ]));
  set_skill("perception", 150);
  set_skill("melee", 90);
  set_skill("dodge", 150);
  set_skill("parry", 100);
  set_skill("two handed blade", 200);
  set_stats("strength", 200);
  set_stats("intelligence", 140);
  set_skill("attack", 180);
  set_overall_ac(50);
  set_property("enhance criticals", -2);
  set_languages(({ "common", "serra", "yin", "treefolk", "catfolk", "elvish",
		"dwarvish", "drow", "undead-tongue", "middle-english", "stormspeak" }));
  set_spell_level("blizzard", 6);
  add_spell("blizzard", "$A");
  set_spell_level("internal flame", 6);
  add_spell("internal flame", "$A");
  set_spell_level("power word, kill", 6);
  add_spell("power word, kill", "$A", 1, 100);
  set_spell_level("mirror image", 6);
  add_spell("mirror image", "$(ME)", 1, 220);
  set_spell_level("blur", 6);
  add_spell("blur", "$(ME)", 1, 200);
  set_spell_level("fire shield", 6);
  add_spell("fire shield", "$(ME)", 1, 1200);
  set_combat_chance(120);
  set_spell_level("draxnar's anti-magic field", 4);
  add_spell("draxnar's anti-magic field", "", 1, 500);
  set_property("ambidextry", 1);
  ob = new("/d/damned/guilds/sword-mage/gm_sword");
  ob->set_property("enchantment", 15);
  ob->set_property("enhance criticals", 1);
  ob->set_property("hit bonus", 10);
  ob->move(this_object());
  force_me("wield sword in right hand and left hand");
  return;
}

