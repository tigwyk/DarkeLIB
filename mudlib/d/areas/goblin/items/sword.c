inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"sword", "rusted sword"}) );
	set_short("rusted sword");
	set_long("A crumbling sword, rusted and barely able to function as a sword.  Used mainly by the goblins.");
	set_type("blade");
	set_quality(2);
	set_weight(40);
	set_property("no add quality",1);
	set_value(55);
	set_property("decay", 100);
	set_wc(12, "cutting");
	set_verb("rip");
	set_hit_bonus(10);
}
