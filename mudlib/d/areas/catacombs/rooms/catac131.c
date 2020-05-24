/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void init() {
   ::init();
   add_action("pull_lever", "pull");
}
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway bends sharply here, heading north in one direction and 
   northwest in the other.  There appears to be some kind of lever 
   attached to the southern wall.
  0 0   
   \|   
    @
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear someone laughing.");
   set_items( ([
                ({"wall", "southern wall"}):
        "Set into the southern wall is a small lever.",
                "lever":
        "The lever appears to be made of iron.  You might be able to pull it.",
                ({"walls", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac141",
                "north": PATH+"catac130",
                ]) );
}
 
int pull_lever(string str) {
   object ob;
   int temp;
 
   if(!str) return 0;
   if(str != "lever") {
      notify_fail("Pull what?\n");
      return 0;
   }
   message("info", this_player()->query_cap_name()+ " pulls the lever on the southern wall.\n",
      this_object(), this_player());
   message("info", "You pull down on the lever, which moves with little difficulty.\n",
      this_player());
   switch(random(6)) {
      case 0:
         message("info", "%^BOLD%^A poison dart flies out of the wall and hits you!\n",
            this_player());
         message("info", "%^BOLD%^A poison dart flies out of the wall and hits "+
                this_player()->query_cap_name()+"!\n",
            this_object(), this_player());
         this_player()->add_hp(-10-random(10));
         this_player()->add_poisoning(20+random(20));
         break;
      case 1:
         message("info", "%^BOLD%^An arrow flies out of the wall and strikes you in the chest!\n",
            this_player());
         message("info", "%^BOLD%^An arrow flies out of the wall and strikes "+
                this_player()->query_cap_name()+" in the chest!\n",
            this_object(), this_player());
         this_player()->add_hp(-30-random(10));
         break;
      case 2:
         message("info", "%^BOLD%^A giant mummy appears and attacks you!\n",
            this_player());
         message("info", "%^BOLD%^A giant mummy appears and attacks "+
                this_player()->query_cap_name()+"!\n",
            this_object(), this_player());
         ob = new(MON_PATH+"giant_mummy");
         ob->move(this_object());
         ob->force_me("attack "+this_player()->query_name());
         this_player()->add_follower(ob);
         break;
      case 3..4:
         message("info", "%^BOLD%^%^BLUE%^A blue aura fills the room, and some of your wounds heal.\n",
            this_player());
         message("info", "%^BOLD%^%^BLUE%^A blue aura fills the room, and some of "+
                this_player()->query_cap_name()+"'s wounds heal.\n",
            this_object(), this_player());
         this_player()->add_hp(20+random(10));
         break;
      case 5:
         message("info", "%^CYAN%^%^BOLD%^You are transported somewhere!\n", this_player());
         message("info", "%^CYAN%^%^BOLD%^"+this_player()->query_cap_name()+
                " disappears in a flash of bright light!\n",
                this_object(), this_player());
         this_player()->move_player(find_object_or_load("/d/damned/virtual/room_35_38.world"));
         break;
   }
   return 1;
}
