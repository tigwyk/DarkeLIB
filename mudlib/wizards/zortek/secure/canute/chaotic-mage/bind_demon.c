inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","bind demon");
    set_property("skill","chaos magic");
    set_property("casting time",11);
    set_property("base mp cost",35);
    set_property("dev cost",36);
    set_property("fast dev cost",102);
    set_property("spell level", 8);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast bind demon at $T.");
    set_property("target message","");
    set_property("observer message","$C casts bind demon at $T.");
    set_property("spell type",({ "protection" }));
    set_property("protection types", ([ "impaling" : 7, "crushing" : 7,
          "cutting" : 7, "disruption" : 7, "holy" : -4,
          "fire" : 5, "cold" : 5, "electricity" : 4,
          "impact" : 5 ]));
    set_property("stack key", "demon armour");
    set_property("stack num", 3);
    set_property("duration", 720);
    set_property("must be present", 1);
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell binds a demon to your skin as armour.  The spell must "
"be cast at the demon itself, and the demon must be one which you have "
"summoned and successfully controlled.  The spell must be cast at a level "
"equal to or higher than the power level of the demon.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(!at->id("demon") || at->id("greater demon") ||
        at->id("lesser demon")) {
    message("info", "You must cast this spell at a demon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(!at->query_owner() || (string)at->query_owner() != (string)caster->query_name()) {
    message("info", "The demon must have been summoned and contolled by you.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "Instead of binding the demon to you, you release it "
      "from your control and it attacks!", caster);
    message("info", (string)at->query_cap_name() + " angrily attacks "+
          (string)caster->query_cap_name() + "!", environment(caster),
          ({ caster, at }));
    at->set_owner("asskicker");
    at->kill_ob(caster, 0);
    remove();
    return;
  }
  if((int)at->query_power() < power) {
    message("info", "The demon must be equal or greater power than the spell.",
        caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  message("info", "%^MAGENTA%^%^BOLD%^You bind the demon to your skin.", caster);
  at->remove();
  ::spell_func(caster, caster, power, args, 0);
  return;
}

