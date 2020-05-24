inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "ultimate elemental burst");
    set_property("skill", "elemental magic");
    set_property("casting time", 25);
    set_property("dev cost", 835);
    set_property("fast dev cost", 2256);
    set_property("spell level", 55);
    set_property("moon", "warzau");
    set_property("caster message", "%^B_RED%^%^YELLOW%^You devastate the room with a cataclysmic elemental explosion!%^RESET%^");
    set_property("target message", "");
    set_property("observer message", "%^B_RED%^%^YELLOW%^$C devastates the room with a cataclysmic elemental explosion!%^RESET%^");
    set_property("damage multiplier", 45);
    set_property("spell type", ({ "area damage" }));
    set_property("must be present", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 850\n\nThis sickening spell is the most powerful single connection area spell that an Elemental Mage can cast, and is considerably more powerful than extreme elemental burst. When cast, the spell draws almost 100% pure elemental energy from a mass and creates a realm shattering explosion, causing absolutely insane and often times fatal damage to all targets present in a given room excluding the caster's mass. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass. When casting this spell, no target need be supplied.\n\nSyntax: 'cast *6 ultimate elemental burst'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    object obmass;
    mapping dmg;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 850) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 850));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 400) {
		    loreskill1 = 400;
		}
		if(loreskill2 > 400) {
		    loreskill2 = 400;
		}
		if(loreskill3 > 400) {
		    loreskill3 = 400;
		}
		if(loreskill4 > 400) {
		    loreskill4 = 400;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2) ]));
		if(inv[i]->query_property("lore name two") != 0) {
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2) ]));
		if(inv[i]->query_property("lore name three") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5, ""+lorename2+"" : loreskill2/1.5, ""+lorename3+"" : loreskill3/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2), ""+lorename3+"" : loreskill3/(3/2) ]));
		if(inv[i]->query_property("lore name four") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5, ""+lorename2+"" : loreskill2/1.5, ""+lorename3+"" : loreskill3/1.5, ""+lorename4+"" : loreskill4/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2), ""+lorename3+"" : loreskill3/(3/2), ""+lorename4+"" : loreskill4/(3/2) ]));
	    }
	}
    }
}
message("info", "%^RED%^You expend %^RESET%^850 %^RED%^energy units to cast the spell.%^RESET%^", caster);
obmass = inv[i];
obmass->move("/d/damned/arena/trashroom");
::spell_func(caster, at, power, args, flag);
obmass->move(environment(caster));
obmass->force_me("use stalk at "+ this_player()->query_cap_name());
remove();
return;
}
if(inv[i]->query_property("energy units") < 850) {
    message("info", "There is not enough power left in your energy mass to cast this spell.", caster);
    remove();
    return;
}
}
}
message("info", "There is no energy mass present owned by you that you can draw power from.", caster);
remove();
return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
