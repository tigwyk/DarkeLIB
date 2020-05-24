// Head of the Elemar
// Alpha code by Mortdred, 29/6/96
#include "/adm/include/daemon.h"
#include "/adm/include/std.h"
#include "/adm/include/astronomy.h"

inherit MONSTER;

create () {
       ::create();
       set_name("Elemar");
       set_id("elemar","paradox elemental","skull");
       set_level(15);
       set_short("A skull of blue flames burns you with its' gaze");
      set_long("You look upon a divine paradox, an elemental made of many elements. Its' flaming skull glares at you within blue flames, its' torso churns with deadly acid, its' black quartz arms spin wildly in the air, ignoring all laws of motion and location, while instead of legs it stands upon a vortex of wind.");
       set_max_hp(3125);
       set_hp(3125);
       set_race("elemental");
       set_gender("flaming");
      add_limb("skull","",3125,0,25);
       add_wielding_limb("skull");
      set_melee_damage([ "fire" : 125, "disruption" : 25, "aether" : 5, "depression" : 1 ]);
       set_skill("attack",125);
       set_skill("dodge",125);
       set_skill("melee",125);
       set_property("base hp regen",25);
       set_property("enhance criticals", ([
          "fire": -25,
          "disruption": -5,
          "aether": -5,
          "cutting": -1,
          "impaling": -1,
          "slashing": -1,
          "acid": 3
        ]) );
}



