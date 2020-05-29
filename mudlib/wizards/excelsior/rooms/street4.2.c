// /wizards/excelsior/rooms/street4.2
// the road continues
// this was created by you know who
inherit "std/room";
create() {
::create();
set_property("light",1);
set_property("indoors",1);
set("short","Tunnel Entrance");
set("long","Here the street enters a large tunnel. On top of the "+
"tunnel is another street. You see no where up from here and guess "+
"it was built that way because you are, after all, in the outcast "+
"quarter and you suppose the humans above want nothing to do with this "+
"place. Deeper inside the tunnel you see little because it is very "+
"dark. A few torches are lit along the walls but most of them are out. "+
"You think that if you ran this city you would fire the torch lighter "+
"guy. But then you think that lighting torches is the only source of "+
"income that guy must have for 5 children, a wife, and a grandma- and "+
"then there's the rent. Aye! Some panhandling orcs are here, "+
"but being as you have better things to spend your money on you pretend "+ 
"not to see them. There seems to be a bit of a commotion off to the "+
"west. You notice a sign here attached to the tunnel wall.");
set_items( (["orcs":"Don't look at them! You're pretending you don't "+
"see them, remember? If they notice you looking at them your guilt may "+
"force you to spare them some change!","tunnel":"You're in it, bub.",
"torches":"Excelsior doesn't want to explain these again. Read the "+
"long description.","commotion":"Go west and see. I wonder what it "+
"could be?","sign":"The sign was meant to say: 'Street 36b- Pandora "+
"Tunnel', but scrawled across it in what appears to be blood are the "+
"words: 'Welcome to planet Mother Fucker. Human Lovers enter at own "+
"risk'.","blood":"You lick it and your spectacular taste buds tell "+
"you that it is human in origin."  ]) );
set_exits( (["east":"/wizards/excelsior/rooms/street4.1",
"west":"/wizards/excelsior/rooms/street4.3" ]) );
}
