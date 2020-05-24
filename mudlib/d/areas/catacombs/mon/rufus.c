/* Rufus Tenderfoot (quest npc) coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   object ob;

   ::create();
   set_name("Rufus");
   set("id", ({"man", "Rufus", "Rufus Tenderfoot", "rufus tenderfoot", "rufus"}) );
   set_level(30);
   set("short", "[30]Rufus Tenderfoot");
   set("long",
   "Before you stands Rufus Tenderfoot, the famous explorer and "
   "adventurer.  Rumors say that his soul was stolen by a lich, and that "
   "Rufus cannot leave this world until his soul is freed.  He walks the "
   "earth lifeless, almost like a zombie, devoid of any emotions, save "
   "unhappiness and despair."
   );
   set_max_hp(100000);
   set_hp(100000);
   set_overall_ac(100);
   set("race", "high-elf");
   set_gender("male");
   set_body_type("human");
   set_languages( ({"common"}) );
   force_me("speak common");
   set_speech(5, "common",
              ({ "Ohh, woe is me!",
                 "Why did I ever challenge that creature?!",
                 "Please help me!  Save me!",
                 "Retrieve my soul and I will greatly reward you!",
                 "What did I do to deserve this fate?",
                 "Please help me, worthy adventurer!",
                 "Save me from this eternal torture!  Find that lich!",
               }), 0);
   set_achats(30, ({
                    "Rufus shouts: \"Die, vile scum!\"",
                    "Rufus shouts: \"Fool!  You will die a horrible death!\"",
                    "Rufus shouts: \"You cannot defeat me!\"",
                   }) );
   ob = new(WEAP_PATH+"boneswrd");
   ob->move(this_object());
   ob->add_poisoning(5000);
   force_me("wield sword in right hand");
}
 
void catch_tell(string str) {
   object tp, ob;
   string a, b;
 
   if(sscanf(str, "%s gives you %s", a, b) == 2) {
      a = lower_case(a);
      tp = present(a, environment(this_object()));
      if(!tp) return;
      ob = present("soul_of_rufus_tenderfoot", this_object());
      if(ob) {
         if(!tp->set_quest("stolen_soul")) {
            force_me("say Thank you for helping me once again, my friend!  Farewell!");
/*            present("bone sword", this_object())->remove();*/
              this_object()->move(find_object_or_load("/wizards/duridian/workroom"));
            this_object()->remove();
            return;
         }
         tell_room(environment(this_object()),
"\nRufus takes the globe and smashes it on the ground.  A great flash of \n"+
"light blinds you for a moment, and when your vision returns, you see \n"+
"that Rufus looks stronger and that he is smiling.\n\n"+
"\"Thank you for restoring my soul, brave friend,\" he says.  \"Here is\"\n"+
"my sword, Bone Crusher.\"\n");
         present("bone sword", this_object())->move(environment(this_object()));
         tell_room(environment(this_object()),
"He leans the sword against the wall.\n\n"+
"\"This weapon will help you in fighting the undead and other evil beings.\n"+
"Keep it by your side and you will never falter.\"  He pauses.  \"I must\n"+
"go now.  Fight with honor, dear friend.\"  He runs off into the \n"+
"darkness, relieved to have regained his soul.\n");
         write("\nCongratulations!  You have solved the Stolen Soul quest!\n");
         write("You have been awarded 2000 experience points!\n");
         tp->add_exp(2000);
         present("soul_of_rufus_tenderfoot", this_object())->remove();
         this_object()->remove();
      }
   }
}

