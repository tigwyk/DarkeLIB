//  Wizard:   Khojem
//  Monster:  Hill-giant
//  File:     giant.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("giant");
    set_id( ({ "giant", "hill-giant" }) );
    set_level(9);
    set_short("[9]giant");
    set_long("The huge, massive hill-giant does not like the fact that you "+
      "have disturbed his solitude."
      );
    set("race", "hill-giant");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    add_money("gold", random(15));
 	set_overall_ac(15);
	set_wielding_limbs( ({ "left hand" }) );
    set_property("melee damage", ([ "crushing" : 20]));
	set_class("fighter");
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
    set_emotes(5, ({
	  "The hill-giant lumbers to the left.",
	  "The hill-giant lumbers to the right.",
	  "The hill-giant lumbers to close to the precipe's edge and trys to "+
	    "regain his balance before falling.",
	  "The hill-giant spits out a wad of tobacco and frowns.",
	}),1);
	new("/d/damned/virtual/wall-shield.armour")->move(this_object());
	force_me("wear shield on right hand");
	new("/d/khojem/port/weapon/flail")->move(this_object());
	force_me("wield flail in left hand");
}

int query_kho_mon() { return 1;}

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}


