//           Maxwell's Underground Mud Library
//                  River Monster

#include <std.h>
#include "under.h"
inherit MONSTER;
inherit UNEQP;

object money,mob;
string *river_rooms;
string here;
object *targets,*dest;
mixed *inv;
int picked_target,y,rp,pause;

create() {
    ::create();
   set_name("Trechin");
   set_id( ({ "Trechin","trechin","monster" }) );
   set_short("[25]nasty mold covered Trechin");
   set_level(25);
   set("long", "The Trechin is coverd in foul smelling mold. You can see "
    "drool running out from the corner of her razor sharp mouth. The "
    "drool drips down and bursts into small clouds of white acidic ash.\n");
   set_gender("female");
   set("race", "River Trechin");
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("merperson");
   set_exp(400000);
   set_overall_ac(25);
   set("gang bang", 0);
   set_emotes(10,
     ({ "The Trechin sloshes the water around her.",
     "The Trechin eyes you evily.",
     "The Trechin grinds her teeth.",}),0 );
   set_achats(50,
     ({ "Trechin loses her balance.",
       "Trechin grunts.",
       "Trechin spreads her jaws wickedly.",}) );
// Spell Code
    set_combat_chance(80);
    add_spell("ice dagger", "$A");
    add_spell("fireball", "$A");
    set_spell_level("ice dagger", 6);
    set_spell_level("fireball", 6);   
// Skills For Spells/Weapons
    set_skill("conjuration",75);
    set_skill("two handed blunt",110);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+200));
    money->move(this_object());
//Equipment Code
    mob = this_object();
    wield_hand = "right hand";
//Misc
    set_moving(1); 
    set_speed(60);
    set("aggressive",(: call_other,this_object(), "no_other_monsters" :) );
    mob = this_object();
    river_rooms = ({ UNDER+"dm17a",UNDER+"dm17b",UNDER+"dm17c",UNDER+"dm17d"
                    ,UNDER+"dm17e",UNDER+"dm17f",UNDER+"dm17g",UNDER+"dm17a"
                    ,UNDER+"dm17h",UNDER+"dm17i",UNDER+"dm17j",UNDER+"dm17a"
                    ,UNDER+"dm17k",UNDER+"dm17l",UNDER+"dm17m",UNDER+"dm17a"
                    ,UNDER+"dm17n",UNDER+"dm17o",UNDER+"dm17p",UNDER+"dm17"
                    ,UNDER+"dm18",UNDER+"dm19",UNDER+"16",UNDER+"46"
                    ,UNDER+"dm47"});    
    pause = 1;
}
void heart_beat(){
   ::heart_beat();
  
   if( random(100) < 10 && environment()
       && sizeof(mob->query_attackers()) != 0 ){
      here = file_name(environment());
      targets = (mob->query_attackers());
      if(member_array(here,river_rooms) != -1){
        picked_target = random(sizeof(targets));
      if(present(targets[picked_target]) && pause == 1){
         y = 0;
         while(y < (sizeof(river_rooms)) ){
           rp = random(sizeof(river_rooms));
           inv = all_inventory(find_object_or_load(river_rooms[rp])); 
           dest = filter_array(inv,"is_player");
           if(sizeof(dest) == 0){
             if(here != river_rooms[rp]){
               pause = 3;
               tell_object(targets[picked_target],"\nSomething wraps around "
               "your legs! You are roughly yanked under the surface of the "
               "water!!\n\nYou are flung out of the water in another part "
               "of the river!");
               tell_room(environment(targets[picked_target]),
               targets[picked_target]->query_cap_name()+" is suddenly yanked "
               "under the water! All that remains behind is a small frothy "
               "wave!\n",targets[picked_target]);
               targets[picked_target]->move(river_rooms[rp]);
               call_out("follow_player",10,targets[picked_target]);
               y = (sizeof(river_rooms));                       }
             }
             y = y + 1;
          }

       }
     }
    if(pause != 1)
      pause = pause - 1;    
   }
}
int follow_player(object who){
    if( member_array(file_name(environment(who)),river_rooms) != -1){
       tell_room(environment(this_object()),"The Trechin dives under the "
         "waves!\n");
       tell_room(environment(who),"\nThe water begins to bubble around "
       "you..\nA nasty acid drenched Trechin rises out of the water!!!\n");
       this_object()->move(environment(who));
       this_object()->restart_heart_beat();
       return 1;
    }
}
int no_other_monsters(object who) {
  if(who->is_player() || who->is_pet()) return 1;
    else return 0;
}
void die(object who) {
int current;
object master_room;
 if(this_object()->query_property("master_room") != 0){
   master_room = (this_object()->query_property("master_room"));
   current = (master_room->query_property("dead"));
   (master_room)->set_property("dead",(current+1));
 }
  tell_room(environment(this_object()),
    "Trechin thrashes about and collapses into the water!");
  ::die(who);
  return;

}


