// /wizards/excelsior/rooms/snack_bar
// it always seems like my rooms are more complicated then they have to 
// be. This snack bar is only open at night
// Excelsior

inherit "std/room";

string open;
object guy;
int bring_back;

void reset() {
	::reset();
	if (!present("guy")) new("/wizards/excelsior/mon/guy")->move( 
		this_object());
	guy = present("guy");
}

void init() {
	::init();
	add_action("read_menu","read");
	if (!query_night()) {
		guy = present("guy");
		open = "closed";
		if ( guy ) {
			guy->remove();
			open = "closed";
			bring_back = 1;
		}
	}
	else if ( guy && !present(guy) && bring_back == 1) {
		new("/wizards/excelsior/mon/guy")->move(this_object());
		bring_back = 0;
		open = "open";
	}
	else if (!present("guy")) open = "closed";
}

void create() {
	::create();
	this_object()->reset();
	set_property("light",2);
	set_property("indoors",1);
	set("short","At the theatre pub");
	open = "open";
	set("day long","This is the theatre pub. Here they sell a "+
		"variety of beverages and drinks at an affordable price. "+
		"In fact, when someone smart enough comes along, "+
		"they may even think up a creative name for this place, like maybe, oh, the snack bar! "+
		"This place may even have a few alcoholic beverages. There is "+
		"a menu over the counter. It is too bad however that this "+
		"snack bar is only open at night when theatre goers are here. "+
		"You do not see any theatre goers right now. Damnation!");
	set("night long","There is a long line of people here waiting to "+
		"buy snacks at the pub. Many of them are rich and fat. "+
		"It disgusts you that these people could be so fat while just "+
		"outside people are starving. A menu over the counter here "+
		"tells you what there is to buy. You can't wait to see "+
		"what they got.");
	set_items( (["theatre goers":"You don't see them during the day.",
		"people":"Many are fat. You realize that the food here "+
		"might be high in calories. 'Bah! Forget my diet!' you "+
		"think, 'I want some artificial butter on my popcorn!'",
		"menu":"You might be able to 'read' it, but that's a long "+
		"shot."]) );
	set_exits( (["east":"/wizards/excelsior/rooms/theatre"]) );
}

int read_menu(string str) {
	object ob;
	if (str != "menu") {
		notify_fail("Read what?");
		return 0;
	}
	ob = new("/wizards/excelsior/mon/guy");
	write("-------------------------------------------------\n"+
" Popcorn..............................."+(int)ob->get_price("popcorn")+"\n"+
" Candy Bar............................."+(int)ob->get_price("candy")+"\n"+
" Fizzo Soda Pop........................"+(int)ob->get_price("soda")+"\n"+
" McCloud's Dry Champaign..............."+(int)ob->get_price("champaign")+
"\n Simply type 'buy <item>' to purchase something\n"+
" \n"+
" We accept gold only\n"+
" We are currently "+open);
	ob->remove();
	return 1;
}
