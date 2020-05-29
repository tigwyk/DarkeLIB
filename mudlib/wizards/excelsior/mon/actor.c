// /wizards/excelsior/mon/actor
// a taste of Shakespeare

inherit "std/monster";
void reset() {
	::reset();
	if (!present("sword")) {
	new("/wizards/excelsior/weapons/fencing_sword")->move(this_object());
	force_me("wield sword in right hand");
	}
	force_me("wield sword in right hand");
	force_me("wear outfit");
}
void init() {
	::init();
	add_action("shit","bog");
}

void shit() {
	force_me( "wield sword in right hand");
	force_me( "wear outfit" );
}

void create() {
	object weapon,armor;
	::create();
	set_name("actor");
	set("id",({"actor","guy"}) );
	set_stats("strength",80);
	set_skill("blade",15);
	set_level( 2 );
	set("short","A bad actor");
	set("long","This is a young actor just starting his career. He is "+
		"pretty bad.");
	this_object()->set_money("copper",100);
	set("race","human");
	set_gender("male");
	set_body_type("human");	
	set_overall_ac( 2 );
	set_languages( ({"common"}) );
	set_speech( 45,"common",({"O Romeo, Romeo! Where for art thou Romeo?",
	"What light through yonder window breaks?","When shall we three "+
	"meet again? In thunder, lightning, or in rain?","Is this a dagger "+
	"which I see before me...?","Et tu, Brute?","Once more unto the "+
	"breach, dear friends, once more...","To be or not to be- that is "+
	"the question.","The better part of valour is discretion...","A "+
	"horse! a horse! My kingdom for a horse!","How sharper than a "+
	"serpents tooth it is to have a thankless child.","What angel wakes "+
	"me from my flowery bed?","Lord, what fools mortals be!","Alas, "+
	"poor Yorick, I knew him Horatio..."}),0);
	set_stats("strength",80);
	new("/wizards/excelsior/weapons/fencing_sword")->move(this_object());
	force_me("wield sword in right hand");
	armor = new("std/armour");
	armor->set_name("clothes");
	armor->set("id",({"outfit","clothes","renaissance clothes"}));
	armor->set("short","A renaissance outfit");
	armor->set("long","This is an entire renaissance outfit. It looks "+
		"like "+
		"it will provide a small amount of protection.");
	armor->set_type("body armor");
	armor->set_ac(2);
	armor->set_limbs(({ "head","left arm","right arm","torso","right leg",
		"left leg"}) );
	armor->set_weight(82);
	armor->set_value(30);
	armor->move(this_object());
	force_me("wear outfit");
	reset();
	call_out("shit",1);
}

