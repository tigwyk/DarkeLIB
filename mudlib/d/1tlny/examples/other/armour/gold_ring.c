// /wizards/excelsior/armor/gold_ring

inherit "/std/armour";

void create() {
	::create();
	set_name("ring");
	set("id",({"gold ring","ring"}) );
	set("short","A gold ring");
	set("long","This finely made ring looks like an excellent target for a thief.");
	set_type("ring");
	set_ac(4);
	set_limbs( ({"finger"}) );
	set_weight( 7 );
	set_value( 700 );
}
