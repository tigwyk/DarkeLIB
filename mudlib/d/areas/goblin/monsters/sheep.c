#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

	::create();
	set_name("sheep");
	set_id(({"sheep"}));
	set_class("thief");
	roll=random(10);
	switch(roll){
	case 0:zlevel=1;break;
	case 1:zlevel=1;break;
	case 2:zlevel=1;break;
	case 3:zlevel=1;break;
	case 4:zlevel=2;break;
	case 5:zlevel=2;break;
	case 6:zlevel=2;break;
	case 7:zlevel=2;break;
	case 8:zlevel=3;break;
	case 9:zlevel=4;break;
}
	set("race", "cattle");
	set_long("A sacrificial lamb to appease the great gods Gork and Mork.");
	set_body_type("quadruped");
	set_level(zlevel);
	xskill=4*zlevel;
	set_skill("dodge", xskill);
	set_skill("melee", xskill);
	set_hp(5000);
	set_skill("attack", xskill);
	xchange=random(2);
if(xchange)
	set_gender("male");
else set_gender("female");
if (zlevel == 4) set_short("[4]sheep");
if (zlevel == 3) set_short("[3]sheep");
if (zlevel == 2) set_short("[2]sheep");
else set_short("[1]sheep");
}
