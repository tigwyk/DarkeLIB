#include <std.h>
#include <daemons.h>
inherit OBJECT;
void create() {
    ::create();
    set("name", "gem");
    set("id","stone");
    set("short", "A pretty gem");
    set("long",
      "A pretty gem.");
    set("weight", 100);
    set_value(0);
}

void init()
{
    add_action("check","check");
}

int check()
{
    object *them;
    int i;
    them = users();
    i = sizeof(them);
    while(i--)
    {
	if (them[i]->query_level() > 99) {
	    write(them[i]->query_name());
	}
    }
    write("END.\n");
    return 1;
}
