// /wizards/excelsior/mon/ent
// the plot thickens

#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("teloll");
	set("id",({"ent","teloll"}) );
	set_level( 10 );
	set("short","Teloll, the wise old ent");
	set("long","Teloll is perhaps the oldest creature living in New Faerie "+
		"Dust. He has much to tell, and may be able to answer some of your "+
		"questions concerning New Faerie Dust. Type 'say teloll, help'.");
	set("race","ent");
	set_gender("male");
	set_body_type("ent");
	set_overall_ac( 6 );
	set_combat_chance( 80 );
	add_spell( "power word, stun","$A" );
	add_spell( "power word, blind","$A" );
	add_spell( "magic missile","$A" );
	add_spell( "burning hands","$A" );
	set_spell_level("power word, stun",3);
	set_spell_level("power word, blind",3);
	set_spell_level( "magic missile",4);
	set_spell_level( "burning hands",5);
	set_skill("magery",74);
	set_skill("conjuration",63);
	set_skill("melee",25);
	set_stats("wisdom",95);
       this_object()->set_money("silver",1500);
	set_languages( ({"treefolk","middle-english","common"}) );
}

void catch_tell(string str) {
	string language
;
	if ( sscanf( str, "%*s says something in %s.",language) == 2) {
		force_me("say Sorry, I don't speak "+language+".");
		return;
	}
}

void answer_question( string what ) {
	if ( what == "theatre" ) {
		force_me("say Well I don't know much abuot the New Faerie Dust "+
			"Theatre company, but it does have some problems. You should "+
			"check it out.");
		return;
	}
	if ( what == "government" ) {
		force_me("say Ah, yes. The government. Well lets just say that this here city "+
			"wasn't always in that bad a shape. In fact, we were prospering "+
			"until a couple 'a years ago. Thats when I felt a great evil "+
			"presence enter this city. About the same time a new mayor was "+
			"elected, non-humans started being persecuted and things basically "+
			"went down the tubes. Sigh. I'd tell you what this evil is, but "+
			"the gnomes have blocked my scrys.");
		return;
	}
	if ( what == "outcast quarter") {
		force_me("say The new mayor set out to persecute all non-humans. "+
			"He created this here outcast quarter to hold us. We don't "+
			"rise up in protest because the gnomes control our minds. "+
			"It's all I can do to allow myself free thought.");
		return;
	}
	if ( what == "gnome farms" ) {
		force_me("say The new mayor has managed to set up a sort of breeding "+
			"camp for gnomes. The gnomes are used to control the population "+
			"magically so that we don't rise up in protest against the "+
			"government. If you want to get into the gnome farms, you'll "+
			"need a key. I hear that a guard recently misplaced a key to the "+
			"farms somewhere around town square. Maybe if you can find that "+
			"one...");
		return;
	}
	if (  what == "power plant") {
		force_me("say Nobody really knows how this city produces its power, "+
			"but there is a large power plant near the top of the city.");
		return;
	}
	if ( what == "factory" ) {
		force_me("say The wealthy of New Faerie Dust own a very large factory "+
			"on the third level of the city. It is not known to the general "+
			"public what is made there, but if you want to get in I hear "+
			"it is possible to sneak in through the sewers.");
		return;
	}
	if ( what == "prison" ) {
		force_me("say Many political prisoners are kept in the New Faerie Dust "+
			"City Prison Facility. It is located over the theatre.");
		return;
	}
	if ( what == "hospital" ) {
		force_me("say The hospital is one of the most corrupt organizations "+
			"we got here. I've heared all kinds of horror stories about the "+
			"genetic "+
			"experiments they are performing on this city's general public.");
		return;
	}
	force_me("say I don't feel like telling you about that.");
}

void directed_message( object from, string str ) {
	string what;
	force_me("speak "+(string)from->query_primary_language() );
	if(!this_object()->query_primary_language())
		force_me("speak common");
	if ( str == "help" ) {
	force_me("say You can 'ask about <topic>'. See 'help communication' for "+
		"more info. The topics I can provide information about are:\n"+
		"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
		"theatre         government      outcast quarter   gnome farms\n"+
		"power plant     factory         prison            hospital\n"); 	
		return;
	}
	if ( sscanf( str, "ask about %s",what ) == 1) {
		answer_question( what );
	}
	return;
}
