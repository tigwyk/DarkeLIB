inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "black fire");
set_property("skill", "owedquar's will");
set_property("casting time", 6);
set_property("base mp cost", 185);
set_property("dev cost", 210);
set_property("fast dev cost", 565);
set_property("spell level", 24);
set_property("moon", "warzau");
set_property("caster message", "You call upon a raging blaze of black fire!");
set_property("target message", "$C calls upon a raging blaze of black fire!");
set_property("observer message", "$C calls upon a raging blaze of black fire.");
set_property("spell type", ({ "area damage" }));
set_property("damage types", ([ "unholy" : 60, "unholy #2" : 60, "fire" : 60, "fire #2" : 60 ]));
set_property("damage multiplier", 20);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("no target", 1);
return;
}

void info() {
message("help", "This spell calls forth a very powerful blaze of extremely hot dark fire. The fire tainted with the power of darkness inflicts both types of damage in a violent manner to all targets present.", this_player());
}
