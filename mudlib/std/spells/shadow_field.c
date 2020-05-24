inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "shadow field");
set_property("skill", "empowerment");
set_property("casting time", 25);
set_property("base mp cost", 165);
set_property("dev cost", 89);
set_property("fast dev cost", 249);
set_property("spell level", 20);
set_property("moon", "ankh");
set_property("caster message", "An extremely dense shadow encases your entire body.");
set_property("target message", "You summon an enormously thick shadow into your surroundings.");
set_property("observer message", "An extremely dense shadow encases $T's entire body.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "impaling" : 12, "crushing" : 12, "strike" : 12, "impact" : 12, "cutting" : 12, "unholy" : 12, "infernal" : 12, "stress" : 12, "aether" : 12, "holy" : 11, "disruption" : 12, "cold" : 12, "vacuum" : 12, "radiation" : 12, "plasma" : 12, "acid" : 12, "electricity" : 12, "fire" : 12 ]));
set_property("duration", 40);
set_property("stack key", "shadow field");
set_property("stack num", 1);
set_property("self cast", 1);
set_property("must be present", 1);
return;
}

void info() {
message("help", "With the power of this spell, a Dark Paladin can tap directly into the pure power of Owedquar and cover himself in an extraordinarily dense shadow. While encased in it, the loyal follower of the dark god will experience incredible boosts in protection. This spell can only be used for the casters benefit.", this_player());
}
