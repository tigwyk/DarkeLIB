// /wizards/excelsior/mon/thranx
// the only real monster on level 1
// excelsior

inherit "std/monster";
void reset() {
::reset();
if (!present("thranx club")) {
new("/wizards/excelsior/weapons/thranx_club")->move(this_object());
force_me("wield club in first hand and second hand");
}
if (!present("paring knife")) {
new("/wizards/excelsior/weapons/paring_knife")->move(this_object());
force_me("wield knife in third hand");
}
}


void create() {
::create();
set_name("thranx");
set("id",({"thranx","a thranx","a rampaging thranx"}) );
set_level( 6 );
set("short","a rampaging thranx");
set("long","This thranx is angry because he is being forced out of "+
"New Faerie Dust. He's already killed 1 and wounded countless others. "+
"Perhaps you should intervene..oh, wait, you already have! Human lover!");
set("race","thranx");
set_gender("male" );
set_body_type("thranx");
set_overall_ac( 8 );
set_property("magic resistance",24);
set_max_hp( 200 );
set_hp( 200 );
set_skill("attack",75);
set_skill("melee",81);
set_skill("two handed blunt",77);
set_skill("knife",36);
reset();
set_skill("blade",51);
set_stats("strength",97);
call_out( "reset",2);
}
