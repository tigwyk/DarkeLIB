#include "/adm/include/spell.h"
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","call lightning");
    set_property("skill","conjuration");
    set_property("casting time",8);
    set_property("base mp cost",42);
    set_property("dev cost",52);
    set_property("fast dev cost",140);
    set_property("spell level", 12);
    set_property("moon","luna");
    set_property("caster message","You cast call lightning.");
    set_property("target observer message", "");
    set_property("target message","You see some storm clouds gather above you...");
    set_property("observer message","$C concentrates intently.");
    set_property("spell type", ({ "damage" }));
    set_property("damage multiplier", 6);
    set_property("damage types", ([ "electricity" : 30, "electricity #2" : 30 ]));
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("no target", 1);
    set_property("prereq", "lightning bolt");
    return;
}

void info() {
message("help",
"This spell can call a lightning bolt to strike the target ANYWHERE ON "
"THE MUD!!!!!!  You must scry the target first.\n"
"Syntax: cast *3 call lightning",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(!(at = (object)caster->query("scry"))) {
    message("info", "You must scry the target first ('help spell scry').",
          caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(time() > (int)caster->query("scry time")) {
    message("info", "Your scry has expired.",
          caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) at = caster;
  message("info", "Due to the powerful nature of this spell, "+
    "you must re-scry the target before casting again.", caster);
  caster->set("scry", 0);
  message("info", "Some storm clouds gather above...",
    ET);
  delayed_call("zap_me", 4, at, caster, power);
  return;
}

void zap_me(object at, object caster, int power) {
  if(!at || !caster) return;
  message("info", "%^YELLOW%^%^BOLD%^Suddenly, a HUGE bolt of lightning "+
        "strikes you!!!", at);
  message("info", "%^YELLOW%^%^BOLD%^Suddenly, a HUGE golt of lightning "+
        "strikes "+TQN+"!", ET,
        ({ at }));
  ::spell_func(caster, at, power, 0, 0);
  remove();
  return;
}

