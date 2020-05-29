#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
int pow;
string message;

void create() {
	seteuid(getuid());
	return;
}

void set_power(int x) { pow = x; }

int start_shadow(object ob, int dur, string msg) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    message = msg;
    delayed_call("expire_me", dur, this_object());
    return 1;
}

int query_d_trans() { return 1; }

int query_flying() { return 1; }

mixed query_property(string what) {
  mapping tmp;

  if(what == "melee damage") {
    tmp = (mapping)next_shadow()->query_property("melee damage");
    if(tmp) return tmp + ([ "holy" : pow * 3 ]);
    else return ([ "holy" : pow*3 ]);
  }
  return next_shadow()->query_property(what);
}

int query_skill(string what) {
  if(what == "melee")
    return 4 * pow + (int)next_shadow()->query_skill("melee");
  return (int)next_shadow()->query_skill(what);
}

void expire_me(object what) {
  if(what != this_object()) {
    next_shadow()->expire_me(what);
    return;
  }
  if(message)
    message("info", message, who_shadowed);
  remove();
}
