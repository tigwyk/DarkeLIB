#include <std.h>

inherit "/std/pet";

int my_hp;
object owner;
int flag;
int type;
string *spells;

void wink_out();
int score_rep(object att);

void set_dur(int dur) {
  call_out("wink_out", dur);
  return;
}

void create() {
  ::create();
  type = 0;
  set_body_type("human");
  flag = 0;
  this_object()->set_up(random(3));
  set_attack(1);
  set_can_change_aggr(1);
  return;
}

void set_up(int x) {
  type = x;
  switch(x) {
  case 0:
    set_name("dracolich");
    set_body_type("winged-humanoid");
    set_short("ominous Dracolich");
    set_long("This Dracolich is perhaps the most powerful of undead creatures.");
    set_id(({ "dracolich", "lich", "undead" }));
    spells = ({ "Dracolich casts ROT.", "Dracolich casts lifesteal at you.\nDracolich's spell hits you." });
    set("race", "undead");
    set_level(20);
    set_exp(1);
    break;
  case 1:
    set_name("dragon");
    set_body_type("winged-humanoid");
    set_short("Vacid Dragon");
    set_long("This Dragon glows with th energy of Vacid.");
    set_id(({ "dragon", "elemental", "vacid dragon" }));
    set("race", "elemental");
    spells = ({ "Dragon casts elemental storm.\nDragon's spell hits you.",
        "Dragon casts elemental strike.\nDragon's spell hits you.\nDragon's spell hits you.\nDragon's spell hits you.\nDragon's spell hits you." });
    set_level(20);
    set_exp(1);
    break;
  case 2:
    set_name("angel");
    set_body_type("winged-humanoid");
    set_short("radiant Arch Angel");
    set_long("This Angel is a divine being indeed.");
    set_id(({ "angel", "arch angel", "radiant arch angel" }));
    set("race", "angel");
    spells = ({ "Angel casts harm at you, opening many festering wounds!",
        "Angel cures almost all of Angel's wounds." });
    set_level(20);
    set_exp(1);
    break;
  }
  return;
}

void restore_locker(string file) {
  ::restore_locker(file);
  if(type) this_object()->set_up(type);
  return;
}

int ill_guard() { return 1; }

int ill_guard_filter(object who, object att) {
  if(!who->ill_guard()) return 0;
  if(!pointerp(who->query_attackers())) return 0;
  if(member_array(att, (object *)who->query_attackers()) < 0) return 0;
  return 1;
}

int score_rep(object att) {
  object *inv;
  int i;

  inv = filter_array(all_inventory(environment()), "ill_guard_filter",
    this_object(), att);
  i = sizeof(inv);
  if(i <= 1) return 1;
  else if(member_array(this_object(), inv) == (i-1)) return 1;
  return 0;
}

void set_hits(int x) { my_hp = x; }

varargs void heart_beat(int flag) {
  object *att;
  int i, j, last_hp;
  
  if(my_hp < 0) {
    wink_out();
    return;
  }
  clean_up_attackers();
  att = query_attackers();
  if(att && sizeof(att)) {
    i = sizeof(att);
    while(i--) {
      last_hp = (int)att[i]->query("last hp");
      if(!last_hp || last_hp > (int)att[i]->query_hp()) last_hp = (int)att[i]->query_hp();
      if((string)att[i]->getenv("SCORE") == "on")
        att[i]->setenv("SCORE", "off");
      for(j=1;j<=3;j++) {
        switch(random(3)) {
        case 0:
        default:
          message("my_combat", (string)this_object()->query_cap_name() +
            " hits you very hard, leaving you bleeding.", att[i]);
          last_hp -= 12;
          break;
        case 1:
          message("my_combat", (string)this_object()->query_cap_name() +
            " hits you very violently, astonishing you immensely.",
              att[i]);
          last_hp -= 17;
          break;
        case 2:
          message("my_combat", (string)this_object()->query_cap_name() +
          " hits you very hard.",
              att[i]);
          last_hp -= 20;
          break;
        }
        if(last_hp < 1) last_hp = 1;
      }
      if(score_rep(att[i]))
        message("info", sprintf("hp: %d (%d)  mp: %d (%d)",
          last_hp, (int)att[i]->query_max_hp(), (int)att[i]->
          query_mp(), (int)att[i]->query_max_mp()), att[i]);
    }
  }
  return;
}

int do_damage(string limb, int dam) {
  if(dam <= 0) return dam;
  my_hp--;
  return dam;
}

void set_fumble() { flag = 1; }

void add_hp(int hp) {
  if(hp >= 0) return;
  my_hp--;
  return;
}

void heal(int x) {
  if(x >= 0) return;
  my_hp--;
  return;
}

void wink_out() {
  message("info", "%^GREEN%^%^BOLD%^"+(string)this_object()->query_short()+
      " winks out of existence.", environment());
  remove();
  return;
}

