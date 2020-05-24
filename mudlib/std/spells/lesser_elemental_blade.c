inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("stack key", "ele weapon");
    set_property("stack num", 3);
    set_property("name","lesser elemental blade");
    set_property("skill","elementalism");
    set_property("casting time",3);
    set_property("base mp cost",15);
    set_property("dev cost",17);
    set_property("fast dev cost",51);
    set_property("spell level", 3);
    set_property("moon","warzau");
    set_property("caster message","You cast a lesser elemental blade at $T!");
    set_property("target message","");
    set_property("observer message","$C casts a lesser elemental blade at $T.");
    set_property("duration", 180);
    set_property("must be present", 1);
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("target type", "any");
    return;
}

void info() {
message("help",
"This spell imbues any weapon with a small deal of elemental "
"damage.  It is an elemental spell (see 'help spellsys').",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
  string *ele;
  int i;
  mapping tmp;
  
  if(!at->is_weapon()) {
    message("info", "This spell must be cast on a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }
  ele = props["element types"];
  if(!pointerp(ele) || !sizeof(ele)) {
    message("info", "There is a bug with this spell!", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 3*power ]);
  seteuid(getuid());
  
  ob = new("/std/spells/shadows/weapon_shadow");
  if(check_stack(at, ob)) {
	message("info", "You imbue the weapon with the power of "+props["element"]+".", caster);
	ob->set_extra_wc(tmp);
	ob->start_shadow(at, props["duration"], "%^CYAN%^An elemental blade spell wears off.");
  }
  else {
    message("info", "You may not stack any further elemental blades on that weapon.", caster);
    caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
  }
    remove();
    return;
}


  
  
