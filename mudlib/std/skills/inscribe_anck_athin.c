inherit "/std/skills/long_term.c";
inherit "/std/check_brittle";

int skill;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(17);
    set_fast_dev_cost(45);
    set_property("prereq", "engrave");
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill is used to inscribe a Anck Athin rune (slicing rune) on a weapon."
"This rune adds cutting damage to the weapon permanently.  The amount of damage "
"depends on skill level.  This is a long-term skill ('help long-term') and takes "
"much real time to use.  If interrupted, you may pick up the skill again later "
"by 'use'-ing the skill again.\n"
  "Syntax: use inscribe anck athin at <weapon>",
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
  if(sizeof(tmp) >= 3) {
    message("info", "No weapon may receive more than 3 runes.", from);
    remove();
    return;
  }
  if(member_array("anck athin", tmp) >= 0) {
    message("info", "That weapon already has a anck athin rune on it.", from);
    remove();
    return;
  }
  skill = props["skill level"];
  time = 2000 - (skill * 9);
  if(time < 600) time = 600;
  message("info", "You begin inscribing.", from);
  set_work_message("You inscribe upon the weapon.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  mapping wc;
  int i;
  string *runes, *wc_keys;
  mixed tmp;
  
  message("info", "You finish inscribing the rune.",
    from);
  if(!check_brittle(at, from, 8)) {
    remove();
    return;
  }
  wc = (mapping)at->all_base_wc();
  if(!wc) wc = ([]);
  if(!wc["impact"]) wc["cutting"] = 0;
  wc["impact"] += skill / 6 + 2;
  if(!wc["crushing"]) wc["impaling"] = 0;
  wc["crushing"] += skill / 6 + 2;
  wc_keys = keys(wc);
  i = sizeof(wc_keys);
  while(i--)
    at->set_wc(wc[wc_keys[i]], wc_keys[i]);
    message("info", "A %^YELLOW%^Anck Athin%^RESET%^ rune appears on the weapon.", from);
  if(!(runes=(string *)at->query_property("runes")))
    runes = ({});
  runes += ({ "anck athin" });
  at->set_property("runes", runes);
  tmp = at->query_property("extra long");
    if(pointerp(tmp)) tmp += ({ "A %^YELLOW%^Anck Athin%^RESET%^ rune is inscribed on the weapon." });
    else if(stringp(tmp)) tmp = ({ tmp, "A %^YELLOW%^Anck Athin%^RESET%^ rune is inscribed on the weapon." });
  else tmp = ({ "A %^YELLOW%^Anck Athin%^RESET%^ rune is inscribed on the weapon." });
  at->set_property("extra long", tmp);
  remove();
  return;
}
