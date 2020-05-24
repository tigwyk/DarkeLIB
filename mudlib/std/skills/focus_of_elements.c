inherit "/std/skills/skill.c";

int sk_bonus;
int med;
object shad;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(10);
    set_fast_dev_cost(35);
    set_property("no target", 1);
}

void info() {
message("help",
"This spell is used to gather the force of a single element for use in casting.  "
"A bonus is given to the lore skill in the chosen element, which decays over time.  "
"Higher skill level allows you to use the skill more often and to focus in less time.\n"
"Syntax: use focus of elements at <element>\n"
"Ex: use focus of elements at fire"
	, this_player());
}

void skill_func(object from, object at, string arg) {
  object ob;
  int time;
  
  if(props["skill level"] < 0) props["skill level"] = 0;
  if((time() - (int)from->query_last_use("focus of elements")) < (3600 /
    (props["skill level"]/5+1)))
    {
    message("info", "You may only use this skill once every "+
      sprintf("%d minutes (real time).", (60 / (props["skill level"]/5+1))), from);
    remove();
    return;
  }
  if(from->query("focus of elements")) {
    message("info", "You are already using focus of elements.", from);
    remove();
    return;
  }
  if(!arg) {
    message("info", "See 'help skill focus of elements' for syntax.", from);
    remove();
    return;
  }
// heh, ummm yeah, trade is an elemental lore (TM April 2K)
if(lower_case(arg)=="trade"){
message("info", "%^YELLOW%^That's not an elemental lore, what are you dumb?", from);
remove();
return;
}

  arg = lower_case(arg);
  if(!from->query_skill(arg+" lore")) {
    message("info", "You must choose an element for which you have a lore "
      "skill.", from);
    remove();
    return;
  }
  from->set_last_use("focus of elements");
  from->set("focus of elements", 1);
  message("info", "%^CYAN%^You begin to call on the elemental focus....",
    from);
  ob = new("/std/spells/shadows/move_shadow");
  ob->set_move_func((: call_other, this_object(), "stop_med" :));
  ob->set_move_arg(from);
  med = 1;
  time = 100 - props["skill level"]/2;
  if(time < 10) time = 10;
  shad = ob;
  delayed_call("do_focus", time, from, arg);
  return;
}

void stop_med(object from) {
  if(!med) return;
  message("info", "%^CYAN%^You interrupt your focusing efforts.\n",
    from);
  if(shad) shad->external_destruct(shad);
  remove_delayed_call("do_focus");
  remove();
  return;
}

int clean_up() { return 0; }

void do_focus(object from, string arg) {
  if(!from) {
    remove();
    return;
  }
  med = 0;
  if(shad) shad->external_destruct(shad);
  message("info", "%^CYAN%^You call upon the focus of "+arg+".", from);
  sk_bonus = 30 + random(10) + random(10);
  message("info", sprintf("You receive a %d%% bonus to you %s lore skill.",
    sk_bonus, arg), from);
  arg += " lore";
  from->add_skill_bonus(arg, sk_bonus);
  delayed_call("reduce_bonus", 60, from, arg);
  return;
}

void reduce_bonus(object from, string arg) {
  if(!from) {
    remove();
    return;
  }
  if((sk_bonus - 5) <= 0) {
    from->add_skill_bonus(arg, -1 * sk_bonus);
    from->set("focus of elements", 0);
    write("Your focus of elements disappears.\n");
    remove();
    return;
  }
  sk_bonus -= 5;
  from->add_skill_bonus(arg, -5);
  delayed_call("reduce_bonus", 60, from, arg);
  return;
}

