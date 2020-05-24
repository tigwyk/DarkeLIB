//      Wizard:  Khojem
//      earl's mansion
//      e3.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "A massive mansion");
    set("long", "The balcony is elaborately furnished with heavy slate "+
      "floors and oil paintings.  The walls are paneled in english oak.  "+
      "A wide, slate staircase leads down to a grand foyer which can be seen "+
      "from over the brass railing of the balcony.  An archway leads south to "+
      "an adjoining room."
    );
    add_exit("/d/khojem/port/room/e1","down");
    add_exit("/d/khojem/port/room/e5","south");
    set_items(([
     ({ "brass railing", "brass rail", "railing", "rail" }) :
        "A highly-polished, exquisitely crafted rail borders the balcony.",
     ({ "oil paintings", "paintings" }) :
        "Paintings of the Earl of Vo'Sangor as a young man line the balcony's "+
        "wall.  In many he is dressed as a soldier with polished armour and "+
        "armed with sword and lancet.  Often mounted on a fine white stallion.", 
     ({ "mansion", "foyer" }) : "It's a hell of a pad!",
     ({ "crystal chandelier", "chandelier", "ceiling" }) :
        "Gazing upwards at the momentarily awed by the crystal chandelier's "+
        "exquisite beauty.  Never before have you seen such finely crafted "+
        "work.",
     ({ "furniture", "mahogany furniture" }) :
        "The mahogany furniture was probably imported.  It's wood is highly "+
        "polished.",
     ({ "floors", "slate floors", "floor" }) :
        "The slate floors are finely crafted and well maintained.",
     ({ "walls", "wall", "english oak", "english oak walls", "paneling" }):
        "The english oak wall paneling is highly polished and of the finest "+
        "quality.  It is exquisitely molded with fine details and scrollwork.",
     ({ "stairs", "staircase", "steps", "slate staircase" }) :
        "A wide slate staircase leads down to a spacious foyer.",
    ]));
    set_listen("default", "You hear voices to the south.");
}

