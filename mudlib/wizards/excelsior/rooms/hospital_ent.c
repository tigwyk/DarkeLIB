// /wizards/excelsior/rooms/hospital_ent
// entrance to New Faerie Dust Municipal Hospital (NFDMH)
// (C)Excelsior

inherit "std/room";

void create() {
   set_property("indoors",0);
   set_property("light",1);
   set("short","Entrance to the NFDMH");
   set("day long","You stand in a small court with a fountain "+
      "that families "+
      "from the area have turned into a bath. There is a hospital employee "+
      "here trying hopelessly to shoo away the happy bathers, who have no "+
      "water for themselves in their own rooms.  This court serves as the "+
      "entry to the New Faerie Dust Municipal Hospital,  or NFDMH. It "+
      "is a bit more open in this area and light shines down from above, "+
      "penetrating the deep dark shadows the humungous buildings cast "+
      "in a chaotic phantasmagoria of light.  To the southeast is the "+
      "large hospital itself, and if you look to the northwest you see a "+
      "extremely large building that stretches up above the clouds. You "+
      "do not see any way in this building from here.");
   set("night long","At night here in the hospital court you are "+
      "practically squashed several times by the horse drawn carts "+
      "that serve as ambulances in this large urban spectacular. You can "+
      "see the benefits of modern technology in ambulances, but being as "+
      "they have yet to been invented we don't know how. You are appalled "+
      "by the wounded victims that come here only to be turned away in "+
      "favor of the wounded victims who actually have money. Though the "+
      "hospital "+
      "is supposed to be a free city service, you can see they have their "+
      "priorities straight. Not a few nurses are getting rich off selecting the "+
      "order of patient care through bribes.");
   
   set_items( (["court":"It serves as the entrance to the hospital.",
		"buildings":"The biggest one is to your northwest.",
		"fountain":"It is filled with happy bathers. You wish you could be a happy bather too.",
            "employee":"He looks like he hates his life.",({"fountian","bath"}):
            "People have used it for more then just improving the looks of "+
            "the area.","shadows":"They are spectacular but somewhat "+
            "terrifiying as well.","hospital":"A very busy place.","building":
            "You wonder what is at the top of such a monument to human "+
            "ability. You can't help but marvel at the many years it must "+
            "have taken to haul the stone up its many flights of stairs. "+
            "Magic was certainly used effectively."+
            "Though you can see no entance, you feel like you are destined "+
            "to find a way.","lights":"Very magnificent.","clouds":"Only "+
            "the tallest buildings reach them.",({"carts","ambulances"}):
            "You wonder if the harshness of the ride kills any patients.",
            "nurses":"They look very corrupt."]) );
   set_exits( (["north":"/wizards/excelsior/rooms/street3_cont",
            "west":"/wizards/excelsior/rooms/street4.1","southeast":
            "/wizards/excelsior/rooms/hospital" ]) );
}
