// /wizards/excelsior/mon/pie_man
// Excelsior 6-8-96

#include <std.h>

inherit MONSTER;

void make_me_apron() {
	object ob;
	seteuid(getuid());
	ob = new("/std/armour");
	ob->set_name("apron");
	ob->set("id",({"apron","baker's apron","bakers apron"}));
	ob->set("short","baker's apron");
	ob->set("long","This looks like an apron worn by a pie man.");
	ob->set_type("cloak");
	ob->set_ac(3);
	ob->set_limbs("torso");
	ob->set_weight(40);
	ob->set_value(10);
	ob->set_wear("You feel like making pies.");
	ob->move(this_object());
	command("wear apron");
}

void create() {
	seteuid(getuid());
	::create();
	set_name("man");
	set("id",({"pie man","man","pie","man pie"}));
	set_level(8);
	set("short","The pie man");
	set("long","This is the pie man. He makes his living selling pies. If you "+
		"want to but a pie, type 'buy pie'. They cost 200 copper each. He "+
		"will only except copper. There are no refunds and no credit.");
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(16);
	set_melee_damage("holy");
	set_combat_chance(50);
	add_spell("heal","$(ME)");
	add_spell("fireball","$A");
	set_spell_level("heal",3);
	set_spell_level("fireball",4);
	set_skill("melee",75);
	set_skill("conjuration",70);
	set_skill("----------",65);
	set_class("war-priest");
	set_languages( ({"middle-english","yin","dwarvish","serra","common"}) );
	set_wimpy(60);
	make_me_apron();
	add_money("copper",500);
}

void init() {
	::init();
	add_action("buy","buy");
}

int buy(string str) {
	object ob;
	if(str != "pie") {
		notify_fail("Buy whay?\n");
		return 0;
	}
	if((int)this_player()->query_money("copper") < 200) {
		notify_fail("You do not have 200 copper to buy the pie with!\n");
		return 0;
	}
	this_player()->add_money("copper",-200);
	write("You buy a pie. Yum.");
	message("other_action",this_player()->query_cap_name()+" buys a delicious "+
		"pie. You want one too.",environment(),({this_player()}));
	
	seteuid(getuid());
	ob = new("/wizards/excelsior/obj/pie");
	ob->move(this_player());
	if(!present(ob,this_player())) {
		write("You cannot carry the pie and it falls to the ground.");
		ob->move(environment());
	}
	set_primary_lang((string)this_player()->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	force_me("say Thank you for your purchase.");
	return 1;
}
