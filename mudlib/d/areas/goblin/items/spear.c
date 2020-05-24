inherit "/std/weapon";

	create() {
	::create();
	set("id", ({"spear"}) );
	set("short", "sharp spear");
	set("long", "This is a spear covered in a red oily liquid. Obviously the wielder was trying to show that he had killed many opponents.");
	set_type("two handed polearm");
	add_poisoning(5);
	set_quality(2);
	set_weight(50);
	set_value(60);
	set_property("decay", 500);
	set_wc(10, "impaling");
	set_verb("thrust");
	set_parry_bonus(-5);
}
