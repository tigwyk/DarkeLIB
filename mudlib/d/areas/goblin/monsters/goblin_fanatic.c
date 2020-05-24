#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id( ({"goblin", "fanatic"}) );
	set_level(2);
	set_short("[2]Psychotic goblin");
	set_long("An estatic gibbering goblin, who is impervious to pain, and is largely unaware of his enviroment.  He is immensely strong, and immensely unfeeling to pain.  He carries a hug ball on a chain, a weapon so large that is would be impossible for any goblin to pick up in normal circumstance, but the Fanatic's strength is boosted by a fungus beer enabling himi to swing the heavy ball at his whim.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_gender("male");
	set_skill("attack", 10);
	set_alignment(-10);
if(!present("chain")) {
new(ITEM+"ball_chain.c")->move(this_object());
force_me("wield chain in left hand and right hand"); }
set_languages( ({"common"}) );
	set_speech(3, "common", ({"Aaarrrgghh!!", "URRGGG!", "Unnngggghh!", "AAAAiiieee!"}),1 );
	set_achats(20, ({"The goblin mumbles a prayer", "The goblin scurries around the room like a rat on steroids.", "The goblin jumps up and down psychotically."}));
	set_money("gold", 5);
}
