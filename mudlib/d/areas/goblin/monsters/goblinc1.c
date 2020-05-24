#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id( ({"goblin", "champion"}) );
	set_level(3);
	set_short("[3]oversized goblin champion");
	set_long("This is one of the goblin champions, his immense size is a status symbol in his clan.  He wields a large axe that would easily topple any goblin trying to wield it.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_overall_ac(3);
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 13);
	set_skill("block", 12);
	set_alignment(-20);
	set_stats("strength", 30);
set_languages( ({"common"}) );
	set_speech(5, "common", ({"Har Har har...You call that a weapon?", "Are you what they call an adventurer? What a joke!", "More for me to practice?"}),1 );
	set_achats(20, ({"The goblin champion swings his weapon hard down on you.", "The goblin champion swings his weapon like a madman.", "The goblin champion slobbers madly all over the room."}));
	set_money("gold", 6);
if(!present("axe")) {
new(ITEM+"l_axe.c")->move(this_object());
force_me("wield axe in left hand and right hand");
}
}
