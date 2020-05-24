inherit "/std/spells/spell";

void create() {
    ::create();
set_property("name", "death");
    set_property("skill","magery");
set_property("casting time", 0);
    set_property("base mp cost",115);
    set_property("dev cost", 85);
    set_property("fast dev cost", 220);
    set_property("spell level", 18);
    set_property("moon","warzau");
set_property("caster message", "You call forth the grim reaper to strike down $T.");
set_property("target message", "$C calls forth the grim reaper to strike you down!");
set_property("observer message", "$C calls forth the grim reaper to strike down $T.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("save mod", "constitution");
    set_property("damage multiplier", 6);
    set_property("combat spell", 1);
    set_property("duration", "instantaneous");
    set_property("target type", "living");
    set_property("prereq", "power word, blind");
    return;
}

void info() {
message("help",
"This spell attempts to KILL the target.  You have a higher chance of killing "
"targets of lower levels, and of course, the chance is increased at high power.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int diff;
  
  if(flag) {
    message("info", "%^RED%^%^BOLD%^OOPS, You kill yourself!!!", caster);
    caster->add_hp(-20 + -1*(int)caster->query_hp());
  }
  diff = (int)caster->query_level() - (int)at->query_level();
  if(diff >= 0 && random(100/power) <= diff) {
    message("info", "You kill "+(string)at->query_cap_name()+"!", caster);
message("info", "%^RED%^You fall over dead without suffering.%^RESET%^", at);
at->set_hp(-1);
  } else {
    message("info", "Your spell has no effect.", caster);
    message("info", (string)caster->query_cap_name() +
"attempted to instantly slay you, but luckily was unsuccessful.", at);
  }
  remove();
  return;
}

