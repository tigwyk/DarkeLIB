inherit "/std/guilds/spell_room";
#include "/d/damned/guilds/dark-paladin/dark-paladin.h"

void create() {
::create();
set_short("The Dark Paladins' Spell Training Room");
set_long("This is the small room where the Dark Paladins of Owedquar practice their deadly magics to overthrow the reign of the divine gods over Daybreak Ridge. Countless inscriptions cover the walls instructing those worthy enough how to learn them.\n");
set_property("light", 2);
set_property("indoors", 1);
set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "east");
add_spell("shadow bolt", 1);
add_spell("mist cloud", 3);
add_spell("owedquar's eyes", 3);
add_spell("holy ward", 4);
add_spell("curse vision", 7);
add_spell("anger charge", 7);

//8
add_spell("dark weapon");
//10
add_spell("dark assault", 10);
//12
add_spell("unholy rage", 12);
add_spell("black shroud", 12);
//13
add_spell("lesser shadow field");
//14
add_spell("summon black weapon");
//15
add_spell("owedquar's fury");
//16
add_spell("owedquar's might");
//17
add_spell("black fire");
//18
add_spell("black edge");
//20
add_spell("dark pact");
add_spell("shadow field");
//22
add_spell("cause weakness");
//23
add_spell("summon holy bane");
//25
add_spell("abyss blast");
//27
add_spell("absorption");
add_spell("greater shadow field");
//28
add_spell("abyss blade");
//30
add_spell("storm of ages");
add_spell("owedquar's wrath");
//31
add_spell("power of darkness");
//35
add_spell("soul crush");

return;
}
