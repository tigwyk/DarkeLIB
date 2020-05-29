//	Skills listing command...gives name and level of each skill.
//	DarkeLIB 0.1
//	Diewarzau 3/31/94

int cmd_spells(string str) {
    string *skills, *list, which_skill, file, dev_str;
    int i;

    seteuid(getuid());
    if(stringp(str) && sscanf(str,"info %s",which_skill)) {
	if(!file_exists((file = "/std/spells/"+replace_string(
	    which_skill," ","_")+".c")))
	    return notify_fail("There is no help on that spell.\n");
	file = replace_string(file,".c","");
	if(!function_exists("info",to_object(file)))
	    return notify_fail("This spell exists but has no help.  "
		"report this bug via the bug command.\n");
        write("Spell help: " + which_skill);
	write("Spell skill used: " + (string)file->query_property("skill"));
	if((string)this_player()->query_class() == "moon mage")
	    write("Governing moon: "+(string)file->query_property("moon"));
	dev_str = sprintf("Development cost: %d/",(int)file->
	    query_property("dev cost"));
	if((i=(int)file->query_property("fast dev cost"))) dev_str += sprintf(
	    "%d\n",i); else dev_str += "*\n";
	write("Base mp cost per power level: "+identify((int)file->
	    query_property("base mp cost")));
	write(dev_str);
	file->info();
	return 1;
    }
    skills = (string *)this_player()->query_all_spells();
    if(!skills || !sizeof(skills))
        return notify_fail("You have no spells.  You suck.\n");
    skills = sort_array(skills,"alphabetize",this_object());
    list = ({});
    for(i=0;i<sizeof(skills);i++)
        list += ({ sprintf("%-27s *%1d",capitalize(skills[i]),
            (int)this_player()->query_spell_level(skills[i])) });
    message("info", "%^BOLD%^Your spells are:%^RESET%^\n%^BLUE%^%^BOLD%^"+
      repeat_string("-", 65)
	,this_player());
    this_player()->more(explode(format_page(list, 2),"\n"));
    return 1;
}

void help() {
message("help",
"This command lists all spells available to you and their respective levels.  "
,this_player());
}

int alphabetize(string first, string next) {
	return strcmp(explode(first," ")[0],explode(next," ")[0]);
}
