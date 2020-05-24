#include <std.h>
#include <daemons.h>
#include <shao.h>

inherit ROOM;

#define COST    money/bonus
#define MAX_DONATION 600

mapping blood;

void init() {
    ::init();
    add_action("new_body", "renew");
    add_action("clean_poison", "clean");
    add_action("regenerate", "regenerate");
    add_action("read", "read");
    //    add_action("donate", "donate");
    //    add_action("transfuse", "transfuse");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short","Shao-tan Hospital of the damned");
    set("long",
"%^YELLOW%^REDO THIS LATERS, WHEN YA FIGURE OUT THAT "
"OTHER SHIT "
      "Here they specialize in the regeneration of lost limbs.  "
      "A list of all services they perform is posted on the wall.");
    set_items(
      (["list" : "You can read all the services by typing <read list>.",
	"hospital" : "The clerics here specialize in regenerating "
	"lost limbs.",
	"clerics" : "They are mending the wounds of patients.",
	"cleric" : "He is mending a patient's wounds."]));
add_exit(PATH+"hr2","north");
add_exit(PATH+"hos_front","south");
    blood = ([ "who": ([]), "hp":200, "mp":200 ]);
    set_property("no teleport", 1);
}

int new_body(string str) {
    object *inv;
    int i;

    if( (int)this_player()->query_level() > 3) {
	notify_fail("The clerics only perform this service for the inexperienced.\n");
	return 0;
    }
    inv = all_inventory(this_player());
    for(i=0; i<sizeof(inv); i++) {
	inv[i]->unequip();
    }
    write("A cleric comes over to you and mutters a small prayer.");
    write("You again have all the limbs you were born with!");
    say("A cleric mutters a small prayer for the novice "+this_player()->query_cap_name()+".", this_player());
    this_player()->new_body();
    return 1;
}

int read(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "list") {
	notify_fail("That is not here for reading.\n");
	return 0;
    }
    message("info", "Welcome to the Cleric's Hospital of Akkad!",this_player());
    message("Ninfo",
      "The clerics perform the following services:\n"
      "------------------------------------------------------------------\n"
      "<renew body>: This is a charity service the clerics perform for\n"
      "	novice adventurers who have lost limbs while adventuring.\n"
      "	All limbs are replaced.\n"
      "<regenerate [limb]>: This service is for the experienced adventurer\n"
      "	who has lost limbs.  The limb is replaced and acts like new.\n"
      "	Costs for regeneration:\n"
      "            1120-1470 gold for most limbs (non-clerics)\n"
      "<clean poison>: Helps remove SOME of the poison from your body.\n"
      "       Cost: 50 gold\n"        
      "----------------------------------------------------------------\n",
      this_player());
    return 1;
}

int clean_poison(string str) {
    object tp;

    if(!str) return 0;
    if(str != "poison") return 0;
    tp = this_player();
    if((int)tp->query_poisoning()<1) {
	notify_fail("A cleric whispers to you: But you are not poisoned!\n");
	return 0;
    }
    if((int)tp->query_money("gold") < 50) {
	notify_fail("You do not have enough gold for the tithe.\n");
	return 0;
    }
    tp->add_money("gold", -50);
    tp->add_poisoning(-20);
    write("%^BOLD%^%^GREEN%^A cleric casts a spell of healing upon you.%^RESET%^");
    say("%^BOLD%^%^GREEN%^A cleric casts a spell of healing on "+tp->query_cap_name()+".%^RESET%^", tp);
    return 1;
}

