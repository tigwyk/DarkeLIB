#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
	::create();
	set_name("templar");
	set_id( ({"templar", "dark templar"}));
	set("race", "human");
	set_level(30);
	set_short("[30]Dark templar of Slaneesh");
	set_overall_ac(300);
	set_long("A immense and dark templar, he stands here as if guarding something.  His armour is a dark purple hue, while his helmet is a jet black in color.  On his side he carries a large two handed axe that seems to be moving by itself.");
	set_body_type("humanoid");

	set_stats("strength", 200);
	set_stats("dexterity", 200);
	set_stats("constitution", 200);
	set_stats("intelligence", 100);
	set_stats("charisma", 100);
	set_stats("wisdom", 100);
	set_skill("attack", 200);
	set_max_hp(10000);
	set_hp(10000);
	set_skill("dodge", 200);
	set_skill("perception", 200);
	set_skill("reverse stroke", 150);
	set_skill("parry", 200);
	set_skill("blade", 100);
	set_skill("two handed blade", 100);
	set_skill("melee", 200);
	set_wielding_limbs( ({"right hand", "left hand"}));
	set_property("melee damage", (["impact" : 200]));
	set_speech(30, "common", ({
	"If you have any problems please mail Blial.",
	"Enjoy yourself!",
	"Don't even think about attacking me.",
	"There is some hidden passageways in the settlement, but i'm not sure where they are.",
	"This area is for levels 7 and under!",
	}), 1);
	set_gender("male");
	set_alignment(-5000);
	set_property("magic resistance", 100);
}
