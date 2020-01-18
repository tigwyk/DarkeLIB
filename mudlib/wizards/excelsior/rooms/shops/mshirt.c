inherit "std/armour";

void create() {
   ::create();
   set_name("shirt");
   set_type("shirt");
   set_limbs( ({ "torso" }) );
   set("id",({"shirt","striped shirt"}) );
   set("short","A magical striped shirt");
   set("long","This is a magical striped shirt. It is enchanted to "+
                "provide superb protection to its wearer.");
   set_material("/misc/leather"); 
   set_ac(25);
   set_weight(180);
   set_value(8000);
   }
