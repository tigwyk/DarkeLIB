inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","lightning bolt");
    set_property("skill","conjuration");
    set_property("casting time",4);
    set_property("base mp cost",35);
    set_property("dev cost", 39);
    set_property("fast dev cost", 135);
    set_property("spell level", 7);
    set_property("moon","warzau");
    set_property("caster message","You cast a lightning bolt at $T.");
    set_property("target message","$C casts a lightning bolt at you!");
    set_property("observer message","$C casts at lightning bolt at $T.");
    set_property("can resist", 2);
    set_property("save mod", "dexterity");
    set_property("can resist", 2);
    set_property("spell type",({ "damage" }));
    set_property("must be present", 1);
    set_property("damage types", ([ "electricity" : 25 ]));
    set_property("damage multiplier", 7);
    set_property("combat spell", 1);
    set_property("target type", "living");
    return;
}

void info() {
message("help",
"This spell hurls deadly lightning at the target!",
this_player());
}

