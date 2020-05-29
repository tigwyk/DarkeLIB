// Tell hist functions added by Thrace for Darke Domain
// April 28th 1999
#include <daemons.h>
#include <tell.h>
#include <objects.h>
#include <security.h>
#include <ansi.h>

inherit DAEMON;

int cmd_tell(string str) {
    string tell_msg, who, target, mud, msg;
    object ob;
    int sp_cost;
    int ttr, x;
    string hist;
    string *foo;
    if (str=="hist"){
        seteuid(UID_LOG);
        if(!file_exists("/log/tells/"+this_player()->query_true_name())) {
            write("You have no tell history.");
            return 1;
        }
        hist = read_file("/log/tells/"+this_player()->query_true_name());
        seteuid(getuid());
        foo = explode(hist, "\n");
        x = sizeof(foo) - 22;
        if(x > 0)
            this_player()->more(foo[x..]);
        else
            this_player()->more(foo);
        if(x > 20) {
            seteuid(UID_LOG);
            rm("/log/tells/"+this_player()->query_true_name());
            write_file("/log/tells/"+this_player()->query_true_name(), implode(foo[x..], "\n"));
            seteuid(getuid());
        }
      return 1;
      }

    if (!str || sscanf(str,"%s %s",who,msg) != 2) {
        notify_fail("usage: tell <player> <message>\n");
        return 0;
    }
    if(sscanf(lower_case(who),"%s@%s",target,mud) == 2) {
        if(!NETWORK_D->mud_exists(mud)) 
          return notify_fail("That mud is not listed with"+mud_name()+".\n");
        SERVICES_D->send_gtell(mud, target, msg);
        return 1;
    }
    if(wizardp(this_player())||this_player()->query("in creation")) sp_cost = 0;
        else sp_cost = 4 - (8*(int)this_player()->query_skill("telepathy")) /200;
    sp_cost = (sp_cost < 0)? 0:sp_cost;
    if(!this_player()->query("in creation") && !wizardp(this_player()) && (int)this_player()->query_mp() < sp_cost)
        return notify_fail("You are too mentally exhausted to tell anyone anything.\n");
    this_player()->add_mp(-sp_cost);
    if(!(ob = find_living(who = lower_case(who)))) {
        notify_fail(capitalize(who)+NOT_HERE+"\n");
        return 0;
    }
    if(archp(ob)) {
      ttr=ob->query("tells");
      ttr=ttr+1;
          message("info", (string)ob->query_cap_name() + " has received: "+ttr+" tells this reboot.", this_player());
      ob->set("tells", ttr);
    }
    if(ob->query_invis() && wizardp(ob) && !archp(this_player())) {
        message("info", sprintf("%s%s", capitalize(who), NOT_HERE), this_player());
        message("tell", sprintf("%s is unaware of telling you: %s", (string)this_player()->query_cap_name(), msg), ob);
        ob->set("reply", (string)this_player()->query_name());
        return 1;
    }
    if(ob->query_blocked("tell")) {
        write(ob->query_cap_name()+" is currently blocking all tells.");
        return 1;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail(ob->query_cap_name()+" is link-dead and cannot hear you.\n");
        return 0;
    }
    message("tell", (string)this_player()->query_cap_name() + " tells you: "+ msg, ob);
if (ob->is_player()){
    seteuid(UID_LOG);
    log_file("tells/"+ob->query_true_name(), "\t\t\t\t"+ctime(time())+"**\n%^RED%^"+ (string)this_player()->query_cap_name()+" tells you: %^RESET%^"+msg+"\n");
    seteuid(getuid());
}
    ob->set("reply", (string)this_player()->query_name());
    message("tell", sprintf("You tell %s: %s", (string)ob->query_cap_name(), msg), this_player());
    if(!ob->is_player()) return 1;
    if(query_idle(ob) > IDLE_TIME)
      write(ob->query_cap_name() +
          " is idle, and may not have been paying attention.");
    if(in_edit(ob) || in_input(ob))
      message("info", (string)ob->query_cap_name()+" is in edit and may "+
        "not be in a position to respond.", this_player());
    return 1;
}

void help() {
    message("help",
      "Syntax: <tell [player] [message]>\n"
      "        <tell [player]@[mud] [message]>\n\n"
      "Sends the message to the player named either on this mud if no "
      "mud is specified, or to the player named on another mud when "
      "another mud is specified.\n\n"
      "See also: say, shout, yell, emote", this_player()
    );
}
