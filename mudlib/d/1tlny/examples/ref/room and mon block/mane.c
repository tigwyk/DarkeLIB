/* Monster By: Zortek for DarkeMud
 * Date:       031596
 * File:       mane.c
 * Location:   /wizards/mon/
 * Used in:    /wizards/room/path*
 * Power:      Low for Domain (10+)
 * Notes:      Should be used in groups
 */
#include <std.h>
inherit MONSTER;
int only_players(object who);

void init() {
  int x;
  ::init();
  x = only_players(this_player());
  if (x) force_me("kill "+this_player()->query_name());
} 
void create() {
   int lev;
   ::create();
   lev = random(5)+5;
   set_property("zor_mon", 1);
   set_name("mane");
   set("id", ({"mane"}) );
   set_level(lev);
   set("short", "a sly mane");
   set("long", @LONG
This is a small and sleek devilish creature with black oily skin
and short stringy hair.  This creature looks sly and small, but its
bite may be worse than its bark.  The flames licking its claws looks
a bit unnerving.
LONG
);
   set("race", "devil");
   set_gender("neuter");
   set_alignment(-1*lev*25);
   set_money("copper", random(lev*100)+123);
   set_languages( ({"common","devilish"}) );
   set_combat_chance(75);
   set_casting_chance(55);

   set_skill("conjuration", random(lev*10)+125);
   add_spell("burning hands", "$A");
   set_spell_level("burning hands", random(3)+3);

   set_skill("magery", random(lev*10)+125);
   add_spell("fire shield", "$(ME)");
   set_spell_level("fire shield", random(3)+3);


   set_body_type("devil");
   set_emotes(5, ({
      "A mane peers at you.",
      "A mane kicks your ankle.",
      "A mane begins to dance and chant.",
      "A mane shudders and speaks in tongues.",
    }), 0);
   set_achats(15, ({
      "A mane claws at your face.",
      "A mane jumps back from your attack.",
      "A mane hisses at you.",
    }) );
  set_property("melee damage", ([ "fire" : 25, ]));
  set_speed(100);
  set_moving(1);
}
//---------------------------------------------------------
/* The Manes are cold blooded killers.  They kill for sport
 * and pleasure.  They will; however, not combat other
 * monsters except on a fumble (Standard Devil)
 * Manes take special delite in killing seraphs, high-men,
 * and sprites, but almost always ignore wraiths.
 */
int only_players(object who) {
  int x = random(100);
  if(who->query_npc()) return 0;
  if(wizardp(who)) return 0;
  if(who->is_player()) {
    switch( (string)who->query_level() ) {
      case 0..2:  return 0;
      case 3..5:  if(x<5)  return 1; break;
      case 6..7:  if(x<10) return 1; break;
      case 8..10: if(x<15) return 1; break;
      case 11..13:if(x<20) return 1; break;
      case 14..16:if(x<25) return 1; break;
      case 17..19:if(x<30) return 1; break;
      case 20..22:if(x<35) return 1; break;
      case 23..25:if(x<40) return 1; break;
      case 26..28:if(x<45) return 1; break;
      case 29..31:if(x<50) return 1; break;
      case 32..35:if(x<60) return 1; break;
      default: return 1;
    }
  }
  else {
    return 0;
  }
  return 0;
}
