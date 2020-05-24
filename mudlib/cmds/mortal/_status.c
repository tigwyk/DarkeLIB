//      _status.c
//     created by Descartes for the Nightmare mudlib 141192
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_status(string arg) {
    string mind;
    int level, nlevel, exp, nexp;
    mixed lexp;

    level=this_player()->query_level();
    nlevel=level+1;
    exp=this_player()->query_exp();
    nexp="/adm/daemon/advance_d"->get_exp(nlevel);
    lexp=nexp-exp;
            switch((int)this_player()->percent_buffer()) {
            case 0..5: mind = "clear"; break;
            case 6..25: mind = "almost clear"; break;
            case 26..50: mind = "slightly fuzzy"; break;
            case 51..75: mind = "clouded"; break;
            case 76..89: mind = "very fuzzy"; break;
            case 90..98: mind = "%^MAGENTA%^full of facts%^RESET%^"; break;
            case 99..110: mind = "%^GREEN%^OVER FOF%^RESET%^"; break;
            case 111..200: mind = "%^RED%^OVER FOF%^RESET%^"; break;
            case 201..1100: mind = "%^WHITE%^OVER FOF%^RESET%^"; break;
            default: mind = "clear"; break;
            }
 if(!arg) {
  write("%^BOLD%^CYAN%^hp: %^BOLD%^WHITE%^"+this_player()->query_hp()+"/"+this_player()->query_max_hp()+"  "
        "%^BOLD%^CYAN%^mp: %^BOLD%^WHITE%^"+this_player()->query_mp()+"/"+this_player()->query_max_mp()+"  "
        "%^BOLD%^CYAN%^experience: %^BOLD%^WHITE%^"+lexp+"  "
        "%^BOLD%^CYAN%^Mind: %^BOLD%^WHITE%^"+mind+"%^RESET%^");
  return 1;
 }
  if(lower_case(arg) == "on") {
	this_player()->setenv("SCORE", "on");
	write("Hp/mp report is ON.");
  } else if(lower_case(arg) == "off") {
	this_player()->setenv("SCORE", "off");
        write("Hp/mp report is OFF.");
  }   
  else write("Unknown arguement: "+ arg);
  return 1;
}
 
void help() {
    write("Syntax: <status>\n\n"+
        "'status on' turns on your hp/mp report.  You will receive an hp/mp "
	"report whenever you take damage or heal mp or hp.  Useful for "
	"tracking healing or combat.\n"
	"'status off' turns the report off.\n"
	"'status' just tells you your hp and mp.\n\n"
        "See also: score\n"
    );
}
