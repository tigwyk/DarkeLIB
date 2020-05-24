#include "nevin.h"
inherit "/std/barkeep";

create() {
    	::create();
   	set_name("hsspra");
    	set_id( ({ "waitress", "hsspra", "kuril mob" }) );
  	    set_level(10);
    	set_short("[10]Hsspra the restaurant waitress");
   	set("aggressive", 0);

    	set_long("She is ready to take your order.\n");
   	set_gender("female");
   	set("race", "gerudan");
	set_max_hp(750);
   	set_hp(750);
   	add_money("silver", 30);
   	set_skill("melee",90);
    	set_body_type("human");
	set_currency("silver");
	set_lang_prof("common", 8);
    	set_menu(
		({ "cider", "ale", "wine", "stew", "bread" }),
		({ "drink_in", "drink_in", "drink_in", "dine_in", "food" }),
		({ 3, 15, 7, 26, 10})
   	 );
    	set_my_mess( ({
		"The spiced cider goes down reasonable well.\n",
		"A truly powerful blend from the dwarves--they sure do know their liquor!\n",
		"The minty taste lingers on and on.\n",
		"Nice and thick just the way you nice your stew.\n",
		"The way the bread almost melts in your mouth makes you crave for another.\n"
	}) );
   	set_your_mess( ({
		"drinks his glass of spiced cider, must be under age.\n",
		"nearly gags on a powerful dwarven alchoholic mixture.\n",
		"daintily quaffs a glass of mint wine.\n",
		"nearly inhales a bowl full of stew--no manners!\n",
		"eats some buttered bread--look at all the crumbs.\n"
    	}) );
    	set_menu_short( ({
		"A glass of spiced cider",
		"A glass of dark dwarven ale",
		"A glass of Aomalian mint wine",
		"A rich bowl of stew",
		"A platter of bread and butter"
	}) );
    	set_menu_long( ({
		"A glass of spiced cider from the Golden Beers.\n",
		"A stout mug of dark dwarven ale from the Golden Beers.\n",
		"A delicate glass of Aomalian mint wine from the Golden Beers.\n",
		"A hearty bowl of stew from the Golden Beers.\n",
		"A platter of bread and butter from the Golden Beers.\n"
	}) );
}

void catch_tell(string str) {
	string a;

	if(sscanf(str, "%s enters.", a) == 1) {
		call_out("greet_player", 1, a);
	}
}

void greet_player(string player) {
	force_me("speak common");
	force_me("say Welcome traveller, please come in and make yourself at "
		"home.  Just read the menu to find what we serve here.");
	force_me("grin seductively");
}
