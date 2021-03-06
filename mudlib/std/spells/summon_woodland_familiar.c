inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","summon woodland familiar");
    set_property("skill","woodland lore");
    set_property("casting time",90);
    set_property("base mp cost", 100);
    set_property("dev cost", 31);
    set_property("fast dev cost", 83);
    set_property("spell level",7);
    set_property("moon","luna");
    set_property("caster message","You summon a familiar.");
    set_property("target message","");
    set_property("observer message","$C summons a familiar.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 600);
    return;
}

void info() {
message("help",
"This spell summons a woodland creature to serve the ranger, binding the
soul "
"of the creature to the it's master.  The creature may aid the ranger in "
"combat.  Greater power summons more powerful familiars.  You may also "
"borrow magic points from the familiar.  Once the familiar is summoned, "
"typing 'help familiar' will tell you how.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob;

  seteuid(getuid());
  ob = new("/d/damned/guilds/ranger/familiar");
  ob->set_up(power);
  ob->move(environment(caster));
  ob->set_dur(props["duration"]);
  ob->set_owner((string)caster->query_name());
  message("info", "You summon "+lower_case((string)ob->query_short()) +
          ".", caster);
  message("info", "A "+lower_case((string)ob->query_short()) +
          " appears.", environment(caster), ({ caster }));
  if(flag) {
    message("info", "You are unable to bond the creature to your soul, " +
            "and it attacks you!", caster);
    ob->force_me("kill "+caster->query_true_name());
  }
  else
    ob->set_master((string)caster->query_name());
  remove();
  return;
}
