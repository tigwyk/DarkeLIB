inherit "/std/lightsaber";

	create() {
	::create();
	set_ac(6);
	set("id", ({"saber", "lightsaber"}));
	set_short("newbie lightsaber");
	set_long("This blade is made out of some strange material not known to you, it has a color of dark emerald green.  The hilt of the sword is a strange swirling mass of pink and black.");
	set_type("lightsaber");
	 set_quality(5);
	set_material("metal/zatrichque");
        set_decay_rate(400);
	set_property("no add quality", 1);
	set_property("poisoning", 5);
	set_weight(15);
	set_wield((: call_other, this_object(), "extra_wield" :));
	set_unwield((: call_other, this_object(), "extra_unwield" :));
	set_value(30);
         set_wc(10, "cutting");
      set_property("enchantment", 4);
      set_property("flame blade", 3);
	set_wc(3, "electricity");
	set_wc(2, "fire");
	set_wc(1, "cold");
	set_verb("eviscerate");
}