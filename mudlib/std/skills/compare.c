inherit "/std/skills/skill";

string wc_str(int wc);
int abs(int num);

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(17);
    set_fast_dev_cost(55);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill may be used to compare two armours or weapons to see which will "+
"fare better in combat.  Use it with the following format:\n"+
"	use compare at sword and mace\n"+
"	use compare at helmet and breastplate\n",
this_player());
}

string wc_str(int wc) {
  switch(wc) {
  case -100..0:
    return "terrible";
  case 1..5:
    return "poor";
  case 6..10:
    return "below avg";
  case 11..17:
    return "average";
  case 18..27:
    return "above avg";
  case 28..40:
    return "good";
  case 41..60:
    return "excellent";
  case 61..99:
    return "awesome";
  case 100..10000:
    return "INSANE";
  default:
    return "terrible";
  }
}

void skill_func(object from, object at, string arg) {
  object *ob;
  string tmp, *types1, *types2, what1, what2;
  float *avg;
  int *wc;
  int *vals, count, which, i;

  if(sscanf(arg, "%s and %s", what1, what2) != 2) {
    message("info", "Format: use compare at <what> and <what>",from);
    remove();
    return;
  }
  ob = allocate(2);
  ob[0] = present(what1, from);
  ob[1] = present(what2, from);
  if(!ob[0]) {
    message("info", "You do not have a "+what1+".", from);
    remove();
    return;
  }
  if(!ob[1]) {
    message("info", "You do not have a "+what2+".", from);
    remove();
    return;
  }
  count = (member_array("std/weapon.c", deep_inherit_list(ob[0])) >= 0 &&
	   member_array("std/weapon.c", deep_inherit_list(ob[1])) >= 0);
  count = count || (member_array("std/armour.c", deep_inherit_list(ob[0])) >= 0 &&
		    member_array("std/armour.c", deep_inherit_list(ob[1])) >= 0);
  if(!count) {
    message("info", "The items you compare must either be both weapons or "+
	    "both armours.", from);
    remove();
    return;
  }
  if(ob[0]->is_weapon()) {
    switch(props["skill level"]) {
    case 61..10000:
      types1 = keys(ob[0]->query_all_wc());
      types2 = keys(ob[1]->query_all_wc());
      tmp = sprintf("%-31s %-31s", (string)ob[0]->query_short(),
		    (string)ob[1]->query_short()) + "\n";
      for(i = 0; (i < sizeof(types1) && i < sizeof(types2)); i++) {
	if(i < sizeof(types1))
	  what1 = sprintf("%-15s %-10s      ",types1[i]+":",
			  wc_str((int)ob[0]->query_wc(types1[i])));
	else what1 = sprintf("%' '31s ", "");
	if(i < sizeof(types2))
	  what2 = sprintf("%-20s %-10s",types2[i]+":",
                          wc_str((int)ob[1]->query_wc(types2[i])));
        else what2 = sprintf("%' '31s", "");
	tmp += what1 + what2 + "\n";
      }
      message("my_action", tmp+"\n", from);
    case -10..60:
      wc = allocate(2);
      for(i=0; i<=1; i++) {
      	vals = values(ob[i]->query_all_wc());
	count = sizeof(vals);
	while(count--) wc[i] += vals[count];
      }
      if(abs(wc[0] - wc[1]) < ((100 - props["skill level"])) / 5) {
	message("my_action", "The two appear to be roughly equal.", from);
	remove();
	return;
      }
      if(wc[0] > wc[1]) i = 0;
      else i = 1;
      message("my_action", (string)ob[i]->query_short() + " seems to be "+
	      "the better weapon.", from);
      remove();
      return;
    }
    remove();
    return;
  } else {
    switch(props["skill level"]) {
    case 61..10000:
      types1 = keys(ob[0]->query_all_ac());
      types2 = keys(ob[1]->query_all_ac());
      tmp = sprintf("%-31s %-31s", (string)ob[0]->query_short(),
                    (string)ob[1]->query_short()) + "\n";
      for(i = 0; (i < sizeof(types1) && i < sizeof(types2)); i++) {
        if(i < sizeof(types1))
          what1 = sprintf("%-15s %-10s      ",types1[i]+":",
                          wc_str((int)ob[0]->query_ac(types1[i])));
        else what1 = sprintf("%' '31s ", "");
        if(i < sizeof(types2))
          what2 = sprintf("%-15s %-10s     ",types2[i]+":",
                          wc_str((int)ob[1]->query_ac(types2[i])));
        else what2 = sprintf("%' '31s", "");
        tmp += what1 + what2 + "\n";
      }
      message("my_action", tmp+"\n", from);
    case -100..60:
      avg = allocate(2);
      avg[0] = 0.0;  avg[1] = 0.0;
      for(i=0; i <= 1; i++) {
	vals = values(ob[i]->query_all_ac());
	for(count = 0; count < sizeof(vals); count++)
	  avg[i] += vals[count];
	avg[i] /= (count + 1);
      }
      if(abs(to_int(avg[0] - avg[1])) < ((100 - props["skill level"]) / 7)) {
        message("my_action", "The two appear to be roughly equal.", from);
        remove();
        return;
      }
      if(avg[0] > avg[1]) i = 0;
      else i = 1;
      message("my_action", (string)ob[i]->query_short() + " seems to be "+
              "the better armour.", from);
    default:
      remove();
      return;
    }
    remove();
    return;
  }
  remove();
  return;
}

int abs(int num) {
  if(num >= 0) return num;
  else return -1 * num;
}
