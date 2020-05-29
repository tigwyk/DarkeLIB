// /wizards/excelsior/rooms/street4.3
// a thranx is causing a commotion!

inherit "std/room";
int loot_ok;

void reset() {
object thranx;
::reset();
loot_ok = 1;
if (!present("thranx") ) {
thranx = new("/wizards/excelsior/mon/thranx");
thranx->move( this_object());
}
remove_item( "thranx" );
set_items( ([ ({"group","people"}):"They seem to be watching a thranx "+
  "beat the pulp out of fellow nonhumans.","nail":"Great, you broke "+
  "it! And you haven't seen a descent manicurist the whole time you've "+
  "been here!","corpse":"A poor human just doing his job. Oh well. You "+
  "could probably 'loot' the corpse before someone else does.","elf":
  "He is not here. You stand looking at where he was for several hours "+
  "trying to grasp that concept." ]) );
}


init() {
    ::init();
    if (!present("thranx") ) {
	set_items( ([ ({"group","people"}):"They are just hanging around in the "+
	  "aftermath of the violence because they have nothing better to do.",
	  "nail":"Great, you broke "+
	  "it! And you haven't seen a descent manicurist the whole time you've "+
	  "been here!","corpse":"A poor human just doing his job. Oh well. You "+
	  "could probably 'loot' the corpse before someone else does.","elf":
	  "He is not here. You stand looking at where he was for several hours "+
	  "trying to grasp that concept." ]) );
	add_item("thranx","Well, it looks like you can't "+
	  "show off your skills at protecting peace and justice in the world because somebody "+
	  "already has!");
    }
    add_action("loot_corpse","loot");
}

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set("short","A sight of commotion");
    set("long","Here a large group of people have assembled. You cannot "+
      "see what is the center of their attention, but you guess it is "+
      "something violent. As you push and shove to get a good view you "+
      "trip on something. After making sure the nail you broke is ok you "+
      "look to see what it is- a corpse! A young elf notices your interest "+
      "and explains 'He's the tax collector. He came in to evict some "+
      "thranx who's papers were not in order from the city, and the "+
      "guy just went on a rampage.' You wonder why someone would not "+
      "want to leave this city. When you turn to ask the young elf, he is gone. "+
      "You become even more puzzled when you realize that he never said a "+
      "word, but instead communicated to you telepathically. You shrug it "+
      "off and decide to see what you can do to help.");
    set_items( ([ ({"group","people"}):"They seem to be watching a thranx "+
      "beat the pulp out of fellow nonhumans.","nail":"Great, you broke "+
      "it! And you haven't seen a descent manicurist the whole time you've "+
      "been here!","corpse":"A poor human just doing his job. Oh well. You "+
      "could probably 'loot' the corpse before someone else does.","elf":
      "He is not here. You stand looking at where he was for several hours "+
      "trying to grasp that concept." ]) );
    set_exits( (["east":"/wizards/excelsior/rooms/street4.2",
      "west":"/wizards/excelsior/rooms/street4.4" ]) );
}

int loot_corpse(string str) {
    object money;
    int amount;
    if ( str != "corpse" ) {
	write("Do you want to loot your nose?");
	return 1;
    }
    if ( loot_ok == 1 ) {
	loot_ok++;
	write("You feel very dirty as you lift off some taxpayers money "+
	  "from the corpse.");
	money = new("/std/obj/coins");
	amount = random(10);
	money->set_money("gold",amount);
	money->set_money("copper",amount + 4);
	money->move( this_player() );
	return 1;
    }
    else
    {
	write("Oh darn! Someone has already looted the corpse!");
	return 1;
    }
}
