// greater zombie

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("enourmous zombie");
   set("id", ({"zombie", "man"}) );
   set_level(18);
   set_short("An enourmous zombie");
   set("long",
   "This zombie is not quite like the rest.  He is much larger, much "+
   "more deformed, and he also looks a whole lot angrier."
   );
   set("race", "undead");
   set_gender("male");
   set_body_type("human");
   set_skill("melee", 150);
   set_skill("resist stun", 150);
   set_max_hp(1700);
   set_hp(1700);
   set_overall_ac(20);
   set_stats("strength", 180);
   set_stats("dexterity", 180);
   set_emotes(5, ({
                   "The zombie wails loudly as he reaches for you.",
                   "The zombie stumbles around.",
                   }), 0);
   set("aggressive", 1);
}
