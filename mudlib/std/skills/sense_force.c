inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("force");
    set_dev_cost(21);
    set_fast_dev_cost(57);
}

void info() {
message("help",
"This skill allows you to detect when a player is focusing on a Force ability, even if "
"he/she can normally focus silently.  Also, if you have the skill at a "
"sufficiently high level, you can even sense what ability they are "
"focusing on!",
this_player());
}

