// /wizards/excelsior/rooms/pipe
// climb the pipe, or you may fall and get hurt.

#include <std.h>

inherit ROOM;
void warning( object who ) {
	tell_object( who, "You are losing your grip, soon you will fall." );
    call_out("warning",random(10));
}

void fall_down_go_boom(object who) {
	if(!present(who)) return;
	tell_object(who, "Your fingers cannot take this physical exertion anymore. "+
		"you fall.\nA\n A\n  A\n   A\n    A\n     A\n      H\n       H\n    "+
		"    H\n         H\n          H\n           H\n            H\n     "+
		"        !\n              !\n               !\n                !\n "+
		"                !\n"+
		"You have fallen to the lot below.");
	tell_room( this_object(),"Oh no, "+who->query_cap_name()+" cannot hold on any "+
		"longer and falls.",who);
	who->add_hp(-40 - random(50) );
	who->move_player("/wizards/excelsior/rooms/empty_lot.c");
}

void falling_time(object *players) {
	int n,strength,nu,ni;
	n = sizeof(players);
	n--;
	while (n >= 0) {
		strength = players[n]->query_stats("strength");
		nu = 3 + random(3);
		ni = strength/nu;
		call_out( "fall_down_go_boom",ni,players[n] );
		n--;
	}
}
	
void init() {
	object *players;
	int n,strength;
	::init();
	players = all_inventory( this_object() );
	n = sizeof( players );
	while(n--) {
		if ( !living( players[n] ) ) {
			players[n] = 0;
			call_out("warning",10,players[n]);
		}
	}
	if (!players) return;
	falling_time(players);
}

void create() {
	::create();
	set_property("light",0);
	set_property("indoors",0);
	set("short","On a drainpipe");
	set("long","You have your way onto a drainpipe on the side of the "+
		"theatre buildings. It is very scary up this high, and you wonder "+
		"how you manage to get yourself into these predicaments. In fact, "+
		"if you don't climb now, you may just fall and hurt yourself. To your "+
		"left is a window you could enter, and to your right is a really cute blue bird. "+
		"As you stare at this bird dumbfoundedly, your fingers begin to slip...");
	set_items( (["window":"Type 'window' to enter it.",
		"bird":"It is incredibly cute, but really it is just a time wasting "+
			"device to try and get you to fall. The gods are such practical "+
			"jokers. Hahahahaha!" ]) );
	set_exits( (["window":"/wizards/excelsior/rooms/dressing_room",
		"climb":"/wizards/excelsior/rooms/ledge" ]) );
}
