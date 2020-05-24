inherit "/std/weapon";

create() {
	::create();
	set_ac(5);
	set("id", ({ "club", "spiked club"}) );
	set("short", "A large spiked club");
	set("long", "A long cone shaped club with a large spike protruding out of the side.");
	set_type("club");
	set_quality(3);
	set_weight(50);
	set_property("no decay",1);
	set_property("no add quality",1);
	set_wc(1000,"impaling", "time");
	set_verb("impale");
	set_hit("You impale your opponent on the end of the spike!");
	set_wield("You feel like impaling and bashing something!");
	add_poisoning(40);
	set_auto_critical("impaling E");
	set_hit_bonus(70);
}
