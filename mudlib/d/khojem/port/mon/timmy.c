//  Khojem
//  Monster:  Timmy
//  timmy.c

//  believe it or not I actually know this guy.  what a loser!

#include <std.h>

inherit MONSTER;

int query_kho_mon();
int query_kho_mon() { return 1;}

create() {
  int zspeed;
  object obj,money;
  ::create();
    set_name("Timmy");
    set_id( ({ "tim", "timmy" }) );
    set_level(1);
    set_short("Timmy a hapless fool is here");
    set_long("Timmy is a bearded, hunched man with furtive "+
      "eyes.  His finger is constantly up his nose, but he "+
      "removes it when you look his way.  Once your "+
      "head is turned, the finger returns to his nose.  "+
      "Timmy looks like he wants to put his finger up his nose."
    );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    set_wimpy(50);
	set_languages(({ "common" }));
	set_lang_prof("common",10);
	set_primary_lang("common");
    set_moving(1);
    zspeed=50+random(20);
    set_speed(zspeed);
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+10));
    money->move(this_object());
}
 
void catch_tell(string str) {
  string a;
  object ob1;
  if(sscanf(str, "%s looks you over.", a) == 1) {
    message("info", "Timmy removes his finger from his nose.\n",
	  environment(this_object()));
    return;
  }
  return;
}

