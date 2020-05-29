//	A user shadow that can be cloned and used to temporarily 
//	modify a player stat.  Configured so it is cumulative with other
//	such shadows.
//	DarkeLIB 0.1
//	Diewarzau 3/27/94

#include <security.h>
inherit "/std/spells/shadows/shadow";

string stat, mesg;
int mod;
object who_shadowed;

void create() {
	seteuid(getuid());
	stat = "";
	mod = 0;
}

void set_stat(string arg) { stat = arg; }

void set_mod(int arg) { mod = arg; }

int start_shadow(object ob, int duration, string expire_msg) {
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    mesg = expire_msg;
    if(!mesg) mesg = "A spell just expired.";
    who_shadowed = ob;
    if(duration)
    call_out("remove",duration,this_object());
    return 1;
}

int query_stats(string str) {
    if(!stat || stat != lower_case(str)) return
	(int)next_shadow()->query_stats(str);
    return (int)next_shadow()->query_stats(str) + mod;
}

void remove() {
    if(!::remove()) return;
    message("info", mesg, who_shadowed);
    return;
}

