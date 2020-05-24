inherit "/std/weapon";

create() {
	::create();
	set_ac(30);
	set("id", ({"flail"}));
	set("short", "Flail of many groin destructions");
	set("long", "A strange femur shaped handle, which extends out into 3 heavy chains.  Upon each chains is a glowing skull.");
	set_type("blunt");
	set_quality(6);
	set_property("no decay",1);
	set_property("no add quality",1);
	set_wc(200, "fire", "electricity", "acid", "cold", "impact", "depression", "disruption");
	set_verb("castrate");
	set_property("enchantment",30);
	add_poisoning(20);
	set_hit_bonus(100);
	set_hit("the three skulls destroy your groin!");
	set_wield("You want to destroy some groins!");
}
