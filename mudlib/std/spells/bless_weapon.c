inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle"; 

void create() {
    ::create();
    set_property("name","bless weapon");
    set_property("skill","prayer");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",55);
    set_property("dev cost", 17);
    set_property("fast dev cost", 51);
    set_property("spell level", 4);
    set_property("moon","luna");
    set_property("caster message","You begin to pray upon the weapon.");
    set_property("target message","");
    set_property("observer message","$C begins to pray upon a weapon.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help", @TEXT
This prayer (if successful) will confer a blessing from the Divine
and become a sanctioned weapon for in the war against evil. Only
4 of these spells may be stacked on any weapon.  You may not cast
bless weapon with any other primary enchantment or prayer.  This
is a long-term spell (see help long-term), and may take much real
time to cast.  If you are interrupted while casting, you may pick
up again at a later time.
TEXT
,this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "Impure thoughts invade your mind and unconciously "+
      "quake and scream, drop the weapon and it crumbles to dust!", caster);
    message("info", (string)caster->query_cap_name() +
      " screams, drops the weapon and it crumbles to dust.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  if((int)at->query_property("flame blade") ||
    (int)at->query_property("icy weapon") ||
    (int)at->query_property("holy weapon") ||
    (int)at->query_property("blessed weapon") >=4 ) {
    message("info", "This weapon can not receive any additional blessing.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  set_work_message("%^CYAN%^You pray over the weapon.");
  start_work(at, caster, 480 + 90*power, power);
  return;
}

void finish_work(object caster, object at, int power) {
  int ench, i, idx;
  mixed tmp;

  if(power <= 0) {
    message("info", "BUG in Cleric Bless Weapon spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }

  message("info", "You are finished praying over the weapon!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
    "holy words and makes a sign over a weapon with "+
    (string)caster->query_possessive()+" hands.",
	  environment(caster), ({ caster }) );
  /*
   * Brittle code follows...
   */
  if(!check_brittle(at, caster, power)) {
    remove();
    return;
  }
  /*
   * End of brittle code
   */
  
  ench = (int)at->query_property("blessed weapon");
  if(!ench) ench = 0;
  if(ench + 1 >= 4) {
    message("info", "This weapon has received its limit of Divine blessings "+
	    "this prayer.", caster);
    at->set_property("blessed weapon", 4);
  } else {
    at->set_property("blessed weapon", ench + 1);
  }
  ench = (int)at->query_wc("holy");
  if(!ench) ench = power+2;
  else ench += power+2;
  at->set_wc(ench, "holy");
  tmp = (mixed)at->query_property("extra long");
  if(!tmp) tmp = ({});
  else if(stringp(tmp)) tmp = ({ tmp });
  idx = -1;
  i = sizeof(tmp);
  while(i--) {
    if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 &&
       decolorize(tmp[i][0]) == "This weapon is a Blessed Weapon.") idx = 1;
  }
  if(idx < 0)
    tmp += ({ ({ "This weapon is a %^BOLD%^Blessed Weapon%^RESET%^." ,
		   "detect magic" }) });
  at->set_property("extra long", tmp);
  remove();
  return;
}

