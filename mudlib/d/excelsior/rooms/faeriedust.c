//The entrance to Excelsior's area,  the city of Fearie Dust.

inherit "std/room";
object sign,*people;

void init() {
	string name;
   ::init();
   add_action("read_sign","read");
	save_object("/wizards/excelsior/rooms/news");
   add_action("news_clear","clear");
   if(!previous_object()->is_player()) return;
   name = this_player()->query_name();
   if(sizeof(people) < 1) {
   	write("%^GREEN%^Congradulations! You're the first one here!");
   } else if(sizeof(people) == 1) {
   write("%^GREEN%^Only 1 person has been here before you.");
   } else {
   write("%^GREEN%^A total of %^BLUE%^%^BOLD%^"+sizeof(people)+"%^RESET%^%^GREEN%^ "+
   	"people have been here since the last reboot.");
   }
   if(this_player()->query_level() < 3) 
   write("%^RED%^You can get into the newbie area! %^RESET%^Go %^BLUE%^southwest%^RESET%^"+
   	" %^BLUE%^north%^RESET%^, %^BLUE%^east%^RESET%^, %^BLUE%^portal%^RESET%^.");
   if(member_array(name,query_property("read news")) < 0) {
	write("%^BLUE%^%^BOLD%^The area news has been updated since you last read it." +
		"%^RESET%^ Go %^RED%^ SW%^RESET%^, %^RED%^N %^RESET%^ to find it.");
	}
	if(member_array(this_player(),people) < 0) people += ({this_player()});
}

void create() {
   ::create();
   set_property("light", 1);
set("short","The city entrance");
   set("long","You have finally arrived at the legendary city of "+
      "New Faerie Dust- and let it be know that so far you are not "+
      "impressed.\n\tAs a child you had heard stories of a city covered in "+
      "gold, of jeweled gates that welcome visitors to the city with open "+
      "arms, of buildings so tall and magnificent that no god could have "+
      "built them better himself. All this is no longer the case- You see "+
      "no gold anywhere, the gates, which now loom before you, beckon "+
      "you to enter a city of despair like a silent devil, ever vigilant, ever "+
      "evil. The buildings and towers are still there, but they don't look "+
      "that magnificent- though they still have a sturdy air about them, "+
      "things are so polluted and dirty it looks like the gods they rivaled "+
      "became jealous. \n\tAs you stand here looking at the filth, the disease, "+
      "you can't help but wonder- why were the stories of your childhood "+
      "so wrong?\nA dirty sign.");
   set_items( ([ "city": "The city looks to be very run down.", "gates":
            "They have been stripped of their gold plating.  The gold probably fed a\n"+
            "family of 4 for about 5 years.",  "buildings": "A guy could really get lost " +
            "in a city this huge.", "sign": "It is very dirty. You wonder what it " +
            "'read's.." ]) );
	set_exits((["southwest":"/wizards/excelsior/rooms/square",
	"leave":"/d/damned/virtual/room_13_6.world"]));
	restore_object("/wizards/excelsior/rooms/news");
	people = ({});
	reset();
}

void reset() {
	if(!query_property("read news")) set_property("read news",({}));
}

int read_sign(string str) {
   if ( str != "sign" ) {
      notify_fail("Read what?\n");
      return 0;
   }
write("Welcome to the city of New Faerie Dust, created by "+
	"the wizard Excelsior. %^GREEN%^Be sure to vist the Excelsior emporium, southwest and then north of here.");
write("%^BLUE%^The newbie area is southwest, north, east.");
   return 1;
}

int news_clear() {
	if(!wizardp(this_player())) return 0;
	write("%^CYAN%^%^BOLD%^You reset the area news.");
	set_property("read news",({}));
	return 1;
}

void remove() {
	if(!::remove()) return;
	save_object("/wizards/excelsior/rooms/news");
}

int sorry() {
	write("Due to large compatabilty problems that just surfaced "+
		"regarding my area and the new driver, NFD is temporarily closed. I will fix it as "+
		"soon as possible- Xlcr");
	return 0;
}
