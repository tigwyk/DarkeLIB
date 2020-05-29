// /wizards/excelsior/mon/gnome_king


inherit "std/monster";

void make_me_boots();
void make_me_medallion();

void reset() {
	::reset();
	if(!present("boots")) make_me_boots();
	if(!present("medallion")) make_me_medallion();
	if(query_money("copper") < 3000)
		set_money("copper",5500);
}

void create() {
	::create();
	set_name("absalom");
	set("id",({"gnome","a gnome","gnome king","the gnome king","absalom"}));
	set_level(16);
	set("short","Absalom the gnome king");
	set("long","This character looks as though he is incharge of these farms. "+
		"The evil that has created the misery here is a gnome himself? Satan "+
		"works in twisted ways! Maybe you could find out more by asking him "+
		"for 'help'. (If you don't know how to communicate by now you suck.)");
	set("race","gnome");
	set_gender("male");
	call_out(
"reset",1);
	set_body_type("human");
   set_overall_ac( 30 );
	set_languages(({"common","dwarvish","elvish","middle-english","yin","serra"}));
	set_combat_chance(95);
	set_skill("melee",20);
	set_stats("wisdom",97);
	set_stats("intelligence",95);
	add_spell("cure critical wounds","$(ME)");
	set_spell_level("cure critical wounds",4);
	add_spell("ice dagger","$A");
	set_spell_level("ice dagger",5);
	add_spell("magic missle","$A");
	set_spell_level("magic missle",5);
	add_spell("power word, stun","$A");
	set_spell_level("power word, stun",4);
	add_spell("elemental bolt","$A");
	set_spell_level("elemental bolt",4);
	add_spell("harm","$A");
	set_spell_level("harm",3);
	add_spell("fireball","$A");
	set_spell_level("fireball",4);
	add_spell("decay","$A");
	set_spell_level("decay",3);
	set_skill("elementalism",65);
	set_max_hp(1600);
	set_hp(1600);
	set_max_mp(5500);
	set_mp(5500);
	set_skill("prayer",83);
	set_skill("conjuration",85);
	set_skill("magery",79);
	set_skill("necromancy",74);
}

void make_me_boots() {
	object boots;
	boots = new("/std/armour");
	boots->set_name("boots");
	boots->set("id",({"gnome boots","boots"}));;
	boots->set("short","A pair of gnome boots");
	boots->set("long","This is a pair of gnome boots with pointy toes.");
	boots->set_type("boots");
	boots->set_ac(4);
	boots->set_limbs(({"right foot","left foot"}));
	boots->set_weight(93);
	boots->set_value(30);
	boots->move(this_object());
	force_me("wear boots");
}

void make_me_medallion() {
	object boots;
	boots = new("/std/armour");
	boots->set_name("medallion");
	boots->set("id",({"medallion","necklace"}));;
	boots->set("short","A gnome king's medallion");
	boots->set("long","This is the traditional medallion gnome kings in this "+
		"region have worn for centuries.");
	boots->set_type("necklace");
	boots->set_ac(6);
	boots->set_limbs(({"neck"}));
	boots->set_weight(150);
	boots->set_value(899);
	boots->move(this_object());
	force_me("wear medallion");
}

string query_element() { return "fire"; }
	
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
		force_me("say What are you doing in my gnome farms fool? If it weren't "+
			"for that it was prophesised that a stranger would enter our midst to "+
			"save us from this hell, I would have you killed. As it is, if "+
			"you wish to know of your destiny then tell me 'yes'. Otherwise, "+
			"I will take you not to be our salvation and you will be cursed "+
			"to the darkest depths of evil.");
		return;
	}
	if(strlen(str) >= 3 && str[0..2] == "yes") {
		force_me("say You may consider me a monster for what I do- breed my own "+
			"people, select which ones to keep, then use their magic to run the "+
			"city. But I was not always like this. I am forced to do it. For the "+
			"history of te gnome farms, tell me 'history'. For your quest, tell me "+
			"'quest'.");
		return;
	}
	if(strlen(str) >= 7 && str[0..6] == "history") {
		force_me("say The gnomes were in this land long before any humans. We "+
			"built the village that would latter grow into this large city. Our "+
			"magic built those immense buildings you see here. We continued to "+
			"live peacefully with the mojority humans until the new mayor, Beals E. "+
			"Bub was elected and proceeded to rewrite our city's constitution, "+
			"proclaiming himself dictator for life. He amassed a large army and "+
			"came to me saying 'either you work for me our I kill your enitre race'. "+
			"At first we resisted both but there was a very strong magical force "+
			"behind him that we couldn't defeat. So I built these farms. The "+
			"gnomes in these farms don't resist because this life is all they ever "+
			"knew. The few who try are killed on the spot. Sigh.");
		return;
	}
	if(strlen(str) >= 5 && str[0..4] == "quest") {
		force_me("say The mayor is not in control of this city. We now control him. "+
			"But there is another, greater magical force that tells me what to do. "+
			"I don't know what this force is, but it is created by a life form of "+
			"some sort, I know that much. I have surmised that its creator lives in "+
			"the city somewhere. Now, I am watched to closely by this force to "+
			"investigate it at all, but I have one close friend, Talson, who is not. "+
			"Talson is a human who has made a small fortune for himself in this city. "+
			"He lives in the upperclass neighborhood of Evergreen heights. He can "+
			"help you uncover the source of this magical power, he is one of the "+
			"most powerful mages alive today. If you accept to search out this evil, "+
			"say 'agree', otherwise 'decline'.");
		return;
	}
	if(strlen(str) >= 5 && str[0..4] == "agree") {
		force_me("say I knew you were the one! Here, give Talson this medallion "+
			"so he will know who sent you. He is then much more likely to aid "+
			"you in your quest.");
		force_me("remove medallion");
		force_me("give medallion to "+from->query_name());
		force_me("bow");
		if(present("gnome"))
			present("gnome")->force_me("bow");
		return;
	}
	if(strlen(str) >= 7 && str[0..6] == "decline") {
		force_me("say Well, I guess you are not as brave as I thought you were.");
		return;
	}
}

void kill_ob(object who,int i) {
	if(present("greater gnome")) {
		write("%^BLUE%^The other gnome present steps in to protect its king.");
		present("greater gnome")->kill_ob(who,0);
	}
	::kill_ob(who,i);
}
