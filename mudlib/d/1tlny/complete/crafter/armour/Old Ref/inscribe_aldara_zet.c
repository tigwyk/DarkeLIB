inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(17);
    set_fast_dev_cost(47);
    set_property("target type", "any");
    set_property("prereq", "engrave");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a aldara zet rune (feather-weight rune) on an armour.  "
"This rune reduces the weight of the armour.  The potency of the rune "
"depends on skill level.  This is a long-term skill ('help ling-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
"Syntax: use inscribe aldara zet at <armour>",
	this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

  if(!at->is_armour()) {
    message("info", "This skill must be used on a piece of armour.", from);
    remove();
    return;
  }
  fname = file_name(at);
  if(strlen(fname) < 18 || fname[0..17] != "/d/damned/virtual/") {
    message("info", "Runes may only be inscribed on 'generic' armours, "+
      "i.e., those forged by tinkers or purchased at a shop.", from);
    remove();
    return;
  }
  while(shadow(at, 0)) shadow(at, 0)->external_destruct(shadow(at, 0));
  tmp = (string *)at->query_property("runes");
  if(!tmp) tmp = ({});
  if(sizeof(tmp) >= 10) {
    message("info", "No armour may receive more than 10 runes.",
      from);
    remove();
    return;
  }
  if(member_array("aldara zet", tmp) >= 0) {
    message("info", "That armour already has an aldara zet rune on it.",
      from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 1600 - (skill * 8);
  if(time < 500) time = 500;
  message("info", "%^CYAN%^%^BOLD%^You begin inscribing.", from);
  set_work_message("%^CYAN%^You inscribe upon the armour.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  int i, weight;
  mixed tmp;
  string *runes;
  
  message("info", "%^CYAN%^%^BOLD%^You finish inscribing the rune.",
    from);
  message("info", "A %^GREEN%^%^BOLD%^Aldara Zet%^RESET%^ rune appears on the armour.", from);
  weight = (int)at->query_weight();
  weight -= (2*skill / 3) * weight / 100;
  at->set_weight(weight);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "aldara zet" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
  if(pointerp(tmp)) tmp += ({ "A %^YELLOW%^%^BOLD%^Aldara Zet%^RESET%^ rune is inscribed on the armour." });
  else if(stringp(tmp)) tmp = ({ tmp, "A %^YELLOW%^%^BOLD%^Aldara Zet%^RESET%^ rune is inscribed on the armour." });
  else tmp = ({ "A %^YELLOW%^%^BOLD%^Aldara Zet%^RESET%^ rune is inscribed on the armour." });
  at->set_property("extra long", tmp);
  remove();
  return;
}

