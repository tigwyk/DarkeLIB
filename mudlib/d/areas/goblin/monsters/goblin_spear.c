#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id("goblin");
	set_level(2);
	set_short("[2]Goblin guard");
	set_long("A goblin from the Night goblin clan, known for its ferocity and strength, also known for an animosity to almost everything.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 15);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 10);
	set_skill("block", 10);
	set_alignment(-10);
if(!present("spear")) {
new(ITEM+"spear.c")->move(this_object());
force_me("wield spear in left hand and right hand"); }
set_languages( ({"common"}) );
	set_speech(3, "common",({"Doant yer be dooin unithin krazy now!", "I've kulled er muny pepul wit me spe'a er!"}), 1 );
	set_achats(15, ({"The goblin flails his spear around his haed.", "The goblin tries to stab you, but misses retardedly.", "The goblin falls over and almost impales himself on his spear."}));
	set_money("gold", 5);
}
