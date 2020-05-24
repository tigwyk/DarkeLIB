inherit "/std/weapon";

create() {
    ::create();
    set_ac(5);
    set("id", ({ "sword", "scimitar" }) );
    set_short("An unsurpassed scimitar");
    set_long("It is a nice scimitar.\n");
    set_type("blade");
    set_quality(6);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(30, "cutting");
    set_wc(12, "impaling");
    set_verb("slice");
    set_parry_bonus(15);
    set_value(1000);
    return;
}
