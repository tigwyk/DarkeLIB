//      From Maxwell's Underground mudlib
//        42nd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large chamber. In the center of "
"the chamber is a large stone tomb.");
    set("long", @ext You are standing in a large stone chamber. The walls are 
covered with the same ancient script as the other tomb room you were 
in earlier. Dominating the center of the chamber is a large stone tomb. 
Against the walls are several large metal pots that must have been used to 
light the room.
  
 0--@
ext);
    set_exits( ({ UNDER+"dmc6"}),
      ({ "west" }));
    set_items( ([
"pots" : "The large pots are still filled with a foul smelling liquid."]) );
    set_smell("default", "You can smell the foul stench of decay and "
"mold.");
  set_pre_exit_functions( ({"down"}),({"owner_check"}) );
}
int exit(string fun){
    object tomb;
    tomb = present("tomb");
    call_other(tomb,"exit");
    add_exit(UNDER+"dm44","down"); 
    return 1;
}
void reset() {
    object ob;
   ::reset();
    remove_exit("down");
    (UNDER+"dm44")->remove_exit("up");
    if(present("tomb")) { 
    ob = present("tomb");
    ob->reset();
    return;
    }
    ob = new(UNETC+"tomb1");
    ob->move(this_object());
}
int owner_check(){
 if(read_file(UNQST+"axe_owner") == "nobody")
    return 1;
 else {
    write("A magical force stops you from entering the "
     "tomb. You can hear a whisper of wind in your ear..\n"
     "Until the Axe is returned to the Dwarves no one can enter "
     "the sacred tomb. It is rumored that "+read_file(UNQST+"axe_owner")+
     " has possesion of the Axe.");
     return 0;
 }
} 
