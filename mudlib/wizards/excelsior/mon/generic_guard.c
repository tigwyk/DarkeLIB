// /wizards/excelsior/mon/generic_guard


inherit "std/monster";

int spear,sword,helmet,chainmail;

void create() {
	::create();
	set_name("guard");
	set("id",({"guard","a guard"}) );
	set_level( 12 );
	set_gender("male");
	set("short","A guard at his post");
	set("long","It appears that though the New Faerie Dust Government "+
		"has taken the position that all non-humans are inferior, they are "+
		"not below standing on guard duty for various places.");
	set("race","oger");
	set_body_type("human");
	set_overall_ac(3);
	set_skill("melee",55);
	set_skill("blade",60);
	set_skill("two handed polearm",61);
	set_skill("parry",75);
}

void make_spear() {
	if (present("spear",this_object())) return;
	new("/wizards/excelsior/weapons/spear")->move(this_object());
	spear = 1;
}

void make_sword() {
	if (present("sword",this_object())) return;
	new("/wizards/excelsior/weapons/short_sword")->move(this_object());
	sword = 1;
}

void make_helmet() {
if (present("helmet",this_object())) return;
	new("/wizards/excelsior/armor/guard_helmet")->move(this_object());
	helmet = 1;
}

void make_chainmail() {
if (present("chainmail",this_object())) return;
	new("/wizards/excelsior/armor/guard_chainmail")->move(this_object());
	chainmail = 1;
}

void reset() {
	::reset();
	if (chainmail && !present("chainmail",this_object()))
		new("/wizards/excelsior/armor/guard_chainmail")->move(this_object());
	if (helmet && !present("helmet",this_object()))
		new("/wizards/excelsior/armor/guard_helmet")->move(this_object());
	if (sword && !present("short sword",this_object()))
		new("/wizards/excelsior/weapons/short_sword")->move(this_object());
	if (spear && !present("spear",this_object()))
		new("/wizards/excelsior/weapons/spear")->move(this_object());
	if (query_money("copper") < 100) set_money("copper",780);
	force_me("wield spear in right hand and left hand");
	force_me("wield sword in right hand");
	force_me("wear helmet");
	force_me("wear chainmail");
}

void kill_ob(object ob,int i) {
	if (present("guard")) {	
		present("guard")->kill_ob(ob,0);
	}
	::kill_ob(ob,i);
}
