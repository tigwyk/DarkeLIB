#include <std.h>
#include <nevin.h>

inherit MONSTER;

void create(){
	::create();
	set_name("a ghoul");
	set_id( ({"ghoul", "grounds ghoul"}) );
	set_level(5);
	set("short", "With blood encrusted nails, a ghoul rakes the air before you.");
	set("long",
		"Through a voiceless mouth, the ghoul cries in anger at it's undead state.  Stumbling toward you, is seeks to destroy anything living."
	);
	set("race", "ghoul");
	set_gender("neuter");
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_moving(0);
	set_skill("conjuration", 30);
	set("aggressive", 1);
	add_money("gold", 10 + random(40));
	add_spell("ice dagger", "$A");
	set_spell_level("ice dagger", 3);
}
