//	Cast command for invoking spells!
//	DarkeLIB 0.1
//	Diewarzau 4/4/94

int cmd_cast(string str) {
    string spell_dir, file, spell,arg;
    int pow;
    object spell_ob;

if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
    seteuid(getuid());
    if(!str || (sscanf(str,"*%d %s at %s",pow,spell,arg) != 3 &&
	sscanf(str,"*%d %s",pow,spell) != 2))
	return notify_fail("Usage: cast *<pow> <spell> at <target>[<args>]\n");
    if(pow < 0)
    return notify_fail("Usage: cast *<pow> <spell> at <target>[<args>]\n");
        if(!this_player()->query_spell_level(spell))
	return notify_fail("You do not know that spell.\n");
    spell = replace_string(spell," ","_");
    if(!wizardp(this_player()) || !file_exists(file = "/wizards/" +
	(string)this_player()->query_name() + "/spells/"+spell+".c"))
	file = "/std/spells/"+spell+".c";
    if(!file_exists(file))
	return notify_fail("BUG! You know a spell that doesn't exist!\n");
    if(this_player()->query_paralyzed())
	return notify_fail("You may not cast while stunned!\n");
    spell_ob = clone_object(file);
    spell_ob->begin_casting(this_player(), arg, pow);
    return 1;
}

void help() {
message("help",
"This command is used to invoke spells with the syntax:\n"
"cast *<power-level> <spell> at <target> [with <args>]\n"
"Note: with <args> is only necessary with some spells.\n"
"See: spell, spells"
,this_player());
}

