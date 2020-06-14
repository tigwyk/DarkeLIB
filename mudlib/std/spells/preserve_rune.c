inherit "/std/spells/long_term_spell";

object rune;

void create() {
    ::create();
    set_property("name","preserve rune");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",69);
    set_property("dev cost", 64);
    set_property("fast dev cost", 195);
    set_property("spell level", 12);
    set_property("moon","luna");
    set_property("caster message","You begin to stabilize the rune.");
    set_property("target message","");
    set_property("observer message","$C begins to magically stabilize a rune.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("can be in room", 1);
    set_property("prereq", "delay rune");
    return;
}

void info() {
message("help",
"This spell allows you to make a rune permanent.  It will stay until a reboot, "
"and it will save past reboots if it is in a room capable of saving chests, e.g. "
"inn rooms or castles.  This spell also adds 3 commands to the rune, which "
"you can use to make certain players besides the caster of the rune immune to "
"the rune.  You can preserve a rune cast by another player, but you will not take "
"control of it.\n"
"Extra commands:\n"
"runeadd <player> to <rune>\n"
"    adds a player to the immune list.\n"
"runeremove <player> from <rune>\n"
"    removes a player from the list.\n"
"runelist <rune>\n"
"    lists all immune players (caster will not be listed).\n"
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time, mod;
  if(!at->is_rune()) {
    message("info", "You must cast this spell at a rune.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the energies of the spell and erase "+
	    "the rune!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently erases a rune.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if((int)at->query_level() > (props["extra power"] ? power + props["extra power"] : power)) {
    message("info", "You must cast this spell at a power equal to or greater than the rune's power.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("%^CYAN%^You are stabilizing the rune.");
  at->start_preserve();
  rune = at;
  time = 60 + 20*power;
  mod = 40+2*props["spell level"];
  start_work(at, caster, (time*mod)/caster->query_skill("enchantment"), power);
  return;
}

void move_me(object who) {
  if(rune) rune->set_dur(300);
  ::move_me(who);
  return;
}

void finish_work(object caster, object at, int power) {
//  object ob;

  if(power <= 0) {
    message("info", "BUG in Rune spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "The rune is now permanent!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations.",
	  environment(caster), ({ caster }) );
	at->preserve_me();
  remove();
  return;
}

