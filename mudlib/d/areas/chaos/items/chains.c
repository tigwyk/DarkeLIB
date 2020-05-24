inherit "/std/armour";

   create() {
	::create();
	set_name("chains");
	set("id", ({"suit", "chains"}));
	set_short("The chains of Slaneesh");
	set_long("The chains of Slaneesh seem to be very beautiful and elegant, except when you look closer, you can see souls of people long dead trapped withing the chains.");
	set_type("armor");
	set_ac(15);
	set_limbs( ({"torso", "left arm", "right arm", "right hand", "left hand", "left leg", "right leg"}));


	set_value(100000);
	set_weight(100);
}
