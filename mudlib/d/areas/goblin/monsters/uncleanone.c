#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
  ::create();
	set_name("Great Unclean One");
	set_id( ({"demon", "great unclean one"}) );
	set("race", "demon");
	set_level(20);
	set_short("[20]great disgusting feotid demon");
	set_long("A gigantic figure bloated with decay, disease and all imaginable kinds of physical corruption.  The skin of the demon is greenish necrose and leathery, its surface is covered with pockmarks, sores, and other signs of infestation.  The inner organs, rank with decay, spill through the ruptured skin and hand like drapes about the girth.");
	set_body_type("human");
	add_limb("tongue");

	set_stats("constitution", 120);
	set_stats("strength", 100);
	set_stats("intelligence", 100);
	set_skill("attack",60);
	set_skill("melee", 70);
	set_skill("parry", 100);
	set_overall_ac(14);
	set_combat_chance(80);
	set_property("magic resistance", 50);
	set_mp(5000);
	add_spell("cause_critical_wounds", "$A");
	add_spell("weaken", "$A");
	add_spell("instill_poison", "$A");
	set_spell_level("cause_critical_wounds", 10);
	set_spell_level("weaken", 8);
	set_spell_level("instill_poison", 12);
}
