inherit "/std/armour";

   create() {
	::create();
	set_name("chaos armour");
	set("id", ({"suit", "chaos armour", "chaos armor", "armor"}));
	set_short("suit of heavy armour");
	set_long("A suit of heavy armour made from metal and crafted from the forges of chaos.");
	set_type("body armor");
	set_ac(1000, "plasma");
	set_limbs( ({"torso"}));


	set_value(500);
	set_weight(200);
}
