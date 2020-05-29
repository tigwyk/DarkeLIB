//      /obj/daemon/more_d.c
//      from the Nightmare Mudlib
//      a daemon to handle more (and save memory)
//      created by Descartes of Borg 930905


private mapping more_info;

void do_more(string str);
void do_help();

void create() {
    seteuid(getuid());
    more_info = ([]);
}

varargs int more(mixed what, string cl, function endmore) {
    string *tmp, filecont;
    object ob;

    if(!interactive(ob = previous_object())) return 0;
    if(!what) return notify_fail("Unknown file reference.\n");
    more_info[ob] = ([]);
    if(!(more_info[ob]["class"] = cl)) more_info[ob]["class"] = "info";
    if(!(more_info[ob]["screen"] = atoi((string)ob->getenv("LINES"))))
      more_info[ob]["screen"] = 20;
    if(stringp(what)) {
        if(sizeof(tmp = (string *)ob->wild_card(what)) != 1) {
          map_delete(more_info, ob);
          return notify_fail("Ambiguous file reference.\n");
        }
        seteuid(getuid(ob));
        filecont = read_file(tmp[0]);
        if(!filecont || (filecont == "")) {
           return notify_fail("Unable to display file. It may be too large.\n");
        }
        more_info[ob]["total"] = sizeof(more_info[ob]["lines"] =
          explode(filecont, "\n"));
        seteuid(getuid());
    }
    else if(pointerp(what))
      more_info[ob]["total"] = sizeof(more_info[ob]["lines"] = what);
    else {
        map_delete(more_info, ob);
        return notify_fail("Illegal file reference.\n");
    }
    if(wizardp(ob) && tmp && tmp[0])
      message(more_info[ob]["class"], "--==** "+tmp[0]+" **==--", ob);
    if(!more_info[ob]["total"]) {
        map_delete(more_info, ob);
        return 1;
    }
    more_info[ob]["current"] = 0;
    if(functionp(endmore)) more_info[ob]["endfun"] = endmore;
    do_more(" ");
    return 1;
}

protected void do_more(string cmd) {
    string arg;
    string *matches;
    object ob;
    int i;

    if(!cmd || cmd == "") cmd = " ";
    if((i=strlen(cmd)) > 1) arg = cmd[1..(i-1)];
    else arg = "";
    if(!more_info[ob= this_player()]) return;
    switch(cmd = cmd[0..0]) {
        case " ": break;
        case "b": case "B":
          more_info[ob]["current"] -= more_info[ob]["screen"]*2;
          if(more_info[ob]["current"] < 0) more_info[ob]["current"] = 0;
          break;
        case "<": more_info[ob]["current"] = 0; break;
        case ">": more_info[ob]["current"] = more_info[ob]["total"]-1; break;
        case "/":
          more_info[ob]["regexp"] = cmd+arg;
          if(!sizeof(matches=regexp(more_info[ob]["lines"][more_info[ob]["current"]..more_info[ob]["total"]-1], arg))) {
            message(more_info[ob]["class"], "Pattern not found.", ob);
            input_to("do_more");
            return;
          }
          for(i=more_info[ob]["current"]; i<more_info[ob]["total"]; i++) {
            if(more_info[ob]["lines"][i] != matches[0]) continue;
            more_info[ob]["current"] = i;
            break;
          }
          message(more_info[ob]["class"], "Skipping to line "+
            more_info[ob]["current"]+"...", ob);
          do_more(" ");
          return;
        case "?":
          more_info[ob]["regexp"] = cmd+arg;
          if(!sizeof(matches=regexp(more_info[ob]["lines"][0..more_info[ob]["current"]], arg))) {
            message(more_info[ob]["class"], "Pattern not found.", ob);
            input_to("do_more");
            return;
          }
          more_info[ob]["current"] = member_array(matches[0],
            more_info[ob]["lines"][0..more_info[ob]["current"]]);
          message(more_info[ob]["class"], "...Backing up..", ob);
          do_more(" ");
          return;
        case "n":
          if(!more_info[ob]["regexp"] || more_info[ob]["regexp"] == "") {
            message(more_info[ob]["class"], "No previous search.", ob);
            input_to("do_more");
            return;
          }
          do_more(more_info[ob]["regexp"]);
          return;
        case "=":
          message(more_info[ob]["class"], "Current line: "+
            more_info[ob]["current"], ob);
          input_to("do_more");
          return;
        case "v": case "V":
          message(more_info[ob]["class"], "Nightmare Mudlib \"more\" "+
            "version 1.0 by Descartes of Borg 930905.", ob);
          input_to("do_more");
          return;
        case "h": case "H": do_help(); input_to("do_more"); return;
        case "Q": case "q":
          message("N"+more_info[ob]["class"], "\n", this_object());
          if(functionp(more_info[ob]["endfun"])) (*more_info[ob]["endfun"])();
          map_delete(more_info, ob);
          return;
        default:
          message(more_info[ob]["class"], "Unrecognized command.", ob);
          input_to("do_more");
          return;
    }
    message("N"+more_info[ob]["class"], "\n", ob);
    for(i=more_info[ob]["current"];
      i<more_info[ob]["current"] + more_info[ob]["screen"]; i++) {
        if(i>= more_info[ob]["total"]) {
          if(functionp(more_info[ob]["endfun"])) (*more_info[ob]["endfun"])();
          map_delete(more_info, ob);
          return;
        }
        message(more_info[ob]["class"], more_info[ob]["lines"][i], ob);
    }
    more_info[ob]["current"] = i;
    message("Ninfo", "%^B_WHITE%^BLACK%^--More-- ("+
      to_int(percent(more_info[ob]["current"], more_info[ob]["total"]))+"%) ", ob);
    input_to("do_more");
    return;
}

void do_help() {
    message("Nhelp",
      "Help for the \"more\" utility:\n\n"
      "<spacebar> Display the next page of text.\n"
      "B or b     Display the previous page of text.\n"
      "<          Goto the beginning of the document.\n"
      ">          Goto the end of the document.\n"
      "=          Display the current line number.\n"
      "/<exp>     Goto the next line with the expression <exp> in it.\n"
      "?<exp>     Goto the previous line with the expression <exp> in it.\n"
      "v or V     See the version information about this pager.\n"
      "h or H     This help screen.\n"
      "q or Q     Quit out of the pager.\n", this_player()
    );
}
