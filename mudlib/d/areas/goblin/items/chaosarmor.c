inherit "/std/armour";

   create() {
	::create();
	set_name("chaos armor");
	set("id", ({"armor", "armour"}) );
	set("short", "a suit of chaos armor");
	set("long", "A powerful suit of armor that comes from the void, the armor seems to want to meld with something.  The armor is a deep black in color.  No light escapes from the clutches of the armor.");
	set_type("body armour");
	set_ac(60);
	set_limbs( ({"torso"}) );
	set_weight(10);
	set_property("magic item", ({"illuminate", "darken"}) );
}
