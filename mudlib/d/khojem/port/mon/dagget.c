//  Wizard:   Khojem
//  Monster:  Habor Master
//  File:     master.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

int query_kho_mon() { return 1;}

void init() {
  string zstr;
  int i,lvl;
  object *inv;
   ::init();
  inv = all_inventory(environment(this_object()));
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i]) && (!inv[i]->query_kho_mon())) {
      lvl = (int)inv[i]->query_level();
      if(inv[i] != this_object())
      write_file("/d/khojem/log/dagget.log",
        "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}

create() {
  object money;
  ::create();
    set_name("dagget");
    set_id( ({ "master", "harbor master", "dagget", "Dagget" }) );
    set_level(14);
    set_short("[14]Dagget");
    set_long("Dagget serves as the harbor master in the port town of "+
      "Vo'Sangor.  Which means he does some customs work and takes bribes "+
      "from merchant vessel captains so they can unload their goods." 
      );
    set("race", "drow-elf");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 40]));
    set_overall_ac(16);
    money=new("std/obj/coins");
    money->set_money("gold",10);
    money->move(this_object());
    money->set_money("silver",(random(200)));
    set_exp(40000);
    set_wimpy(0);
    set_class("war priest");
    set_casting_chance(0);
    set_combat_chance(90);
    add_spell("harm","$A");
    set_spell_level("harm",2);
    add_spell("battle aura","$ME");
    set_spell_level("battle aura",2);
    add_spell("shields of war","$ME");
    set_spell_level("shields of war",2);
    set_skill("prayer",60);
    set_skill("body alteration",40);
    set_skill("concentrate",60);
    set_fingers(5);
    money = new("/d/khojem/port/obj/sangor_key");
    money -> move(this_object());
    command("use concentrate");
}

void catch_tell(string str) {
  string who, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/dagget.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
    return;
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/dagget.log",
      "*** Player Kill:  "+who+"\t\t\t"+ctime(time())+"\n");
  }
  return;
}

void die() {
  write_file("/d/khojem/log/dagget.log",
    ">>> Dagget died \t\t\t"+ctime(time())+"\n");
   ::die();
}

