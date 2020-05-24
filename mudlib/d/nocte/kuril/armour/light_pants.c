inherit "/std/armour";

void create() {
	::create();
	set_name("pants");
	set("id", ({ "pants", "light pants", "light leather pants" }) );
	set("short", "light leather pants");
	set("long",
		"Acceptable in quality, but poor in taste, these pants serve "
		"their purpose and nothing more."
	);
	set_weight(80);
	set_type("cloth pants");
	set_limbs( ({"right leg", "left leg" }) );
	set_ac(3);
	set_value(20);
	set_material("cloth");
}
