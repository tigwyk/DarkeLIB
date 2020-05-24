inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "black edge");
set_property("skill", "empowerment");
set_property("casting time", 12);
set_property("base mp cost", 144);
set_property("dev cost", 200);
set_property("fast dev cost", 565);
set_property("spell level", 28);
set_property("moon", "warzau");
set_property("damage multiplier", 1);
set_property("caster message", "You cast %^BOLD%^%^BLUE%^black edge %^RESET%^at $T!");
set_property("target message", "");
set_property("observer message", "$C casts %^BOLD%^%^BLUE%^black edge %^RESET%^at $T.");
set_property("spell type", ({ }));
set_property("duration", 300);
set_property("must be present", 1);
set_property("stack key", "black edge");
set_property("stack num", 3);
set_property("target type", "any");
return;
}

void info() {
message("help", "This spell imbues a respectable amount of dark power into a weapon, allowing its wielder to strike its foes with greatly increased darkness elemental energy for the spells duration.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;
object weap;

if(!at->is_weapon()) {
message("info", "You may only cast this magic upon weapons.", caster);
caster->add_mp(props["mp cost"]);
return;
}

ob = new("/std/spells/shadows/weapon_shadow");
message("info", "You imbue the weapon with dark energy.", caster);
ob->set_extra_wc(([ "unholy" : 9*power ]));
ob->set_auto_crits(([ "unholy B" : 5*power ]));
ob->set_shadow_name("black edge");
ob->start_shadow(at, props["duration"], "%^BLUE%^A black edge spell wears off.%^RESET%^");
remove();
return;
}
