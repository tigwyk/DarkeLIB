// /wizards/excelsior/mon/toaster_king
// I have such freaky ideas it scares even me

#include <std.h>

inherit MONSTER;

void reset() {
	if (!present("sceptre")) new("/wizards/excelsior/obj/sceptre")->move(
		this_object() );
	if (!present("mikey") ) new("/wizards/excelsior/weapons/toaster")->move(
		this_object());
	if(present("mae-tagg")) present("mae-tagg")->remove();
	command(
"wield rock in right hand");
command("speak common");
	force_me("speak common");
}

void init() {
	::init();
	add_action("ask","ask");
}

void create() {
	object money;
	::create();
	set_name("toastmaster");
	set("id",({"toastmaster","toaster king","man"}) );
	set_level( 14 );
	set("short","Toastmaster the sewer eccentric");
	set("long","This is quite a funny little man. He appears to live all "+
		"by his lonesome deep in the sewers. Maybe he has a story to "+
		"tell. Perhaps you should say 'hi'. (see 'help communication')");
	set("race","high-elf");
	set_gender("male");
	set_body_type("human");
	set_overall_ac( 7 );
	set_combat_chance( 50 );
	add_spell("disruption bolt","$A");
	set_spell_level("disruption bolt",4);
	set_max_mp( 900 );
	set_mp( 900 );
	set_skill("chaos magic",70);
	set_skill("blunt",66);
	set_languages( ({"common","Gods-tongue","middle-english","elvish"
		"moo","cowish"}) );
	call_out( "reset",1);
	set("aggressive",(: call_other,this_object(),"check_quest":));
}

void catch_tell(string str) {
	string language
;
	if ( sscanf( str, "%*s says something in %s.",language) == 2) {
		force_me("say Sorry, I don't speak "+language+".");
		return;
	}
}

void directed_message( object from, string str ) {
	force_me("speak "+from->query_primary_language() );
	if (!this_object()->query_primary_language()) 
		force_me("speak common");
	if ( str == "hi" ) {
		force_me("say Why hello lil' fella! You may be wondering what I'm "+
			"doing down here in the sewer! Well let me tell ya, here I am "+
			"king!  On the surface people "+
			"laughed at my ambitions to change the world, but in here, I got little gremlins (they are the smartest things!) to do what ever I want "+
			"them too! Besides, I'm wanted by the New Faerie Dust police. "+
			"My best bud Mae-tagg has already been caught. In fact, "+
			"if you 'ask about mae-tagg', I may have a proposition for "+
			"ya!");
		return;
	}
	if ( str == "ask about mae-tagg" ) {
		if(present("mae-tagg")) {
			force_me("say well I would ask you to save him, but somebody "+
				"already did! hahahaha!");
			return;
		}
		force_me("say well, him and me are kind of freedom-fighter types. "+
			"This here cities under some kind o'tyranical rule, and the "+
			"forces behind it ain't from this world! Anyways, he's done gone "+
			"got himself caught. If you can free him from the New Faerie Dust "+
			"City Prision Facility (NFDCPF) and bring him back to my hiding "+
			"place here, I'll show you a secret way into the upper-class portion "+
			"of the city. Deal? Great!");
		return;
	}
}
			
int ask(string str) {
	write("Type 'say toastmaster, ask about mae-tagg'");
	return 1;
}

void kill_ob(object who,int i) {
	force_me("say joey, attack "+who->query_name() );
	::kill_ob( who, i );
}

int check_quest(object ob) {
	object who;
	if((string)ob->query_name() != "mae-tagg") return 0;
	who = ob->query_savior();
	if(!who) return 0;
	if(ob->query_saved() ) {
		command("say Oh, thank you! It's mae-tagg! Yipeee! I shall reward you now...");
		command("say If you come back later some day, I will show you a way into the "+
			"deeper parts of the city...");
		who = ob->query_savior();
			if(who->set_quest("mae-tagg")) {
		tell_object(who,
			"The toasterking pays you 11000 copper coins and gives you his sceptre as "+
			"a reward.");
		who->add_money("copper",11000);
		who->add_exp(550);
			present("sceptre",this_object())->move(who);
		if(!present("sceptre",who)) {
			message("info","You are to weak to carry the "+
				"sceptre, so it falls to the ground.",
				who);
		present("sceptre",this_object())->move(environment(this_object()));
		}
		}
			call_out("take_care",1,who,ob);
		ob->set_saved(0);
		return 0;
	}
}


void take_care(object who,object ob) {
	who->remove_follower(ob);
}
