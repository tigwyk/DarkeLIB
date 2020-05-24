//  Wizard:   Khojem
//  Monster:  sand urchin
//  File:     sand_urchin.c

#include <std.h>

inherit MONSTER;

create() {
  int    mod;
  ::create();
    set_name("sand urchin");
    set_id( ({ "sand urchin","urchin" }) );
    mod = random(3);
    set_level(5);
    set_short("[5]sand urchin");
    set_long("The sand urchin rests here deeply rooted in the sand.  "+
      "The urchin is a plant-like creature with long, spiny thorns that "+
      "bristle and quake as you approach it."
      );
    set("race", "plant");
    set_gender("neuter");
    set_body_type("sphere");
    set_skill("melee",0);
    set_skill("dodge",0);
    set_skill("parry",0);
    set_stats("intelligence", 80);
    set_stats("wisdom", 90);
    set_stats("strength",40);
    set_stats("dexterity",20);
    set_wimpy(0);
    set_alignment(-20);
    set_emotes(5, ({
	  "The sand urchin bristles its long spines.",
	  "The sand urchin sends out a high, pitched whine."
	}),1);
	set_class("mage");
	set_casting_chance(0);
	set_combat_chance(95);
	add_spell("magic missile","$A");
	set_spell_level("magic missile",(5+mod));
	add_spell("fireball","$A");
	set_spell_level("fireball",(2+mod));
	add_spell("ice dagger","$A");
	set_spell_level("ice dagger",(mod));
	set_skill("conjuration",((4+mod)*5));
	add_spell("blur","$ME");
	set_spell_level("blur",2);
	set_skill("illusionism",((4+mod)*5));
}
