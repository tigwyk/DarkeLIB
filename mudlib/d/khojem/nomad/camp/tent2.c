//      Tent 2
//      tent2.c

#include <std.h>

inherit ROOM;

int check_peasant();
int search_count;

void init() {
   ::init();
}

void reset() {
   ::reset();
  if(check_peasant()<7)
    new("/d/khojem/nomad/mon/peasant")->move(this_object());      
}

void create() {
  string desc;
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("night light",1);
  desc = "This tent serves as the communal living quarters of the "
    "camp's peasant population.  Numerous lice-infested bedrolls, "
    "sheets, towels and robes litter the floor of this huge tent.  "
    "Children and dogs run wild through the large space.";
  set("day long","The daytime sun beating down on the tent's roof "
    "turns the tent into a sweltering sauna.  "+desc  
  );
  set("night long","The torchlight sends odd, flickering shadows "
    "across the room.  "+desc
  );
  add_exit("/d/khojem/nomad/camp/tent1","southeast");
  set_items(([
    ({ "tent" }) :  
      "The tent has a low-pitch roof and is trussed with some "
      "timber bracing along the roof's center.  Numerous bedrolls "
      "are arranged on the sandy floor.",
    ({ "bedrolls", "robes", "towels", "sheets"}) :
      "Its a shame that these poor nomad folks have to live in such "
      "squalor.  Many objects that litter the sandy floor are teeming "
      "with lice and filthy.",
    ({ "torches" }) :
      "A few torches provide light to this large tent.",
    ({ "children", "dogs" }) :
      "The dogs and children are quick and dart about the tent "+
      "while keeping their distance from you.  They are much too "+
      "fast for your attack.",
    ({ "floor", "sand" }) :
        "What you can see of the sandy tent floor is littered with "+
        "peasant bedrolls and clothing."
  ]));
  set_search("floor",(: call_other, this_object(),"do_search" :));
  set_search("sand",(: call_other, this_object(),"do_search" :));
  set_search("bedrolls",(: call_other, this_object(),"do_search" :));
  set_search("robes",(: call_other, this_object(),"do_search" :));
  set_search("sheets",(: call_other, this_object(),"do_search" :));
  set_smell("default", "A musty smell fills the tent.");
  set_listen("default","It is quieter here than out in the "
    "camp's center."
  );
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

void do_search() {
  int skill;
  object money,obj;
  string str;
  message("info",this_player()->query_cap_name()+
    " appears to be searching the dirty bedrolls and "
    "soiled clothing.\n",this_object(),this_player()
  );
  skill=(int)this_player()->query_skill("perception");
  if((random(100)<skill-40) && search_count<1){
    search_count++;
    skill = random(100) + 20;
    message("info","Your search is successful.  You "
      "discover "+skill+" silver coins and quickly "
      "scoop them up and place them in your pocket.\n",
      this_player()
    );
    message("info",this_player()->query_cap_name()+
      "reaches down and picks something up off the "
      "sandy floor.",this_object(),this_player()
    );
    this_player()->add_money("silver",skill);
    return;
  }
  if((random(100)<(skill-20)) && search_count==2){
    search_count++;
    obj = new("/d/khojem/nomad/obj/glowstick");
    str = "glowstick";
    message("info","As you search the mess on the floor "
      "you find a "+str+".  You quickly fetch it.\n",
      this_player()
    );
    message("info",this_player()->query_cap_name()+
      " finds "+str+" and quickly trys to pick it up!\n",
      this_object(),this_player()
    );
    obj->move(this_player());
    return;
  }
  message("info","Your search yields nothing.",this_player());
  return;
}
