inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"axe", "oversized axe", "large axe"}) );
	set_short("oversized two-handed axe");
	set_long("An oversized two-handed axe.  This axe is about 6 ft long from handle to head, its axe head is as sharp as a razor, blood stains are splattered all along the whole weapon.");
	set_type("two handed blade");
	set_quality(3);
	set_weight(120);
	set_wc(12, "cutting");
	set_verb("rip");
	set_hit_bonus(10);
	set_value(200);
}
