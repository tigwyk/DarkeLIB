/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   object ob;

   ::create();
   set_name("lich");
   set("id", ({"lich", "evil lich", "lich_to_start_invasion"}) );
   set_level(40);
   set_property("enhance criticals",-5);
   set_max_hp(10000);
   set_hp(10000);
   set("short", "evil lich");
   set("long",
   "The horrible creature before you is the most feared of all undead, the "
   "lich.  The living corpses of powerful wizards, liches retain their "
   "magical skills they acquired during their mortal lives.  This particular "
   "lich is clothed in fancy garments that are torn and rotted.  Every once "
   "in a while he laughs a loud, evil laugh that echoes in the dungeons.",
   );
   set("race", "lich");
   set_gender("male");
   set_money("mithril", 100+(random(25)));
   set_body_type("human");
   set_overall_ac(120);
   set_skill("illusionism", 175);
   set_skill("conjuration", 175);
   set_skill("necromancy", 175);
   set_skill("concentrate", 175);
   set_languages( ({"common"}) );
   set_property("enhance critical", -2);
   set_combat_chance(90);
   add_spell("fireball", "$A");
   set_spell_level("fireball", 6);
   add_spell("ice dagger", "$A");
   set_spell_level("ice dagger", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
   add_spell("drain life", "$A");
   set_spell_level("drain life", 6);
   add_spell("cold blast", "$A");
   set_spell_level("cold blast", 6);
   add_spell("decay", "$A");
   set_spell_level("decay", 6);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   set_emotes(5, ({
               "The lich eyes you suspiciously.",
               "The lich looks you up and down.",
               "The lich gives you a once-over and laughs.",
               "The lich mutters, \"Foolish mortal he was...\"",
               "The lich throws his head back and cackles maniacally.",
                   }), 0);
   set_achats(20, ({
               "The lich shouts, \"You will die a thousand deaths, foolish mortal!\"",
               "The lich shouts, \"You will suffer the fate of Rufus Tenderfoot!\"",
               "The lich shouts, \"You cannot defeat me!  I am immortal!\"",
                   }) );
   new(WEAP_PATH+"lichdggr")->move(this_object());
   force_me("wield dagger in right hand");
   force_me("use concentrate");
}
 
void catch_tell(string str) {
   string a, b;
   object tp, ob;
   int flag;

   flag = 0;
   if(sscanf(str, "%s soul%s", a, b) == 2)
      flag = 1;
   if(sscanf(str, "%s rufus%s", a, b) == 2)
      flag = 1;
   if(sscanf(str, "%s Rufus%s", a, b) == 2)
      flag = 1;
   if(flag == 1) {
      message("info", 
"\nThe lich speaks in a deep, booming voice.  \"Rufus, that fool.  He dared\n"+
"to cross me, so I stole his greatest possession - his soul.  Bring me\n"+
"the Elixir of Youth and I will restore his life.\"\n",
                environment(this_object()), this_object());
      flag = 0;
   }
 
   if(sscanf(str, "%s gives you %s", a, b) == 2) {
      a = lower_case(a);
      tp = present(a, environment(this_object()));
      if(!tp) return;
      ob = present("elixir_of_youth", this_object());
      if(ob) {
         message("info", 
"\nThe lich speaks: \"Give me that!  Finally, I thought I would never have\n"+
"this again.  Here is the soul of Rufus Tenderfoot, you pathetic mortal.\"\n",
                environment(this_object()), this_object());
         force_me("drink elixir");
         new(MISC_PATH+"rufsoul")->move(this_object());
         force_me("drop magic globe");
         message("info", 
"The undead creature continues: \"Now leave my sight before I decide to\n"+
"crush you like the scrawny insect you are!  Begone!\"\n",
                environment(this_object()), this_object());
      }
   }

   if(sscanf(str, "%s enters.", a) == 1) {
      a = lower_case(a);
      tp = present(a, environment(this_object()));
      if(!tp) return;
      force_me("cast *6 curse at "+a);
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));

   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc1"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc2"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc3"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc4"));
             
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns4"));
   new("/d/camps/catacombs/mon/giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns5"));

   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew3"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew5"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew7"));
   new("/d/camps/catacombs/mon/giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew9"))
   }
}

void die(object ob) {
   object ob1;

   message("shout", "%^BOLD%^%^BLUE%^Evil Lich shouts:%^RESET%^ "+
"
Wretched mortals!  You have won this battle, but my destruction shall not "+
"have been in vain!  Unleash my undead hordes upon the realms!  Destroy the "+
"vagabonds, my loyal minions!", users());
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/db_square"));

   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc1"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc2"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc3"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbcc4"));
             
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns2"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns4"));
   new(MON_PATH+"giant_skeleton")->move(find_object_or_load("/d/daybreak/room/dbns5"));

   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew3"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew5"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew7"));
   new(MON_PATH+"giant_mummy")->move(find_object_or_load("/d/daybreak/room/dbew9"));

   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns1"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew10"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbew1"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw1"));

   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw2"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbbw3"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));
   ob1 = new(MON_PATH+"goldskel");
   ob1->set_moving(1);
   ob1->set_speed(10);
   ob1->move(find_object_or_load("/d/daybreak/room/dbns2"));

   write_file("/wizards/duridian/logs/lich.log",
      "Evil Lich died "+ctime(time())+".\n");
   ::die();
}

