//  Wizard:   Khojem
//  Monster:  Storm-Giant Whore
//  File:     bertha.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

void init() {
  ::init();
  add_action("go_feel","feel");
  add_action("go_feel","grope");
  add_action("go_feel","caress");
  add_action("go_feel","fondle");
  add_action("go_feel","grab");
  add_action("go_feel","fuck");
  add_action("go_feel","kiss");
  add_action("do_look","look");
}
 
create() {
  object money;
  ::create();
    set_name("bertha");
    set_id( ({ "whore","prostitute", "bar slut", "slut",
      "vixen", "Bertha", "bertha" }) );
    set_level(4);
    set_short("bertha, the bar slut");
    set_long("WOW!  Bertha's a big ol' gal!  For a storm-giant female she's a bit "+
      "on the LARGE size.  Ol' Bertha has seen many years workin' the docks of this "+
      "harbor.  She tries to conceal her age with loads of gaudy makeup on eyes "+
      "and cheeks.  Her tight-fitting dress has a plunging neckline that reveals "+
      "her 'bountiness'.  You'd have to be real drunk to be interested in her!"
      );
    set("race", "storm-giant");
    set_gender("female");
    set_body_type("human");
    set_overall_ac(5);
    set_property("melee damage", ([ "crushing" : 20]));
    set_languages(({"common", "stormspeak", "drow", "middle-english" }));
    set_lang_prof("common",10);
    set_lang_prof("stormspeak",10);
    set_lang_prof("drow",8);
    set_lang_prof("middle-english",8);
    set_primary_lang("common");
    new("/d/khojem/port/armor/dress")->move(this_object());
    force_me("wear dress");
    set_emotes(1, ({
	  "Bertha looks longingly at you.",
	  "Bertha repositions herself on the stool and hoists up the neckline of "+
	    "her dress.  Somehow it seems to always creep down...",
	  "Bertha flutters her long, storm-giant eyelasses at you longingly.  Yuck!",
	  "Bertha takes a smoke from her fat cigar.",
	  "Bertha burps rudely.  Ooo!  You can smell her beer breath!",
	  "Bertha takes a long pull on a tankard of ale.",
	}),0);
    set_speech(1,"common",({ 
	  "Oh!  Why hello, honey!",
	  "Hey, ya' big stud!  Com'on over here and buy me a dwinnk!",
	  "Are ya' man enough for a real woman?  I'm all the woman you can handle!",
	  "Its been a slow day, sugar.  How about you and me spend some time together?",
	}),0);
	force_me("speak common");
}

do_look(string str) {
  if(str=="dress"){
    write("You are amazed at the massive cleavage that is exposed by "+
      "Bertha's dress.  Those big ol' hogans seem to catch every loose "+
      "bit of cigar ash from Bertha's lit cigar.  The leather dress is "+
      "tight fitting and large rolls of fat form massive folds in its "+
      "fabric.  The dress is cut high along the thigh and reveals a big, "+
      "nasty wart!");
      say(this_player()->query_cap_name()+" looks over the storm-giant's "+
        "dress.\n");
    return 1;
    }
  return 0;
} 

go_feel(string str){
  int flag, amt, steal_amt;
   
  flag = 0;
  switch(str){
    case "bertha"  : flag=1; break;
    case "whore"   : flag=1; break;
    case "bitch"   : flag=1; break; 
    case "storm-giant"   : flag=1; break;
    case "tit"     : flag=1; break; 
    case "tits"    : flag=1; break;    
    case "breast"  : flag=1; break;
    case "breasts" : flag=1; break;
    case "hogans"  : flag=1; break; 
    case "ass"     : flag=1; break; 
    case "butt"    : flag=1; break; 
    case "legs"    : flag=1; break;
    case "leg"    : flag=1; break;
    default        :  return 0;
  }
  if(flag) {
    steal_amt = random(50) + 10;
    amt = ((int)this_player()->query_money("gold") - steal_amt);
    if(amt < 0) {
      write("Bertha farts and knees you hard in the groin!\n");
      say("Bertha viciously knees "+this_player()->query_cap_name()+" in the "+
        "and pivots her girth towards the bar.\n");
      return 1;
    }
    write("Bertha suddenly embraces you and lays a big, open mouth kiss on you!  "+
      "Her fat, beer bloated tongue frenches you deeply.  You are left with the "+
      "taste of ale and stale cigar smoke in your mouth.\n");
    say("Bertha lays a massive lip-lock on "+this_player()->query_cap_name()+".\n");
    this_object()->add_money("gold",steal_amt);
    steal_amt = steal_amt * -1;
    this_player()->add_money("gold",steal_amt);    
    if(random(10)==0) {
      write("You feel Bertha's hand in your pocket."); 
    }
    return 1;
  }
}

