//  Wizard:   Khojem
//  Monster:  Harghuul
//  File:     harghuul.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  ::create();
    set_name("harghuul");
    set_id( ({ "harghuul", "guardian" }) );
    set_level(15);
    set_short("[15]Harghuul");
    set_long("Harghuul, the Guardian stands here.  This sword-demon is the "+
      "guardian of the Darke Temple of the Order of the Blessed Return.  "+
      "He stands close to eight feet in height and looms menacingly."
      );
    set("race", "sword-demon");
    set_gender("male");
    set_body_type("sword-demon");
    set_overall_ac(15);
    set_property("melee damage", ([ "crushing" : 40]));
	set_skill("reverse stroke",40);
	set_skill("whirlwind attack",60);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_wimpy(0);
    set_alignment(-1200);
    set_emotes(5, ({
	  "Harghuul arches his head forward, spreads his wings, and hisses at you!",
	  "Harghuul throws his head back and cackles insanely!",
	  "Harghuul lunges at you!",
	  "Harghuul retreats cautiously.",
	  "Harghuul steps back and does a 360 spin.  His sword sweeps just over "+
	    "your head!"
	}),1);
	set_class("fighter");
	set_casting_chance(0);
	set_combat_chance(80);
	add_spell("disruption bolt","$A");
	set_spell_level("disruption bolt",6);
	set_skill("chaos magic",60);
	add_spell("drain life","$R");
	set_spell_level("drain life",6);
	set_skill("necromancy",60);
	new("/d/khojem/nomad/weapon/triple_blade")->move(this_object());
	force_me("wield sword in right hand and left hand");
	new("/d/khojem/nomad/armor/black_cape")->move(this_object());
    money=new("std/obj/coins");
    money->set_money("silver",((random(20))+40));
    money->move(this_object());
	force_me("wear cape");
	force_me("use whirlwind attack");
}

int query_kho_mon() { return 1;}
 
void catch_tell(string str) {
  string a;
  object ob1;
  if(sscanf(str, "%s enters.", a) == 1) {
    a = lower_case(a);
    ob1 = present(a, environment(this_object()));
    if(ob1) {
      if(ob1->is_player()) {
        if(ob1->query_invis()) { return; }
        force_me("kill "+ a);
        return;
      }
    }
  }
  return;
}

