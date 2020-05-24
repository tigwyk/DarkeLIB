/* Town Crier coded by Traer for Darke Domain. */
/* 03-22-99 */
 
#include "std.h"
inherit MONSTER;
	object ob;

void create() {
   ::create();
   set_name("town crier");
   set("id", ({"town crier", "crier"}) );
   set_level(100);
   set("short", "town crier");
   set("long",
   "The town crier has been sent here by the gods to bring you the latest in news and happenenings from around the realms. A gentle man, not known for combat stands before you with a paper in his hand. He is aware of all that goes on in the realms of the Darke Domain. You may ask him to read his paper, tell of news and happenings, or simply ask him for basic information reagarding living in the realms."
   );
   set("race", "human");
   set_gender("male");
   set_body_type("human");
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
		            "catfolk", "ogryn" }));
   new("/d/damned/akkad/obj/newspaper.c")->move(this_object());
}
