//      Wizard:  Khojem
//      earl's mansion
//      e2.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "a stately courtyard");
    set("long", "The Earl of Vo'Sangor has a fine courtyard just off the main "+
      "entrance to his mansion.  Many rare and exotic flora can be seen thriving "+
      "here.  The cinder pathway is lined with many shells from the nearby reef."
    );
    add_exit("/d/khojem/port/room/e6","north");
    add_exit("/d/khojem/port/room/e1","south");
    set_items(([
     ({ "flora", "plant", "plants" }) :
        "They look like the kind of things rich people spend their money on.",
     ({ "shell", "shells", "pathway", "cinder pathway", "cinder" }) :
        "The broad, cinder pathway is well maintained and lined with various "+
        "seashells with intricate whirling patterns.", 
     ({ "mansion", "wall", "walls" }) :
        "The main portion of the mansion is to the south.  Off to the north "+
        "another building can be seen.  The courtyard is surrounded by high "+
        "walls and ivy can be seen growing on the walls' surface.",
    ]));
    set_smell("default", "A fresh, earthy smell fills the air.");
    set_listen("default", "Numerous birds sing and chirp.");
}
