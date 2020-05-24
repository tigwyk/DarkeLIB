//	An example guildmaster for necromancers.
//
//	DarkeLIB 0.1
//	Diewarzau 8/8/95

inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create() {
  object ob;

  ::create();

  //  The one difference is the following line:
  set_join_room("/d/damned/guilds/join_rooms/nethermancer_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", " the Nethermancer Guildmaster");
  set("long", "The Nethermancer Guildmaster is clad entirely in black robes.  "+
      "His only ornamentation is a large amulet shaped like a silver skull. "+
      "He has a pasty white complexion and eyes that glow slightly red.");
  set_level(20);
  set_max_hp(2000);
  set_hp(2000);
  set_max_mp(4000);
  set_mp(4000);
  set_overall_ac(60);
  set_property("base hp regen", 50);
  set_property("base mp regen", 100);
  set_gender("male");
  set("race", "human");
  set_body_type("human");
  set_id(({ "guildmaster", "nethermancer", "nethermancer guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
set_property("dagger damage", ([ "crushing" : 50, "cold" : 30 ]));
set_skill("dagger", 200);
  set_skill("perception", 150);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_stats("strength", 130);
  set_skill("attack", 200);
  set_skill("necromancy", 90);
  set_skill("prayer", 80);
  set_skill("elementalism", 85);
  set_skill("chaos lore", 85);
  set_spell_level("rot", 5);
  add_spell("rot", "");
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("elemental strike", 4);
  add_spell("elemental strike", "$A");
  set_combat_chance(150);
  set_property("ambidextry",1);
  ob = new("/d/damned/guilds/nethermancer/gm_amulet");
ob->move(this_object());
force_me("wear amulet");
ob = new("/d/damned/guilds/nethermancer/gm_dagger");
  ob->move(this_object());
force_me("wield dagger in right hand");
  return;
}

int query_num_rounds() { return 3; }

string query_element() { return "chaos"; }
















