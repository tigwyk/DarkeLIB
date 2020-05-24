//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

    set("short", "The workroom of a new immortal");
    set("long", "This inherits from /std/vault_locker_room.c");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");

    set_property("light", 5);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    set_exits( ({ "/wizards/honspron/workroom.c"}), ({"west"}) );
    
    if(!present("forge")) {
	 new("/wizards/diewarzau/obj/misc/greater_forge") ->move(this_object());
	}

add_skill("swimming", 1);
add_skill("detect magic", 1);
add_skill("spell sense", 1);
add_skill("wizforge armour", 1);
add_skill("wizforge weapon", 1);
add_skill("wizinscribe aldara zet", 1);
add_skill("wizinscribe harah lit", 1);
add_skill("wizinscribe malsa bonnes", 1);
add_skill("wizinscribe malsa koren", 1);
add_skill("wizinscribe malsa sen zora", 1);
add_skill("wizinscribe malsa xen", 1);
add_skill("wizinscribe xen mora", 1);
add_skill("wizinscribe zalm lit", 1);
add_skill("wizleather craft", 1);
//add_skill("wiztestforge armour", 1);
//add_skill("wiztestforge weapon", 1);
add_skill("wizzalm lit", 1);

  
  return;
}

