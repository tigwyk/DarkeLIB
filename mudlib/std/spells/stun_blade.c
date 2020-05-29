inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";
void create()
{
    ::create();
    set_property("name","stun blade");
    set_property("skill","magery");
    set_property("casting time",16);
    set_property("base mp cost",45);
    set_property("dev cost",65);
    set_property("fast dev cost",155);
    set_property("spell level", 10);
    set_property("moon","warzau");
    set_property("damage multiplier", 1);
    set_property("caster message","You cast stun blade at $T.");
    set_property("target message","");
    set_property("observer message","$C casts a spell at $T.");
    set_property("spell type",({}));
    set_property("duration", 240);
    set_property("must be present", 1);
    set_property("stack key", "stun blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info()
{
    message("help",
      "This spell imbues your weapon temporarily with the power to stop foes from moving, fighting, or casting!\n",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;

    if(!at->is_weapon())
    {
	message("info", "You must cast this spell at a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    ob = new("/std/spells/shadows/weapon_shadow");
    if(check_stack(at,ob))
    {
	message("info",
	  "%^YELLOW%^Your weapon crackles with stunning energy.%^RESET%^",
	  caster);
	ob->set_extra_wc(([ "impaling" : 5*power ]));
	ob->set_auto_crits((["stun B" : 4*power ] )); 
    ob->start_shadow(at,props["duration"],
      "%^YELLOW%^The energy fades from your weapon abruptly.%^RESET%^"
    );
}
else
{
    message("info","Your weapon may not receive another stun blade "+
      "at this time.",caster);
    ob->external_destruct(ob);
}
remove();
return;
}
