inherit "/std/weapon";

	create() {
	::create();
	set_ac(0);
	set("id", ({"knife"}) );
	set_short("rusted knife");
	set_long("A knife used by gretchin, this knife is stained with the multicolored parts of the mushroom found in the caves of the goblins.");
        set_type("knife");
	set_quality(2);
	set_weight(15);
	set_property("decay", 200);
	set_value(30);
	set_wc(7, "impaling");
	set_verb("poke");
	set_hit_bonus(10);
}
