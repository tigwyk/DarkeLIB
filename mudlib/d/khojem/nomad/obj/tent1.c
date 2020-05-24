//      Wizard:  Khojem
//      Tent 1
//      tent1.c

#include <std.h>

inherit ROOM;

int check_mobs();
int check_peasant();
int search_count;

void init() {
    ::init();
}

void reset() {
    ::reset();
    if(check_mobs()<1) {
      new("/d/khojem/nomad/mon/rogue")->move(this_object());
    }
    if(check_peasant()<10) {
      new("/d/khojem/nomad/mon/peasant")->move(this_object());
      new("/d/khojem/nomad/mon/peasant")->move(this_object());
    }      
}

void create() {
  object obj;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("night light",1);
    set("day long",
      "The daytime sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "
      "The tent serves as communal lodgings for the camp's peasant population.  "+
      "Numerous lice-infested bedrolls, sheets, towels and robes litter the "+
      "floor of this huge tent.  Children and dogs run wild through the large "+
      "space.\n"
   );
    set("night long",
      "The torchlight sends odd, flickering shadows across the room.  "+
      "The tent serves as communal lodgings for the camp's peasant population.  "+
      "Numerous lice-infested bedrolls, sheets, towels and robes litter the "+
      "floor of this huge tent.  Children and dogs run wild through the large "+
      "space.\n"
    );
    add_exit("/d/khojem/nomad/camp/center","southeast");
    add_exit("/d/khojem/nomad/camp/tent2","northwest");
    set_items(([
     ({ "tent" }) :  
        "The tent has a low-pitch roof and is trussed with some timber bracing along "+
        "the roof's center.  Numerous bedrolls are arranged on the sandy floor.",
     ({ "bedrolls", "robes", "towels", "sheets"}) :
        "Its a shame that these poor nomad folks have to live in such squalor.  "+
        "The items are alive with lice and filthy.  They litter the floor of the "+
        "tent.",
     ({ "torches" }) :
        "A few torches provide light to this large tent.",
     ({ "children", "dogs" }) :
        "The dogs and children are quick and dart about the tent while keeping "+
        "their distance from you.  They are much too fast for your attack.",
     ({ "floor", "sand" }) :
        "What you can see of the sandy tent floor is littered with pheasant "+
        "bedrolls and clothing."
    ]));
    set_search("floor",    (: call_other, this_object(),"do_search" :));
    set_search("sand",     (: call_other, this_object(),"do_search" :));
    set_search("bedrolls", (: call_other, this_object(),"do_search" :));
    set_search("robes",    (: call_other, this_object(),"do_search" :));
    set_search("sheets",   (: call_other, this_object(),"do_search" :));
    set_smell("default", "A musty smell fills the tent.");
    set_listen("default", "It is quieter here than out in the camp's center.");
    obj=new("/d/khojem/nomad/obj/basket");
    obj->move(this_object());
    obj->toggle_closed();  
    search_count=0;  
}
int check_peasant() {
  object *all;

  all = filter_array(livings(), "my_peasant_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_peasant_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/peasant")  
    return 1;                                        
  return 0;
}                                      

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/rogue")  
    return 1;                                        
  return 0;
}                                      

void do_search() {
  int skill;
  object money;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "the dirty bedrolls and soiled clothing.\n");
  skill=(int)this_player()->query_skill("perception");
  if((random(100)<skill) && search_count<2){
    search_count++;
    write("Your search is successful.");
    money = new("std/obj/coins");
    skill=random(10)+skill;
    money->set_money("silver",skill);
    money->move(this_player());
    write("You find some silver coins in the mess on the floor.");
  }
  else
    write("Your search yields nothing.");
  return;
}
