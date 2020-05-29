// /wizards/excelsior/rooms/hospital
// 8-14-95 Excelsior- where my annoying orderly can
// be found.

inherit "std/room";

void init() {
   ::init();
   add_action("enter_fail","enter");
}

void reset() {
   ::reset();
   if (!present("orderly")) new("/wizards/excelsior"+
	 "/mon/orderly")->move(this_object());
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   set("short","Inside the hospital");
   set("long","You are in the entry hall of the hospital, and it is "+
	"clear that unaithorized personnel go no further. "+
   "You realize that the city is quite ahead of its times with this "+
	"insitution designed to help cure the needy and sick with "+
	"the latest in herbal developments. "+
      "Doctors and employees scurry this way and that, "+
      "fighting a losing battle against disease and injuries in this city. "+
      "Though you try your hardest, you can't get anyones attention. "+
      "The exit is back to the northwest. There is a door here that no "+
      "one seems to be guarding. Hmmm.");
   set_items( ([ "hall":"It is rather big, and all anyone who is not a "+
	    "patient or an employee sees.","desk":"A large desk that is inset "+
	    "in the wall. No one is there.",({"doctors","employees"}):"You can't "+
	    "seem to get their attention.","door":"Peeking through, you see that "+
	    "it leads to a stairway. You could probably 'enter'." ]) );
   set_exits( (["northwest":"/wizards/excelsior/rooms/hospital_ent",
]) );
}

int enter_fail(string str) {
string name;
name = this_player()->query_cap_name();
   if ( str != "door" ) {
      write("What do you want to enter?");
      return 1;
   }
write("You slip through the door into a back room");
this_player()->move_player("/wizards/excelsior/rooms/stairway");
tell_room( this_object(),name+" slips through a door and out of sight.",
({}) );
return 1;
}

int door_message() {
   write("You slip through the door into the back stairway.");
   say( this_player()->query_cap_name()+" slips through a door into "+
      "a back room.",this_player() );
   return 1;
}
