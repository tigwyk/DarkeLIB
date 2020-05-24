inherit "/std/weapon";

create() {
	::create();
	set_id( ({"mace", "moon mace"}));
	set("short", "A shiny moon mace");
	set_long("A ten pound shiny steel ball attached to a stick");
	set_type("blunt");
	set_property("no decay",1);
	set_property("no add quality",1);
	set_weight(30);
	set_wc(5, "fire");
	set_verb("crack");
	set_hit_bonus(5);
	set_value(150);
}
