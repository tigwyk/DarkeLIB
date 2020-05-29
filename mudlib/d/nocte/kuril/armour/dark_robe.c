inherit "/std/armour";

void create() {
	::create();
	set_name("dark robe");
	set("id", ({"robe", "pitch black robe", "black robe"}) );
	set("short", "pitch black robe");
	set("long",
		"Long flowing robes that cover almost the entire body.  "
	);
	set_type("armor");
	set_ac(12);
	set_limbs( ({ "torso", "left arm", "right arm", "left leg",
		"right leg" }) );
	set_value(500);
	set_weight(120);
}
