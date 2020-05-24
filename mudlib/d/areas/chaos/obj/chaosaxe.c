inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"axe", "oversized axe", "large axe"}) );
	set_short("two-handed chaos axe");
	set_long("An oversized two-handed axe.  This axe is about 6 ft long from handle to head, its axe head is as sharp as a razor, blood stains are splattered all along the whole weapon.");
	set_type("two handed blade");
	set_quality(6);
	set_weight(120);
	set_wc(40, "cutting");
	set_verb("rip");
	set_hit_bonus(100);
	set_auto_critical("disruption E");
	set_value(10000);
}
