// /wizards/excelsior/rooms/street5.2
// excelsior

inherit "std/room";

void create() {
::create();
set_property("light",1);
set_property("indoors",1);
set("short","The tunnel entrance/exit");
set("long","Here the street you are following becomes covered and more "+
"of a man made cave then anything inhabitable. None the less, many "+
"creatures call this part of town their home- and I mean creatures. "+
"Though there are plenty of poor humans in this city none of them "+
"stoop to living in the outcast quarter. That would just be too much. "+
"Hrm. You wonder how humans came too rule this city so absolutely, "+
"in a world dominated by a diversity of life forms. And of these "+
"life forms, humans are by no means the most powerful. Sad.");    
set_items( (["street":"It goes into a tunnel. Oooo.. scary.",
"tunnel":"Quite cave-like in structure. Fearsome indeed." ]) );
set_exits( (["north":"/wizards/excelsior/rooms/street5.3",
"south":"/wizards/excelsior/rooms/street5.1" ]) );
}
