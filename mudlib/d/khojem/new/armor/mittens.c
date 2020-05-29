//  Wizard:  Khojem
//  Leather Mittens
//  leather_mittens.c

inherit "/std/armour";

void create() {
    ::create();
    set_name("leather mittens");
    set("id", ({ "mittens", "leather mittens" }) );
    set("short", "leather mittens");
    set("long", "A pair of crudely-tanned, leather mittens.  It is grimey "+
      "and has a few holes.");
    set_weight(50);
    set_value(20);
    set_type("glove");
    set_limbs( ({ ({ "right hand", "left hand", 
      "first branch", "second branch", "third branch", "fourth branch" }) }) );
    set_ac(4);
}
