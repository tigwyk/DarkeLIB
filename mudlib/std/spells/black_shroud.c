inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "black shroud");
set_property("skill", "owedquar's will");
set_property("casting time", 5);
set_property("base mp cost", 80);
set_property("dev cost", 90);
set_property("fast dev cost", 240);
set_property("spell level", 12);
set_property("moon", "warzau");
set_property("caster message", "You summon a shroud of darkness!");
set_property("target message", "$C summons a shroud of darkness!");
set_property("observer message", "$C summons a shroud of darkness.");
set_property("spell type", ({ "area damage" }));
set_property("must be present", 1);
set_property("can resist", 1);
set_property("damage types", ([ "unholy" : 40, "unholy #2" : 40 ]));
set_property("damage multiplier", 10);
set_property("combat spell", 1);
set_property("no target", 1);
return;
}

void info() {
message("help", "This spell creates a shroud of darkness covering the entire immediate vicinity of the caster. All targets present in the room at the time will be hurt by a fair amount of darkness elemental damage.", this_player());
}
