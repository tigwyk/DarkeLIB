inherit "/std/skills/lore_skill";

void create() {
    ::create();
    set_property("element", "vacuum");
    set_dev_cost(9);
    set_fast_dev_cost(28);
}
