inherit "/std/monster";

void create() {
   object ob;
   ::create();
   set_name("dragon");
   set("id", ({ "dragon", "Dragon" }));
   set("short", "A huge Red Dragon");
   set("long",
	"Scales ripple as powerful muscles move beneath the skin of this large "+
	"dragon.  The heat that ripples from his body gives evidence to the fire "+
	"contained within.  Massive large claws as long as swords and sharp teeth "+
	"only serve to add to this creatures powerful arsenal.");

   set_level(25);
   set_exp(6432454);

   set_property("enhance criticals",-3);
   set_property("magic resistance", 90);
   set_overall_ac(275);
   set_body_type("dragon");
   set_alignment(-100);
   set("race", "dragon");
   set_gender("male");

   set("aggressive", 1);
   set("chase",1);

   set_stats("strength", 160 + random(30));
   set_stats("dexterity", 140 + random(30));
   set_stats("constitution", 120 + random(20));
   set_stats("wisdom", 50 + random(20));
   set_stats("intelligence", 50 + random(20));
   set_stats("charisma", 100);

   set_skill("melee", 160);
   set_skill("attack", 180);
   set_skill("defense", 140);
   set_skill("dodge", 140);
   set_skill("reverse stroke", 120);
   set_skill("martial arts",175);
   set_skill("concentrate", 100);
   set_skill("perception", 156);
   set("concentrate", 1);
    set_skill("resist stun", 200);

   set_skill("conjuration", 140);
   set_skill("prayer", 100);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");
   set_combat_chance(100);

   set_property("melee damage", ([
	"crushing" : 50,
	"cutting" : 40,
	"fire" : 80 ]) );
   set_hp(10000);
   set_max_hp(10000);
   set_max_mp(7000);
   set_mp(7000);
}


