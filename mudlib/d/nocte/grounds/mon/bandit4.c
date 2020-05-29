#include <std.h>
#include <nevin.h>

inherit MONSTER;

create() {
	::create();
	set_name("bandit");
	set("id", ({ "bandit", "_bandit4" }) );
	set_level(3);
	set("short", "A bandit grabs hold of his sword as you approach.");
	set("long",
		"Unlike his fellow bandits, this fellow looks very dangerous."
	);
	add_money("copper", random(1000));
	set_alignment(-200);
	set("race", "half-orc");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(0);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 30);
	set_skill("attack", 30);
	set_skill("blade", 30);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_wimpy(10);
	set("aggressive", 0);
	set_lang_prof("orcish", 7);
	set_emotes(5, ({"The half-orcish bandit spits in your general direction."}), 0);
	set_speech(5, "orcish", ({"Lookie here...more easy pickins has arrived."}), 0);
	new(WEAP+"short_sword.c")->
		move(this_object());
	force_me("wield sword in right hand");
}
