// /wizards/excelsior/obj/light_crystal
// a light crystal that can be recharged with a players mp
// created by Excelsior 2 Febuary 1996

#include <std.h>

inherit OBJECT;

int lit,fuel,light_time;
object shadow;

void create() {
	::create();
	set_name("crystal");
	set_id( ({"crystal","light crystal","sparkling crystal"}) );
	set("short","A sparkling crystal");
	set("long","This is a special crystal mined in the mountains north of "+
		"the city. It emitts light through a strange chemical reaction. "+
		"The crystal comes with a special piece of black cloth. If you "+
		"wish to use the crystal's lighting ability you can 'uncover' the "+
		"crystal. To stop using the crystal, 'cover' it again. When the crystal "+
		"has used up its own power, you can recharge it with your mp. Type "+
		"'recharge crystal <#>' where <#> is the number of mp's you wish to "+
		"use.");
	fuel = 5000;
	lit = 0;
	shadow = 0;
	set_weight( 170 );
	set_property("no save",1);
	set_float_value( 1.45 );
}

void init() {
	::init();
	add_action("extinguish","cover");
	add_action("light","uncover");
	add_action("recharge_energy","recharge");
}

int light(string str) {
	if(effective_light(this_player()) < -4) {
		notify_fail("It is too dark.\n");
		return 0;
	}
	if(!str || present(str, this_player()) != this_object()) {
		notify_fail("Uncover what?\n");
		return 0;
	}
	if (lit) {
		notify_fail("It is already uncovered!\n");
		return 0;
	}
	if (!fuel) {
		notify_fail("The crystal has no energy.\n");
		return 0;
	}
	write("You uncover the crystal.");
	seteuid(getuid());
	say(this_player()->query_cap_name()+" uncovers his light crystal.",
		this_player());
	shadow = new("/std/spells/shadows/light_shad");
	shadow->set_light(3);
	shadow->start_shadow(environment());
	call_out("start_drain",fuel);
	light_time = time();
	lit = 1;
	return 1;
}

int extinguish(string str) {
	if(!str || present(str, this_player()) != this_object() ) {
		notify_fail("Cover what?\n");
		return 0;
	}
	if(!lit) {
		notify_fail("The crystal is already covered!\n");
		return 0;
	}
	write("You cover up your light crystal.");
	say(this_player()->query_cap_name()+" covers up his light crystal.",
		this_player());
	fuel -= (light_time - time());
	if (shadow) shadow->external_destruct(shadow);
	remove_call_out("start_drain");
	lit = 0;
	return 1;
}

void start_drain() {
	if(shadow) shadow->external_destruct(shadow);
	fuel = 0;
	if(living(environment(this_object())))
		tell_object(environment(this_object()),"Your crystal goes dark.");
	set_short(::query_short()+" (out of energy)");
	lit = 0;
}

int recharge_energy(string str) {
	string num,what;
	int cnum,to_fuel;
	if(!str || sscanf(str, "%s %s",what,num) != 2 ) {
		notify_fail("You need to type 'recharge crystal 70' (or another number).\n");
		return 0;
	}
	if( what != "crystal" ) {
		notify_fail("What do you wish to recharge?\n");
		return 0;
	}
	if(!atoi(num)) {
		notify_fail("How much do you wish to recharge the crystal?\n");
		return 0;
	}
	cnum = atoi(num);
	if (cnum > this_player()->query_mp()) {
		notify_fail("You don't have that much mp.\n");
		return 0;
	}
	if(effective_light(this_player()) < -2) {
		notify_fail("It is too dark.\n");
		return 0;
	}
	to_fuel = cnum*5;
	if (lit) {
		if (!shadow) {
			notify_fail("BUG! No light shadow.\n");
			return 0;
		}
		shadow->external_destruct(shadow);
		remove_call_out("start_drain");
		fuel -= (light_time-time());
		fuel += to_fuel;
		shadow = new("/std/spells/shadows/light_shad");
		shadow->set_light(3);
		shadow->start_shadow(environment());
		call_out("start_drain",fuel);
	}
	else {
		fuel += to_fuel;
	}
	this_player()->add_mp(-cnum);
	write("You recharge some of the light crystals energy.");
	set_short("A sparkling crystal");
	return 1;
}

string query_short() {
	string str;
	str = ::query_short();
	if (lit) str = str+" (uncovered)";
	return str;
}

int move(mixed dest) {
	int x;
	if(lit && shadow)
		shadow->external_destruct(shadow);
	x = ::move(dest);;
	if(lit) {
		seteuid(getuid());
		shadow = new("/std/spells/shadows/light_shad");
		shadow->set_light(3);
		shadow->start_shadow(environment());
	}
	return x;
}

remove() {
	if(lit && shadow) shadow->external_destruct(shadow);
	return ::remove();
}

int query_lit() { return lit; }
int query_fuel() { return fuel; }
object query_shadow() { return shadow; }
int query_light_t() { return light_time; }
