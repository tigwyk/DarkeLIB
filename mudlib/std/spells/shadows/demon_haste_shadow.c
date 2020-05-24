#include <security.h>
inherit "/std/spells/shadows/shadow";

object who_shadowed;
string exp_mesg;
static int fumble;

void start_shadow(object who, int dur, string mesg) {
  seteuid(UID_SHADOW);
  begin_shadow(who);
  who_shadowed = who;
  exp_mesg = mesg;
  if(dur) call_out("expire_haste", dur, this_object());
  seteuid(getuid());
  return;
}

int query_haste() { return (1+(int)next_shadow()->query_haste()); }

void expire_haste(object me) {
  if(me != this_object()) {
    next_shadow()->expire_haste(me);
    return;
  }
  message("info", exp_mesg, who_shadowed);
  remove();
  return;
}

int query_num_rounds() {
  int res;
  if(!(res = (int)next_shadow()->query_num_rounds()))
    res = 1;
    return res;
} 