inherit "/std/weapon";

create() {
    ::create();
    set_ac(0);
    set("id", ({ "hammer", "warhammer", "war hammer" }) );
    set_short("A blood red warhammer");
    set_long("It looks very mean.\n");
    set_type("two handed blunt");
    set_quality(6);
    set_property("no decay",1);
    set_property("no add quality",1);
     set_wc(30,"crushing","fire");
    set_verb("pulverize");
   set_value(6000);
    set_parry_bonus(5);
    set_property("enchantment",10);
    set_enh_critical(1);
    return;
}
