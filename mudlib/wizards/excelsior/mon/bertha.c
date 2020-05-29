// /wizards/excelsior/mon/bertha

#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("bertha");
	set("id",({"bertha","big bertha"}) );
	set_level( 5 );
	set("short","Big Bertha the theatre manager");
	set("long","This is Big Bertha. She runs the New Faerie Dust Theatre "+
		"company. She looks very stressed out. Maybe you should say hi to "+
		"her. ('say bertha, hi')");
	set("race","human");
	set_gender("female");
	set_body_type("human");
	set_overall_ac( 6 );
	set_exp( 1 );
       set_money("silver",500);
	set_skill("melee",50);
	set_languages( ({"common","middle-english","yin","elvish","serra"}) );
}

void character_info( string who ) {
	if ( who == "clown" ) {
		force_me("say I had a really good clown here not to far back but "+
			"the theatre met financial troubles and I had to let someone "+
			"go. Being as clowns aren't very popular around here- not "+
			"to mention the fact that he was just scary to be around- "+
			"he seemed to be the perfect canidate. He was pretty pissed "+
			"about it and he threatened the whole city with ruin, but "+
			"whats a clown going to do anyway?");
			return;
		}
	if ( who == "actor" ) {
		force_me("say Our lead actor is really really bad, but he's the only "+
			"guy I could find to work here. All the good actors of New Faerie "+
			"Dust have moved away.");
		return;
	}
	if ( who == "actress" ) {
		force_me("say She was a damn good actress in her time, but recently she's "+
			"gone mentally insane and locked herself in her dressing room. I'd "+
			"open the door and knock some sense into her, but I've lost my key "+
			"to her room. Its gotta be somewhere in this theatre!");
		return;
	}
	if ( who == "stage director" ) {
		force_me("say Ok, so my stage director was always a little strange, but "+
			"now he's just flat out gone. Don't ask me what happened to him.");
		return;
	}
}

void catch_tell( string str ) {
	string language;
	if ( sscanf( str, "%*s says something in %s.", language) == 2 ) {
		force_me("speak common");
		force_me("say Sorry, I don't speak "+language+".");
		return;
	}
}

void directed_message( object from, string line ) {
	string who;
	force_me("speak common");
	if ( line == "hi" ) {
		force_me("say I really don't have time to talk right now fella. "+
			"I am really stressed out here. My theatre is a mess. My "+
			"lead actress has gone insane and locked herself in her "+
			"dressing room, my lead actor is incredibly bad, my stage "+
			"director has disapeared, and I had to fire one of my star "+
			"clowns. If you want to ask me about any of these characters "+
			"communicate to me 'ask about <character>'. See help "+
			"communication for more info, I don't have the time to explain "+
			"it to you.");
			return;
		}
		if ( sscanf( line, "ask about %s", who ) == 1 ) {
			character_info( who );
			return;
		}
	}
