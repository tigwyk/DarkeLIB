inherit "std/room";


void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit("/d/damned/akkad/ak_bless4", "west");
    add_exit("/d/damned/akkad/ak_bless3","east");
    add_exit("/d/damned/akkad/ak_ngate","north");
    add_exit("/d/damned/akkad/ak_victory7","south");
    set("short","   0\n   | \n0--@--0\n   | \n   0\nIntersection of Victory and Blessing Way");
    set("long","You are standing at the intersection of Victory Street and "+
	"the Blessing Way.  To the east is the church and the various "+
	"clerical guilds as well as hospitals to aid the many wounded. "+
	"Far to the south, you see the center of the city busy with its "+
	"many shops and businesses.  West of you is the Slum section " +
	"inhabited by various denizens known as lurkers.\n   0\n   | \n0--@--0\n   | \n   0\n");
    
}
