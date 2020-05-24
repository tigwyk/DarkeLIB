//  Wizard:  Khojem
//  envenomed dagger
//  envenom_dagger.c

inherit "/std/weapon";

create() {
    ::create();
    set_name("envenomed dagger");
    set_ac(1);
    set("id", ({ "envenomed dagger", "dagger" }));
    set("short", "envenomed dagger");
    set("long", "A mean-looking weapon of death.  It is a short, pointed "+
      "knife which can be wielded or thrown.  Its cutting edge has been "+
      "specially treated with oils from rare poisonous plants."
    );
    set_type("knife");
    set_quality(random(2)+5);
    set_wc(12, "impaling");
    set_verb("stab");
    set_parry_bonus(-15);
    set_weight(50);
    set_value(50);
    set_property("enchantment",2);
    add_poisoning(20);
    set("throwable",1);
}
