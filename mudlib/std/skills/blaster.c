inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(5);
    set_fast_dev_cost(15);
}

void info() {
message("help","This is skill with blasters."
	, this_player());
}

