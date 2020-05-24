inherit "/std/armour";

   create() {
	::create();
	set_name("bunny ears");
	set("id", ({"ears", "bunny ears"}));
	set_short("a pair of pink fuzzy bunny ears");
	set_long("A pair of cute pink bunny ears which you can wear atop your head as decoration");
	set_type("helmet");
	set_ac(7);
	set_weight(10);
	set_limbs( ({"head"}));

	set_value(100);
	set_weight(20);
}
