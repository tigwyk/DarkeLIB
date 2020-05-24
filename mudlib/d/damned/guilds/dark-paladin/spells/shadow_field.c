inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "shadow field");
set_property("skill", "empowerment");
set_property("casting time", 25);
set_property("base mp cost", 250);
set_property("dev cost", 445);
set_property("fast dev cost", 1115);
set_property("spell level", 30);
set_property("moon", "ankh");
set_property("caster message", "An extremely dense shadow encases your entire body.");
set_property("target message", "You summon an enormously thick shadow into your surroundings.");
set_property("observer message", "An extremely dense shadow encases $T's entire body.");
set_property("spell type", ({ "protection" }));
set_property("target type", "living");
set_property("protection types", ([ "impaling" : 25, "crushing" : 25, "strike" : 25, "impact" : 25, "cutting" : 25, "royal" : 25, "time" : 25, "reflection" : 25, "unholy" : 25, "infernal" : 25, "stress" : 25, "aether" : 25, "holy" : 25, "disruption" : 25, "cold" : 25, "vacuum" : 25, "radiation" : 25, "plasma" : 25, "acid" : 25, "electricity" : 25, "fire" : 25 ]));
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
