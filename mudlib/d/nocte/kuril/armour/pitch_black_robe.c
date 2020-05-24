inherit "/std/armour";

void create() {
	::create();
	set_name("pitch black robe");
	set("id", ({"robe", "pitch black robe", "black robe"}) );
	set("short", "pitch black robe");
	set("long",
		"Long flowing robes that cover almost the entire body.  "
	);
	set_type("robe");
	set_ac(12);
	set_limbs( ({ "torso", "left arm", "right arm", "left leg",
		"right leg" }) );
	set_value(400);
	set_weight(100);
	set_material("cloth");
}
