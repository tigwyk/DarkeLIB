// /wizards/excelsior/orderly.c
// a real jerk
// by excelsior

inherit "std/monster";

int times_talked;
object person;

void talk();

void init() {
   ::init();
	add_action("hit","hit");
   force_me("speak common");
}

void reset() {
   ::reset();
   times_talked = 0;
}

void create() {
	seteuid(getuid());
   ::create();
   set_name("orderly");
   set("id", ({ "orderly","nurse","a orderly","a nurse"}) );
   set_level( 3 );
   set("short","An orderly");
   set("long","This guy is smoking while people all around him "+
      "are in agony. He appears to be some sort of a male nurse, not quite a cleric. In any case, he is totally ignoring you. You should 'talk' "+
      "to him. (see 'help communication')");
   set("race","human");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(2);
   set_languages( ({"common"}) );
   set_speech(50, "common", ({"Hey, I'm sorry man!","Stop attacking me and we "+
	    "can talk!","OUCH!","Just 'give 100 silver coins to orderly'- that's "+
	    "all I ask!","Just 'give 100 silver coins to orderly'- that's "+
	    "all I ask!","I can't help you if I'm dead, man!"}),1);
   times_talked = 0;
}

int talk() {
   if (present("child")) {
      if (times_talked == 0) {
	 write("You get the orderly's attention.");
	 force_me("say What do you want man, I'm on my break! I don't "+
	    "want to 'talk' to you! Get out of here!");
	 times_talked = 1;
	 return 1;
       }
      if (times_talked == 1) {
	 write("You ask the orderly for assistance again, pointing out the fact "+
	    "the child is about to die and that it is his job to take in new "+
	    "patients...\n");
	 force_me("say Wtf did I say? I'm not going to 'talk' to you or assist you "+
	    "while I'm on my break! What is your problem? I don't care if he "+
	    "were mayor of this here hell hole, I ain't helping him while I'm on "+
	    "break! wtf fear.");
	 times_talked = 2;
	 return 1;
       }
      if (times_talked >= 2 ) {
	 write("You plead with the orderly to help the dying child, but he just "+
	    "scowls at you. You feel like you could 'hit' him!");
	 return 1;
       }
   }
   force_me("say You look fine to me! You don't need any help! "+
      "Go screw yourself.");
   return 1;
}

void catch_tell(string str) {
   int amount;
   object ob;
   string who, what;
   if ( sscanf( str, "%s gives you %d %s coins.", who, amount, what ) == 3) {
      if (present("child")) {
	 if ( what != "silver" ) {
	    force_me("say wtf? I only take GOLD coins!  Got that?");
	    force_me("give "+amount+" "+what+" coins to "+lower_case(who));
	    return;
	  }
	 if ( amount < 100 ) {
	    force_me("say 100 silver coins idiot! This just isn't enough for "+
	       "me to waste my valuable time on you.");
	    force_me("give "+amount+" "+what+" coins to "+lower_case(who));
	    return;
	  }
	 person = find_player(lower_case(who));
	 if ( this_object()->query_money("silver") >= 100  ) {
	    message( "tell" , "The orderly smartly takes the child by the hand and \n"+
	       "leads him into a back room. Time passes. The clock on the wall seems \n"+
	       "to click back two for every one it clicks forward. Tik tok tik tok tik tok. \n"+
	       "You feel that you must scream or die!-and now-again!-hark! louder ! \n"+
	       "louder! louder! louder! LOUDER! tik tok tik tok. \n", person);
	    message( "tell" , "   'Villains' you shriek, 'dissemble no more! I admit \n"+
	       "the deed!--tear up the planks!--here, here!--it is the beating of his \n"+
	       "hideous heart!' You are awakened from your literary reference by the \n"+
	       "return of the orderly. He hands you a note from the doctor like the poor\n"+
	       "mother wanted and says:\n", person);
	    force_me("say Its been a pleasure doing business with you, "+
	       who + ". Have you ever read any E.A. Poe?");
	    force_me("bow");
	    tell_room( environment( this_object() ), "The orderly takes the boy "+
	       "and returns, handing "+who +" a small note.",
	       ({this_object(),person}));
	    ob = find_living("child");
	    ob->remove();
		new("/wizards/excelsior/obj/doctors_note")->move( person );
	person->set("child following",0);
	    return;
	  }
       }
      else
	 {
	 force_me("say Thanks!");
       }
   }
}


int hit(string str) {
	if(!str || !id(str)) {
		notify_fail("Hit who?\n");
		return 0;
	}
	write("You hit the orderly! Ouch!");
	message("info",(string)this_player()->query_cap_name()+" hits the orderly! Ouch!",
	environment(),({this_player()}));
	write("The orderly says in common: Ok ok! Just 'give 100 silver to orderly', "+
		"thats all I ask!");
	return 1;
}

void directed_message(object from, string msg) {
	if(msg == "talk") talk();
}
