// /wizards/excelsior/rooms/backstage_under
// gothic in an industrial sense

#include <std.h>
#include <ansi.h>

#define POSSIBLE_NOTES ({"a","b","c","d","e","f","g","a#","b#","c#","d#","e#","f#","g#","ab","bb","cb","db","eb","fb","gb"})
#define POSSIBLE_SONGS ({"sccggaag","sedcdeeedddegg"})
	

inherit "std/room";

string song;
int *index_of_song;

void reset() {
	int bla;
	::reset();
	if (!present("phantom")) new("/wizards/excelsior/mon/phantom")->move(
		this_object() );
	song = "s";
	index_of_song = allocate( sizeof( POSSIBLE_SONGS ) );
	bla = sizeof( index_of_song );
	bla--;
	while ( bla > -1 ) {
		index_of_song[bla] = sizeof( index_of_song ) + 2;
		bla--;
	}
}

void init() {
	::init();
	add_action("organ","play");
}

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",1);
	set("short","In the lair of the phantom");
	set("long","You are under the stage of the New Faerie Dust Theatre "+
		"Company. Here, it appears some strange twisted soul has built "+
		"himself some sort of strangely American but twistedly gothic "+
		"abode. There is an arched passageway leading north. The walls "+
		"are cold stone but there a tapestries and paintings hung on the "+
		"walls to make the place more cozy. The torches and large pipe organ "+
		"diminish the total attempted affect of a well kept apartment though.");
	set_items( (["tapestries":"They are extremely detailed pictures of past "+
			"stars at this theatre.",
		"paintings":"Old posters from past productions.",
		"torches":"The are firmly fastened to the wall.",
	"walls":"They are covered with old theatre posters.",
		"passageway":"It leads to the north.",
		({"pipe organ","organ"}):"You could probably 'play' a note on it. "+
			"Use # for sharps and b for flats. If you are playing a song "+
			"and would like to start over, type 'play reset'." ]) );
	set_exits( (["up":"/wizards/excelsior/rooms/center_stage",
		"north":"/wizards/excelsior/rooms/basement" ]) );
	reset();
}

int organ(string note) {
	int check_index,bob;
	object coins;
	string ansi_message;
	if ( note == "reset" ) {
		song = "s";
		write("You can now start your song over.");
		return 1;
	}
	if (member_array( note, POSSIBLE_NOTES ) == -1 ) {
		write("You obviously have no musical talent in you, for that note "+
			"does not exist.");
		return 1;
	}
	else
	{
	if ((string)this_player()->getenv("TERM") == "ansi") {
		write(RED+"You play a "+HIB+note);
		}
		else
		{
			write("You play a '"+note+"'");
		}
		tell_room( this_object(), this_player()->query_cap_name()+" plays "+
			"organ.", ({ this_player() }) );
		song += note;
		check_index = member_array( song, POSSIBLE_SONGS );
		if (  check_index != -1 ) {
			if ( member_array( check_index, index_of_song ) == -1 ) {
				index_of_song[check_index] = check_index;
				write("A small drawer in the side of the organ opens up. In it "+
					"is a cash prize for playing a song correctly.");
				coins = new("/std/obj/coins");
			bob = check_index + 1;
				coins->set_money("gold",513*bob);
				coins->move( this_object() );
				return 1;
			}
			write("Sorry, the reward for that song has already been obtained.");
			song = "s";
		}
		return 1;
	}
}
