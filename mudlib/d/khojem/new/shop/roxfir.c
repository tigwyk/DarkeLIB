//  Wizard:   Khojem
//  Monster:  Wood-Elf Whore
//  File:     whore.c

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

void init() {
  ::init();
  add_action("go_feel","feel");
  add_action("go_feel","grope");
  add_action("go_feel","caress");
  add_action("go_feel","grab");
  add_action("go_feel","fuck");
  add_action("go_feel","kiss");
  add_action("do_look","look");
}
 
void create() {
  object money;
  ::create();
    set_name("Rox'fir");
    set_id( ({ "whore","prostitute", "wood-elf whore", "wood-elf prostitute",
      "vixen", "wood-elf vixen", "Rox'fir", "rox'fir" }) );
    set_level(4);
    set_short("wood-elf vixen");
    set_long("For a wood-elf... Rox'fir is not that bad looking.  Her smooth, "+
      "creamy skin is almost porcelain-like.  For an elf she has some ample "+
      "features in just the right places.  She certainly is not modest "+
      "about showing off her body!"
      );
    set("race", "wood-elf");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 10]));
    set_skill("melee", 20);
    set_skill("dodge", 20);
    set_stats("dexterity", 90);
    set_stats("intelligence", 100);
    set_skill("perception",70);
    set_wimpy(50);
    set_alignment(-100);
    set_languages(({"common", "elvish", "drow", "middle-english" }));
    set_lang_prof("elvish",10);
    set_lang_prof("drow",8);
    set_lang_prof("middle-english",8);
    new("/d/khojem/new/armor/thong")->move(this_object());
    force_me("wear thong");
    new("/d/khojem/new/armor/chemise")->move(this_object());
    force_me("wear chemise");
    set_emotes(1, ({
	  "The vixen looks longingly at you.",
	  "The vixen repositions herself in the chair.",
	  "The vixen nibbles on your ear.",
	  "The vixen looks at you and slowly caresses her lips with her tongue.",
	}),0);
    set_speech(1,"common",({ 
	  "Oh!  You're just what I've been waiting for!",
	  "Hey, stud!  Buy me a drink and come over here.",
	  "Would you like some company?",
	}),0);
}

varargs void say_this(string str, object whom) {
    string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
      >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}

int do_look(string str) {
  if(str=="thong"){
    write("You wonder why she even bothers to wear it!  The thong "+
      "is worn high on the waist and barely covers her.  You can't even see "+
      "the strap running up her ample butt cheeks.  With something like "+
      "this she seems more attired for the beach rather than a village pub.  "+
      "The elven vixen has a cute pair of dimples above her butt.");
      say(this_player()->query_cap_name()+" looks over the elf "+
        "vixen's thong.\n");
    return 1;
  }
  if(str=="chemise"){
    write("The smooth, leather chemise hangs loosely from the shoulder "+
      "and ends abruptly just below Rox'fir's firm, full bosom.  Her "+
      "slender midriff and waist are bare.  Rox'fir has an in'ee.");
    say(this_player()->query_cap_name()+" looks over the elf "+
      "vixen's chemise.\n");
    return 1;
    }
  return 0;
} 

int go_feel(string str){
  int flag, amt, steal_amt;
   
  flag = 0;
  switch(str){
    case "whore"   : flag=1; break;
    case "bitch"   : flag=1; break; 
    case "vixen"   : flag=1; break;
    case "tit"     : flag=1; break; 
    case "tits"    : flag=1; break;    
    case "breast"  : flag=1; break;
    case "hogans"  : flag=1; break; 
    case "ass"     : flag=1; break; 
    case "butt"    : flag=1; break; 
    case "legs"    : flag=1; break;
    default        :  return 0;
  }
  if(flag) {
    steal_amt = (random(50) + 10) * -1;
    amt = ((int)this_player()->query_money("gold") - steal_amt);
    if(amt < 0) {
      write("Rox'fir slaps you hard across the face.\n");
      say(this_player()->query_cap_name()+" gets slapped across the "+
        "face by Rox'fir.\n");
      return 1;
    }
    write("Rox'fir whispers in your ear that it will cost you.");
    say("Rox'fir whispers into "+this_player()->query_cap_name()+"'s ear.");
    this_player()->add_money("gold",steal_amt);
    if(!random(8)) {
      write("You notice Roxfir's hand slip out of your pocket."); 
      say("You notice Rox'fir palm something from "+
        this_player()->query_cap_name()+"'s pocket.");
    }
    return 1;
  }
}
