#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
	::create();
	set_name("gelatinous cube");
	set_id( ({ "cube", "blod", "gelatinous cube", "stuff"}));
	set("race", "elemental");
	set_short("[3]Clear gelatinous mass");
	set_long("This mass of geleatinous substance is almost invisible except for its floating nucleus in the center of the room.");
	set_body_type("slime");
	set_property("melee damage", ([ "crushing" : 4]));
	set_stats("dexterity", 50);
	set_skill("dodge", 30);
	set_skill("parry", 25);
	set_skill("melee", 30);
	set_level(3);
	set_skill("invisibility art", 40);
	set_overall_ac(4);
	set("aggressive", 1);
new(ITEM+"newbie.c")->move(this_object());
	force_me("use invisibility art");
}
