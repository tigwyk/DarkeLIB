#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV;

	HPBASE = 100;

	::create();
	seteuid(geteuid());
	set_name("Centaur Warrior");
	set("id", ({"warrior", "centaur", "centaur warrior" }) );
	set_level(14 + random(5));
	switch(random(5)) {
		case 0: var = "An Edgy Centaur"; break;
		case 1: var = "A Snorting Centaur"; break;
		case 2: var = "A Scarred Centaur"; break;
		case 3: var = "A Hairy Centaur"; break;
		case 4: var = "A Mean Centaur"; break;
	}
	this_object()->set("short", var);
	set("long",
   "This is one of the fiercest Centaur creatures you have ever seen."
   " His arms and chest are massively built, and his 4 equine legs look like "
   "they could run forever. He is wearing no clothing, yet has an air of "
   "sophistication and superiority about him, that awe you into reverence of "
   "this great creature. "
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

     LEV = random(6) + 12;
	set_skill("two handed polearm", 90 + random(50));

	set("aggressive", 0);
	set("gang bang", 1);
	add_money("silver", 100 + random(200) );
   new(PLATOBJ+"spear")->move(this_object());
   force_me("wield spear in left hand and right hand");
}
