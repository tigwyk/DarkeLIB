
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


void create() {

  ::create();
set("short", "[20]great statue of a Cat-man");
set_name("statue");
set("long", "A large statue of a Cat-man mage, standing straight and ready
to strike at anything. There is an evil look in the statue's eyes.");
set_id( ({"statue", "mage", "demon"}));
set ("aggressice", 1);
  set_level(20);
        set_max_hp(1750);
        set_hp(1750);
  set_max_mp(3000);
  set_mp(3000);
  set_property("base mp regen", 45);
  set_property("base hp regen", 80);
  set_gender("male");
 set("race", "demon");
 set_body_type("human");
  set_property("melee damage", ([ "crushing" : 50 ]));
        set_skill("melee", 100);
  set_skill("perception", 150);
set_skill("dodge", 180);
  set_skill("blunt", 87);
  set_stats("strength", 79);
set_skill("perception", 200);
  set_skill("reverse stroke", 80);
  set_stats("wisdom", 140);
  set_skill("attack", 67);
set_skill("elementalism", 93);
set_spell_level("elemental bolt", 6);
set_spell_level("lesser elemental storm", 6);
add_spell("elemental bolt", "$A");
add_spell("lesser elemental storm");
  set_casting_chance(30);
  set_combat_chance(120);
  set_property("ambidextry", 1);
}

