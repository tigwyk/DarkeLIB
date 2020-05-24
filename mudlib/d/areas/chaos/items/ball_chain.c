inherit "/std/weapon";

create() {
	::create();
	set_ac(2);
	set_id( ({"chain", "ball and chain"}) );
	set("short", "A huge ball and chain");
	set("long", "A huge ball, that is around 1 foot in diameter, attached to a chain and assumed to be swung around like a madman.");
	set_type("blunt");
	set_property("no decay",1);
	set_property("no add quality",1);
	set_wc(17);
	set_verb("pummel");
	set_weight(100);
	set_hit_bonus(5);
	set_parry_bonus(-2);
	set_value(80);
}
