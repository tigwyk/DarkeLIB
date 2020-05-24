inherit "std/room";


void init() {
  ::init();
  add_action("read_fun", "read");
}


void create() {
  ::create();
    set_property("indoors",1);
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_res2", "east");
    set("short","   \n    \n   @--0\n    \n   \nCity Library");
    set("long","This is the City Library where knowledge dating back to " +
	"Great War can found in the various tomes on the bookshelves.  There "+
	"is much to be learned here for those patient enough to sift through "+
	"the arcane lore.\nThere are some books here.\n   \n    \n   @--0\n    \n   \n");
    add_item("books","You see a history book and a self-help book");
    add_item("tomes","You see a history book and a self-help book");
    add_item("history book","A History of the World Pt. I");
    add_item("self-help book","Everything You Always Wanted to Know, But Were Afraid to Ask");
    
}


int read_fun(string str) 
{
  if (!str) {
    notify_fail("Read what?\n");
    return 0;
  }

  if (str == "history book") {
    this_player()->more("/wizards/mikus/history");
    return 1;
  }
  if (str == "self-help book") {
    this_player()->more("/doc/help/user/faq");
    return 1;
  }

  notify_fail("You do not see that here!\n");
  return 0;
}
      
  










