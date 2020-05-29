//  Wizard:   Khojem
//  Monster:  Vo'Sangor Coffin Wight
//  File:     wight.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("wight");
    set_id( ({ "wight", "shadowy wight" }) );
    set_level(7);
    set_short("shadowy wight");
    set_long("The wight appears to be humanoid, but lacks any definition of feature.  "+
      "Where a face should be is blankness and two glowing red eyes." 
      );
    set("race", "ghost");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "vacuum" : 5]));
    set_overall_ac(5);
    money=new("std/obj/coins");
    money->set_money("silver",(400+random(200)));
    money->move(this_object());
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
    set_moving(1);
    set_speed(120);
    set_wimpy(0);
    set_class("necromancer");
    set_stats("intelligence", 90);
    set_casting_chance(0);
    set_combat_chance(80);
    add_spell("chilling touch","$A");
    set_spell_level("chilling touch",6);
    add_spell("hex","$A");
    set_spell_level("hex",4);
    add_spell("drain life","$A");
    set_spell_level("drain life",3);
    set_skill("necromancy",50);
    set_skill("concentrate",40);
    set_fingers(5);
    command("use concentrate");
}

int query_kho_mon() { return 1;}

int no_other_monsters(object who) {
  if(who->is_player()) {
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}


