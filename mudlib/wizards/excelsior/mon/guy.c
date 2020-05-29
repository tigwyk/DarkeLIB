// /wizards/excelsior/mon/guy
// an adolescent snack bar person
// now of the female variety

inherit "std/barkeep";

void create() {
	::create();
	set_name("cashier");
	set("id",({"guy","cashier","snack bar cashier"}));
	set_level( 3 );
	set("short","A young snack bar cashier");
	set("long","This is a young cashier here to help you with your "+
	"junk food needs. She points at a sign listing items they have "+
	"available. She couldn't be more then 13.");
	set("race","human");
	set_gender("female");
	set_body_type("human");
	set_overall_ac( 3 );
	set_menu( ({"popcorn","candy","soda","champaign"}),
		({"food","food","soft drink","alcoholic"}),
		({ 35,3,20,25}) );
	set_currency("gold");
	set_my_mess( ({"You take the large popcorn and quickly gulp it down.",
	"The candy bar goes quite fast- mmm! Yum!",
	"You drink the Fizzo Pop. Unfortunately, a guy next to you tells you "+
		"a funny story, and you laugh so hard you lose some of it out "+
		"your noise. It feels funny.",
	"You drink a glass of fine champaign." }) );
	set_your_mess( ({"eats some popcorn.","eats a candy bar.",
	"loses some of the soda he was drinking out his nose, making a "+
		"complete fool out of himself. Ahahahaha! What a fool!",
	"drinks a glass of fine champaign."}) );
	set_empty_container( ({"popcorn container",0,"aluminum can",
		"wine glass"}) );
}
