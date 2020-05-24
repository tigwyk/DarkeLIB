#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
	::create();
	set_name("wastem");
	set_id( ({ "wastem", "puppy"}) );
	set("race", "rodent");
	set_level(5);
	set_short("[5]cute pink puppy, pet thing.");
	set_long("A pink round creature with cute round ears.  Its red button nose glows with a strange aura.  There is a certain musk around the wastem, a certain musk of edibility.");
	set_body_type("quadruped");

set_max_hp(10000);
}
