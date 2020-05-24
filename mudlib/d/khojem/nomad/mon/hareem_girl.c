//  Wizard:   Khojem
//  Monster:  hareem girl
//  File:     hareem_girl.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void init() {
  ::init();
}

create() {
 // int mod;
  ::create();
    set_name("hareem girl");
    set_id( ({ "hareem girl", "girl" }) );
   // mod=random(10);
    //if(mod==0) { set_level(5); }
    //if(mod>0)  { set_level(6); }
   // if(mod>7)  { set_level(7); }
set_level(7)
    set_short("[7]hareem girl");
    set_long("A dark-haired attractive woman.  Her face is "+
      "veiled, but you notice a mischievous glint in her eye."
      );
    set("race", "high-man");
    set_gender("female");
    set_body_type("human");
    set_wimpy(0);
    add_money("silver", random(10));
    set_emotes(2, ({
	  "A hareem girl giggles briefly.",
	  "A hareem girl blushes as she catches your eye.",
	  "A hareem girl beams you a smile.",
	  "A hareem girl winks suggestively at you."
	}),0);
	new("/d/khojem/nomad/armor/veil")->move(this_object());
	force_me("wear veil");
	new("/d/khojem/nomad/armor/pantaloons")->move(this_object());
	force_me("wear pantaloons");
	new("/d/khojem/nomad/armor/bodice")->move(this_object());
	force_me("wear bodice");
}

int query_kho_mon() { return 1;}
