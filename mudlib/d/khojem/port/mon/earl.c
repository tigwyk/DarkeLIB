//  Wizard:   Khojem
//  Monster:  Earl of Vo'Sangor
//  File:     earl.c

#include <std.h>
inherit MONSTER;

int wielding;

int query_kho_mon();
void wield_sword();

void init() {
  string zstr;
  int i,lvl;
  object *inv;
   ::init();
  if(this_player()->is_player() && !wielding) {
    wielding = 1;
    delayed_call("wield_sword", 4);
  }
  inv = all_inventory(environment(this_object()));
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i]) && (!inv[i]->query_kho_mon())) {
      lvl = (int)inv[i]->query_level();
      if(inv[i] != this_object())
      write_file("/d/khojem/log/earl.log",
       "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}

create() {
  int zlevel;
  object obj;
  ::create();
    set_name("earl");
    set_id( ({ "earl", "earl of vo'sangor" }) );
    set_level(22);
    set_exp(160000);
    set_short("[22]Earl of Vo'Sangor");
    set_long("The Earl of Vo'Sangor is aged but appears still a fit fighter."
      );
    set("race", "storm-giant");
    set_gender("male");
    set_body_type("human");
    set("gang bang",1);
    set_wimpy(0);
    set_property("enhance criticals", -2);
    set_class("fighter");
    set_overall_ac(28);
    set_wielding_limbs( ({ "right hand" }) );
    set_casting_chance(0);
    set_combat_chance(95);
    add_spell("blur","$ME");
    set_spell_level("blur",6);
    set_skill("illusionism",110);
    set_skill("concentrate",90);
    set_fingers(5);
    new("/d/khojem/port/obj/earl_desk_key")->move(this_object());
    new("/d/khojem/port/weapon/epee")->move(this_object());
    command("use concentrate");
    wielding = 0;
}

void wield_sword() {
  object zroom;
  zroom = environment(this_object());
  tell_room(zroom,"The Earl of Vo'sangor looks up at you.  His eyes narrow and\n"+
    "his hand reaches for the hilt of his epee.");
  force_me("wield jeweled epee in right hand");
  return;
}


int query_kho_mon() { return 1;}

void catch_tell(string str) {
  string who, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/earl.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
    return;
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/earl.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  return;
}

void die() {
  write_file("/d/khojem/log/earl.log",
    ">>> Earl of Vo'Sangor died \t\t"+ctime(time())+"\n");
   ::die();
}

