inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("stack key", "ele weapon");
    set_property("stack num", 2);
    set_property("name","greater elemental blade");
    set_property("skill","elementalism");
    set_property("casting time",9);
    set_property("base mp cost",68);
    set_property("dev cost",75);
    set_property("fast dev cost",224);
    set_property("spell level", 15);
    set_property("moon","warzau");
    set_property("caster message","You cast greater elemental blade at $T!");
    set_property("target message","");
    set_property("observer message","$C casts greater elemental blade at $T.");
    set_property("duration", 360);
//TLNY 2020 added code
    set_property("spell type",({}));
//TLNY 2020 Duplicates?
   // set_property("must be present", 1);
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("target type", "any");
    set_property("prereq", "elemental blade");
    return;
}

void info() {
message("help",
"This spell imbues any weapon with elemental "
"damage.  It is an elemental spell (see 'help spellsys').",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;
//TLNY 2020 add code
  int stack;
//TLNY 2020 end add
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
  message("info", "You imbue the weapon with the power of "+props["element"]+".",
        caster);
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 10*power ]);
  seteuid(getuid());
  ob = new("/std/spells/shadows/weapon_shadow");
//TLNY 2020 ADD stack code
  if(at->query_property("ele") > 1) {
    message("info", "You may not stack any more greater elemental blade spells on that weapon.",
      caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
//TLNY 2020 end add code

if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }
//TLNY 2020 ADDED STACK CODE
    stack = at->query_property("ele");
	stack += 1;
  at->set_property("ele", stack);
// TLNY 2020 end add
  ob->set_extra_wc(tmp);
  ob->start_shadow(at, props["duration"], "%^CYAN%^An elemental blade spell wears off.");
  remove();
  return;

}

  
