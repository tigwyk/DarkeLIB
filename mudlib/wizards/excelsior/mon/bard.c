// /wizards/excelsior/mon/bard
// Excelsior 6-28-96

inherit "/std/monster";

int lute;

void reset() {
	::reset();
	lute = 0;
}

void create() {
	::create();
	set_name("bard");
	set("id",({"bard","falsath"}));
	set_level(2);
	set("short","Falsath the bard");
	set("long","This is Falsath the bard. If you have a music paper you would like "+
		"him to examine, you can 'show' him the the '<music paper>'. If you "+
		"just want to talk, you can tell him to 'talk'.")
;
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(3);
	set_languages(({"common","middle-english","elvish"}));
	reset();
}

void init() {
	::init();
	add_action("show","show");
}

int show(string str) {
	object ob;
	ob = present(str,this_player());
	if(!ob) {
		write("You don't have a "+str+"!");
		return 1;
	}
	if(!(int)ob->query_property("music paper")) {
		notify_fail("That isn't a music paper!\n");
		return 0;
	}
	set_primary_lang((string)this_player()->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	command("say Why, this is the music to "+(string)ob->query_song()+"! "+
		"It goes like this: "+(string)ob->query_notes() );
	command("bow");
	return 1;
}

void directed_message(object from,string str) {
	if(str != "talk") return;
	set_primary_lang((string)from->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	force_me("say Why, I'm Falsath the bard. I used to work well, but "+
		"demand for a bard has gone way down. Sigh... so now I live here! "+
		"Isn't it great! I just wish I had a picture to hang on "+
		"my wall! YES OYES! Can you give me a picture?");
	return;
}

void catch_tell(string str) {
	string who;
	object from;
	if(sscanf(str,"%s gives you a picture",who) != 1) return;
	who = lower_case(who);
	from = find_player(who);
	if(!from) return;
	set_primary_lang((string)from->query_primary_lang());
	if(!query_primary_lang()) set_primary_lang("common");
	if(!present("picture",this_object())) return;
	if(!(int)present("picture",this_object())->is_right_picture()) {
		command("say I don't like this picture.");
		command("drop picture");
		return;
	}
	command("say oh! Thank you!!! YES YES YES JESUS NOG THIS ROCKS! Here, "+
		"I'll give you this lute to repay you.");
	message("info","Falsath jumps for joy.",environment());
	if(lute) {
		command("say well, actually, I'd give you my lute, but I've already given it away!");
		message("other_action","Falsath shrugs.",environment());
		return;
	}
	message("info","Falsath drops his a lute onto the ground.",environment());
	new("/wizards/excelsior/obj/lute")->move(environment());
	return;
}
