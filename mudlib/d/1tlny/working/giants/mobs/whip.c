// /wizards/excelsior/weapons/whip

inherit "std/weapon";

void create() {
	::create();
	set_name("whip");
	set("id",({"whip","torture whip"}));
	set("short","beating whip");
	set("long","This looks to be a very painful whip used for beating people "+
		"mercilessly.\nType of weapon: flail");
	set_weight(75);
	set_value(50);
	set_ac(0);
set_wc(20, "stress");
	set_type("flail");
set_quality((4+random(2)));
}
