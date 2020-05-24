#include <std.h>
#include "nevin.h"
inherit MONSTER;

void init() {
	if(query_night()) {
		if(!wizardp(this_player())) {
			this_object()->move_object(ROOMS+"incinerator");
		}
	}
}

create() {
	object ob;
// var & var2 are two string vars used for various things
// qual is the quality of loaded weapons
// crit is the criticals given to some weapons
// power is the power level of the criticals
// obj, sub, and poss, are objective, subjective, and possessive pronouns
	string str, var, var2, qual, crit;
	string obj, sub, poss;
	int power;
    	::create();
   	set_name("citizen");
    	set_id( ({ "citizen", "kuril mob" }) );
	switch(random(2)) {
		case 0: str = "male"; break;
		case 1: str = "female"; break;
	}
	this_object()->set_gender(str);
	obj = (string)this_object()->query_objective();
	sub = (string)this_object()->query_subjective();
	poss = (string)this_object()->query_possessive();
	switch(random(30)) {
		case 0: var = "[5]An average looking citizen";
			var2 = "Trying to keep from being noticed unduly, "
				"this citizen keeps quiet and minds "+poss+
				" own business to keep from attracting "
				"attention.";
			break;
		case 1: var = "[5]A busy citizen";
			var2 = "Trying to run a business in Kuril is "
				"often both risky financially and dangerous "
				"personally.  The three factions in Kuril "
				"all have differing viewpoints...and staying "
				"on good terms with all on them can be "
				"both difficult and dangerous at times.";
				break;
		case 2: var = "[5]A hunched back citizen";
			var2 = "From years of hard labor, this poor citizen "
				"can barely move about.  Doing the dangerous "
				"work that the rich and powerful would not "
				"dare risk their expensive undead on, "+sub+
				" has lived a life of poverty and hardship.";
				break;
		case 3: var = "A leary eyed citizen";
			var2 = "In order to survive in this city, many have "
				"taken to preying upon others.  This citizen "
				"is obviously one of them from the look in "
				+poss+" eyes.  Such people can often be found "
				"in the hire of any of the warring factions "
				"in Kuril.  From this conflict arise "
				"opportunities for such people.";
				break;
		case 4: var = "[5]A black toothed citizen";
			var2 = "Filthy and reaking of the gods know what, "
				+sub+" graces you with only a cursory glance "
				"before returning to more important things.";
				break;
		case 5: var = "[5]A facial scarred citizen";
			var2 = "Who knows what battles this citizen has "
				"fought in the near state of war that has "
				"existed in Kuril for the past few centuries.  "
				"If it where not for the underground movement "
				"which you have heard some talk of, the "
				"Necromancers and the Priests of the Dark "
				"Temple would surely be at war right now.  It "
				"is only because of the new threat that an "
				"uncomfortable 'peace' now reigns in Kuril.";
				break;
		case 6: var = "[5]A drunken citizen";
			var2 = "Smelling of potent ales and other liquors "
				"this citizen has chosen the bottle over "
				"reality.  Thieves and murderers will mostly "
				"likely liberate this person of "+poss+" life "
				"before the sun rises once again.";
				break;
		case 7: var = "[5]A weapon toting citizen";
			var2 = "No citizen of Kuril would ever be caught "
				"without a weapon.  In a city where even "
				"the watch cannot be trusted at times, "
				"protection is something best done for "
				"one's self.  Those that can afford "
				"magical weapons are quick to buy them "
				"for it is known that the foul denizens of "
				"this city are often resistant to normal arms.";
				break;
		case 8: var = "[5]A cautious citizen";
			var2 = "Ever a way of life to prevent death, "
				"cautiousness is something that is taught "
				"to each and every child of Kuril.  Those that "
				"have a place to call home leave their "
				"children there for safety.  A child's first "
				"journey onto the streets of Kuril is often "
				"to seek for food...after their parents fail "
				"to return for days.";
				break;
		case 9: var = "[5]A hawk eyed citizen";
			var2 = "Preying upon the weak and helpless, this "
				"person makes "+poss+" living by night.  "
				"Careful not to venture into the Lower Ward, "
				"even this person does not have a death wish.";
				break;
		case 10: var = "[5]A hapless citizen";
			var2 = "Weak from malnutrition this citizen will "
				"likely not live for more than a few days "
				"at best.  From the symbol on "+poss+
				" forehead, cut with a blunt knife, "+sub+
				" is offering to sell "+obj+"self, "+poss+
				" corpse, and "+poss+" eternal soul, so that "
				+poss+ " family may live another month in the "
				"heartless streets of Kuril.";
				break;
		case 11: var = "[5]A crazed citizen";
			var2 = "In order to keep the populace in line, "
				"the Necromancers of the School of Magic "
				"often release some of their experimental "
				"subjects back onto the streets of Kuril.  "
				"Foaming at the mouth and bleeding from "
				"dozens of wounds on "+poss+" face, neck, "
				"arms, and chest, "+sub+" staggers about "
				"in an almost euphoring stupor.";
				break;
		case 12: var = "[5]A contemplative citizen";
			var2 = "A rare sight in this city, "+sub+" must "
				"be new to this city to be wasting time "
				"thinking about life and the universe.  "
				"Someone will surely 'educatate' this person "
				"about the truth of this city before long.";
				break;
		case 13: var = "[5]A peaceful citizen";
			var2 = "Greeting each passing person with a bow "
				"and blessing of peace, "+sub+" is viewed "
				"with suspicion and fear.  Either this citizen "
				"is up to something sinister or there is "
				"something not going right up there.";
				break;
		case 14: var = "[5]A terrified citizen";
			var2 = "Shivering from an unseen cold, this "
				"citizen keeps mumbling about 'their cold "
				"hands ', 'those cold, cold hands'.  Hugging "
				+obj+"self to keep warm, "+poss+" blood shot "
				"eyes and pale skin tell you not to get "
				"any closer.";
				break;
		case 15: var = "[5]A pleasant citizen";
			var2 = "Ever a rare sight in this dark city, "
				"you wonder whether these people are really "
				"in a good mood of whether they are simply "
				"crazy.";
				break;
		case 16: var = "[5]A foul breathed citizen";
			var2 = "Infested with one of a variety of oral "
				"infestations, you almost fall over from "
				"the foulness of this citizen's breathe.  "
				"Rotting teeth poke out of dry, cracked "
				"lips as "+sub+" tries to converse with you.";
				break;
		case 17: var = "[5]A diseased citizen";
			var2 = "A common sight here in Kuril, many citizens "
				"fall prey to diseases and infections of "
				"various sorts.  Some believe that the "
				"majority of such victoms are the responsibi"
				"lity of the Necromancers of Kuril.  For the "
				"rich and powerful never seem to become ill.";
				break;
		case 18: var = "[5]An offensive smelling citizen";
			var2 = "Straight from hours of toil and labor, "
				"many citizens take to working for minimal "
				"pay and high risk in order to feed themselves "
				"and their children.  Why don't they just "
				"leave the city you say.  Well, they would "
				"laugh at you...for those who have tried to "
				"leave this city, end up leaving this world "	
				"as well...temporarily though.";
				break;
		case 19: var = "[5]A specter-like citizen";
			var2 = "Left to wandering the streets of Kuril, "
				"this sun burned, dehydrated, wraith of a "
				"person will quickly end up filling the ranks "
				"of a necromancer's army.";
				break;
		case 20: var = "[5]A haughty citizen";
			var2 = "If raised any higher, the inside of this "
				"citizen's nose may get sunburned.  You wonder "
				"what circumstances has given this citizen "
				"the impression that "+sub+" is the center of "
				"the universe.  Perhaps you should bring "
				+obj+" back to reality.";
				break;
		case 21: var = "[5]An insolent citizen";
			var2 = "Wearing boldly the symbol of the Reclaimers "
				"upon his forehead, this citizen has dared "
				"to break the law by displaying the forbidden "
				"symbol.";
				break;
		case 22: var = "[5]A vain citizen";
			var2 = "Stopping at every chance to check "+poss+
				" clothes and hair, this citizen obviously "
				"likes the way "+sub+" looks.";
				break;
		case 23: var = "[5]A bitter citizen";
			var2 = "Upset at the current state of Kurilian "
				"politics and affairs, this citizen cries "
				"out for an upheaval in the city government, "
				"the tearing down of the walls of both the "
				"School of Necromancy and the Temple of "
				"Darkness.  Such thoughts will quickly lead "
				"to "+poss+" death and subsequent 'reeducation'"
				" within one of the undead armies of Kuril.";
				break;
		case 24: var = "[5]A sickly citizen";
			var2 = "Afflicted with some type of degenerative "
				"disease, this citizen is coughing up "
				"blood and phlegm all over the place.  "
				"You had best stay away and let this poor "
				"sould die.";
				break;
		case 25: var = "[5]A charming citizen";
			var2 = "A charming young citizen, "+sub+" carries "
				+obj+"self with an air of confidence and "
				"class.  Being a noble of Kuril has many "
				"benifits, for one you will be allowed to "
				"die normally.  Your corpse will not be used "
				"for the gain of others after your passing.  "
				"At least, that's what the Necromancers tell "
				"the nobles.  You've heard otherwise.";
				break;
		case 26: var = "[5]An affluent citizen";
			var2 = "Born and breed a noble, this citizen is "
				"accorded great respect, or is that fear, "
				"by the majority of the populace.  Having "
				"most likely gained this position through "
				"treachery and deceit, "+sub+" is still a toy "
				"to be used by those who really rule this "
				"city.";
				break;
		case 27: var = "[5]A bumbling citizen";
			var2 = "Almost stepping on your toes while trying "
				"avoid falling upon "+poss+" face, this "
				"citizen is a walking disaster.  You are "
				"surprised that "+sub+" hasn't killed "
				+obj+"self yet.";
				break;
		case 28: var = "[5]A quiet citizen";
			var2 = "This citizen does not have much to say.";
			break;
		case 29: var = "[5]A loquacious citizen";
			var2 = "You wonder if this person was a preacher "
				"in a previous life from the way "+sub+
				"just keeps on talking about the current "
				"state of affairs in Kuril.  From listening "
				"you are able to learn that there are "
				"currently three factions fighting for power "
				"in Kuril.  The Reclaimers, the Necromancers, "
				"and the priests from the Temple of Darkness.";
				break;
	}
	this_object()->set("short", var);
	this_object()->set("long", var2);
   	set("aggressive", 0);
  	set_level(5);
	switch(random(9)) {
		case 0: var = "werebear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "sword-demon"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "werewolf"; break;
		case 6: var = "troll"; break;
		case 7: var = "ogre"; break;
		case 8: var = "gerudan"; break;
	}
	this_object()->set("race", var);
   	add_money("silver", ((int)this_object()->query_level()) * random(10));
	if(random(50) == 0) { add_money("mithril", random(3)); }
	if((string)this_object()->query_race() == "sword-demon") {
		set_body_type("winged-humanoid");
	}
	else { set_body_type("human"); }
	set_wimpy(30);
	if(random(7) == 0) {
		new(ARM+"high_boots")->
			move(this_object());
		new(ARM+"fine_clothes")->
			move(this_object());
	}
	else {
		new(ARM+"plain_boots")->
			move(this_object());
		new(ARM+"commoners_clothes")->
			move(this_object());
	}
	force_me("wear boots");
	force_me("wear clothes");
	switch(random(8)) {
		case 0: var = "two-handed-sword";
			var2 = "sword";
			break;
		case 1: var = "short-sword";
			var2 = "sword";
			break;
		case 2: var = "long-sword";
			var2 = "sword";
			break;
		case 3: var = "footman's-flail";
			set_skill("two handed flail", (int)this_player()->
				query_level() * 7);
			var2 = "flail";
			break;
		case 4: var = "hammer";
			var2 = "hammer";
			break;
		case 5: var = "footman's-mace";	
			var2 = "mace";
			break;
		case 6: var = "quarter-staff";
			var2 = "staff";
			set_skill("two handed staff", (int)this_player()->
				query_level() * 7);
			break;
		case 7: var = "short-sword";
			var2 = "sword";
			break;
		case 8: var = "scimitar";
			var2 = "scimitar";
			break;
		case 9: var = "hand-axe";
			var2 = "axe";
			set_skill("axe", (int)this_player()->query_level() * 7);
			break;
		case 10: var = "dagger";
			var2 = "dagger";
			break;
		case 11: var = "battle-axe";
			var2 = "axe";
			set_skill("axe", (int)this_player()->query_level() * 7);
			break;
	}
	switch(random(10)) {
		case 0: qual = "1"; break;
		case 1: qual = "2"; break;
		case 2: qual = "3"; break;
		case 3:	qual = "3"; break;
		case 4: qual = "3"; break;
		case 5: qual = "3"; break;
		case 6:	qual = "3"; break;
		case 7: qual = "4"; break;
		case 8: qual = "4"; break;
		case 9:	qual = "5"; break;
	}
	ob = new("/d/damned/virtual/"+var+"_"+qual+".weapon");
	if(random(10) == 0) {
		switch(random(10)) {
			case 0: crit = "fire"; break;
			case 1: crit = "cold"; break;
			case 2: crit = "fire"; break;
			case 3: crit = "cold"; break;
			case 4: crit = "fire"; break;
			case 5: crit = "cold"; break;
			case 6: crit = "plasma"; break;
			case 7: crit = "disruption"; break;
			case 8: crit = "stress"; break;
			case 9: crit = "lightning"; break;
		}
		switch(random(10)) {
			case 0: power = random(2) + 1; break;
			case 1: power = random(3) + 1; break;
			case 2: power = random(4) + 1; break;
			case 3: power = random(4) + 1; break;
			case 4: power = random(4) + 1; break;
			case 5: power = random(4) + 1; break;
			case 6: power = random(6) + 1; break;
			case 7: power = random(6) + 1; break;
			case 8: power = random(8) + 1; break;
			case 9: power = random(10) + 1; break;
		}
		ob->set_wc(power, crit);
	}
	ob->move(this_object());
	if(random(10) == 0) {
		force_me("wield "+var2+" in left hand");
	}
	else {
		force_me("wield "+var2+" in right hand");
	}
	force_me("wield "+var2+" in right hand and left hand");
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Citizen!", a) == 1) {
		call_out("cit_terror", random(5) + 10, a);
		return;
	}
}

void cit_terror(string who) {
	string str;
	str = "Help!  "+CAP(who)+"is attacking us!";
	if(random(3) < 1) { force_me("yell "+str); }
	call_out("cit_flee", (random(10) + 1));
	return;
}

void cit_flee() {
	int i;
	string *exits;
	exits = ENV(TO)->query_exits();
	i = sizeof(exits);
	if(random(3) < 1) { force_me("scream in terror"); }
	force_me(exits[random(i)]);
}

int chk_my_mob() {
	return 1;
}
