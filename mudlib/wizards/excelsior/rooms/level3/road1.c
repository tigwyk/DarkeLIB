// /wizards/excelsior/rooms/level3/road1

#include <std.h>
#define MONEY_TYPES ({"copper","electrum","gold","silver","mithril"})
inherit ROOM;

void init() {
	::init();
	add_action("hand","hand");
}

int hand(string str) {
	int i;
	string what;
	if(sscanf(str,"%d %s coins to beggar",i,what) != 2) {
		notify_fail("type: \"hand <amount> <type> coins to beggar\"\n");
		return 0;
	}
	if(member_array(what,MONEY_TYPES) < 0) {
		notify_fail("The beggar won't take that coin type.\n");
		return 0;
	}
	if(i = 0) i = 1;
	if(i < 0) i = -1*i;
	switch(what) {
		case "silver":
			if(i > 40) i = 0;
			break;
		case "gold":
			if(i > 15) i = 0;
			break;
		case "mithril":
			if(i > 1) i = 0;
			break;
		case "electrum":
			if(i > 30) i = 0;
			break;
		case "copper":
			if(i > 80) i = 0;
			break;
	}
	if(i) {
		write("The beggar laughs. Ha! You will have to offer a bit more than that
"+
			"to get anything out of this beggar! He still grabs the money though.");
		message("other_action","A beggar takes some of "+(string)this_player()->
			query_cap_name()+"'s money and gives nothing in return.",this_object(),
			({ this_player() }) );
		this_player()->add_money(what,-i);
		return 1;
	}
	write("The beggar laughs and whispers to you: 'Here is some advice of
mine. In "+
		"recent history there was a thief named Galran that lived under the
theatre stage. They "+
		"say he was a lover of music, he was. Seek out music papers and a bard "+
		"to interpret them for you and a large reward will be yours- in fact, "+
		"this may be the key to all of your troubles...' the beggar walks off, "+
		"minding his own business.");
		message("other_action","A beggar takes some of "+(string)this_player()->
			query_cap_name()+"'s money and whispers something to "+
			(string)this_player()->query_objective_pronoun()+".",this_object(),
			({ this_player() }) );
		this_player()->add_money(what,-i);
		return 1;
}
void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set_property("no castle",1);
	set_property("no mine",1);
	set("short","Advancing to the next level");
	set("long","You have climbed a ramp to the next level of the city. To your
"+
		"south the path you came up on goes down in this direction. Looking "+
		"around, what you hoped would be a scenic and more pleasant atmosphere "+
		"is just as dirty and poverty stricken as anywhere. All around are
beggars "+
		"begging and bothering passerbys. As you walk you try to avoid making eye
"+
		"contact with them, but several hit you up anyway. Finally you lose your
"+
		"patients and smack the next beggar to approach in the face. The beggars
seem "+
		"to leave you alone after this. You aristocratic bastard. Looking around,
"+
		"you notice you are at the entrance to some sort of open air market.");
	set_items( (["ramp":"It is to your south. It goes down. Funny, when you
came "+
			"up it it was going the other way. Weird.",
		"beggars":"You notice one that looks rather special",
		"beggar":"This beggar looks extra poor and poverty stricken. Couldn't you
"+
			"'hand' him a little change?",
		({"air market","market","open market","open air market","open
air","open",
			"air","air open","air market open","market open air"}):"You see vendors
"+
				"lining the streets in two directions: west around a corner and east "+
				"over a bridge. How exciting, you love to shop!" ]) );
	set_exits((["east":"/wizards/excelsior/rooms/level3/bridge",
		"northwest":"/wizards/excelsior/rooms/level3/road2",
		"south":"/wizards/excelsior/rooms/street6.6"]));
}
