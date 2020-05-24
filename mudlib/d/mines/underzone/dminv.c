//      From Maxwell's Underground mudlib
//      Spare Room for items

#define UNDER "/wizards/maxwell/underzone/"

inherit "/wizards/maxwell/underzone/exit_traps";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short",
      "You are standing in Max's Spare Parts Room."
       );
    set("long",@ext 
You are standing in a cluttered Spare Parts Room.
    0   
    |   
    @
ext);
    set_exits( ({ UNDER+"dm1" }), ({ "north" }) );
 
//Trap Code Variable
    trap_active = "armed";
    trap_type = "Explosive";
    trap_level = 13;
    trapped_exit = "ruts";
    sister_trap = (UNDER+"dm1");
    safe_players = ({});
//Selected Items
    new("/wizards/maxwell/objects/etc/safe2")->move(this_object());
}

   
