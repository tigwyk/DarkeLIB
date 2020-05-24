inherit "/std/weapon";

create() {
    ::create();
    set_ac(20);
    set("id", ({ "sword", "skull sword" }));
    set("short", "The Skull Sword of Diewarzau");
    set("long", "This is a very impressive weapon.  The blade is "
	"crafted of an unearthly dull grey metal, and the hilt is "
	"encrusted with tiny skulls whose eyes glow deep red.  ");
    set_type("blade");
    set_quality(6);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(30,"cutting");
    set_verb("slice");
    set_parry_bonus(10);
    set_property("enchantment",10);
    set_enh_critical(4);
    return;
}
