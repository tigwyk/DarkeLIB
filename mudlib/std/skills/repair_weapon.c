// Added basic ability to restore weapon quality with a spare ingot
// Tigwyk
// June 2020

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(11);
    set_fast_dev_cost(27);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill may be used to keep weapons in good repair.  "
"Weapons go down in quality after repeated usage, but repairing "
"them periodically can delay, or even prevent this loss.  Note that "
"in order to restore a lost quality level, this skill will consume an "
"ingot of the same material as the targeted weapon.",
this_player());
}


void skill_func(object from, object at, string arg) {
  int max, rep;
  object ingot;
  if(!at->is_weapon()) {
    message("info", "That is not a weapon!", from);
    remove();
    return;
  }
  if(from->query("repair weapon")) {
    message("info", "You can only do that once at a time.", from);
    remove();
    return;
  }

  max = (int)at->query_decay_rate();
  max -= props["skill level"] * max /100;

  if(max < 0) max = 0;
  if(((int)at->query_decay_status() <= max) && ((int)at->query_quality() == 6)) {
    message("info", "You have repaired that weapon as much as your skill allows.",
      from);
    remove();
    return;
  }

  if(((int)at->query_decay_status() == 0) && ((int)at->query_quality() < 6)) {
    //message("info", "You might be able to restore this weapon's quality.", from);
    ingot = present("ingot", from);
    if(!ingot || (ingot && ingot->query_material() != at->query_material())) {
      message("info", "You do not have the required raw materials to restore this weapon's quality.", from);
      remove();
      return;
    } 
  }

  max = (int)at->query_decay_rate() - max;
  rep = (props["skill level"]/2 + random(props["skill level"]/2))*max / 100;
  if((int)at->query_decay_status() <= rep) rep = (int)at->query_decay_status();
  message("info", "%^CYAN%^%^BOLD%^You begin repairing the weapon...", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " begins repairing a weapon.",
      environment(from), ({ from }));
  from->set("repair weapon", 1);
  call_out("repair", 10, rep, at, from);
  return;
}

void repair(int rep, object at, object from) {
  object ingot;
  if(from) from->set("repair weapon", 0);
  if(!present(at, from) && !present(at, environment(from))) {
    message("info", "%^CYAN%^%^BOLD%^You have lost the weapon...the skill fails.",
        from);
    remove();
    return;
  }

  ingot = present("ingot", from);
  
  if(at->query_decay_status() == 0 && at->query_quality() < 6) {
    if (ingot && ingot->query_material() == at->query_material()) {
      message("info","You use up a spare "+ingot->query_property("material_name")+" ingot.", from);
      at->set_quality(at->query_quality()+1);
      ingot->remove();
      } else {
      message("info", "You fail to complete the repairs without a spare "+at->query_property("material_name")+" ingot.", from);
      message("info", (string)from->query_cap_name()+" fails to restore the weapon's quality.", environment(from), ({ from }) );
      return;
    }
  }

  message("info", "%^CYAN%^%^BOLD%^You complete the repairs.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " finishes repairing a weapon.",
      environment(from), ({ from }));
  at->repair(rep);
  remove();
  return;
}

