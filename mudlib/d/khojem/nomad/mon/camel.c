//  Wizard:   Khojem
//  Monster:  camel
//  File:     camel.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  ::create();
    set_name("camel");
    set_id( ({ "camel" }) );
    set_level(7);
    set_short("smelly camel");
    if(random(2))
      set_long("A large one-hump camel.  Its hair is matted with clots of dried "+
        "manure.");
    else 
      set_long("A large two-hump camel.  Its hair is matted with clots of dried "+
        "manure.");
    set("race", "horse");
    set_body_type("quadruped");
    set_gender("male");
    set_stats("intelligence", 20);
    set_property("melee damage", ([ "crushing" : 10]));
    set_emotes(5,({
      "A camel chews something.",
      "A camel blinks.",
      "A camel shakes its neck and a bunch of flies swarm.",
      "A camel spits at the ground.",
      "A camel spits on you!"
    }),0);    
 }

int query_kho_mon() { return 1;}

