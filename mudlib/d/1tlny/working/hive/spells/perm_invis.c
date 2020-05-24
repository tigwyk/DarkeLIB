inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","improved invisibility");
    set_property("skill","illusionism");
    set_property("casting time",13);
    set_property("base mp cost",82);
    set_property("dev cost", 105);
    set_property("fast dev cost", 305);
    set_property("spell level", 20);
    set_property("moon","luna");
    set_property("caster message","You cast impoved invisibility.");
    set_property("target message","");
    set_property("observer message","$C casts imporved invisibility.");
    set_property("spell type",({ }));
    set_property("duration", 32000);
    set_property("no target", 1);
    return;
}

void info() {
message("help",
"This is a more powerful version of the 'invisibility' spell with two important "
"differences.  First, it may only be cast at the caster (you need not supply a target).  "
"Second, attacking or being attacked does NOT cancel the spell!  You can still be "
"hit while invisible, but a substantial penalty is incurred.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  at = caster;
  if(flag) {
    message("info", "Hmm...the spell seems to have worked...", caster);
    message("info", "Everything seems fine...BUT WAIT...you're invisible, "+
          "but you are BLIND TOO!", at);
    ob = new("/std/spells/shadows/blind_shadow");
    ob->start_shadow(at);
    call_out("expire_blind", props["duration"], at, ob);
  }
  if(at->query_invis()) {
    message("info", nominative(at) + " is already invisible...your spell fails.",
       caster);
    message("info", "%^CYAN%^"+(string)caster->query_cap_name() +
          "'s spell fails.", environment(caster), ({ caster }) );
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  message("info", "You fade into invisibility...",
        at);
  message("info", (string)at->query_cap_name() +
        " fades from sight.",
        environment(caster), ({ caster }) );
  ob = new("/std/spells/shadows/imp_invis_shadow");
  ob->start_shadow(at, props["duration"], "%^CYAN%^An improved invisibility spell wears off.");
  remove();
  return;
}
