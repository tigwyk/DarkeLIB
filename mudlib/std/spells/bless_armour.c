inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","bless armour");
    set_property("skill","prayer");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",43);
    set_property("dev cost", 17);
    set_property("fast dev cost", 56);
    set_property("spell level", 3);
    set_property("moon","luna");
    set_property("caster message","You begin to pray over a piece of armour.");
    set_property("target message","");
    set_property("observer message","$C begins to pray over a piece of armour.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This prayer adds a small bit of extra protection to a piece of armour.  There is a "
"limit to which any piece of armour can be enchanted, and you will be informed when that limit is reached.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time, mod;
  if(!at->is_armour()) {
    message("info", "You must cast this spell at a piece of armour.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "Impure thoughts ruin your prayer and destroy the armour!", caster);
    message("info", (string)caster->query_cap_name() +
	    "'s impure thoughts destroy the armour.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if((int)at->query_property("enchantment") >= 10) {
    message("info", "This armour may receive no further "+
      "blessings.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("%^CYAN%^You pray over the armour.");
  time = 660+210*power;
  mod = 30+2*props["spell level"];
  start_work(at, caster, (time*mod)/caster->query_skill("prayer"), power);
  return;
}

void finish_work(object caster, object at, int power) {
  int ench, i, idx;
  mixed tmp;

  if(power <= 0) {
    message("info", "BUG in Cleric spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You are finished praying!", caster);
  message("info", (string)caster->query_cap_name() + " mutters some "+
	  "holy words.",
	  environment(caster), ({ caster }) );
	ench = (int)at->query_property("enchantment");
	if(!ench) ench = 0;
	if(ench + power >= 10) {
	  message("info", "This armour is now blessed as much as is possible with "+
	      "this spell.", caster);
	  at->set_property("enchantment", 10);
	  ench = 10-power;
	} 
	else
	  {
	    at->set_property("enchantment", ench + power);
	  }
	tmp = (mixed)at->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
      arrange_string(tmp[i][0], 14) == "Blessing:") idx = i;
  }
  if(idx >= 0) tmp = exclude_array(tmp, idx);
  tmp += ({ ({ sprintf("Blessing: %%^CYAN%%^%+d", power+ench),
    "detect magic" }) });
  at->set_property("extra long", tmp);
  remove();
  return;
}

