// /wizards/excelsior/mon/mae-tagg
// bring this fella to the toaster king and you got yourself some quest 
// points
inherit "std/monster";

int saved;
object savior;

void create() {
	::create();
	set_name("mae-tagg");
	set("id",({"mae-tagg","man","prisoner"}));
	set_level(6);
	set("short","Mae-tagg the revolutionary");
	set("long","This is mae-tagg the revolutionary. He looks like he "+
		"needs some help. Perhaps if you told him you would 'help' him "+
		"he would tell you more.");
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(4);
	set_languages(({"middle-english","common","yin","serra","elvish","toasterish"}));
	set_combat_chance(0);
	add_spell("harm","$A");
	set_spell_level("harm",4);
	set_skill("prayer",65);
	add_spell("cure light wounds","$ME");
	set_spell_level("cure light wounds",4);
	reset();
}

void reset() {
	::reset();
	if(saved) return;
	saved = 0;
	savior = 0;
}

void catch_tell(string str) {
	if(sscanf(str,"%*s says something in %*s") == 2) {
		force_me("speak common");
		force_me("say Sorry, I don't understand you.");
	}
}

void directed_message(object from,string str) {
	force_me("speak "+(string)from->query_primary_language());
	if(!this_object()->query_primary_language()) 
		force_me("speak common");
	if(strlen(str) >= 4 && str[0..3] == "help") {
		force_me("say Have you come to free me? I am a rebel here in this "+
			"city. I want to make the city how it was. I have a friend who will "+
			"protect me, he lives in the sewers. If you can take me to him, "+
			"tell me 'yes'. I'm sure you will be rewarded for your deeds.");
		return;
	}
	if(strlen(str) >= 3 && str[0..2] == "yes") {
		force_me("say Oh, thankyou! I will follow you back to my friend in the "+
			"sewers. You rock.");
		saved = 1;
		savior = from;
		if(environment() != environment(from)) {
			message("info","You must be in the same room if you want mae-tagg "+
				"to follow you.",from);
			return;
		}
		from->add_follower(this_object());
		message("info","Mae-tagg starts following you.",from);
		return;
	}
}

int query_saved() { return saved; }

object query_savior() { return savior; }

void set_saved(int i) {
	saved = i;
}
