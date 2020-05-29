// /wizards/excelsior/mon/manfrog

inherit "std/monster";
	
#define WHAT_WEAPON ({"/wizards/excelsior/weapons/fun_axe","/wizards/excelsior/weapons/paring_knife","/wizards/excelsior/weapons/short_sword"})
#define HANDS ({"right","left"})

object weapon;
int ind,ind2;
string name,hand;

void reset() {
	::reset();
	force_me("wield "+name+" in "+hand+" hand");
}

void create() {
	int max;
	::create();
	set_name("manfrog");
	set("id",({"man frog","manfrog"}));
	set_level( 12 );
      set_exp(40000);
	set("short","A vicious manfrog");
	set("race","amphibian");
	if ( random(1) == 0 ) {
		set_gender("female");
	} else {
		set_gender("male");
	}
	set_body_type("human");
	set("long","This creature is half man, half frog. It is doomed to "+
		"live in the sewers where it hunts for food.");
	max = random( 100 ) + 200
;
	set_max_hp(max);
	set_hp( max - random(10) );
	this_object()->set_money("silver",random( 300 ) + 234 );
	set_overall_ac( 5 );
	set("aggressive",(: call_other, this_object(), "check_attack" :) );
	set_fingers(4);
	set_skill("dodge",84);
	set_skill("axe",51);
	set_skill("knife",51);
	set_skill("blade",51);
	set_skill("melee",39);
	set_stats("dexterity",91);
	set_wimpy(20);
	ind = random( sizeof( WHAT_WEAPON )  );
	ind2 = random ( sizeof( HANDS )  );
	weapon = new( WHAT_WEAPON[ind] );
	weapon->move( this_object() );
	name = weapon->query_name();
	hand = HANDS[ind2];
	call_out( "reset",1);
}

int check_attack( object who ) {
	if (who->is_player()) { return 1; }
	return 0;
} 
