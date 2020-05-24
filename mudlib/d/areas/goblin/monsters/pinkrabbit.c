#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
  ::create();
	set_name("Pink bunny");
	set_id( ({"bunny", "pink bunny"}));
    set("race", "rabbit");
	set_level(4);
	set_short("[4]pink fuzzy bunny");

	set_long("A pink bunny rabbit that is extremely cute, with its button nose and fuzzy tail.");
	set_body_type("human");

    set_stats("intelligence", 10);
	set_property("base hp regen", 50);
    set_property("melee damage", ([ "crushing" : 0]));
    set_skill("melee", 10);
	set_skill("dodge", 70);
    set_skill("parry", 5);
	set_wimpy(40);
    set_stats("dexterity", 40);
	set_speed(60);
	set_moving(1);
new(ITEM+"bunnyear.c")->move(this_object());
force_me("wear bunny ears");
new(ITEM+"bunnysuit.c")->move(this_object());
force_me("wear bunny suit");
new(ITEM+"bunnyshoe.c")->move(this_object());
	force_me("wear bunny shoes");
}
