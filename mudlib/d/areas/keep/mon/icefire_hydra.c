#include <std.h>
#include "../keep.h"

/* This is a mini-boss for the black keep. At level 85, it is a major challenge for a party of high level players. However due to the difficulty as second most powerful mob in the area, it is not a monster a player can just run into by accident. It is only encountered once, when a paladin attempts to offer the Crystal Shard of Terra to Sacrel in the paladin temple room. This powerful dragon has high natural defense and very powerful offense, and has many types of breath attacks. It can use fire breath and ice breath from its two elemental heads, and on certain occassions can breathe area damage from both with its icefire breath attack. When its hp falls below half, it loses one head and cannot use its area attack anymore, but its frequency of single target elemental breath from that head doubles. It may be a tough mini-boss, but it IS possible to defeat with cheap shots. This is to give the player a false sense of security for when they attempt to go after Owedquar's Shadow, who cannot be killed as easily. */

inherit MONSTER;

int c;

void create() {
::create();
set_name("icefire hydra");
set_level(85);
set_max_hp(100000);
set_hp(100000);
set_max_mp(75000);
set_mp(75000);
set_combat_chance(0);
set_property("aggressive", 1);
set_property("gang bang", 1);
set("id", ({ "hydra", "icefire hydra", "blue and red hydra", "dragon", "blue and red headed hydra" }));
set_short("[85]%^BLUE%^blue %^BOLD%^%^RED%^and %^RESET%^%^RED%^red %^BOLD%^%^RED%^headed hydra");
set_long("This is a terribly vicious looking creature, standing approximately eight foot tall and glaring at you from two sets of bright white eyes, one on both its red and blue colored heads. From the mouth of the red head swirls fire, and from the blue mouth icy wind shimmers endlessly. The hulking behemoth lets out a deafening roar as it plants itself into the ground, preparing to strike.");
set("race", "dragon");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-300);
set_skill("attack", 850);
set_skill("melee", 700);
set_skill("martial arts", 700);
set_skill("conjuration", 550);
set_skill("parry", 400);
set_skill("dodge", 400);
set_stats("wisdom", 500);
add_spell("fire breath", "$A");
set_spell_level("fire breath", 6);
add_spell("ice breath", "$A");
set_spell_level("ice breath", 6);
add_spell("icefire breath", "$A");
set_spell_level("icefire breath", 6);
force_me("use concentrate");
set_overall_ac(1500);
c = 0;
return;
}

void heart_beat() {
object target;
int a;
int b;
int d;
::heart_beat();
a = (random(100));
b = query_hp();
target = this_object()->query_current_attacker();
if(b>50000 && c<1) {
if(a>90) {
tell_room(environment(this_object()), "%^BOLD%^%^MAGENTA%^Both heads on the Icefire Hydra roar and slightly lean back.%^RESET%^");
force_me("cast *6 icefire breath");
}
if(a>79 && a<90) {
force_me("cast *6 fire breath at "+this_object()->query_current_attacker()->query_name());
}
if(a>69 && a<80) {
force_me("cast *6 ice breath at "+this_object()->query_current_attacker()->query_name());
}
}
if(b<50001 && c<1) {
d = (random(1));
if(d==0) {
tell_room(environment(this_object()), "Icefire Hydra has its blue head severed!");
delete_spell("icefire breath");
delete_spell("ice breath");
c = 1;
}
if(d==1) {
tell_room(environment(this_object()), "Icefire Hydra has its red head severed!");
delete_spell("icefire breath");
delete_spell("fire breath");
c = 1;
}
}
if(c==1) {
if(a>70 && d==1) {
force_me("cast *6 ice breath at "+this_object()->query_current_attacker()->query_name());
}
if(a>70 && d==0) {
force_me("cast *6 fire breath at "+this_object()->query_current_attacker()->query_name());
}
}
return;
}
