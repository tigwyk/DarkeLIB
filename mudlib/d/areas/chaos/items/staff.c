inherit "/std/weapon";

	create() {
	::create();
	set("id", ({"staff"}) );
	set_short("gnarled wooden staff");
	set("long", "This is a long wooden staff maybe about 5 to 6 feet long.  The whole body of the staff is twisted and gnarled into many different shapes.");
	set_type("two handed staff");
	set_quality(4);
	set_value(400);
	set_weight(30);
	set_property("decay", 500);
	set_wc(17, "blunt");
	set_verb("smash");
	set_parry_bonus(-5);
}
