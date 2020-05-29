// /wizards/excelsior/mon/thief

#include <std.h>
#include <daemons.h>
#include <clock.h>

inherit MONSTER;

void make_me_dagger();

void reset() {
	::reset();
	if (!present("dagger"))
		make_me_dagger();
}

void create() {
	int ben;
	string race;
	::create();
	set_name("thief");
	set("id",({"thief","criminal","crook","robber"}) );
	set_level( 10 );
	set_fingers( 5 );
	set("short","A crafty little thief");
	set("long","This little thief is likely to steal from you if you don't "+
		"watch out.");
	ben = random(3);
	if (ben == 0) {
		race = "high elf";
	}
	if (ben == 1) {
		race = "human";
	}
	if (ben == 2) {
		race = "dwarf";
	}
	set("race",race);
	ben = random(2);
	if (ben) {
		race = "male";
	} else {
		race = "female";
	}
	set_gender( race );
	set_body_type("human");
	set_overall_ac( 6 );
	call_out("reset",1);
	set_skill("melee",44);
	set_skill("knife",69);
	set_skill("perception",55);
	set_skill("pick pocket",95);
	set_skill("stealth",95);
	set_skill("dodge",50);
	set_skill("parry",45);
	set_skill("reverse stroke",66);
	set_stats("dexterity",95);
	set_skill("attack",70);
	set_skill("thrown",60);
	set_class("thief");
       set_money("silver", 500);
	set("aggressive",(: call_other, this_object(),"check_attack" :) );
	call_out("reset",1);
}

int check_attack(object ob) {
	int ran;
	if((string)ob->query_name() == "thief") return 0;
	if((string)EVENTS_D->query_time_of_day() == "day") {
		ran = 7;
	}
	if((string)EVENTS_D->query_time_of_day() == "night") {
		ran = 4;
	}
	if (!ran) {
		ran = random(2)+5;
	}
	if (!random(ran)) return 1;
	return 0;
}

int check_if_living(object ob) {
	if(ob == this_object()) return 0;
	if(living(ob) && (string)ob->query_name() != "thief") return 1;
	return 0;
}

void make_me_dagger() {
	object dagger;
	dagger = new("/std/weapon");
	dagger->set_name("dagger");
	dagger->set("id",({"dagger","knife","thief's dagger"}));
	dagger->set("short","thief's dagger");
	dagger->set("long","This is a thief's dagger. It is ideal for armed "+
		"robberies.");
	dagger->set_weight(95);
	dagger->set_value(450);
	dagger->set_ac(2);
	dagger->set_wc(10,"cutting");
	dagger->set_type("knife");
	dagger->set_quality(3);
	dagger->set_throwable(1);
	dagger->move(this_object());
	force_me("wield knife in right hand");
}

void heart_beat() {
	object who,*stuff,*stuff2;
	int check,i,my_silver,your_silver;
	::heart_beat();
	if(present("coins",environment(this_object()))) 
		force_me("get coins");
	if ((string)EVENTS_D->query_time_of_day() == "day") {
		i = 3;
	} else {
		i = 2;
	}
	if (random(i) == 0) return;
	stuff2 = all_inventory( environment( this_object()));
	stuff = filter_array( stuff2, "check_if_living", this_object() );
	i = sizeof(stuff);
	if (!stuff || !i) return;
	i--;
	while ( i > -1 ) {
		if((string)stuff[i]->query_name() != "thief") {
		if(random(6) == 0)	{
			if(check > 2) return;
			force_me("use pick pocket at "+stuff[i]->query_name());
			check++;
		}}
		i--;
	}
	if (!present("knife",this_object())) return;
	if (random(31) == 0) {
		my_silver = query_money("silver");
		who = stuff[random(sizeof(stuff))];
		your_silver = who->query_money("silver");
		if(!your_silver) return;
		tell_object( who, "%^YELLOW%^%^BOLD%^The thief steals some of your "+
			"silver at knife point!" );
		tell_room(environment(this_object()),"The thief steals some of "+
			who->query_cap_name()+"'s silver at knife point!", ({who,this_object()}));
		i = random(your_silver);
		who->add_money("silver",-i);
		set_money("silver",my_silver+i);
	}
}
