// /wizards/excelsior/mon/galran

inherit "/std/monster";

void reset() {
	::reset();
	if(!present("staff")) {
		new("/wizards/excelsior/weapons/galran_staff")->move(this_object());
	command("wield staff in right hand and left hand");
}}

int query_undead() {return 1;}

void create() {
	::create();
	set_name("galran");
	set("id",({"galran","ghost","ghost of galran"}));
	set_level(20);
	set("undead",1);
	set("short","the ghost of galran");;
	set("long","This spirit is obviously the leader of the group and sits apon "+
		"the throne. Could it be that this is the legendary thief Galran, still "+
		"guarding the jewel of power? Perhaps you could 'ask about jewel'.");
	set("race","human");
	set_body_type("human");
	set_gender("male");
	set_overall_ac(24);
	set_melee_damage((["holy":15]));
	set_combat_chance(70);
	add_spell("clone","$(ME)");
	add_spell("wrath of god","$A");
	add_spell("heal","$(ME)");
	add_spell("smite","$A");
	set_spell_level("clone",1);
	set_spell_level("wrath of god",3);
	set_spell_level("heal",6);
	set_spell_level("smite",6);
	set_money("gold",175);
	set_skill("attack",100);
	set_skill("parry",90);
	set_skill("dodge",90);
	set_skill("two handed staff",95);
	set_skill("worship of k'thach",90);
	set_skill("prayer",93);
	set_skill("magery",90);
	set_property("magic resistance",70);
	set_languages( ({"common","undead-tongue","middle-english","rel","rachk",
		"hisaaa","mountainspeak"}));
	reset();
}

void question() {
	command("say well actually I have that chest sealed closed right now. "+
		"If you want to look inside just tell me to open it.");
}

void apology() {
	command("say sorry fella, but somebody stole that jewel from me after I "+
		"died several years ago. Shrug I wonder where it is now. ");
}

void directed_message(object from,string what) {
	string thing;
	set_primary_lang((string)from->query_primary_lang());
	if(!query_primary_lang()) 
		set_primary_lang("common");
	if(what[0..3] == "open") {
			force_me("say ok, now you can open it!");
			environment()->set_open();
			return;
	}
	if(sscanf(what,"ask about %s",thing) != 1) return;
	switch(thing) {
		case "jewel":
			force_me("say You mean the Crystal of Karen? The jewel of power? "+
				"why, I stole that from the visiting ruler ruler of South "+
				"Cape! I stashed it in this here very chest! Why don't you ask "+
				"about this chest here!");
			break;
		case "chest":
			question();
			break;
	}
}

void init() {
	::init();
	add_action("ask","ask");
}

void ask() {
	notify_fail("See 'help communication'.\n");
	return 0;
}
	
