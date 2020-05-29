// /wizards/excelsior/mon/clown
// the source of all evil
inherit "/std/monster";

int have_pass;
object person;

void init() {
	::init();
	force_me("speak common");
}

void reset() {
   ::reset();
   have_pass = 1;
   if(!present("ticket")) 
   new("/wizards/excelsior/obj/ticket")->move(this_object());
   if (present("torch")) present("torch")->remove();
   new("/std/obj/torch")->move( this_object() );
}

void create() {
   ::create();
   set_name("clown");
   set("id",({"clown","a poor clown","poor clown","a clown"}) );
   set_level(4);
   set("short","A poor clown");
   set("long",
	"This is a pathetic clown who looks to be very down on his "
	"luck. You put aside your immense clownophobia and decide "
	"it would be nice to say 'hi'. After all, he was probably a very funny jester at one time .");
   set("race","human");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(3);
   set_languages( ({"common"}) );
	set_emotes(30, ({"The clown moans.","The clown mopes about "+
		"looking depressed.","The clown groans.","The clown wallows "+
		"in self pity."}),0 );
   reset();
   set("aggressive",(: call_other,this_object(),"light_torch":) );
}

void carry_out_show(string who,object person,string what) {
 force_me("speak "+person->query_primary_language());
   if ( what == "hi" ) {
   force_me("say Hello. I don't know why you'd want to talk to "
	"me I'm so pitiful. If however you want to hear the "
	"story of my woes just say yes.");
   return;
   }
   if ( what == "yes" ) {
   force_me("say Well ok.. here goes. I used to work at the "
	"New Faerie Dust Theatre Company, just down the road "
	"here.");
   tell_room( environment(this_object()),"The clown points west.",
	({this_object()}) );
   force_me("say I was the best clown this town has ever seen. "
	"I could juggle while standing on my head, fall down "
	"innumerable flights of stairs- whatever a clown was "
	"supposed to do, I did best. Say 'go on' if you want "
	"me too, because I know I'm boring you.");
   return;
   }
   if ( what == "go on" ) {
   force_me("say Everything was going well until recently, "
	"when the attendance to the theatre went way down. "
	"The richer humans just didn't want to have to come "
	"down to this level of the city. It was a couple "
	"of days ago when I got a pink slip from the manager. "
	"And the days of us clowns entertaining kings are over! We have been reduced from king's courts to dark dirty disease infested alleyways!"
	"sigghhh. Say 'more' if you wish it.");
   return;
   }
   if ( what == "more" ) {
if ( present("ticket") ) {
if ( environment( present("ticket") ) == this_object() ) have_pass = 1;
}
   if ( have_pass == 1 ) {
   force_me("say Well, so here I am now. ALL I KNOW HOW TO DO IS BE A "
	"CLOWN! AND NOW I CAN'T! IT'S NOT FAIR! HERE... TAKE THIS "
	"STUPID THEATRE TICKET! I WON'T BE NEEDING IT! DO YOU KNOW "
	"WHAT BEING A CLOWN IS REALLY LIKE?!?!? IT's NOT ALL FUN "
	"AND GAMES! IT'S HARD, DEPRESSING WORK! AHHHHHH!");
   who = lower_case(who);
	present("ticket")->move(present(who));
	message("info","The clown gives you a ticket.",present(who));
	message("info","The clown gives "+capitalize(who)+" a theatre ticket.",
		environment(),({present(who)}));
   have_pass = 0;
   }
   else {
   force_me("say Well, so here I am now. ALL I KNOW HOW TO DO IS "
	"BE A CLOWN! AND NOW I CAN'T! IT'S NOT FAIR! I'D GIVE YOU A "
	"THEATRE TICKET IF I HADN'T ALREADY GIVEN IT AWAY!\n I DON'T "
	"NEED IT! CLOWNING ISN'T ALL FUN AND GAMES! IT IS HARD, "
	"DEPRESSING WORK! AHHHHH!");
   }
   write("\nYou decide you had better be on your way before the "
	"guy really goes berserk. Besides, an intense wave of your "
	"chronic clownophobia is washing over you. This is one "
	"scary clown.");
   return;
}}

void catch_tell(string str) {
   string language,who,what;
   if ( sscanf(str,"%s says something in %s.",who,language) == 2) {
   	force_me("speak common");
   	force_me("say Sorry, I don't understand "+language+".");
   	return;
   }
}

void directed_message(object from,string str) {
	string name;
	person = from;
	name = from->query_cap_name();
	carry_out_show(name,from,str);
}

void heart_beat() {
   ::heart_beat();
   if (person != 0 ) {
	if (!present(person)) {
	  command("speak common");
	  command("yell PEOPLE DON'T NEED TO BE AFRAID OF US! OUR "
		"SOLE PURPOSE IN LIFE IS TO MAKE YOU LAUGH, AND YOU "
		"RUN AWAY! BEING A CLOWN IS _HARD WORK_ -WHY CAN'T "
		"PEOPLE UNDERSTAND THAT?");
	  force_me("extinguish torch");
	  person = 0;
}}}

int light_torch( object ob ) {
	force_me("light torch");
	return 0;
}
