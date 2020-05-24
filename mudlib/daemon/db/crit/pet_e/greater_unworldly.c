// /wizards/excelsior/crits/greater_unworldly
// coded up for Aether critical hits by Excelsior 4/8/96

inherit "std/pet";

void create() {
	::create();
	set_name("unworldy");
	set("id",({"unwordly","thing","creature"}));
	set_level(19);
	set("short","%^GREEN%^%^BOLD%^powerful%^RESET%^ "+
		"%^BOLD%^%^RED%^strange and unworldy creature");
	set("long","This strange and powerful being does not appear to be from any "+
		"nearby dimension. It is large and blob like, having no definite shape, "+
		"but instead lives by assimilating all mater around it into itself. "+
		"Fearsome.");
	set_attack(1);
	set("race","unworldy");
	set_gender("neuter");
	set_body_type("sphere");
	set_overall_ac(16);
	set_melee_damage((["aether":10,"holy":26,"impaling":35]));
	set_skill("melee",120);
	set_skill("attack",103);
}
