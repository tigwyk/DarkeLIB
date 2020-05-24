//  Wizard:   Khojem
//  Monster:  wolf
//  File:     wolf.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  int mod;
  ::create();
    set_name("silvery wolf");
    set_id( ({ "silvery wolf", "wolf" }) );
    mod=(random(2));
    set_level((9+mod));
if (mod == 0) set_short("[9]A silvery wolf");
else 
if (mod == 1) set_short("[10]A silvery wolf");
else
if (mod == 2) set_short("[11]A silvery wolf");

else set_short("[12]A silvery wolf");
    set_long("The wolf has human-like intelligence as it looks deeply into your "+
      "soul.  Its fur radiates a silvery glow and its snout is surrounded by "+
      "aged, bushy gray hairs."
      );
    set("race", "dog");
    set_body_type("quadruped");
    set_gender("female");
    set_stats("intelligence", 70);
    set_property("melee damage", ([ "cutting" : 20, "impaling" : 10 ]));
    set_overall_ac(15);
    set_combat_chance(86);
    set_spell_level("magic missile",4);
    add_spell("magic missile","$A");
    set_spell_level("mad rage",2);
    add_spell("mad rage","$ME");
    set_skill("conjuration",70);
    set_skill("illusionism",70);
    set_skill("magery",80);
    set_skill("concentrate",70);
    set_skill("perception",90);
    set_wimpy(0);
    set_emotes(20,({
      "A wolf barks and snaps viciously at your feet.",
      "A salivating wolf lungs at you.",
      "A wolf leaps at you and knocks you into the stone wall.",
      "A wolf welps and retreats back a few feet.",
    }),1);    
    force_me("use concentrate");
 }

int query_kho_mon() { return 1;}

