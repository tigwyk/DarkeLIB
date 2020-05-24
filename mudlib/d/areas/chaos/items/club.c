inherit "/std/weapon";

create() {
	::create();
	set_ac(1);
	set("id", ({ "club", "spiked club"}) );
	set("short", "A large spiked club");
	set("long", "A long cone shaped club with a large spike protruding out of the side.");
	set_type("club");
	set_quality(2);
	set_property("decay", 250);
	set_property("no add quality",1);
	set_value(60);
	set_weight(60);
	set_wc(12, "impaling");

return;
	set_verb("impale");
	set_hit("You impale your opponent on the end of the spike!");
	set_wield("You feel like impaling and bashing something!");
	set_hit_bonus(5);
}
