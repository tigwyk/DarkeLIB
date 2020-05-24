//  Wizard:   Khojem
//  Monster:  demi-dragon
//  File:     demi-dragon.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
 
void create() {
   object ob;
   ::create();
   set_name("demi-dragon");
   set("id", ({"dragon", "demi-dragon", "kho_mob"}) );
   set_level(30);
   set_short("[30]demi-dragon");
   set_long("The demi-dragon is huge and can barely stand erect in the vault "+
     "room.  Spawned from the Ethereals' experiments in racial construction "+
     "he has lived many millennia.  His physical appearance is very "+
     "dragon-like, but you detect a cross of some human traits.  The "+
     "demi-dragon's skin is heavily scaled, his eyes burn red, and his "+
     "tail is broad at the base, but quickly narrows to a spindley shape with "+
     "broad-boney scales at its tip.  A ridge of spiked, thorny scales run up "+
     "the center of his back, his ears are small and pointed, and his "
     "glowing-red eyes reveal a great intelligence as it measures you as a "+
     "potential prey.\n\nYet, the demi-dragon's wings are greatly "+
     "depreciated making flight impossible, he stands erect on his hind legs, "+
     "and his forelegs are developed much like a very strong Storm-giant.  "+
     "What should be long claws on each leg are now boney protrusions from the "+
     "limb.\n\n"+  
     "Regardless, of all that... it appears apparent that the Earl of "+
     "Vo'Sangor has captured this beast and keeps it captured here to "+
     "protect his treasures from unwelcome adventurers like yourself."
   );
   set_max_hp(3000);
   set_hp(3000);
   set_exp(2000000);
   set("race", "demi-dragon");
   set_gender("male");
   set_body_type("dragon");
   set_casting_chance(5);
   set_overall_ac(80);
   set_skill("conjuration", 90);
   set_skill("concentrate", 100);
   set_languages( ({"common"}) );
   set_melee_damage( ([ "crushing" : 50, "fire" : 30 ]) );
   set_combat_chance(90);
   add_spell("explosive fireball", "$A");
   set_spell_level("explosive fireball", 4);
   set_emotes(1, ({
	 "The demi-dragon grins broadly and his eyes narrow.",
	 "The demi-dragon grins broadly and his eyes narrow.",
	 "The demi-dragon rotates his girth in the room and suddenly, playfully "+
	   "takes a swing at you with one arm.",
	 "Smoke fumes from the demi-dragon's broad nostrils.",
	 "Smoke fumes from the demi-dragon's broad nostrils.",
	 "A short burst of flame and smoke emits from the demi-dragron's rear "+
	   "as he farts.",
	 "The demi-dragon's eyes narrow and glow a bright red as he gauges your "+
	   "abilities",
	 "The demi-dragon's eyes narrow and glow a bright red as he gauges your "+
	   "abilities",
	}),0);

   force_me("use concentrate");
}

int query_kho_mon() { return 1;}
