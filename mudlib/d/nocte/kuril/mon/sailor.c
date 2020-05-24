#include <std.h>
#include "nevin.h"
inherit MONSTER;

void init() {
	::init();
	if(query_night()) {
		if(!wizardp(this_player())) {
			 this_player()->move_object(ROOMS+"incinerator");
		}
	}
}

create() {
    	::create();
   	set_name("sailor");
    	set_id( ({ "sailor", "kuril mob" }) );
  	set_level(10);
    	set_short("[10]A swarthy sailor");
   	set("aggressive", 0);

    	set_long(
		"Reeking of sweat and alchohol, this sailor saunters past you. "
	);
   	set_gender("male");
   	set("race", "high-man");
   	add_money("silver", 100 + random(30));
    	set_body_type("human");
	new(ARM+"light_pants")->
	  move(this_object());
	force_me("wear pants");
	new(ARM+"blue_shirt")->
	  move(this_object());
	force_me("wear shirt");
	new(ARM+"high_boots")->
	  move(this_object());
	force_me("wear boots");
	new("/d/damned/virtual/dagger_3.weapon")->
	  move(this_object());
	force_me("wield dagger in right hand");
}

int chk_dock_mob() {
	return 1;
}

int chk_my_mob() {
	return 1;
}
