//	Generic skill.c to be inherited by all skills.  Major handler of
//	The DarkeMUD skills system.
//	DarkeLIB 0.1
//	Diewarzau 4/1/94

#include "/adm/include/std.h"

inherit OBJECT;

string query_stat();
void set_stat(string what);
int query_dev();
int query_fast_dev();
void set_dev_cost(int cost);
void set_fast_dev_cost(int cost);
string stat;

int co_filter(mixed *arg) {
  return !(sizeof(arg) != 4 || arg[0] != this_object());
}

int clean_up() {
  if(sizeof(filter_array(call_out_info(), "co_filter", this_object())))
    return 1;
  remove();
  return 0;
}

void do_rune(object from, string arg) {
    string name;
    string target, args;
    object at;
    int i, which;

      if(!arg) {
	message("info", "You must supply a target.", from);
	remove();
	return;
	  }
	  target = arg;
		  at = present(target, environment(from));
		  if(!at) at = present(target, from);
	  if(!at) {
		  message("info","Cannot find "+target+".",from);
		  return;
	  }
      args = arg;
	if(!function_exists("rune_func", this_object())) {
	    message("info", "This rune is latent and cannot be used.",
		from);
	    return;
	}
    name = replace_string(base_name(this_object()), "/std/runes/", "");
    name = replace_string(name, ".c", "");
    name = replace_string(name, "_", " ");
    set_property("skill level", (int)from->query_skill(name));
    this_object()->rune_func(from,at);
    return;
}


string query_stat() { return stat; }

void set_stat(string what) { stat = lower_case(what); }

void set_dev_cost(int cost) { props["dev cost"] = cost; }

void set_fast_dev_cost(int cost) { props["fast dev cost"] = cost; }

int query_dev() { return props["dev cost"]; }

int query_fast_dev() { return props["fast dev cost"]; }
