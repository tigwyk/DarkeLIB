// /wizards/excelsior/mon/police_man

#include <std.h>

inherit MONSTER;

void reset() {
	::reset();
	if (!present("baton")) 
		new("/wizards/excelsior/weapons/police_baton")->move( this_object());
	if (!present("short sword"))
		new("/wizards/excelsior/weapons/short_sword")->move(this_object());
	if (!present("uniform"))
		new("/wizards/excelsior/armor/police_uniform")->move(this_object());
	force_me("wield baton in right hand");
	force_me("wield sword in left hand");
	force_me("wear uniform");
}

void create() {
	::create();
	set_name("police man");
	set("id",({"police man","man","police"}) );
	set_level( 8 );
	set("short","A uniformed police man");
	set("long","This is one of New Faerie Dust's finest. He is standing here "+
		"doing his job. NFD is a bit ahead of its time in that it has created a special "+ 
	"armed force to try and control the cities rampant crime. "+
	"They 'police' the city, hence the name, 'police men'");
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac( 5 );
	set_skill("blade",60);
	set_skill("blunt",59);
	set_skill("dodge",62);
	set_emotes(22,({"The police man blows his whistle.","The police man reads you "+
		"your rights.","The police man threatens you with arrest."}),1);
	call_out("reset",1);
}
