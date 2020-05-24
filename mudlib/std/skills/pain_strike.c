inherit "/std/skills/skill";

   int stabkeeper = 1;
   int ready = 0;
void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(27);
    set_fast_dev_cost(78);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 200%\n\nThis skill is a considerably more powerful version of the lower level 'assassination' skill for Assassins. It enables an Assassin to strike his or her weapon at a target with almost perfectly precise percision and timing, making it far more difficult to reverse than weaker assassination skills and being far more effective against opposing armour with damage determined by WC and skill level as well as the armour. This skill however has a much longer delay than lower assassinations have and is notably expensive to train, and cannot be executed at the same time as those other skills.\n\nSyntax: 'use pain strike at atothek'", this_player());
}

void skill_func(object from, object at, string arg) {
    object *inv;
    int offense;
    int defense;
    int skill;
    int damage;
    int hit;
    int randomizer;
    int difference;
    int stdifference;
    int value;
    int mod;

    inv = (object *)from->query_wielded();

    if(at->query_property("no kill")) {
	message("info", "This target cannot be attacked.", from);
	remove();
	return;
    }
    if(at->query_ghost()) {
	message("info", "You cannot use this skill on a ghost.", from);
	remove();
	return;
    }
    if(environment(from) && environment(from)->query_property("no attack")) {
	message("info", "Greater powers prevent your malice.", from);
	remove();
	return;
    }
    if(from->query_current_attacker()) {
	message("info", "You cannot use this skill while engaged in combat.", from);
	remove();
	return;
    }
    if(!inv || !sizeof(inv)) {
	message("info", "You must be wielding a weapon to use this skill.", from);
	remove();
	return;
    }
    if(sizeof(inv) > 1) {
	message("info", "You must be single wielding to use this skill.", from);
	remove();
	return;
    }

    if((time() - (float)from->query_last_use("assassination")) <= 4.100000) {
	message("info", "You are already attempting an assassination at this time.", from);
	remove();
	return;
    }
    offense = (int)inv[0]->query_wc();
    defense = (int)((at->query_ac("right hand") + at->query_ac("left hand") + at->query_ac("left foot") + at->query_ac("right foot") + at->query_ac("right leg") + at->query_ac("left leg") + at->query_ac("right arm") + at->query_ac("left arm") + at->query_ac("torso") + at->query_ac("head")) / 10);
    skill = (int)from->query_skill("pain strike");
    mod = (int)inv[0]->query("assassination mod");

    if(defense < 500) damage = (offense + skill + 25*mod)*10 - defense;
    if(defense >= 1000 < 1500) damage = (offense + skill + 25*mod)*9 - defense;
    if(defense >= 1000 < 1500) damage = (offense + skill + 25*mod)*8 - defense;
    if(defense >= 1500) damage = (offense + skill + 25*mod)*6 - defense;

    randomizer = random(100);
    difference = to_int(to_float((int)from->query_skill("pain strike")) * to_float(2));
    stdifference = to_int(to_float((int)at->query_skill("reverse stroke")) - to_float((int)from->query_skill("pain strike")));
    value = to_int((to_float(stdifference) / to_float(difference)) * to_float(100));

    if((int)at->query_skill("reverse stroke") <= (int)from->query_skill("pain strike")) {
	hit = 1;
    }
    if(((int)at->query_skill("reverse stroke") > (int)from->query_skill("pain strike")) && ((int)at->query_skill("reverse stroke") < (int)from->query_skill("pain strike")*2)) {
	if(randomizer <= value) {
	    hit = 2;
	}
	if(randomizer > value) {
	    hit = 1;
	}
    }
    if((int)at->query_skill("reverse stroke") >= (int)from->query_skill("pain strike")*2) {
	hit = 2;
    }
    from->set_last_use("assassination");

    if(stabkeeper == 1) {
	if(!present(at, environment(from))) {
	    message("info", "You strike your weapon but your target is unfortunately no longer present.", from);
	    remove();
	    return;
	}
	if(hit == 1) {
	    message("info", "%^MAGENTA%^You swiftly deliver a devastating strike to "+(string)at->query_cap_name()+" from behind with your weapon.%^RESET%^", from);
	    message("info", "%^MAGENTA%^You feel a lethally vicious strike devastate your body from behind without warning!%^RESET%^", at);
	    message("info", (string)from->query_cap_name()+" brutally devastates "+(string)at->query_cap_name()+" in an powerful assassination attempt.", environment(from), ({ at, from }));
	    at->add_hp(-(damage));
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
	if(hit == 2) {
	    message("info", "%^MAGENTA%^Your assassination attempt is perfectly read by "+(string)at->query_cap_name()+" and reversed against you!%^RESET%^", from);
	    message("info", "%^MAGENTA%^You read "+(string)from->query_cap_name()+" attempting to brutally strike and assassinate you and reverse the attack against him!%^RESET%^", at);
	    message("info", (string)from->query_cap_name()+" attempts to brutally strike and "+(string)at->query_cap_name()+" but is caught and reverse struck with his own weapon!", environment(from), ({ at, from }));
	    from->add_hp(-(damage/2));
	    at->kill_ob(from, 0);
	    remove();
	    return;
	}
    }
    if(stabkeeper == 0) {
	stabkeeper = 1;
	message("info", "You position yourself directly behind "+(string)at->query_cap_name()+" readying a powerful strike.", from);
	call_out("skill_func", 20, from, at, arg);
    }
}
