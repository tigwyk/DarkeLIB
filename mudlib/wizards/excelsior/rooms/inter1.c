// wizards/excelsior/rooms/inter1 an inter section
// by excelsior,  of course

inherit "std/room";

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short", "An intersection");
   set("day long", "You have come to another intersection of "+
      "complex and intertwining roads.  You wonder if people "+
      "ever get lost forever in this city.  Hmmm. Quite boggling, "+
      "really.  Here are the things you boggle at: 1) The fact that "+
      "people might leave their homes and never come back. 2) "+
      "the immense size of this place. You are dwarfed "+
      "(no offense to dwarfs) by this city.  High above "+
      "you see a bridge that connects two towers.  It looks much "+
      "nicer up there,  for they get natural daylight.  Down here in the "+
      "depths of this 'wonderful' city (at least that is what the legends "+
      "said) the only light is from street lamps,  even now, during the "+
      "day.  You make a mental note to boggle at that too.  To the west "+
      "is the town square,  while to the northeast you see another "+
      "almost identical intersection.  A dark alley is to the east. "+
      "To the south you see a road.  Boggle.");
   set("night long", "You have come to another intersection of "+
      "complex and intertwining roads.  You wonder if people "+
      "ever get lost forever in this city.  Hmmm. Quite boggling, "+
      "really.  Here are the things you boggle at: 1) The fact that "+
      "people might leave their homes and never come back. 2) "+
      "the immense size of this place. You are dwarfed "+
      "(no offense to dwarfs) by this city!  High above "+
      "you see a bridge that connects two towers.  It looks much "+
      "nicer up there,  for they get natural daylight.  Down here in the "+
      "depths of this 'wonderful' city (at least that is what the legends "+
      "said) the only light is from street lamps,  even during the day.  You "+
      "make a mental note to boggle at that too.  To the west "+
      "is the town square,  while to the northeast you see another "+
      "almost identical intersection.  A dark alley is to the east. "+
      "To the south you see a road. Boggle.");
   set_items( (["buildings":"They are quite massive.","intersection":
            "You are in one,  there is one to the northeast,  and you guess "+
            "the town square to the west is an intersection too.","alley":
            "Not the kind of place you'd want to be at night.","bridge":
            "You wonder what it is like up there away from this horrible "+
            "city street.","bug":"How the hell did you know there was a "+
	"bug here?",
		"towers":"They are very very very very high.",
		"lamps":"They are basically torches attached to the ground.",
			"square":"As seen to your west."]));
   set_exits( ([ "west":"/wizards/excelsior/rooms/square","east":
            "/wizards/excelsior/rooms/clownhome","south":
            "/wizards/excelsior/rooms/street3","northeast":
            "/wizards/excelsior/rooms/inter2" ]) );
}
