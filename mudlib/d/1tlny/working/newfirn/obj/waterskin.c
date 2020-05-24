// Wizard:  Gellor
// leather waterskin
// waterskin.c
#include <std.h>;
inherit OBJECT;
int strength;
int intox;
int drinks_left;
int full() { return drinks_left; }
void create() {
  :: create();
  strength = 0;
  drinks_left = 0;
  intox = 0;
    set_id(({ "skin", "waterskin", "water skin", "leather waterskin",
"leather water skin" }));
    set_name("leather waterskin");
    set("long", "The waterskin is made of fine aged leather. ");
  set_weight(12);
  set_value(80);
  return;
}
string query_short() {
  switch(drinks_left) {
      case  10   : return "leather waterskin is (full)";
      case 7..9  : return "leather waterskin is (mostly full)";
      case 4..6  : return "leather waterskin is (semi-full)";
      case 1..3  : return "leather waterskin is (nearly empty)";
      default    : return "leather waterskin is (empty)";
  }
}
void fill(string id, int drink, int alc) {
  strength  = drink;
  intox     = alc;
  set_value(100+alc);
  drinks_left = 10;
  set_weight(12 + (4 * drinks_left));
    say(this_player()->query_cap_name()+" fills a leather waterskin.\n");
  return;
}
void empty() {
  set_weight(12);
  set_value(80);
  drinks_left = 0;
  strength    = 0;
  intox       = 0;
  return;
}
void init() {
  :: init();
  add_action("drink_me","drink");
  add_action("pour_me", "pour");
  add_action("pour_me", "empty");
  return;
}
int pour_me(string str) {
  if(present(str,this_player()) != this_object()) return 0;
  if(drinks_left == 0) return 0;
    write("You empty the contents of a leather waterskin.\n");
    say(this_player()->query_cap_name()+" empties a leather waterskin.\n");
  this_object()->empty();
  return 1;
}
int drink_me(string str) {
  if(present(str,this_player()) != this_object()) return 0;
  if(drinks_left < 1) {
    write("Hmmm...   it is empty.\n");
    return 1;
  }
  write("You chug the contents of the waterskin.\n");
    say(this_player()->query_cap_name()+" drinks from a leather
waterskin.\n");
  this_player()->add_quenched(strength);
  this_player()->add_intox(intox);
  this_player()->add_mp(intox/10);
  drinks_left--;
  if(drinks_left > 0)
    set_weight(12 + (4 * drinks_left));
  else
    this_object()->empty();
  return 1;
}
