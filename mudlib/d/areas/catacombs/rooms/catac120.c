 
#include "std.h"
inherit ROOM;
 
int spoken_words = 0;
 
void init() {
   ::init();
   add_action("say_it", "say");
}
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   In the middle of this bending corridor is a short, flat rock that sits 
   a few feet high.  The passageway bends to the northwest and northeast, 
   leading into more interesting parts of the catacombs.  There is some 
   writing on the southern part of the wall here, written in small letters.
  0   0  
   \ /   
    @
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
            ({"wall", "south wall", "southern wall", "writing", "letters"}):
        "The scrawl reads: \"refnat nime lenos temerra\".",
                ({"walls", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac152",
                "northeast": PATH+"catac105",
               ]) );
}
 
void reset() {
   ::reset();
   if(!present("shaggy zombie"))
      new(MON_PATH+"shagzomb")->move(this_object());
}
 
int say_it(string str) {
   object ob, tp;
 
   if(spoken_words == 1)
      return 0;
 
   if(!str)
      return 0;
 
   if(strsrch(str, "refnat nime lenos temerra") == -1)
         return 0;
 
   message("info", "\n%^CYAN%^%^BOLD%^Undead monsters appear and attack you!%^RESET%^",
            this_player());
   message("info", "\n%^RED%^%^BOLD%^Evil Lich tells you: %^RESET%^Enjoy my pets!  Muahahaha!",
           this_player());
   message("shout",
            "%^BOLD%^A loud, evil laugh resonates over the land, sending a chill down your spine.%^RESET%^",
            users(), this_object());
   message("info", "%^BOLD%^Undead monsters appear and attack "+this_player()->query_cap_name()+"!%^RESET%^",
              this_object(), this_player());
   spoken_words = 1;
   tp = this_player();
   ob = new(MON_PATH+"giant_mummy");
   ob->move(this_object());
   ob->force_me("attack "+tp->query_name());
   tp->add_follower(ob);
   ob = new(MON_PATH+"giant_skeleton");
   ob->move(this_object());
   ob->force_me("attack "+tp->query_name());
   tp->add_follower(ob);
   return 1;
}