int regenerate(string limb) {
    int money, bonus;
    mapping limb_info;
    object tp;
    string *there, *missing;

    tp = this_player();
    if(present(limb, this_player())) bonus = 2;
    else bonus = 1;
    there = (string *)tp->query_limbs();
    missing = (string *)this_player()->query_severed_limbs() +
    (string *)RACE_D->query_limbs((string)this_player()->query("race"));
    /*
       checking with the race_d is allowing compatibility with old
       versions of the mudlib
    */
    if(!missing) {
	notify_fail("You aren't missing any limbs!\n");
	return 0;
    }
    if(member_array(limb, missing) == -1) {
	notify_fail("You are not missing that limb!\n");
	return 0;
    }
    if(member_array(limb, there) != -1) {
	notify_fail("You already have that one back!\n");
	return 0;
    }
    limb_info= (mapping)RACE_D->query_limb_info(limb,(string)tp->query("race"));
    if(!limb_info) {
	notify_fail("That limb cannot be replaced!\n");
	return 0;
    }
    if(limb_info["attach"] != "0") {
	if(member_array(limb_info["attach"], there) == -1) {
	    notify_fail("You would need a "+limb_info["attach"]+" for that!\n");
	    return 0;
	}
    }
    if((string)this_player()->query_class() == "cleric") money = 240+random(100);
    else money = 1120 + random(350);
    money = money / limb_info["max"];
    if((int)tp->query_money("gold") < COST) {
	notify_fail("The cleric tells you:  You do not have enough gold.\n");
	return 0;
    }
    tp->add_limb(limb, limb_info["ref"], (int)tp->query_max_hp()/limb_info["max"], 0, 0);
    if(member_array(limb, (string *)RACE_D->query_wielding_limbs((string)tp->query("race"))) != -1) 
	tp->add_wielding_limb(limb);
    this_player()->add_money("gold", -COST);
    say(sprintf("%s asks the clerics for some help with %s missing %s.",
	this_player()->query_cap_name(), possessive(this_player()), limb));
    write("%^BOLD%^%^BLUE%^The clerics restore your "+limb+"!%^RESET%^");
    return 1;
}

int donate(string str) {
    string what;
    int amount, tmp;

    if(!str) {
	notify_fail("Donate what?\n");
	return 0;
    }
    if(sscanf(str, "%d %s of blood", amount, what) !=2) {
	notify_fail("Correct syntax: <donate [#] [hp | mp] of blood>\n");
	return 0;
    }
    if(what != "mp" && what != "hp") {
	notify_fail("Donate what?\n");
	return 0;
    }
    if(blood[(string)this_player()->query_name()]+amount > MAX_DONATION) {
	write("You will have to wait before giving that much blood.");
	return 1;
    }
    tmp = (int)call_other(this_player(), "query_"+what);
    if(tmp < amount + 5) {
	notify_fail("You must have at least 5 more than you plan to give!\n");
	return 0;
    }
    call_other(this_player(), "add_"+what, -amount);
    this_player()->add_money("gold", amount/5);
    blood[what] += amount;
    blood["who"][(string)this_player()->query_name()] += amount;
    write("You donate some blood for "+(amount/5)+" gold coins.");
    say(this_player()->query_cap_name()+" donates some blood for some gold.", this_player());
    call_out("reduce_donation", 900, ({ this_player(), amount }));
    return 1;
}

int transfuse(string str) {
    string what;
    int amount;

    if(!str) {
	notify_fail("Transfuse what?\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, what) != 2) {
	notify_fail("Correct syntax: <transfuse [#] [mp | hp]>\n");
	return 0;
    }
    if(what != "hp" && what != "mp") {
	notify_fail("You cannot do that!\n");
	return 0;
    }
    if(amount < 1) {
	notify_fail("Are you crazy?!?\n");
	return 0;
    }
    if(blood[what] < amount) {
	notify_fail("We do not have that much blood in right now.\n");
	return 0;
    }
    if((int)this_player()->query_money("gold") < amount*3) {
	notify_fail("You do not have enough gold for the tithe.\n");
	return 0;
    }
    this_player()->add_money("gold", -(amount*3));
    call_other(this_player(), "add_"+what, amount);
    write("You receive a blood transfusion");
    say(this_player()->query_cap_name()+" receives a blood transfusion.", this_player());
    return 1;
}

void reduce_donation(mixed *tmp) {
    blood["who"][tmp[0]] -= tmp[1];
    if(blood["who"][tmp[0]] < 1) map_delete(blood, tmp[0]);
}




