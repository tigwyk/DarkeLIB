#include <std.h>
#include <nevin.h>

inherit MONSTER;

create() {
	::create();
	set_name("bandit");
	set("id", ({ "bandit", "_bandit2" }) );
        set_level(4);
	set("short", "A bandit is here staring at the sky with his mouth hanging open.");
	set("long",
		"Oh man does his breathe smell!  Too bad you don't have any "
		"mints for him.  He could really use them."
	);
	add_money("copper", random(100));
	add_money("gold", 10+random(30));
	set_alignment(-100);
	set("race", "human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(0);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 20);
	set_skill("attack", 20);
	set_skill("knife", 20);
	set_wimpy(20);
	set("aggressive", 0);
	set_lang_prof("Middle-english", 5);
	set_emotes(5, ({"The lounging bandit smacks his lips as he rolls over."}), 0);
	set_emotes(20, ({"I'm gonna slice ye good!"}), 1);
	new(WEAP+"dagger.c")->
		move(this_object());
	force_me("wield dagger in right hand");
}
