// /wizards/excelsior/mon/moo_cow

#include <std.h>

#define WHAT_I_HAVE ({"/wizards/excelsior/obj/fixer","/wizards/excelsior/obj/explosive","/wizards/excelsior/obj/level","/wizards/excelsior/obj/transporter"})

inherit "std/monster";

void create() {
	int i;
	int ran,level;
	string gender;
	::create();
	set_name("gremlin");
	set("id",({"gremlin","sewer gremlin"}) );
	level = random( 9 ) + 5;
	set_level( level );
		set("short","Sewer gremlin");
	set("long","This is a strange creature indeed. You have heard about them "+
		"before, a strange race of gremlins who have made their life in the "+
		"sewers of New Faerie Dust. Actually, they are somewhat of a legend.  "+
		"The story goes that they were shunned from the surface because of their "+
		"ugliness and vulgar habits, so they retreated to the underworld to "+
		"further develop their technologies. About the size of a short human, "+
		"they are no easy opponent in battle. You pause to boggle at what these "+
		"ugly little creatures are and where they came from.");
	set("race","cgremlin");
	ran = random( 2 );
	if ( ran == 1 )  { gender = "male"; }
	else { gender = "female"; }
	set_gender( gender );
	set_body_type("human");
	set_overall_ac( level );
	set_fingers( 0 );
	set_stats( "intelligence", 100 );
	set_languages( ({"common","yin","cowish","moo","farsi",
		"middle-english","undead-tongue","middle-english"}) );
	set_emotes(30 , ({"The gremlin grumbles.","The sewer gremlin recites 500 digits "+
		"of pi.","The gremlin is smarter then you. You suck.",  
		"The gremlin recites one of the many mystical and "+
			"ancient magical tomes it has memorized.",
		"The gremlin calculates how to store magical energy "+
		"in an object to create an explosive."}),0);
	set_property( "melee damage",(["crushing":20]) );
	set_melee_damage((["crushing":20,"cutting":15]));
	set_combat_chance(75);
	set_skill("prayer",55);
	set_skill("illusionism",75);
	set_skill("necromancy",40);
	set_skill("attack",60);
	set_stats("wisdom",89);
	set_skill("melee",65);
	add_spell("mirror image","$(ME)");
	add_spell("drain life","$A");
	add_spell("cure light wounds","$(ME)");
	set_spell_level("drain life",2);
	set_spell_level("mirror image",4);
	set_spell_level("cure light wounds",3);
	i = sizeof( WHAT_I_HAVE );
	new(WHAT_I_HAVE[ random(i) ] )->move( this_object() );
}
