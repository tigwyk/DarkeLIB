//  Wizard:   Khojem
//  Monster:  captain
//  File:     captain.c

#include <std.h>
inherit MONSTER;

int query_kho_mon();

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
      write_file("/d/khojem/log/captain.log",
        "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}
 
create() {
  object obj;
  ::create();
    set_name("captain");
    set_id( ({ "captain", "sailor" }) );
    set_level(22);
    set_exp(350000);
    set_short("captain");
    set_long("The captain is youthful and appears to be a good fighting man.  "+
      "He is well liked by his men and runs a taut ship."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_property("enhance criticals", -2);
    set_wimpy(0);
    add_money("gold",40);
    add_money("silver", (random(200)));
     set("gang bang",1);
        set_class("fighter");
        set_overall_ac(20);
        set_wielding_limbs(({"right hand"}));
    set_property("magic resistance",80);
     set_skill("resist stun",60);
    set_property("melee damage", ([ "crushing" : 30]));
    set_skill("concentrate", 85);
    set_skill("illusionism", 85);
    set_spell_level("blur", 6);
    add_spell("blur", "$ME");
    set_combat_chance(85);
    set_skill("whirlwind attack",100);
    obj = new("//d/damned/virtual/long-sword_6.weapon");
    obj->set_name("jeweled sabre");
    obj->set_id(({ "sabre", "sword", "blade", "foil", "jeweled sabre" }));
    obj->set_short("jeweled sabre");
    obj->set_long("The sabre foil has an arched guard to protect the "+
               "wielder's hand.  It has a tapered, flexible blade with a "+
               "full cutting edge on one side and a partial cutting edge "+
               "on the back of the tip.  A few jewels can be seen imbeded "+
               "in its hilt.\n");
    obj->set_weight(250);
    obj->set_value(160);
    obj->set_wc(18,"cutting");
    obj->set_parry_bonus(10);
    obj->set_ac(8);
    obj->move(this_object());
    command("wield sabre in right hand");
    command("use concentrate");
}

int query_kho_mon() { return 1;}


void catch_tell(string str) {
  string a, b, who;
  object obj;
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/captain.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/captain.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str,"%s attacks %s",a,b) == 2) {
    b = lower_case(a);
    obj = present(b,environment(this_object()));
    if(obj) {
      b = a+" you scourge!";
      command("yell in common "+b);
      command("use whirlwind attack");
      return;
    }
  }
  return;
}

void die() {
  write_file("/d/khojem/log/captain.log",
    ">>> Captain died \t\t\t"+ctime(time())+"\n");
   ::die();
}


