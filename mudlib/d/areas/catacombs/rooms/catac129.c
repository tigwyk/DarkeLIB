/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void init() {
   ::init();
   switch (random(25)) {
      case 0:
         message("info", "%^RED%^%^BOLD%^A rock strikes you painfully in the head, sending you to your knees!\n",
            this_player());
         this_player()->add_hp(-1*(10+random(10)));
         break;
      case 1..15:
         message("info", "%^CYAN%^Some object flies past your head and out of the room.\n",
              this_player());
         break;
      case 16..24: break;
   }
}
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   A horrible stench of burnt and rotting flesh offends your nostrils 
   as you step into this large chamber of the catacombs.  The ceiling 
   climbs steeply, reaching its apex at around forty or fifty feet.  
   A few mangled corpses lie on the ground.  Three passageways lead 
   away from this room - one to the west, one to the south, and 
   the last to the southeast.       
       
 0--@
    |\
    0 0 
ext);
   set_smell("default", "The air smells of burnt flesh.");
   set_listen("default", "You hear someone cackling in the distance.");
   set_items( ([
                "corpses":
        "The corpses look as if some wild animal has been chewing on them.",
                "ceiling":
        "The ceiling is far above your head.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac108",
                "southeast": PATH+"catac130",
                "south": PATH+"catac141",
                ]) );
 
   set_pre_exit_functions( ({"south"}), ({"go_south"}) );
   set_pre_exit_functions( ({"southeast"}), ({"go_southeast"}) );
}
 
int go_southeast() {
   if(present("shaggy zombie")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The shaggy zombie slashes you in the face with its cutlass!");
      this_player()->add_hp(-5-random(10));
      message("info", this_player()->query_cap_name()+
        " tried to go southeast, but was slashed in the face by the "+
        "shaggy zombie!", this_object(), this_player() );
      return 0;
   }
   else
      return 1;
}
 
int go_south() {
   if(present("shaggy zombie")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The shaggy zombie slashes you in the face with its cutlass!");
      this_player()->add_hp(-5-random(10));
      message("info", this_player()->query_cap_name()+
        " tried to go south, but was slashed in the face by the "+
        "shaggy zombie!", this_object(), this_player() );
      return 0;
   }
   else
      return 1;
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("shaggy zombie")) {
      ob = new(MON_PATH+"shagzomb");
      ob->move(this_object());
      new(WEAP_PATH+"cutlass")->move(ob);
      ob->set_skill("double wielding", 75);
      ob->force_me("wield cutlass in left hand");
   }
}
 
