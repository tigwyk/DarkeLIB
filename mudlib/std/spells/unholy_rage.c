inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "unholy rage");
set_property("skill", "empowerment");
set_property("casting time", 14);
set_property("base mp cost", 75);
set_property("dev cost", 97);
set_property("fast dev cost", 268);
set_property("spell level", 12);
set_property("moon", "luna");
set_property("caster message", "You force $T into an unholy rage!");
set_property("target message", "$C forces you into an unholy rage!");
set_property("observer message", "$C forces $T into an unholy rage.");
set_property("spell type", ({ }));
set_property("target type", "living");
set_property("must be present", 1);
set_property("duration", 240);
return;
}

void info() {
message("help", "This spell infuses the target with potent dark power, giving it an extreme boost in speed and allowing multiple extra attacks per round during its duration.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;

seteuid(getuid());
if(at->query_haste() || at->query_speed()) {
message("info", "The target cannot move any faster than it already is.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}
ob = new("/std/spells/shadows/haste_shadow");
if(flag) {
message("info", "Instead of speeding the target up, you instead significantly slow it down!", caster);
ob->set_fumble();
}
ob->set_shadow_name("unholy rage");
ob->start_shadow(at, props["duration"], "%^CYAN%^Your speed quickly returns to normal.%^RESET%^");
return;
}
