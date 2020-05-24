/*  /d/damned/arena/master_room.c
 *  Made for DarkeMUD
 *  Created by Geldron 031696
 *  Copyright (c) 1996
 *  Do not remove this header
 */


inherit ROOM;

private string *coowners;
private int minbet, betmod;

void create() {
    seteuid(getuid());
    coowners = ({});
    betmod = 2;
    minbet = 1;
    if(file_size("/d/damned/arena/data/arena.o") > 0) 
	restore_object("/d/damned/arena/data/arena");

    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_short("Sagan's Office");
    set_long("The impossibilities in this room is so perplexing, "
      "you barely believe any of it is real.  Several things in this "
      "room are confusing to your primitive brain, which eliminates "
      "using things wrongly.  The booths room resides down the stairs.\n\n"
      "There is a large white sign.");
    set_items( ([
      ({ "large white sign", "white sign", "large sign", "sign" }) :
      "Available commands:\n\nco-owner <name>\tAdds a co-owner.\n"
      "unco-owner <name>\tRemoves a co-owner.\n"
      "minbet <val>\tSets the minimum bet in platinum.\n"
      "betmod <val>\tSets the betting modifier (mod * amount betted = gained).\n"
      "allow <user>\tAllows <user> to bet once.\n"
      "unallow <user>\tDoesn't allow <user> to bet anymore.",
    ]) );
    set_exits( ([
      "down" : "/d/damned/arena/booths_room",
    ]) );
    set_no_clean(1);
}

void init() {
    ::init();
    if(TP && member_array(TPQN, coowners) == -1 && !arena_ownerp(TP)) return;
    add_action("coowner_name", "co-owner");
    add_action("uncoowner_name", "unco-owner");
    add_action("minimum_bet", "minbet");
    add_action("betting_modifier", "betmod");
    add_action("allow_bet", "allow");
    add_action("unallow_bet", "unallow");
}

int coowner_name(string arg) {
    if(!arena_ownerp(TP)) return 0;
    if(!arg) {
	message("co-owner", syntax("co-owner NAME"), TP);
	return 1;
    }
    arg = LOW(arg);
    if(!coowners) coowners = ({});
    if(member_array(arg, coowners) != -1) {
	message("co-owner", CAP(arg) + " is already a co-owner.", TP);
	return 1;
    }
    if(find_player(arg))
	find_player(arg)->set_bet_allowed(0);
    message("co-owner", CAP(arg) + " is now a co-owner.", TP);
    coowners += ({ arg });
    save_object("/d/damned/arena/data/arena");
    return 1;
}

int uncoowner_name(string arg) {
    if(!arena_ownerp(TP)) return 0;
    if(!arg) {
	message("unco-owner", syntax("unco-owner NAME"), TP);
	return 1;
    }
    arg = LOW(arg);
    if(!coowners) coowners = ({});
    if(member_array(arg, coowners) == -1) {
	message("co-owner", CAP(arg) + " is not a co-owner.", TP);
	return 1;
    }
    if(find_player(arg))
	find_player(arg)->set_bet_allowed(0);
    message("co-owner", CAP(arg) + " is no longer a co-owner.", TP);
    coowners -= ({ arg });
    save_object("/d/damned/arena/data/arena");
    return 1;
}

int minimum_bet(string arg) {
    int tmp;

    sscanf(arg, "%d", tmp);
    if(!arena_ownerp(TP) && member_array(TPQN, coowners) == -1) return 0;
    if(!tmp) { 
	message("betting", syntax("minbet VALUE"), TP);
	return 1;
    }
    if(tmp < 1) {
	message("betting", "You cannot set it lower than 1.", TP);
	return 1;
    }
    message("betting", "You set the minimum bet to " + tmp + ".", TP);
    minbet = tmp;
    return 1;
}

int betting_modifier(string arg) {
    int tmp;

    sscanf(arg, "%d", tmp);
    if(!arena_ownerp(TP) && member_array(TPQN, coowners) == -1) return 0;
    if(!tmp) {
	message("betting", syntax("betmod VALUE"), TP);
	return 1;
    }
    if(tmp < 2) {
	message("betting", "You cannot set the betting modifier to lower than 2.", TP);
	return 1;
    }
    if(tmp > 10) {
	message("betting", "You cannot set the betting modifier to higher than 10.", TP);
	return 1;
    }
    if(find_object("/d/damned/arena/booths_room")->in_use()) {
	message("betting", "You cannot change the betting modifier until "
	  "the end of the match.", TP);
	return 1;
    }
    message("betting", "You set the betting modifier to " + tmp + ".", TP);
    betmod = tmp;
    write_file("/d/damned/arena/logs/betmods",
      CAP(TPQN) + " set the betting modifier to " + tmp + 
      " at " + ctime(time()) + ".\n"
      "Level was at " + (int)TP->query_level() + ".\n");
    return 1;
}

int allow_bet(string arg) {
    object ob;

    if(!arena_ownerp(TP) && member_array(TPQN, coowners) == -1) return 0;
    if(!arg) {
	message("betting", syntax("allow USER"), TP);
	return 1;
    }
    ob = find_player(arg);
    if(!ob) {
	message("betting", arg + ": not found.", TP);
	return 1;
    }
    if(ob->query_bet_allowed()) {
	message("betting", ob->query_cap_name() + " is already "
	  "allowed to bet.", TP);
	return 1;
    }
    if(member_array(ob->query_name(), coowners) != -1) {
	message("betting", "You cannot allow a co-owner to bet.", TP);
	return 1;
    }
    if(arena_ownerp(ob)) {
	message("betting", "You cannot allow an owner to bet.", TP);
	return 1;
    }
    if(ob == TP) {
	message("betting", "You cannot allow yourself to bet.", TP);
	return 1;
    }
    message("betting", "You allow " + ob->query_cap_name() +
      " to bet once.", TP);
    ob->set_bet_allowed(1);
    write_file("/d/damned/arena/logs/allows",
      CAP(TPQN) + " allowed " + CAP(ob->query_name()) + " to bet at " +
      ctime(time()) + ".\nLevel was at " + (int)TP->query_level() +
      " and " + CAP(ob->query_name()) + "'s level was at " + 
      (int)ob->query_level() + ".\n");
    return 1;
}

int unallow_bet(string arg) {
    object ob;

    if(!arena_ownerp(TP) && member_array(TPQN, coowners) == -1) return 0;
    if(!arg) {
	message("betting", syntax("unallow USER"), TP);
	return 1;
    }
    ob = find_player(arg);
    if(!ob) {
	message("betting", arg + ": not found.", TP);
	return 1;
    }
    if(!ob->query_bet_allowed()) {
	message("betting", ob->query_cap_name() + " wasn't allowed to bet before.", TP);
	return 1;
    }
    message("betting", "You unallow " + ob->query_cap_name() +
      " to bet.", TP);
    ob->set_bet_allowed(0);
    return 1;
}

int query_minimum_bet() { return minbet; }

int query_betting_modifier() { return betmod; }

nomask string *query_coowners() { return coowners; }

nomask int query_prevent_shadow() { return 1; }
