#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id( ({"goblin", "lunatic"}));
	set_level(2);
	set_short("[2]Temple guard goblin");
	set_long("A dancing goblin, obviously dancing to the gods, Gork and Mork.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_gender("male");
	set_skill("attack", 10);
	set_alignment(-10);
set_languages( ({"common"}) );
	set_speech(3, "common", ({"Aaarrrgghh!!", "URRGGG!", "Unnngggghh!", "AAAAiiieee!"}),1 );
	set_achats(20, ({"The goblin ponders about the situation.", "The goblin madly dashes at you.", "The goblin shakes his head violently, as spit flies everywhere."}));
	set_money("gold", 5);
}
