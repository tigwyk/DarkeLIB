inherit "std/room";
#define ENTRY "/wizards/avatar/tyranid/rooms/0506"
void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive");
    set("long",@ext
You stand in front of a HUGE structure that vaguely resembles a
combination between a huge termite mound and some sort of gigantic
living being!  An entrance of sorts can be seen at the base, though an
unappealing brownish fluid appears to be leaking steadily from it.
       
        hole   
    @
        out
    
ext);
    set_exits( ([
	"out": "/d/damned/virtual/room_12_4.world",
	"hole": ENTRY,
      ]) );
	add_pre_exit_function("out","check_race");
}

int check_race() {
	if(this_player()->query_race() == "tyranid" ) {
		write("Tyranid are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}

void reset() {
    int i;
    ::reset();
    if(!present("marine"))
    {
	i = random(1)+1;
	while(i--)
	{
	    new("/d/1tlny/working/space_marine")->move(this_object());
	}
    }
}


