inherit "/std/armour";

   create() {
	::create();
	set_name("bunny suit");
	set("id", ({"suit", "bunny suit"}));
	set_short("a pink bunny suit");
	set_long("A pink bunny suit with, bunny arms, bunny legs, and a bunny body.");
	set_type("armor");
	set_ac(8);
	set_limbs( ({"torso", "left arm", "right arm", "right hand", "left hand", "left leg", "right leg"}));


	set_value(200);
	set_weight(100);
}
