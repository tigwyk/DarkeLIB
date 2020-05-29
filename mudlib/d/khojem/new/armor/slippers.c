//  Wizard:  Khojem
//  leather slippers
//  slippers.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather slippers");
    set("id", ({ "slippers", "leather slippers" }) );
    set("short", "leather slippers");
    set("long", "A pair of tanned, leather slippers.");
    set_weight(30);
    set_value(4);
    set_type("boot");
    set_limbs( ({ "right foot", "left foot" }) );
    set_ac(4);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(1, "acid");
        set_ac(1, "vacuum");
        set_ac(3, "fire");
        set_ac(4, "cold");
        set_ac(4, "impact");
        set_ac(1, "stress");
        set_ac(1, "strike");
        set_ac(1, "electricity");
        set_ac(0, "time");
        set_ac(4, "crushing");
        set_ac(2, "disruption");
        set_ac(0, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("misc/leather");

}
