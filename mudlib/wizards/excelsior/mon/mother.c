#include <std.h>
inherit MONSTER;
string state_of_child;
object in_charge;


void create() {
    ::create();
    set_name("mother");
    set("id", ({"mother","a mother","a poor mother","poor mother",
      "parent","a parent","a squalid mother","squalid mother"}) );
    set_level( 1 );
    set("short", "A squalid mother");
    set("long","She is very dirty,  and is hopelessly trying to take care "+
      "of several crying babies.  She looks very distressed.  Perhaps you " +
      "say 'hi' to her.");
    set("race","human");
    set_gender("female");
    set_body_type("human");
    state_of_child = "not created";
    in_charge = 0;
    set_overall_ac( 1 );
    set_max_hp( 70 );
    set_hp( 55 );
    set_wimpy( 50);
    set_languages( ({"common","middle-english","yin","serra","ogryn","catfolk",
    	"pix"}) );
    set_emotes(20, ({"One of the mother's babies cries.",
      "The mother whimpers."}), 1);
	seteuid(getuid());
    set_speech(20, "common", ({"can you help me?","Why don't you 'talk' to me if "+
      "you want to help."}), 0);
	call_out("reset",1);
}

void reset() {
	::reset();
	in_charge = 0;
	state_of_child = "not created";
	while(present("note")) 
		present("note")->remove();
	seteuid(getuid());
		set_primary_lang("common");
}

void ok_speech() {
    force_me("say Did I say somethin? Eeem sooree, but I don't need any help. " +
      "gooood-be.");
}

void catch_tell(string str) {
    string language,who;
    object ob;
	if ( sscanf( str, "%*s says something in %s.",language) == 2) {
		force_me("say Sorry, I don't speak "+language+".");
		return;
	}
	if(sscanf(str,"%s gives you A fine doctor's note.",who) == 1) {
		if(!who) return;
		who = lower_case(who);
		ob = present(who);
		if ( ob && ob == in_charge && 
				!(int)ob->query("child following")) {
			force_me("say Theenk you ooh theenk you. I don't have meech "+
				"ta geeve yoo,  bute I can spare dees here key I found "+
				"een soome trash. Ee don't know what its for, so its "+
				"yoors. Eem so Thankful meester, thank ee tank ee!");
			write("\nThe mother hands you the strange key. The key seems to"+
				"produce a strange magical force that makes you feel stronger!");
			new("/wizards/excelsior/obj/farm_key")->move(in_charge) ;
			if(!present("farm key",ob)) {
				write("The key is to heavy and it falls to the ground.");
				new("/wizards/excelsior/obj/farm_key")->move(environment());
			}
		} else {
			force_me("say I heev no idea whi ye is gevin dis to me.");
		}
	}
}

int speech(object who) {
    if ( state_of_child == "not created" ) {
	force_me("say Hello.  I really need you heelp.  Me youngest son here 'as " +
	  "fallin extermenely eel, am I need you to take 'im tooo dee doocter. I'd be "+
	  "takin 'im meself, but eef I mees une day of work I might'n be fired, and as I be "+
	  "'avin 6 other kids toooo loook eefter,  I can 'na take dee chance.");
	message("info","\nIt is all you can do to keep yourself from breaking out in laughter at "+
	  "her accent.  However,  if you want to,  you can 'agree' to help her.",who);
	return 1;
    }
    ok_speech();
    return 1;
}


int agree(object who) {
	object child;
    if ( state_of_child == "not created" ) {
		if(present("child")) present("child")->remove();
		force_me("say theeenk yee, here ees me child.  Please 'urry,"+
			" ee is very eel.");
		if(!present("child")) {
			child = new("wizards/excelsior/mon/baby");
		} else { child = present("child"); }
		child->move(environment());
		state_of_child = "alive";
		who->set("child following",1);
		who->add_follower(child);
		force_me("say Oh--- une last thing.  Pleeeze bring back soome kond of note "+
		  "from dee dooctor telling me 'ow 'ee is.  And thonk you much.");
		message("info","The mother tells her son to behave you and then hands him over.",
			who);
		message("info","The mother gives "+ this_player()->query_cap_name() + 
			" control of one of her children." ,environment(), ({this_player()}) );
		in_charge = who;
		return 1;
    }
    if ( state_of_child == "cured" || state_of_child == "alive" ||
     	 state_of_child == "dead" ) {
		ok_speech();
		return 1;
    }
}

void directed_message(object ob, string what ) {
	force_me("speak "+(string)ob->query_primary_lang());
	if(!query_primary_lang()) force_me("speak common");
	if(what == "agree") agree(ob);
	if(what == "hi" || what == "help") speech(ob);
	return;
}
