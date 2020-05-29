// /wizards/excelsior/mon/doctor
// a psycho

inherit "std/monster";

void reset() {
::reset();
force_me("wear coat");
force_me("wield syringes in right hand");
force_me("wield saw in left hand");
}
void create() {
::create();
this_object()->set_money("silver",120);
set_name("doctor");
set_id( ({"doctor","psycho doctor"}) );
set_level( 7 );
set("short","Psycho doctor from hell");
set("long","This is an insane doctor who is cackling constantly and "+
"looks very mean. You feel lucky that he is so involved in amputating "+
"the appendages of a deceased werewolf and doesn't seem to notice you.");
set("race","human");
set_gender("male");
set_stats("strength",82);
set_body_type("human");
new("/wizards/excelsior/armor/lab_coat")->move(this_object());
new("/wizards/excelsior/weapons/syringe")->move(this_object());
new("/wizards/excelsior/weapons/saw")->move(this_object());
force_me("wear coat");
force_me("wield syringes in right hand");
force_me("wield saw in left hand");
call_out("reset",1);
set_overall_ac( 3 );
set_skill("attack",78);
set_skill("blade",57);
set_skill("thrown",88);
set_skill("knife",44);
set_emotes(20, ({"The doctor laughs out loud.","The doctor falls to the "
"ground cackling.","The doctor takes a quick break to catalog an eyeball."
}) , 1);
}
