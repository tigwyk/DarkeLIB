inherit "/std/spells/spell";



void create() {

    ::create();

    set_property("name","soultaker blade");

    set_property("skill","chaos magic");

    set_property("casting time",20);

    set_property("base mp cost",74);

    set_property("dev cost", 119);

    set_property("fast dev cost",299);

    set_property("spell level", 25);

    set_property("moon","luna");

    set_property("damage multiplier", 1);

    set_property("caster message","You cast soultaker blade on $T!");

    set_property("target message","");

    set_property("observer message","$C casts soultaker blade on $T.");

    set_property("must be present", 1);

    set_property("target type", "any");

    set_property("prereq", "essence blade");
    set_property("duration", 360);

    return;

}



void info() {

message("help",

"This spell must be cast on a weapon which the caster is holding.  It imbues "

"the weapon with a special power...to drain souls!  With every successful hit, "

"the blade will drink the soul from the target and transfer it to "

"the caster.\n"

"Usage: cast *2 soultaker blade at sword",

this_player());

}



void spell_func(object caster, object at, int power, string args, int flag) {

//  object ob;



  if(!at->is_weapon()) {

    message("info", "You must cast this spell at a weapon.", caster);

    caster->add_mp(props["mp cost"]);

    remove();

    return;

  }

  if(at->query("vampiric")) {

    message("info", "A weapon may only receive one spell of this type at a time.",

          caster);

    caster->add_mp(props["mp cost"]);

    remove();

    return;

  }

  if(at->query_hit()) {

    message("info", "This weapon may not recieve soultaker blade at "

            "this time.", caster);

    caster->add_mp(props["mp cost"]);

    remove();

    return;

  }

  if(flag)

    message("info", "Despite the fumble, the spell seems to have proceeded properly.",

        caster);

  seteuid(getuid());

  at->set("vampiric", 1);

  power *= 2;

  if(flag) power *= -1;

  at->set_hit((: call_other, 

	       "/wizards/diewarzau/obj/misc/vamp_mphp_func",

	       "vampiric_func", power :));

  delayed_call("remove_spell", props["duration"], at, caster);

  return;

}



void remove_spell(object at, object caster) {

  if(!at) return;

  at->set_hit(0);

  at->set("vampiric", 0);

  if(caster) message("info", "%^MAGENTA%^%^BOLD%^Soultaker blade wears off.",

		     caster);

  remove();

  return;

}



