//  Wizard:   Khojem
//  Monster:  demi-dragon
//  File:     demi-dragon.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
void slam_door();

void init() {
  string zstr;
  int i,lvl;
  object *inv;
   ::init();
  force_me("cast *4 explosive fireball");
  delayed_call("slam_door", 4);
  inv = all_inventory(environment(this_object()));
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      lvl = (int)inv[i]->query_level(); 
      if(inv[i] != this_object())
      write_file("/d/khojem/log/demi-dragon.log",
      "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}
 
void create() {
   object ob;
   ::create();
   set_name("demi-dragon");
   set("id", ({"dragon", "demi-dragon", "kho_mob"}) );
   set_level(30);
   set_short("[30]demi-dragon");
   set_long("The demi-dragon is huge and can barely stand erect in "
     "the vault room.  Spawned from the Ethereals' experiments in "
     "racial construction he has lived many millennia.  His physical "
     "appearance is very dragon-like, but you detect a cross of some "
     "humanoid traits.  The demi-dragon's skin is heavily scaled, his "
     "eyes burn red, and his tail is broad at the base, but quickly "
     "narrows to a spindley shape with broad-boney scales at its tip.  "
     "A ridge of spiked, thorny scales run up the center of his back, "
     "his ears are small and pointed, and his glowing-red eyes reveal "
     "a great intelligence as it measures you as a potential prey.\n\n"
     "Yet, the demi-dragon's wings are greatly depreciated making "
     "flight impossible, he stands erect on his hind legs, and his "
     "forelegs are developed much like a very strong Storm-giant.  " 
     "What should be long claws on each leg are now boney protrusions "
     "from the limb.\n\nIt appears apparent that the Earl of Vo'Sangor "
     "has captured this beast and keeps it prisoner here to protect "
     "his treasures from unwelcome adventurers like yourself."
   );
  set_max_hp(4000);
  set_hp(4000);
   set_exp(800000);
   set("race", "demi-dragon");
   set_gender("male");
   set_body_type("winged-humanoid");
   set_skill("conjuration", 90);
   set_skill("concentrate", 100);
   set_languages( ({"common"}) );
  set_melee_damage( (["crushing" : 40, "cutting" : 20, "fire" : 30 ]) );
  set_property("magic resistance",99);
  set_skill("martial arts",30);
  set_skill("resist stun",99);
  set_combat_chance(110);
  set_property("enhance criticals",-2);
  set_overall_ac(160);
  set_property("weakness","water");
  set_property("weakness","ice");
  add_spell("explosive fireball", "$A");
  set_spell_level("explosive fireball", 4);
  set_emotes(5, ({
         "The demi-dragon grins broadly and his eyes narrow.",
         "The demi-dragon grins broadly and his eyes narrow.",
         "The demi-dragon rotates his girth in the room and suddenly, "
           "playfully takes a swing at you with one arm.",
         "Smoke fumes from the demi-dragon's broad nostrils.",
         "Smoke fumes from the demi-dragon's broad nostrils.",
         "A short burst of flame and smoke emits from the "
           "demi-dragron's rear as he farts.",
         "The demi-dragon's eyes narrow and glow a bright red  "
           "as he gauges your abilities",
         "The demi-dragon's eyes narrow and glow a bright red "
           "as he gauges your abilities",
  }),0);
   force_me("use concentrate");
}

int query_kho_mon() { return 1;}

void slam_door() {
  message("info","The demi-dragon reaches an arm out "
    "towards the door.",environment(this_object()));
  force_me("close brass door");
  return;
}

void catch_tell(string str) {
  string who, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/demi-dragon.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/demi-dragon.log",
      "*** Player Kill:  "+who+"\t\t\t"+ctime(time())+"\n");
  }
  return;
}

void die() {
  write_file("/d/khojem/log/demi-dragon.log",
    ">>> Demi-Dragon died \t\t\t"+ctime(time())+"\n");
   ::die();
}

