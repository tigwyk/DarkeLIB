inherit "/std/npc_shop";
// test

void create() {
  object ob;

   ::create();
   set_name("fruno");
   set("id", ({"shopkeeper", "shop keeper", "fruno"}));
   set_level(18);
  set_exp(1400000);
   set("short","Fruno, the shopkeeper");
   set("long",
"Fruno is starved dwarf who has not seen daylight in some time "
"he is short.  he is dirty and covered in dirt and mud, and "
"tufts of grey hair protrude from his chest. You'd laugh at him if "+
"you weren't so scared that he'd beat you to a bloody pulp.");
   set_gender("male");
   set_body_type("human");
   set("race", "dwarf");
  set_property("melee damage", ([ "crushing" : 45]));
  set_overall_ac(1000);
  set_skill("melee", 80);
  set_stats("strength", 130);
  set_hp(8000);
  set_skill("conjuration", 95);
  set_spell_level("blizzard", 6);
  add_spell("blizzard", "", 1);
  ob=new("/d/damned/virtual/two-handed-sword_6.weapon");
  ob->set_material("metal/mithril");
  ob->move(this_object());
  force_me("wield sword in right hand and left hand");
  set_skill("reverse stroke", 90);
  set_skill("two handed blade", 200);
  set_combat_chance(150);
  set_mp(10000);
  add_money("gold", 2500);
  set_skill("dodge", 70);
   set_skill("perception", 80);
   set_languages(({"stormspeak", "mountainspeak", "common", "elvish", "treefolk", "serra", "yin", "dwarvish","rachk"}));
   set("storage room","/d/damned/guilds/tinker/t_hole_storage");
   set("pre sell function", (: call_other, this_object(), "sell_ingot" :) );
   set("markup", 15);
}

string sell_ingot(object what) {
  if(!what->id("ingot"))
    return "You may only sell ingots here.";
  return 0;
}

void reset() {
  ::reset();
  add_money("gold", 25*random(10));
}
