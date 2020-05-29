inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","holy fury");
    set_property("skill","body alteration");
    set_property("casting time",16);
    set_property("base mp cost",25);
    set_property("dev cost", 45);
    set_property("fast dev cost", 105);
    set_property("spell level", 10);
    set_property("moon","luna");
    set_property("caster message",
                "You cast holy fury on $T.");
    set_property("target message","$C casts holy fury on you.");
    set_property("observer message",
                "$C casts holy fury on $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("duration", 120);
    return;
}

void info() {
message("help",
"This spell gives the recipient extra holy energy, allowing him/her to "
"fight faster.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
   object ob;

  seteuid(getuid());
  if(at->query_haste()) {
    message("info", "A target may only receive one spell of this type.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  ob = new("/std/spells/shadows/haste_shadow");
  if(flag) {
    message("info", "You accidentally slow the target!",
      caster);
    ob->set_fumble();
  }
  ob->start_shadow(at, props["duration"], "%^CYAN%^Holy fury wears off.");
  return;
}
