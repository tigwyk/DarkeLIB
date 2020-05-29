//	Skills listing command...gives name and level of each skill.
//	DarkeLIB 0.1
//	Diewarzau 3/31/94

int cmd_skills(string str) {
    string *skills, *list, which_skill, file, dev_str;
    int i;

    seteuid(getuid());
    if(stringp(str) && sscanf(str,"info %s",which_skill)) {
	if(!file_exists((file = "/std/skills/"+replace_string(
	    which_skill," ","_")+".c")))
	    return notify_fail("There is no help on that skill.\n");
	file = replace_string(file,".c","");
        if(!function_exists("info",to_object(file)))
	    return notify_fail("This skill exists but has no help.  "
		"report this bug via the bug command.\n");
        write("%^BOLD%^%^BLUE%^"+sprintf("%-65'-'s", "Skill Help ")+"%^RESET%^");
	write("Skill: "+which_skill);
	dev_str = sprintf("Development cost: %d/",(int)file->query_dev());
        if((i = (int)file->query_fast_dev())) dev_str += sprintf("%d\n",i);
        else dev_str +="*\n";
	write(dev_str);
	file->info();
	return 1;
    }
    skills = (string *)this_player()->query_all_skills();
    if(!skills || !sizeof(skills))
	return notify_fail("You have no skills.  You suck.\n");
    skills = sort_array(skills,"alphabetize",this_object());
    list = ({});
    for(i=0;i<sizeof(skills);i++) {
	if(str == "base")
	    list += ({ sprintf("%-20s %3d%1s (%s%d)", skills[i],
		(int)this_player()->query_base_skill(skills[i]),"%",
		((int)this_player()->query_skill_bonus(skills[i]) >= 0)? "+":"",
		(int)this_player()->query_skill_bonus(skills[i])) });
	else
		list += ({ sprintf("%-20s %3d%1s  ", skills[i],
		(int)this_player()->query_skill(skills[i]),"%") });
    }
    message("info", "%^BOLD%^Your skills are:%^RESET%^\n%^BLUE%^%^BOLD%^"+
      repeat_string("-", 65),
        this_player());
    this_player()->more(explode(format_page(list, 2),"\n"));
    return 1;
}

void help() {
message("help",
"This command lists all skills available to you and their respective levels.  "
"If supplied with 'base' as an arguement, it will list base skills and their "
"bonuses.\n");
}

int alphabetize(string first, string next) {
	return strcmp(explode(first," ")[0],explode(next," ")[0]);
}
