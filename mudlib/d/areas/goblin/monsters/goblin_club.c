#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id("goblin");
	set_level(2);
	set_short("[2]Clubber goblin");
	set_long("From the deep withing the caves of the goblins, one of the ferarsome club wielding goblins.  They have nothing to do other than to bash and kill.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_skill("blunt", 15);
	set_wielding_limbs( ({"left hand"}) );
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 10);
	set_skill("block", 10);
	set_alignment(-10);
if(!present("club")) {
new(ITEM+"club.c")->move(this_object());
force_me("wield club in left hand");
}
set_languages( ({"common"}) );
	set_speech(2, "common", ({"Want ta bash, un bash, un bash!", "Are you next fer bashing?", "More bash!, More bash! More bash!"}),1 );
	set_achats(20, ({ "The goblin raises his weapon high and swings at you.", "The goblin looks at his club and then at your head.", "The goblin grunts loudly."}));
	set_money("gold", 7);
}
