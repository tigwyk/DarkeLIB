//	An example guildmaster for paladins.
//
//	DarkeLIB 0.1
//	Diewarzau 8/8/95

inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create() {
  object ob, ob2;

  ::create();

  //  The one difference is the following line:
  set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", "The Dark-Paladin Guildmaster");
  set("long", "The Dark-Paladin Guildmaster is surrounded by an aura of Darkness. "+
      "He is clad in a black breastplate with a glowing sword at his "+
      "side.  Forces of chaos have a formidable opponent in this champion" +
      " of dark");
  set_level(19);
  set_max_hp(3500);
  set_hp(5000);
  set_max_mp(2000);
  set_mp(2000);
  set_overall_ac(60);
  set_property("base hp regen", 100);
  set_property("base mp regen", 50);
  set_gender("male");
  set("race", "human");
  set_body_type("human");
  set_id(({ "guildmaster", "dark-paladin", "dark-paladin guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
  set_property("melee damage", ([ "crushing" : 20 ]));
  set_skill("melee", 80);
  set_skill("perception", 150);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("block", 70);
  set_skill("two handed blade", 200);
  set_skill("blade", 90);
  set_stats("strength", 130);
  set_skill("attack", 200);
  set_spell_level("harm",6);
  set_spell_level("heal",6);
  set_spell_level("armour of faith",6);
  add_spell("heal", "$(ME)");
  add_spell("chaos bane", "$(ME)", 0, 1100);
  set_spell_level("chaos bane", 6);
  add_spell("harm", "$A");
  add_spell("armour of faith","$(ME)");
  set_combat_chance(140);
  set_property("ambidextry",1);
  ob = new("/d/damned/guilds/dark-paladin/weapons/gm_holy_bane");
  ob->move(this_object());
  force_me("equip");
  ob2 = new("/d/damned/guilds/dark-paladin/gm_plate");
  ob2->move(this_object());
  force_me("wear breastplate");
  return;
}

int query_num_rounds() { return 3; }

