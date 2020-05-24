#include <std.h>
#include "nevin.h"

inherit MONSTER;

create() {
	::create();
	set_name("bandit");
	set("id", ({ "bandit", "sickly", "sickly bandit", "_bandit1" }) );
      set_level(3);
	set("short", "[3]A sickly little bandit");
	set("long",
		"He really doesn't look like he belongs with the rest of the "
		"bandit crowd.  In fact, it looks like the rest of the gang "
		"shuns him."
	);
	add_money("copper", random(100));
	set_alignment(100);
	set("race", "human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(0);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 10);
	set_skill("attack", 10);
	set_skill("blunt", 10);
	set_wimpy(75);
	set("aggressive", 0);
	set_lang_prof("Middle-english", 5);
	set_emotes(5, ({"The sickly little bandit sighs as he ponders his life."}), 0);
	set_emotes(30, ({"The sickly little bandit closes his eyes in terror."}), 1);
	set_speech(5, "Middle-english", ({ "I should have listened to mother when I was a lad...things would be so much different now if I had."}), 0);
//	new(WEAP+"dented_club.c")->
//		move(this_object());
//	force_me("wield club in right hand");
}
