// /wizards/excelsior/mon/juggler
// Excelsior 7/1/96

#include <std.h>

inherit MONSTER;

int given;

void reset() {
	::reset();
	if(!present("torch"))
		new("/std/obj/torch")->move(this_object());
	if(!present("knife")) {
		new("/wizards/excelsior/weapons/juggler_knife")->move(this_object());
		command("wield knife in right hand");
	}
	if(!present("knife 2")) {
		new("/wizards/excelsior/weapons/juggler_knife")->move(this_object());
		command("wield knife in left hand");
	}
	given = 0;
}

void create() {
	::create();
	set_name("juggler");
	set("id",({"juggler","joker","live entertainment","entertainment",
			"joker the juggler","juggler the joker","Joker"}));
	set_level(16);
	set("short","Joker the Juggler");
	set("long","This is Joker the jugggler, providing live entertainment "+
		"to the people here at the market.  Not only is he a master juggler, "+
		"but a master illusionist as well. If you want to talk to him, you "+
		"can tell him to. He is very good.");
	set("race","high-man");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(19);
	set_combat_chance(30);
	add_spell("invisibility","$(ME)");
	add_spell("darkness","$A");
	add_spell("blur","$(ME)");
	add_spell("mirror image","$(ME)");
	set_spell_level("invisibility",3);
	set_spell_level("darkness",4);
	set_spell_level("blur",3);
	set_spell_level("mirror image",2);
	set_skill("knife",83);
	set_skill("attack",85);
	set_skill("illusionism",79);
	set_skill("parry",70);
	set_skill("dodge",70);
	set_languages(({"middle-english","common","yin","serra","orcish"}));
	set_emotes(30,({"The juggler tosses one under his leg.","The juggler "+
		"tosses an object behind his back.","The juggler juggles %^YELLOW%^%^BOLD%^"+
		"torches%^RESET%^.","The juggler juggles knives.","Shoot! He dropped one.",
		"The juggler switches to juggling clubs.","Joker juggles 4 objects at once!",
		"Joker juggles %^BOLD%^%^RED%^5%^RESET%^ objects at once!"}),0);
	reset();
}

void catch_tell(string str) {
	string who;
	object ob,ob2;
	if(sscanf(str,"%s gives you A delicious pie.",who) == 1) {
		ob = present(lower_case(who));
		if(!ob) return;
		ob2 = present("pie",this_object());
		if(!ob2) return;
		set_primary_lang((string)ob->query_primary_lang());
		if(!query_primary_lang()) set_primary_lang("common");
		if(!ob2->is_right_pie()) {
			command("say This pie sucks.");
			return;
		}
		command("say Yes! This is an ExCeLlEnT pIe! I could never thank you "+
			"enough.\n\n\n\nBut I'll try! Here, take this juggling club "+
			"as a token of my esteem.");
		if(given > 5) {
			command("say well, I'd give you a juggling club but I seem to have given "+
				"my last one away!");
			message("other_action","The juggler shrugs."
,
				environment(),({this_object()}));
			return;
		}
		message("other_action","Joker tosses a juggling club onto the ground."
,
			environment(),({this_object()}));
		new("/wizards/excelsior/obj/juggling_club")->move(environment());
		given++;
	}
}

void directed_message(object from,string what) {
	set_primary_lang((string)from->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	if(what[0..3] == "talk") {
		force_me("say Well, I've been juggling as long as I can remember. "+
			"I'd really like to try expanding into pies though- you know, "+
			"taking pies in the face etc. You think you could give me a pie?");
	}
}
