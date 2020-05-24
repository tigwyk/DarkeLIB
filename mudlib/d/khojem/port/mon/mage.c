//  Wizard:   Khojem
//  Monster:  mage
//  File:     mage.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();
void do_kill(object who);

void init() {
  string zstr;
  int i,lvl;
  object *inv;
   ::init();
  if(this_player()->is_player())
    delayed_call("do_kill",4,this_player());
  inv = all_inventory(environment(this_object()));
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i]) && (!inv[i]->query_kho_mon())) {
      lvl = (int)inv[i]->query_level();
      if(inv[i] != this_object())
      write_file("/d/khojem/log/mage.log",
        "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}

create() {
  object obj;
  ::create();
    set_name("mage");
    set_id( ({ "wizened mage", "mage" }) );
    set_level(16);
    set_short("[16]wizened mage");
    set_long("The mage is old and mishapened.  He scowls at your presence."
      );
    set("race", "drow-elf");
    set_gender("male");
    set_body_type("human");
    set_wimpy(0);
    set_class("arch-mage");
    set_overall_ac(16);
    set_wielding_limbs( ({ "right hand" }) );
    set_melee_damage( ([ "crushing" : 15 ]) );
    set_casting_chance(0);
    set_combat_chance(88);
    add_spell("faerie fire","$A");
    set_spell_level("faerie fire",4);
    add_spell("magic missile","$A");
    set_spell_level("magic missile",6);
    add_spell("power word, stun","$A");
    set_spell_level("power word, stun",2);
    set_skill("illusionism",80);
    set_skill("conjuration",80);
    set_skill("concentrate",80);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
    set_fingers(5);
    obj = new("/d/damned/virtual/dagger_5.weapon");
    obj->move(this_object());
    command("wield dagger in right hand");
    command("use concentrate");
}

int query_kho_mon() { return 1;}

void do_kill(object who) {
  if(!present(who,environment(this_object()))) { return; }
  this_object()->kill_ob(who,0);
  force_me("cast *6 magic missle at "+who->query_name());
  return;
}

void catch_tell(string str) {
  string who, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/mage.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
    return;
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/mage.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  return;
}

void die() {
  write_file("/d/khojem/log/mage.log",
    ">>> Mage died \t\t\t"+ctime(time())+"\n");
   ::die();
}

