inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "abyss blast");
set_property("skill", "owedquar's will");
set_property("casting time", 5);
set_property("base mp cost", 550);
set_property("dev cost", 576);
set_property("fast dev cost", 1340);
set_property("spell level", 39);
set_property("moon", "warzau");
set_property("caster message", "You blast an earth shattering mass of swirling energy at $T!");
set_property("target message", "$C blasts an earth shattering mass of swirling energy at you!");
set_property("observer message", "$C blasts an earth shattering mass of swirling energy at $T.");
set_property("spell type", ({ "damage" }));
set_property("damage types", ([ "unholy" : 150, "infernal" : 150, "disruption" : 150 ]));
set_property("damage multiplier", 25);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("target type", "living");
return;
}

void info() {
message("help", "This spell conjures a shivering amount of darkness, infernal, and disruption energy into a compact swirling mass and angrily blasts it at the target, causing MAJOR and at most times fatal damage.", this_player());
}
