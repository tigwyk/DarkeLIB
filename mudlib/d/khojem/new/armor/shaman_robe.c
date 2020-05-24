//  Wizard:  Khojem
//  Shaman's Robe
//  shaman_robe.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("shaman robe");
    set("id", ({ "robe", "shaman robe" }) );
    set("short", "A shaman's robe");
    set("long", "The heavy, cloth shaman's robe is as dark as night.  "+
      "Its thick, coarse material chafes your skin.  The robe's long "+
      "sleeves are designed to protect the wearer's arms.");
    set_weight(90);
    set_value(220);
    set_type("robe");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_ac(10);
        set_ac(11, "aether");
        set_ac(11, "depression");
        set_ac(11, "acid");
        set_ac(2, "vacuum");
        set_ac(16, "fire");
        set_ac(16, "cold");
        set_ac(6, "impact");
        set_ac(12, "stress");
        set_ac(12, "strike");
        set_ac(4, "electricity");
        set_ac(1, "time");
        set_ac(6, "crushing");
        set_ac(12, "disruption");
        set_ac(8, "holy");
        set_ac(8, "plasma");
        set_ac(8, "infernal");
        set_material("misc/wool");
}
