//	Cast command for invoking spells!

//	DarkeLIB 0.1

//	Diewarzau 4/4/94



int cmd_hotcast(string str) {

    string spell_dir, file, spell,arg;

    int pow;

    object spell_ob;



    seteuid(getuid());

    if(!str || (sscanf(str,"*%d %s at %s",pow,spell,arg) != 3 &&

	sscanf(str,"*%d %s",pow,spell) != 2))

	return notify_fail("Usage: cast *<pow> <spell> at <target>[<args>]\n");

// HONSPRON 2020 (TLNY2020 note this allows arches only to be able to cast any spell at
// 200 skill level without knowing the spell or skill level. works only with in
// conjuction to /std/spells/spell.c code)

if(!this_player()->query_spell_level(spell) && !archp(this_player()))

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

    write("Spell ob: "+file_name(spell_ob));

    spell_ob->set_property("casting time", 1);

    spell_ob->set_property("base mp cost", 0);

    spell_ob->begin_casting(this_player(), arg, pow);

    return 1;

}



void help() {

message("help",

"This command is used to invoke spells with the syntax:\n"

"cast *<power-level> <spell> at <target> [with <args>]\n"

"Note: with <args> is only necessary with some spells.\n"

"All spells take 1 round with hotcast and spells cast 0 mp\n"

"See: spell, spells"

,this_player());

}

