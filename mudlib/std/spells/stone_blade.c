inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name","stone blade");
    set_property("skill","woodland lore");
    set_property("casting time",17);
    set_property("base mp cost",55);
    set_property("dev cost",42);
    set_property("fast dev cost",115);
    set_property("spell level", 10);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast stone blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts stone blade at $T.");
    set_property("spell type",({}));
    set_property("duration", 420);
    set_property("must be present", 1);
    set_property("stack key", "stone blade");
    set_property("stack num", 4);
    set_property("target type", "any");
    return;
} 
void info() {
message("help",
"This spell turns your blade to stone , unleashing impact criticals "
"on your enemies!\n",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob;
  if(!at->is_weapon()) {
    message("info", "You must cast this spell at a weapon.", caster);
    caster->add_mp(props["mp cost"]);
    return;
  }
   if(flag) {
    message("info", "The spell fizzles, costing double mp.", caster);
    caster->add_mp(-1* props["mp cost"]);
    remove();
    return;
  }


  ob = new("/std/spells/shadows/weapon_shadow");
  	if(check_stack(at, ob)) {
    message("info", "Your weapon turns to stone.", caster);
		if(power < 4 ){
		ob->set_extra_wc(([ "impact" : 6*power, "crushing" : 6*power ]));
		ob->set_auto_crits((["impact A" : 6*power ])); 
		}
		else{
		ob->set_extra_wc(([ "impact" : 8*power, "crushing" : 8*power ]));
		ob->set_auto_crits((["impact A" : 7*power ] )); 
		ob->start_shadow(at,props["duration"], "%^YELLOW%^A stone blade spell wears off.");
		}
	}	
	else{
	message("info", "You may not stack any further stone blade spells on that weapon.", caster);
    caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);	
	}	
  remove();
  return;
}
