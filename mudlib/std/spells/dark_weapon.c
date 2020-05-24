inherit "/std/spells/long_term_spell";
inherit "/std/check_brittle";

void create() {
::create();
set_property("name", "dark weapon");
set_property("skill", "empowerment");
set_property("duration", "permanent");
set_property("casting time", 10);
set_property("base mp cost", 99);
set_property("dev cost", 66);
set_property("fast dev cost", 200);
set_property("spell level", 8);
set_property("moon", "luna");
set_property("caster message", "You begin to imbue dark power into the weapon.");
set_property("target message", "");
set_property("observer message", "$C begins to imbue dark power into $T.");
set_property("spell type", ({ }));
set_property("target type", "any");
set_property("must be present", 1);
return;
}

void info() {
message("help", "This spell allows a follower of Owedquar to imbue dark power into a weapon which will remain with the weapon indefinitely. The number of times you may cast this spell on a weapon is directly determined by the level of the casters empowerment skill. This is a long-term spell (see help long-term), and may take very much real time to cast. If you are interrupted while casting, you may pick up again at a later time.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
int time;
int mod;
int ctime;

if(!at->is_weapon()) {
message("info", "You may only cast this spell upon weapons.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}

if(flag) {
message("info", "You inadvertently fill the weapon with a massive amount of worthless energy!", caster);
message("info", (string)caster->query_cap_name() +" inadvertently imbues useless energy into the weapon.", environment(caster), ({ caster }));
at->set_property("dark weapon", at->query_property("dark weapon") + power);
remove();
return;
}

if((int)at->query_property("dark weapon") >= (caster->query_skill("empowerment") / 5)) {
message("info", "This weapon cannot recieve any more power from this spell at your current skill level.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}
set_work_message("%^BLUE%^You imbue dark power into the weapon.%^RESET%^");
time = 480 + 90*power;
mod = 30+2*props["spell level"];
ctime = (time*mod)/caster->query_skill("empowerment");
if(wizardp(caster)) {
ctime = 1;
}
start_work(at, caster, ctime, power);
return;
}

void finish_work(object caster, object at, int power) {
int ench;
int i;
int idx;
mixed tmp;

if(power <= 0) {
message("info", "BUG in Dark Paladin spell....unable to complete.", environment(caster));
remove();
return;
}
message("info", "You have finished your imbuement!", caster);
message("info", "Uttering one final incantation, "+(string)caster->query_cap_name()+" finishes imbuing a weapon with darkness.", environment(caster), ({ caster }));
ench = (int)at->query_property("dark weapon");

/*
if(!check_brittle_custom(at, caster, power, 3)) {
remove();
return;
}
*/
if(!ench) {
ench = 0;
}
ench += power;
at->set_property("dark weapon", ench);
at->add_wc(power*2, "unholy");
caster->add_exp2(500*power);
tmp = (mixed)at->query_property("extra long");
if(!tmp) {
tmp = ({ });
}
else if(stringp(tmp)) tmp = ({ tmp });
idx = -1;
i = sizeof(tmp);
while(i--) {
if(pointerp(tmp[i]) && sizeof(tmp[i]) == 2 && eliminate_colour(tmp[i][0]) == "This weapon is imbued with darkness.") idx = 1;
}
if(idx < 0) {
tmp += ({ ({ "%^BOLD%^%^BLUE%^This weapon is imbued with darkness.%^RESET%^", "detect magic" }) });
at->set_property("extra long", tmp);
remove();
return;
}
}
