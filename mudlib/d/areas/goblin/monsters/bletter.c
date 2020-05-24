#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
  ::create();
	set_name("bloodletter");
	set_id( ({ "letter", "demon" }) );
	set("race", "demon");
	set_short("[10]evil red demon");
	set_long("The demon of Khorne");
	set_body_type("human");
	set_level(10);
	set_stats("strength", 100);
	set_stats("dexterity", 70);
	set_property("melee damage", ([ "crushing" : 10]));
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_skill("perception", 50);
	set_skill("blade", 70);
	set_skill("melee", 100);
	set_skill("dodge", 70);
	set_skill("parry", 60);
	set_property("magic resistance", 40);
	set_max_hp(300);
	set_hp(300);
	set_overall_ac(12);
	set_skill("block", 60);
	set_lang_prof("common",10);
	set_moving(1);
	set_speed(60);
	set("aggressive", 1);
	set_speech(50, "common", ({"Khorne shall destroy you all!", "You will die mortal!"}),10);
	set_alignment(-200);
	set_gender("male");
if (!present("sword")) {
new(ITEM+"demonsword.c")->move(this_object());
	force_me("wield sword in right hand");
}
}
