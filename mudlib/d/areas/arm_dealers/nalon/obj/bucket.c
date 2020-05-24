// Wizard:  Khojem
// gardeners bucket
// bucket.c
// modified by Tobias for Nalon

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
 set_id(({ "water", "bucket", "water skin"}));
  set_name("water skin");
	set("long",
"This bucket is old and worn, but still holds a good deal of water. "
"The gardeners of Nalon use buckets like this to keep the plants of "
"the village well watered."
	);
  set_weight(48);
  set_value(80);
  return;
}

string query_short() {
  switch(drinks_left) {
   case  10   : return "bucket is (full)";
   case 7..9  : return "bucket is (mostly full)";
   case 4..6  : return "bucket is (semi-full)";
    case 1..3  : return "bucket is (nearly empty)";
   default    : return "bucket is (empty)";
  }
}

void fill(string id, int drink, int alc) {
  strength  = drink;
  intox     = alc;
  set_value(100+alc);
  drinks_left = 10;
  say(this_player()->query_cap_name()+" fills a bucket.\n");
  return;
}

void empty() {
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
  write("You empty the contents of a bucket.\n");
  say(this_player()->query_cap_name()+" empties a bucket.\n");
  this_object()->empty();
  return 1;
}

int drink_me(string str) {
  if(present(str,this_player()) != this_object()) return 0;
  if(drinks_left < 1) {
    write("Hmmm...   it is empty.\n");
    return 1;
  }
  write("You pour the contents of the bucket down your throat.\n");
  say(this_player()->query_cap_name()+" drinks from a bucket.\n");
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
  
