//This is the child that the player is supposed to bring to the doctor

#include <std.h>

inherit "/std/monster.c";

string person;
object who_follow;

void create() {
   ::create();
   set_name("child");
   set("id",({"baby","child","a crying baby","a child"}) );
   set_level( 1 );
   set("short","A crying child");
   set("long","This child is crying for good reason- he is very sick. You better "+
      "get him to the doctor quick before he dies.  You hope it's not contageous.");
   set("race","human");
   set_gender("male");
   set_body_type("human");
   set_overall_ac( 1 );
   set_max_hp(20);
   set_hp(5);
   set_skill("dodge",1);
   set_skill("attack",1);
   set_skill("melee",1);
   set_stats("strength",1);
   set_wimpy(20);
   set_languages( ({ "common" }) );
   set_emotes(50, ({ "The child cries.","The child breaks out "+
            "in a cold sweat." }), 0);
   set_speech(20, "common" ,({"MOOOOOOMMMMM!","Don't hurt me!"}), 1);
}
