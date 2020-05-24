#include <std.h>
#include "../goblin.h"

inherit MONSTER;


void create() {
  object ob;

  ::create();
  set_level(20);
	set("short", "[20]statue of two gods");
set_name("statue");
  set("long", 
"A large statue of two orkish looking gods, each standing opposite each other.  There is an evil look in the statue's eyes.");
	set_id( ({"statue", "gods", "demon"}));

	set_max_hp(1750);
	set_hp(1750);
  set_max_mp(3000);
  set_mp(3000);
  set_property("base mp regen", 45);
  set_property("base hp regen", 80);
  set_gender("male");
 set("race", "demon");
 set_body_type("human");
  set_property("melee damage", ([ "crushing" : 50 ]));
	set_skill("melee", 100);
  set_skill("perception", 150);
  set_skill("dodge", 160);
  set_skill("blunt", 87);
  set_stats("strength", 79);
  set_skill("perception", 150);
  set_skill("reverse stroke", 80);
  set_stats("wisdom", 140);
  set_skill("attack", 67);
  set_skill("prayer", 93);
  set_spell_level("cure serious wounds", 6);
  set_spell_level("heal", 6);
	set_spell_level("wrath of god", 2);
  set_spell_level("cause serious wounds", 6);
  add_spell("cure serious wounds", "$R");
  add_spell("heal", "$(ME)");
  add_spell("wrath of god", "$A");
  set_casting_chance(30);
  set_combat_chance(120);
  set_property("ambidextry", 1);
}

