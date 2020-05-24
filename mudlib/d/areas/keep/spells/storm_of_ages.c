inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "storm of ages");
set_property("skill", "owedquar's will");
set_property("casting time", 10);
set_property("base mp cost", 1020);
set_property("dev cost", 982);
set_property("fast dev cost", 3125);
set_property("spell level", 50);
set_property("moon", "warzau");
set_property("caster message", "You will a petrifying storm of darkness into existence.");
set_property("target message", "$C wills a petrifying storm of darkness into existence!");
set_property("observer message", "$C wills a petrifying storm of darkness into existence!");
set_property("spell type", ({ "area damage" }));
set_property("damage types", ([ "disruption" : 250, "infernal" : 250, "stress" : 250 ]));
set_property("damage multiplier", 30);
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("no target", 1);
return;
}

void info() {
message("help", "This is the most powerful offensive magic available to a follower of Owedquar, available only to the worthy chosen by the dark god himself. This spell calls forth a violent storm of chaotic and infernal energy, causing tremendous damage to anyone or anything unfortunate enough to be caught in its wake. When the storm passes, even the most seasoned warriors will most likely be turned into lifeless mutilated corpses.", this_player()); 
}
