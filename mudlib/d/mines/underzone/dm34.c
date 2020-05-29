//      From Maxwell's Underground mudlib
//        34th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

string *weapon_names,*columns,*placed_pieces,*real_names;
string *column1,*column2,*column3;
int total_placed;
object master; 

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no spell", 1);
    set("short", "You are standing in some sort of underground temple.\n");
    set("long", 
     "You are standing in some sort of ancient underground temple. The "
     "walls are covered with huge murals depicting the history of the "
     "Dwarves. Three corridors lead out of the chamber, each between "
     "a set of massive stone pillars.\n");
    set_exits( ({ UNDER+"dm44",UNDER+"dm35",UNDER+"dm36",UNDER"dm37" }),
               ({ "up","southwest","southeast","north" }) );
    set_items( ([
       "pillars" : "The pillars are supporting the heavy ceiling",
       "murals"  : "The murals are of breathtaking and sometimes "
                   "revolting scenes.",
       "walls"   :  "The thick stone walls must weigh tons."]));
    set_smell("default", "The dust floating through the air is making "
                "it hard to breathe.");
//Quest Code
    columns = ({"silver column","gold column","steel column"});
    weapon_names = ({"silver blade","gold blade","shaft","steel shaft"});
    real_names = ({ UNQST+"sblade",UNQST+"gblade",UNQST+"shaft" });
    column1 = ({"silver column","the silver column"});
    column2 = ({"gold column","the gold column"});
    column3 = ({"steel column","the steel column"});
    placed_pieces = ({});   
    new(UNETC+"gong")->move(this_object());
}
void init() {
   ::init();
    add_action("place","place");
    if(query_property("x") == 2 && !present("silver column") )
       call_out("raise_columns",3,this_object());
}
int raise_columns(){
    tell_room(UNDER+"dm34","You can hear a low rumbling filling the room. "
              "Suddenly three slots open in the floor and 3 columns rise "
              "up and grind to a halt.");
    new(UNQST+"scol")->move(UNDER+"dm34");
    new(UNQST+"gcol")->move(UNDER+"dm34");
    new(UNQST+"stcol")->move(UNDER+"dm34");    
    set_property("x",0);
    return 1;
}
int place(string str) {
string what,where,item_file,*file_array;
int position,target;
  if(present("silver column")){
    if(!str) {
      write("Format is 'Place <object> on <destination>'");
      return 1;
    }
    if(str == "blade"){
      write("Place which blade on what?");
      return 1;
    }
    if(str == "shaft"){
      write("Place the shaft on what?");
      return 1;
    }
    if(sscanf(str,"%s on %s",what,where));
        { 
        position = (member_array(what,weapon_names));
        if(present(what,this_player())){
          item_file = file_name(present(what,this_player()) );
          file_array = explode(item_file,"#");
        }
        else{
           write("You don't have that!");
           return 1;
        }
        if(position == -1 ){
          write("That won't fit there!");
          return 1;
        }
        if(member_array(file_array[0],real_names) == -1 ){
           write("You don't have the right item!");
           return 1;
        }                        
        target = 0;
        if(position == 0 && member_array(where,column1) != -1 )
           target = 1;
        if(position == 1 && member_array(where,column2) != -1 )
            target = 1;
        if( ( position == 2 || position == 3)
              && member_array(where,column3) != -1 )
            target = 1;
//If the Where they picked is in the array
        if( target == 1){
           //If the item is in the placed item array
           if(member_array(what,placed_pieces) != -1){
              write("That piece has already been placed!");
              return 1;
           }
             if(!present(where)){
                write("The column is not here!");
                return 1;
             }
           //If the Where is in the Weapon Column Array 
              write("You place the "+what+" on the "+where+". It "
              "slides down inside the column and locks in place");
             say(this_player()->query_cap_name()+ " places the "+what+
                " on the "+where+". It slides down and locks in place.");
             tell_room(UNDER+"dm34","The column begins to shake and hum");
             (present(what, this_player()))->remove();
             if(position == 2 || position == 3)
               placed_pieces += ({ weapon_names[2],weapon_names[3] });
             else
               placed_pieces += ({what});
             (present(where))->desc();
             call_out("quest",1,this_player());
             master = this_player();
             total_placed = total_placed + 1;
             present(what,this_player())->remove();
             return 1;
 
         }
         else
            write("Where do you want to place the " + what + "?");
         return 1;
      }         
  }
 }

void quest(){
  if(total_placed == 3) {
     tell_room(UNDER+"dm34","\nThe colunms begin to vibrate and a low "
        "pulsing sound fills the room. A layer of dark colored mist "
        "slowly forms above the stone floor. The mist slowly swirls "
        "around your feet.\n");
     call_out("quest2",8,this_object()); 
  }
  return;
}
int query_size(){
    return sizeof(placed_pieces);
}
void quest2(){
  tell_room(UNDER+"dm34","Crack! Three bright beams of light suddenly "
      "radiate out of the columns! The beams stretch out and connect "
      "together in the center of the room. A bright green orb of light "
      "forms where the beams collide. It slowly begins to rotate as tiny "
      "bolts of electricity shoot off its surface.\n");
   call_out("quest3",8,this_object());
   return;
}
void quest3(){
  tell_room(UNDER+"dm34","The orb begins to rotate faster and you can "
      "see an object forming inside. The object becomes more solid as "
      "huge bursts of energy pulsate out of the columns. After another "
      "few seconds the object becomes a spining axe. The orb shatters in "
      "a flash of intense light and the axe slowly lowers to the ground!\n"
      "The three columns quickly sink down into the stone floor.\n");
    if(present("silver column"))
           present("silver column")->remove();
    if(present("gold column"))
           present("gold column")->remove();
    if(present("steel column"))
           present("steel column")->remove();
  new(UNQST+"daxe.c")->move(this_object());
  master->set_quest("axe of montar");
  write_file("/wizards/maxwell/objects/quest/axe_owner",
              getuid(master),1);
  write_file("/wizards/maxwell/objects/quest/quest_complete",ctime(time())+
             " "+getuid(master)+"obj\n");
  master->remove_action("place","place");
  return;
}

