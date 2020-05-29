// /wizards/excelsior/rooms/street3_cont
// coded by Exselcior, master of all arts

inherit "std/room.c";
void reset() {
   object money;
   int amount;
if ( !all_inventory(this_object()) ) {
   ::reset();
   amount = random(53) + 13;
   money = new("/std/obj/coins");
   money->set_money("gold", amount);
   money->move(this_object());
}
}

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short","The chawls continue");
   set("long","Chawls line both sides of the street here, and if you "+
      "look you see they "+
      "stretch to the north as well.  Who ever owns them obviously "+
      "runs an operation that needs thousands of workers. You "+
      "shudder to think of the work conditions they must suffer "+
      "doing whatever it is they do for a living. Come to think of it, "+
      "you really haven't seen a large employer the whole time you've "+
      "been here. You think 'why the hell do people move here if there "+
      "is no place to work?' In fact, you think this is so funny that you "+
      "burst out laughing and start rolling around on the ground, "+
      "only to stop when you notice a group of rough looking kids starring "+
      "at you wide eyed. When you see a man carrying a straight jacket "+
      "towards you, you decide you better be on your way, and fast. You "+
      "notice a dirty sign here.");
   set_items( (["man":"He looks mean and out to get you.","sign":
            "The sign says: Boober street. New Faerie Dust municipal "+
            "hospital just ahead.","kids":"They all carry industrial sized "+
            "slingshots.  Fearsome.","chawls":"Factory owned for factory "+
            "workers." ]) );
   set_exits( (["north":"/wizards/excelsior/rooms/street3",
            "south":"/wizards/excelsior/rooms/hospital_ent" ]) );
}
