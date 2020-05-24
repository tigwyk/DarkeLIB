inherit "/std/weapon";

create() {
    ::create();
    set_ac(75);
    set("id", ({ "sword", "scimitar", "twinkle" }) );
    set_short("Twinkle");
    set_long("Twinkle is a scimitar owned by the great warrior "
             "Drizz't Do'Urden.  It has a blue aura around the "
             "sword and you feel safe when you are around it.\n");
    set_type("blade");
    set_quality(6);
    set_property("no decay",1);
    set_property("light", 1);
    set_property("no add quality",1);
    set_property("brittle",20);
    set_wc(50, "disruption");
    set_verb("slice");
    set_parry_bonus(40);
    set_property("enchantment",30);
    set_value(100000);
    set_enh_critical(8);
    return;
}
