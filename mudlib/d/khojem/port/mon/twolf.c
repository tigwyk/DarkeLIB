//  Wizard:   Khojem
//  Monster:  wolf
//  File:     wolf.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
void do_warn(object who);

void init() {
   ::init();

  delayed_call("do_warn", 2, this_player());
  return;
}

create() {
  int mod;
  ::create();
    set_name("silvery wolf");
    set_id( ({ "silvery wolf", "wolf" }) );
    mod=(random(2));
    set_level((9+mod));
if (mod == 0) set_short("[9]A silvery wolf");
else 
if (mod == 1) set_short("[10]A silvery wolf");
else
if (mod == 2) set_short("[11]A silvery wolf");
else
else set_short("[12]A silvery wolf");
    set_long("The wolf has human-like intelligence as it looks "
      "deeply into your soul.  Its fur radiates a silvery glow "
      "and its snout is surrounded by aged, bushy gray hairs."
    );
    set("race", "dog");
    set_body_type("quadruped");
    set_gender("female");
    set_stats("intelligence", 70);
    set_property("melee damage", ([ "cutting" : 20, "impaling" : 10 ]));
    set_overall_ac(15);
    set_combat_chance(86);
    set_spell_level("magic missile",4);
    add_spell("magic missile","$A");
    set_spell_level("mad rage",2);
    add_spell("mad rage","$ME");
    set_skill("conjuration",70);
    set_skill("illusionism",70);
    set_skill("magery",80);
    set_skill("concentrate",70);
    set_skill("perception",90);
    set_wimpy(0);
    set_emotes(20,({
      "A wolf barks and snaps viciously at your feet.",
      "A salivating wolf lungs at you.",
      "A wolf leaps at you and knocks you into the stone wall.",
      "A wolf welps and retreats back a few feet.",
    }),1);    
    force_me("use concentrate");
 }

int query_kho_mon() { return 1;}

void do_warn(object who) {
  object zroom;
  string str;
  if(!who || !present(who,environment(this_object()))) { return; }
  str=who->query_name();
  tell_room(zroom,">>"+str);
  zroom = environment(this_object());
   tell_room(zroom,"Here2");
   message("info","Here3",zroom);
  write("got here");
  if(((int)this_player()->query_level()) < 18) {
    message("info","The silvery wolf howls:  Go back young adventurer!\n"
      "My master will be greatly displeased if you disturb him.\n",
      this_player()
    );
    return;
  }
  message("info","The silvery wolf howls:  You seem to be an experienced "
    "adventurer!\nMy master will not like for you to disturb him.\n",
     this_player()
  ); 
  return;
}
