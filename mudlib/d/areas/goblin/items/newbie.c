inherit "/std/weapon";

	create() {
	::create();
	set_ac(6);
	set("id", ({"sword", "blade"}));
	set_short("Darke blade");
	set_long("This blade is made out of some strange material not known to you, it has a color of dark emerald green.  The hilt of the sword is a strange swirling mass of pink and black.");
	set_type("blade");
	 set_quality(5);
	set_material("metal/zatrichque");
        set_decay_rate(400);
	set_property("no add quality", 1);
	set_property("poisoning", 5);
	set_weight(15);
	set_wield((: call_other, this_object(), "check_newbie" :));
	set_value(30);
         set_wc(10, "cutting");
      set_property("enchantment", 4);
      set_property("flame blade", 3);
	set_wc(3, "electricity");
	set_wc(2, "fire");
	set_wc(1, "cold");
	set_verb("eviscerate");
}

int check_newbie() {
  if(!this_player()->is_player()) return 1;
  if((int)this_player()->query_level() > 5) {
    write("This weapon is intended to help newbies and may not be wielded "+
	  "by players over level 5.");
    return 0;
  }
  return 1;
}

void retro_set() {
  set_wield((: call_other, this_object(), "check_newbie" :));
  return;
}

int restore_me(string file) {
  int res;

  res = ::restore_me(file);
  this_object()->retro_set();
  return res;
}
