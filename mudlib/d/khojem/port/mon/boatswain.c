//  Wizard:   Khojem
//  Monster:  boatswain
//  File:     boatswain.c

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
        write_file("/d/khojem/log/boatswain.log",
          "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
          ctime(time())+"\n");
    }
  }
  return;
}

create() {
  object obj;
  ::create();
    set_name("boatswain");
    set_id( ({ "boatswain", "sailor" }) );
    set_level(21);
    set_exp(200000);
    set_short("[21]boatswain");
    set_long("The boatswain looks like a rugged veteran sailor.  He is "+
      "responsibile for the care and maintenance of the vessel."
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_property("enhance criticals",-1);
    set_wimpy(0);
    add_money("gold", 20);
    add_money("silver",(random(200)));
    set("gang bang",1);
    set_class("fighter");
    set_overall_ac(19);
    set_wielding_limbs(({"right hand"}));
    set_property("melee damage", ([ "crushing" : 30]));
    set_skill("concentrate", 80);
    set_skill("illusionism", 80);
    set_spell_level("blur", 6);
    add_spell("blur", "$ME");
    set_combat_chance(80);
    set_skill("magery", 80);
    set_spell_level("haste", 5);
    add_spell("haste", "$ME");
    set_spell_level("slow", 6);
    add_spell("slow", "$A");
    obj = new("//d/damned/virtual/short-sword_6.weapon");
        obj->set_name("cutlass");
        obj->set_id(({ "cutlass", "sword", "blade" }));
        obj->set_short("cutlass");
        obj->set_long("The cutlass is a curved short sword.  It is "+
              "ideally suited for close-quarters fighting on deck.\n");
        obj->set_weight(40);
        obj->set_value(110);
        obj->set_wc(9,"cutting");
        obj->set_wc(6,"impaling");
        obj->set_ac(4);
        obj->move(this_object());
        command("wield cutlass in right hand");
        command("use concentrate");
}

int query_kho_mon() { return 1;}


void catch_tell(string str) {
    object obj;
  string who, a, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/boatswain.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/boatswain.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str,"%s attacks %s",a,b) == 2) {
    b = lower_case(a);
    obj = present(b,environment(this_object()));
    if(obj) {
      b = a+" you scourge!";
      command("yell in common "+b);
      command("cast *6 slow at "+a);
    }  
  }
  return;
}

void die() {
  write_file("/d/khojem/log/boatswain.log",
    ">>> Boatswain died \t\t\t"+ctime(time())+"\n");
   ::die();
}

