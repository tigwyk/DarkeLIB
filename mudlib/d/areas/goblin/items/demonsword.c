inherit "/std/weapon";

   create() {
	::create();
	set_ac(5);
	set("id", ({"sword", "demon sword"}) );
	set("short", "glowing green sword of Khorne");
	set("long", "This weapon glows with a chaotic aura.  THe blade is made of some unknown green substance.  On the blade are hundreds of minute runes that empower the sword.  The sword is covered with dry and fresh blood from its victims.");
	set_type("blade");
	set_quality(5);
	set_property("no decay",1);
      set_wc(40, "cutting");
	set_verb("devour");
	set_property("enchantment",40);
	set_enh_critical(7);
	return;
}
