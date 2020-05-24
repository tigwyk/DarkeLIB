inherit "/std/weapon";



create() {

    ::create();

    set_ac(5);

    set("id", ({ "mace" }));

    set("short", "footman's mace");

    set("long", "This is a cool footman's mace");

    set_type("blunt");

    set_quality(4);

    set_wc(20, "crushing");

    set_verb("pound");

    set_parry_bonus(-5);

    set_value(120);

    set_weight(250);

    return;

}

