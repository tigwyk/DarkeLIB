
#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

int is_zor_mon() { return 1; }
init() {
  if( this_player()->query_race() == "devil" ) {
    force_me("kill "+this_player()->query_name());
  }
}
create() {
  ::create();
    set_name("criegan");
    set_id( ({ "criegan", "guardian", "Guardian Criegan" }) );
    set_level(20);
    set_short("[20]Guardian Criegan");
    set_long(@LONG
Creigan is a frail old man tired and worn by many seasons.  His hair
is a stark white, whispy and unkempt.  His crystal blue eyes are sad
and hint of tears.
LONG
);
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_alignment(500);
    set_languages( ({ "common", "undead-tongue", "devilish" }) );
    set_lang_prof("common",10);
    set_lang_prof("undead-tongue",10);
    set_lang_prof("devilish",10);
    set_emotes(5, ({
    "Criegan sobs quietly.",
    "Criegan mumbles something about the canyon.",
    "Criegan mumbles inaudibly.",
    "Criegan looks at you and appears to almost smile.",
    "Criegan shakes his head and looks at the ground.",
    "Criegan turns around quickly....then shakes his head.",
    "Criegan mutters something reguarding evil.",
    "Criegan appears startled to see you.",
	}),1);
	set_class("fighter");
        set_overall_ac(75);
        set_casting_chance(100);
	set_combat_chance(80);
	add_spell("blur","$ME");
	set_spell_level("blur",5);
	set_skill("illusionism",100);
	add_spell("true heal","$(ME)");
	set_spell_level("true heal",6);
        add_spell("harm", "$A");
        set_spell_level("harm", 6);
	set_skill("prayer",150);
        set("aggressive", 0 );
}
void catch_tell(string str) {
  string a, b, lang;
  object tp, ob;

  if(sscanf(str, "%*s says something in %s.", lang) == 2) {
    say_this("I don't understand "+lang+".  Please speak in common.");
    return;
  }
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    a = lower_case(a);
    tp = present(a, environment(this_object()));
    if(!tp) return;
    ob = present("criegan_quest_ob", this_object());
    if(!ob) {
      write(@WRONG
Why do you give me this?  I do not have need of such; however, if you
will donate it correctly it may help support the cause.
WRONG
);
      force_me("drop all");
      printf("Have you discovered the mystery of Muerta Canyon (y/n)?");
      input_to("mystery_question");
      return;
   }
   ob->remove();
#if 0
   if(!tp->set_quest("Canyon Mystery")) {
      write(@DUPLICATE
You have already discovered the mystery of Muerta Canyon.  While your
diligence and patience is appreciated, you are not elegible for further
acknowledgement.
DUPLICATE
);
     return;
   }
#endif
   if(!this_player()->query_property("guardian1")) {
//   force_me("shout Footest--"+(string)this_player()->query_cap_name()+" quest test.");
     return;
   }
   write(@DONEIT
Criegan smiles at you and says:  You have faced great peril and earned
acknowledgement and reward.  I have guarded the entrance to Muerta Canyon
since we felt the first ripple in the fabric of reality.

You are now elegible to join the Guardians of the Gate; however, membership
may have its rewards...it is also a great responsibility.  You will be
required to keep the purity of the mystery and help protect this entrance.
DONEIT
);
   printf("Do you accept the Oath of the Guardians?");
   input_to("do_oath");
   return;
  }
}
void mystery_question(string str) {
    int x;
    str = lower_case(str);
    switch(str) {
        case "y" :
        case "yes" :
           printf("Very well, precisely what is the mystery?");
           input_to("mystery_question2");
           return;
        default:
           x=random(10);
           switch(x) {
            case 0 :
             write("Seek out the old hag, she has some insight.");
              break;
            case 1 :
              write("Find the Tome of Abomination...but don't read it.");
              break;
            case 2 :
              write("Locate the Spawning Pool....it contains many secrets.");
              break;
            case 3 :
              write("Obtain the Gem of Itrius...and banish it.");
              break;
            default :
              write("Beware the temptations...lest you will sacrifice your soul.");
              break;
           }
    }
}
void mystery_question2(string str) {
    string one,two;
    if(sscanf(str, "%sgateway to hell%s", one, two) ) {
      if(this_player()->query_property("muerta1")) {
         write("You are telling me nothing new.");
         return;
      }
      if(!this_player()->query_property("mystery1") ) {
         write(@UNWORTHY
You speak bold words; however, I can see in your eyes and hear
in the tone of your voice that you have not experienced what
you speak of...perhaps you should listen less to the words of
others and tell me words you believe in your heart!
UNWORTHY
);
         return;
      }
      write(@CORRECT
You are very correct; however, your knowledge and understanding
has just scratched the surface.  I can enlighten you no further.
The next step towards enlightenment shall be found within the
influence of the Tome of Abominations.  By bond, I can tell you
no more...But beware, read the book only when you are ready.
CORRECT
);
      write("DEBUG:  ADD_EXP HERE");
      this_player()->remove_property("mystery1");
      this_player()->set_property("muerta1", 1);
      return;
    }
    if(this_player()->query_property("muerta1")) {
       write(@FORGOT
Apparently, you have forgotten the mystery you once knew.  Seek
out your lost knowldege and return when you remember.
FORGOT
);
       write("DEBUG:  RM_EXP HERE");
       this_player()->remove_property("muerta1");
       return;
    }
    write("You are NOT correct.");
    write("DEBUG: RM_EXP (minor) HERE");
    return;
}

void do_oath(string str) {
   write("This is oath function");
// force_me("shout A new Guardian of the Gate has been inducted.");
   return;
}
void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
    (sscanf(cmd, "%smystery%s",p1, p2) == 2)){
     write("Quest information");
      say("Criegan mumbles something to "+who);
    return;
  }
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
