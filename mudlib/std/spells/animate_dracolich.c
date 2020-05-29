inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","animate dracolich");
    set_property("skill","necromancy");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",221);
    set_property("dev cost", 123);
    set_property("fast dev cost", 361);
    set_property("spell level", 24);
    set_property("moon","luna");
    set_property("caster message","You begin to animate the corpse.");
    set_property("target message","");
    set_property("observer message","$C begins to animate a corpse.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("prereq", "animate demilich");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell animates a corpse into a Dracolich, a powerful, undead dragon, who will serve you as an undead thrall.  "
"She will serve you by fighting beside you in combat.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  The spell must be cast on an embalmed corpse of level 1 or higher, which must "
"be prepared with the 'prepare corpse' skill.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(!at->id("embalmed corpse")) {
    message("info", "You must cast this spell at an embalmed corpse.",
	    caster);
    remove();
    return;
  }
  if((int)at->query_level() < query_property("spell level")) {
    message("info", "You must cast this spell on an embalmed corpse of at least "+
      sprintf("level %d.", query_property("spell level")), caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the summoning energies and destroy "+
	    "the corpse!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently crumbles an embalmed corpse to dust.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("%^GREEN%^You mold the corpse.");
  start_work(at, caster, 7400+560*power, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in undead spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "The corpse transforms into a "+
	  "Dracolich.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "necromantic incantations, and an embalmed corpse "+
	  "transforms into a Dracolich.",
	  environment(caster), ({ caster }) );
	message("info", "%^GREEN%^%^BOLD%^The roar of the mighty Dracolich is heard across the land.",
	    users());
  at->remove();
  seteuid(getuid());
  ob = new("/wizards/diewarzau/obj/pet/dracolich");
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}

