//  Wizard:   Khojem
//  Monster:  Chief Moped
//  File:     moped.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("moped");
    set_id( ({ "chief", "moped", "chief moped" }) );
    set_level(18);
    set_short("[18]chief moped");
    set_long("Chief Moped is aged and worn from years of service for the tribe.  "+
      "He has lived a good life and life in his position and level have rewarded "+
      "him well.  He is obese and large folds of fat create multiple chins and "+
      "a few tires around his torso.  Sweat constantly forms on his brow and "+
      "occasionally streak his face."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", random(20)+20);
	set_casting_chance(0);
	set_combat_chance(85);
	add_spell("power word, blind","$A");
	set_spell_level("power word, blind",5);
	add_spell("mirror image","$ME");
	set_spell_level("mirror image",6);
	add_spell("power word, stun","$A");
	set_spell_level("power word, stun",6);
	set_skill("magery",100);
	set_skill("illusionism",100);
    set_emotes(5, ({
	  "Moped coughs up some spew and spits to the floor.",
	  "Moped eats some more camel meat.",
	  "Moped tosses a bone on the floor.",
	  "Moped puts two fingers down his throat and pukes up some food."
	}),0);
	set_class("arch-mage");
	new("/d/khojem/nomad/weapon/scepter2")->move(this_object());
	force_me("wield scepter in right hand");
	new("/d/khojem/nomad/armor/moped_key")->move(this_object());
	force_me("wear key");
}

int query_kho_mon() { return 1;}
 
void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("guard", b)) {
           tell_room(environment(this_object()),
             "Chief Moped shouts, Death to "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
         }
      }
   }   
}
