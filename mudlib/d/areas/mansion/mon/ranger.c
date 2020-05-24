// ranger

#include "mansion.h"

inherit MONSTER;

create() {
  ::create();
    set_name("ranger");
    set_id( ({ "ranger" }) );
    set_short("[18]elven ranger");
    set("race", "wild-elf");
    set_gender("male");
    set_long("You see an elite elven ranger.  He is clothed in "+
        "light armour and eyes you warily as he readies his "+
        "weapon cautiously.");
    set_body_type("human");
    set_level(18);
    set_skill("melee", 50);
    set_skill("dodge", 90);
    set_skill("parry", 80);
    set_exp(300000);
    set_overall_ac(40);
    set_stats("strength", 200);
    set_stats("dexterity", 200);
    set_max_hp(1500);
    set_hp(1500);
    set_languages(({"common", "elvish"}));
    set_lang_prof("common",10);
    set_lang_prof("wild-elvish",10);
    set_property("handedness", "right hand");
    new(A1WEP+"slayer")->
      move(this_object());
    new(A1ARM+"armour")->
      move(this_object());
    new("/d/damned/virtual/studded-leather-pants.armour")->
      move(this_object());
    force_me("wield sword in right hand");
    force_me("wear armour");
    force_me("wear pants");
   set_emotes(5, ({
                   "The ranger snickers.",
                   "The ranger looks around the grave.",
                   }), 0);
    set_speech(10,"common",({
          "Sure, I knew a few wouldn't make it out alive.",
          "All soldiers need to be tested.",
          "At least the scouts died a lot quicker than that poor "+
          "dumb alchemist.",
        }),0);
}
