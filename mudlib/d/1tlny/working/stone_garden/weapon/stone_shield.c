//  Wizard:  Khojem
//  Stone Shield
//  stone_shield.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("stone shield");
    set("id", ({ "shield", "stone shield" }) );
    set("short", "A stone shield");
    set("long", "An oval, stone shield carved to a disc with leather straps for holding.");
    set_weight(600);
    set_value(1);
    set_type("shield");
    set_limbs( ({ ({ "right hand", "left hand", 
      "first branch", "second branch", "third branch", "fourth branch" }) }) );
    set_ac(15);
        set_ac(0, "aether");
        set_ac(0, "depression");
        set_ac(5, "acid");
        set_ac(0, "vacuum");
        set_ac(5, "fire");
        set_ac(5, "cold");
        set_ac(20, "impact");
        set_ac(1, "stress");
        set_ac(6, "strike");
        set_ac(1, "electricity");
        set_ac(1, "time");
        set_ac(1, "disruption");
        set_ac(1, "holy");
        set_ac(1, "plasma");
        set_ac(1, "infernal");
        set_material("misc/a big fuckin' rock");
}
