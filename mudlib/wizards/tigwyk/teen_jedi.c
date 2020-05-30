#include <std.h>

inherit MONSTER;

create() {
	object weap;

	::create();
	set_name("teen jedi");
	set_id(({"jedi","teen jedi", "jedi teen", "teen"}) );
	set_level(5);
	set_short("teenage Jedi");
	set_long("A distant cousin of someone's uncle.");

	set_body_type("human");
	set("race", "human");
	set_wielding_limbs( ({"left hand"}) );
	set_skill("melee", 10);
	set_skill("parry", 10);
	set_skill("knife", 10);
	set_skill("attack", 60);
	set_stats("strength", 20);
	set_skill("dodge", 15);
	set_skill("lightsaber", 60);
	set_stats("intelligence", 10);
	set_stats("dexterity", 20);
	set_stats("constitution", 10);
	set_stats("charisma", -10);
	set_stats("wisdom", 10);
	set_gender("male");
	set_class("jedi");
	set_alignment(-10);

	set_languages( ({"basic"}) );
	set_speech(3, "basic", ({"I'm learning how to use a lightsaber!", "Mom says I have to stay here until I can save the universe.", "Are you here to slay us all?"}), 1 );
	set_money("credits", 10);
	if(!present("saber")) {
	weap = new("/std/lightsaber");
	weap->set_saber(6+random(3)+1);
	weap->move(this_object());
	force_me("wield saber in left hand");
	}
}
