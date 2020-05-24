inherit "/std/bag_logic.c";

	create() {
	::create();
	set_name("vine string bag.");
	set("id", ({"bag", "vine string bag"}) );
	set("short", "A vine string bag.");
	set("long", "A bag made out of vines from a jungle nearby");
	set_weight(5);
	set_max_internal_encumbrance(100);
	set_value(10);
}
