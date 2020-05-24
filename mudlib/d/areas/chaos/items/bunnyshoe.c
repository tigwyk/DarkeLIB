inherit "/std/armour";

   create() {
	::create();
	set_name("bunny slippers");
	set("id", ({"slippers", "shoes"}));
	set_short("a pair of pink bunny faced shoes");
	set_long("A pair of pink bunny faced shoes.  These shoes feel really comfortable, they also have cute bunny faces that squeak and move as you walk.");
	set_type("boots");
	set_ac(5);
	set_weight(10);
	set_limbs(({"left foot", "right foot"}));

	set_value(100);
}
