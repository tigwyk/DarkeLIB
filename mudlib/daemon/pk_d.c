//      a daemon to keep track of player kills
//      created by Zortek

#include "/adm/include/objects.h"
#include "/adm/include/save.h"
#include "/adm/include/security.h"
#define BOUNTY "/d/damned/guilds/join_rooms/nightblade_join"
mapping *player_kills;

void clean_list();

int check_kill(string killern, string victimn);

string find_killer(string victim);

void create() {
    seteuid(getuid());
    player_kills = ({});
    seteuid(UID_DAEMONSAVE);
    restore_object(PK_LIST);
    seteuid(getuid());
    clean_list();
}

void lose_stat(object victim, object killer){
    string *stats, stat, *stats2, type;
    int chance, try, i;
    mapping oldstats;

    chance = victim->query_level()*2;
    chance = chance + (victim->query_level() - killer->query_level());
    if(chance <= 0)
        return;
    try = random(100);
    // They made the roll.
    if(try > chance) 
        return;
    if(!victim->query_property("old stats")){
        oldstats = ([]);
        stats = victim->query_all_stats();
        for(i=0;i<sizeof(stats);i++){
            oldstats[stats[i]] = victim->query_stats(stats[i]);
        }
        victim->set_property("old stats", oldstats);
    }
    stats = ({});
    stats2 = victim->query_all_stats();
    for(i=0;i<sizeof(stats2);i++){
        if(victim->query_base_stats(stats2[i]) > 10)
            stats += ({ stats2[i] });
    }
    // stats now is a array of all stat types they COULD lose.
    if(!sizeof(stats))
        return;
    i = random(sizeof(stats));
    type = stats[i];
    message("info", "%^BOLD%^%^RED%^You have lost one point in "+type+"!%^RESET%^", victim);
    i = victim->query_base_stats(type);
    i = i -1;
    victim->set_stats(type, i);
    return;
}

mapping *query_player_kills() { return player_kills; }

int check_kill(string killer, string victim) {
    int i, time;
    time=0;
    i = sizeof(player_kills);
    while(i--)
	 if( (player_kills[i]["name"] == killer) && (player_kills[i]["who"]==victim) )
	    time = player_kills[i]["time"];
	 return time;
}

string find_killer(string victim) {
   int i;
    i = sizeof(player_kills);
    while(i--)
	 if( player_kills[i]["who"] == victim)
	   tell_object(this_player(),player_kills[i]["name"]);
	 return player_kills[i]["name"];
}
   
void add_player_kill(object who) {
    int exp, x, wibble;
    string killer,victim, pkm;
    object ob;
    int i;

    if(!(ob = previous_object()) || !userp(ob)) return;

    if(wizardp(ob)) {
      i = sizeof(player_kills);
      while(i--)
        if(player_kills[i]["name"] == (string)ob->query_name() && wizardp(ob))
          player_kills -= ({ player_kills[i] });
      return;
    }
    if(!userp(ob)) return;
    if(!userp(who)) return;
    lose_stat(ob, who);
    x = -1;
    killer = who->query_cap_name();
    victim = ob->query_cap_name();
    if ( (who->query_class() == "nightblade" || "assassin") &&
        (BOUNTY->find_bounty(ob->query_name()) != "none") )
    BOUNTY->bounty_exp(who,ob);
    wibble = random(10);
if (who->query_property("pkmsg")==0){
    switch(wibble) {
      case 0:
        "/daemon/inform_d"->do_inform("murders", 
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        victim+" was just slaughtered by "+killer+".");
        break;
      case 1:        
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        victim+" was just murdered by "+killer+".");
        break;
      case 2:        
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        "Historians will tell of the splendid victory that "+killer+
        " had over "+victim+" in a battle to the death!");
        break;
      case 3:        
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        victim+" crumples in a heap of bloody tissue at the feet of "+killer+".");
        break;
      case 4:        
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        killer+" slaughters "+victim+" in a combat frenzy.");
        break;
      case 5:
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        killer+" murders "+victim+" in cold blood.");
        break;
      case 6:
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        killer+" surgically seperates "+victim+"'s soul and body.");
        break;
      case 7:
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        killer+" and "+victim+" battled and "+victim+" lost.");
        break;
      case 8:
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        victim+" and "+killer+" disagreed and "+victim+" died as a result.");
        break;
      case 9:
        "/daemon/inform_d"->do_inform("murders",
        "%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+
        victim+" is vanquished by "+killer+" in a disgusting battle.");
        break;
    }
}
if (who->query_property("pkmsg")!=0){
   pkm=(string)who->query_property("pkmsg");
   pkm=replace_string(pkm, "ME", killer);
   pkm=replace_string(pkm, "TARGET", victim);
   "/daemon/inform_d"->do_inform("murders","%^BOLD%^%^MAGENTA%^Player Kill:%^RESET%^ "+pkm);
}
    i = sizeof(player_kills);
    while(i--)
      if(player_kills[i]["name"] == (string)ob->query_name()) x = i;
    player_kills += ({ ([ 
      "name":(string)who->query_name(), 
      "time": time(),
      "who": (string)ob->query_name(),
    ]) });
    player_kills = sort_array(player_kills, "sort_list", this_object());
    seteuid(UID_DAEMONSAVE);
    save_object(PK_LIST);
    seteuid(getuid());
}

void clean_list(){
    int exp, x;
    object ob;
    int i;

    x = -1;
    i = sizeof(player_kills);
    while(i--)
      if(player_kills[i]["time"] <= time()-604800)
        player_kills -= ({ player_kills[i] }); 
    player_kills = sort_array(player_kills, "sort_list", this_object());
    seteuid(UID_DAEMONSAVE);
    save_object(PK_LIST);
    seteuid(getuid());
}

int sort_list(mapping alpha, mapping beta) {
    if(alpha["time"] > beta["time"]) return -1;
    else if(alpha["time"] < beta["time"]) return 1;
    else return strcmp(alpha["name"], beta["name"]);
}
