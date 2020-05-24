#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
  ::create();
	set_name("carrion crawler");
	set_id( ({"insect", "carrion crawler", "crawler"}));
	set("race", "insect");
	set_short("[4]Scavenging carrion crawler");

	set_long("The crawler looks like a cross between a giant green cutworm and a cephalopod.  The carrion crawler is a scavenger of subterranean areas, feeding primarily upon carrion.");
	set_body_type("insectoid");
	set_level(4);
    set_stats("intelligence", 10);
	set_property("base hp regen", 50);
	set_property("melee damage", ([ "slashing" :20]));
	set_property("melee damage", ([ "crushing" :10]));
	set_skill("melee", 20);
	set_overall_ac(15);
	set_skill("dodge", 70);
    set_skill("parry", 5);
    set_stats("dexterity", 40);
}
