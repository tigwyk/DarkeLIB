#include "/adm/include/std.h"



inherit OBJECT;



void create() {

  ::create();

  set("name", "shards");

  set("id", ({ "shards", "shard" }));

  return;

}



void set_person(string str) {

  set("short", "A shard of "+

	capitalize(str));

  set("long", "It doesn't look like "+capitalize(str)+

	" is having such a good day...it's falling to pieces actually.");

  call_out("remove", 240);

}



