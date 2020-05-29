inherit "/std/spells/spell";



void create() {

    ::create();

    set_property("name","sanctify blade");

    set_property("skill","prayer");

    set_property("casting time",6);

    set_property("base mp cost",23);

    set_property("dev cost",35);

    set_property("fast dev cost",95);

    set_property("spell level", 8);

    set_property("moon","warzau");

    set_property("damage multiplier", 1);

    set_property("caster message","You cast sanctify blade at $T.");

    set_property("target message","");

    set_property("observer message","$C casts sanctify blade at $T.");

    set_property("spell type",({}));

    set_property("duration", 120);

    set_property("must be present", 1);

    set_property("target type", "any");

    return;

}



void info() {

message("help",

"This spell temporarily sanctifies your weapon, making it holy and "

"increasing the damage.\n",

this_player());

}



void spell_func(object caster, object at, int power, string args, int flag) {

  object ob;

  if(!at->is_weapon()) {

    message("info", "You must cast this spell at a weapon.", caster);

    caster->add_mp(props["mp cost"]);

    remove();

    return;

  }



  message("info", "You sanctify your weapon and bless it with holy power.",

          caster);

  ob = new("/std/spells/shadows/weapon_shadow");

  ob->set_extra_wc(([ "holy" : 3*power ]));

  ob->start_shadow(at, props["duration"], "%^CYAN%^A sanctify blade spell wears off.");

  remove();

  return;

}



