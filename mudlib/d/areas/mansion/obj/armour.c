// leather armour

inherit "/std/armour";

void create() {
       ::create();
       set_name("leather armour");
       set("id", ({"leather", "armour"}) );
       set("short", "a suit of leather armour");
       set("long",
      "This padded leather armour covers your upper body and "+
      "appears to offer a decent amount of protection."
       );
       set_type("armor");
       set_ac(15);
       set_limbs( ({ "torso", "left arm", "right arm"}) );
       set_value(800);
       set_weight(150);
       set_material("leather");
}
