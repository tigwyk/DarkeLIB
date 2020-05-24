inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(19);
    set_fast_dev_cost(49);
    set_property("target type", "any");
    set_property("prereq", "engrave");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a harah lit rune (quickness rune) on a weapon.  "
"This rune allows the wielder of the weapon to gain extra attacks.  The potency of the rune "
"depends on skill level.  This is a long-term skill ('help ling-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
"Syntax: use inscribe harah lit at <weapon>",
	this_player());
}

void skill_func(object from, object at, string arg) {
  string *tmp, fname;
  int time;

  if(!at->is_weapon()) {
    message("info", "This skill must be used on a weapon.", from);
    remove();
    return;
  }
  fname = file_name(at);
  if(strlen(fname) < 18 || fname[0..17] != "/d/damned/virtual/") {
    message("info", "Runes may only be inscribed on 'generic' weapons, "+
      "i.e., those forged by tinkers or purchased at a shop.", from);
    remove();
    return;
  }
  while(shadow(at, 0)) shadow(at, 0)->external_destruct(shadow(at, 0));
  tmp = (string *)at->query_property("runes");
  if(!tmp) tmp = ({});
  if(sizeof(tmp) >= 10) {
    message("info", "No weapon may receive more than 10 runes.",
      from);
    remove();
    return;
  }
  if(member_array("harah lit", tmp) >= 0) {
    message("info", "That weapon already has a harah lit rune on it.",
      from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 2100 - (skill * 10);
  if(time < 600) time = 600;
  message("info", "%^CYAN%^%^BOLD%^You begin inscribing.", from);
  set_work_message("%^CYAN%^You inscribe upon the weapon.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  int i, hit_bonus;
  mixed auto_crit, tmp;
  string *runes;
  
  message("info", "%^CYAN%^%^BOLD%^You finish inscribing the rune.",
    from);
  message("info", "A %^GREEN%^%^BOLD%^Harah Lit%^RESET%^ rune appears on the weapon.", from);
  auto_crit = from->prop("auto critical");
  if(mapp(auto_crit)) {
    if(auto_crit["speed B"]) {
      i = 1;
      while(auto_crit[sprintf("speed B #%d", i)])
        i++;
      auto_crit[sprintf("speed B #%d", i)] = skill/4 + 2;
    }
    else auto_crit["speed B"] = skill/4 + 2;
  }
  else if(pointerp(auto_crit)) {
    i = sizeof(auto_crit);
    tmp = auto_crit;
    auto_crit = ([]);
    while(i--) auto_crit += ([ tmp[i] : 100 ]);
    auto_crit["speed B"] = skill / 4 + 2;
  }
  else auto_crit = ([ "speed B" : (skill/4+2) ]);
  at->set_property("auto critical", auto_crit);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "harah lit" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
  if(pointerp(tmp)) tmp += ({ "A %^MAGENTA%^%^BOLD%^Harah Lit%^RESET%^ rune is inscribed on the weapon." });
  else if(stringp(tmp)) tmp = ({ tmp, "A %^MAGENTA%^%^BOLD%^Harah Lit%^RESET%^ rune is inscribed on the weapon." });
  else tmp = ({ "A %^MAGENTA%^%^BOLD%^Harah Lit%^RESET%^ rune is inscribed on the weapon." });
  at->set_property("extra long", tmp);
  remove();
  return;
}

