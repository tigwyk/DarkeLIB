// a warp monster
// made functional by Excelsior 4-15-96

#include <std.h>

inherit MONSTER;

void create() {
  ::create();
    set_name("warp creature");
    set_id( ({ "creature", "warp creature" }) );
    set_short("A hideous Warp Creature");
    set("race", "warp creature");
    set_long(
"This creature is absolutely hideous!  It has several arms and legs, "
"and it regards you with hundreds of multicolored eyes.  It attacks "
"without hesitation!");
    set("chase",1);
    set("aggressive", (: this_object(), "not_warp" :) );
    set_body_type("quadruped");
    add_limb("first arm", 0, 1000, 0, 4);
    add_limb("second arm", 0, 1000, 0, 4);
    add_limb("third arm", 0, 1000, 0, 4);
    add_limb("fourth arm", 0, 1000, 0, 4);
    add_limb("fifth arm", 0, 1000, 0, 4);
    add_limb("first leg", 0, 1000, 0, 4);
    add_limb("second leg", 0, 1000, 0, 4);
    add_limb("third leg", 0, 1000, 0, 4);
    add_limb("fourth leg", 0, 1000, 0, 4);
    add_limb("fifth leg", 0, 1000, 0, 4);
    add_limb("second head", "FATAL", 1000, 0, 4);
    set_level(19);
    set_stats("intelligence", 70);
    set_property("melee damage", ([ "cutting" : 45, "electricity" : 30,
          "vacuum" : 45 ]));
    set_skill("melee", 120);
    set_skill("dodge", 70);
    set_skill("parry", 80);
    set_stats("dexterity", 90);
    set_max_hp(4000);
    set_hp(4000);
    set_speed(60);
    set_moving(1);
}

 
void die(object obi) {
	object tmp,ob;
	tmp = environment();
	ob = new("/wizards/excelsior/misc/portal");
	ob->move(tmp);
	ob->setup_color();
	call_out("dissolve_portal",500,ob);
	message("info","%^RED%^With the creature dead, the reality it was controlling "+
		"becomes unstable. A portal opens up in the nexus.",tmp);
	message("info","%^BLUE%^A portal opens! It will close as soon as reality "+
		"stabalizes.",tmp);
	::die(obi);
}


