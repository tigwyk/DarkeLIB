//           Maxwell's Underground Mud Library
//                  River Monster

#include <std.h>
#define UNDER "/wizards/maxwell/underzone/"


inherit MONSTER;
inherit "/wizards/maxwell/objects/mon/mob_eq2";

object money,mob;
string *river_rooms;
string here;
object *targets,*dest;
mixed *inv;
int picked_target,y;

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
    add_skill("conjuration",75);
    add_skill("two handed blunt",110);
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+500));
    money->move(this_object());

//Misc

    set("aggressive",0);

}
void heart_beat(){
   ::heart_beat();

   here = file_name(environment(mob));
   tell_player(find_player("maxwell"),"Entered HeartBeat "+here+"\n");   

}



