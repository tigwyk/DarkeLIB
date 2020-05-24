#include <std.h>
#include "nevin.h"
inherit MONSTER;

create() {
	object ob;
    	::create();
   	set_name("fisherman");
    	set_id( ({ "citizen", "fisherman" }) );
    	set_level(7);
    	set_short("[7]A fishing citizen of Kuril");
   	set("aggressive", 0);

    	set_long(
		"Looking down upon the dark blue waters of the ocean, "
		"the citizen casts his fishing pole into the murky waters."
	);
   	set_gender("male");
   	set("race", "high-man");
   	add_money("silver", 30);
    	set_body_type("human");
	set_emotes(1, ({ "The citizen cast his stick into the water.",
		"The citizen grumbles about not being able to catch anything.",
		"The citizen wets his finger and puts it into the air testing "
			"the wind.",
}), 1);
set_languages("middle_english");
	set_speech(1, "middle-english", ({
		"If only I had some bait for this darn pole, then maybe I "
		"would catch something."
}), 1);
	new(MISC+"fishing_pole")->
		move(this_object());
	new(ARM+"plain_boots")->
		move(this_object());
	force_me("wear boots");
	new(ARM+"commoners_clothes")->
		move(this_object());
	force_me("wear clothes");
	ob = new("/d/damned/virtual/short-sword_3.weapon");
	ob->move(TO);
	force_me("wield sword in right hand");
}

int chk_my_mob() {
	return 1;
}
