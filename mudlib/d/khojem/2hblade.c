// Wizard:  Khojem
// test 2hblade
// 2hblade.c

inherit "/std/weapon";

void init() {
  :: init();
  add_action("do_connect","connect");  // usage:  connect pommel
  add_action("do_release","release");  // usage:  release pommel
}

void create() {
   ::create();
  set_name("blade");
  set("id",({"blade"}));
  set_short("blade");
  set_long("A big, long two handed blade!");
  set_weight(1500);
  set_value(1000);
  set_ac(1);
  set_wc(50,"cutting");
  set_wc(8,"impaling");
  set_type("2hblade");
  set_quality(6);
  set("skill level",50);
  set_verb("slash");
  set_parry_bonus(-40);
  set_material("/metal/steel");
  set_property("connected",0);
}

int do_connect(string str) {
  if(str!="pommel") { return 0; }
  if(this_object()->query_property("connected")) {
    write("The pommel is already connected!");
    return 1;
  }
  if(!present("pommel")) {
    write("You don't have the right pommel.");
    return 1;
  }
  set_weight(800);
  set_long("A big long two handed blade with attached pommel!");
  set_value(3000);
  set_verb("lacerate");
  set_parry_bonus(15);
  set_property("connected",1);
  return 1;
}

int do_release(string str){
  object ob;
  if(str!="pommel") { return 0; }
  if(!(this_object()->query_property("connected"))) {
    write("The pommel is not connected!");
    return 1;
  }
  set_long("A big long two handed blade!");
  set_weight(1500);
  set_value(1000);
  set_verb("slash");
  set_parry_bonus(-40);
  set_property("connected",0);
  ob=new("/d/khojem/pommel");
  ob->move(this_player());
  return 1;
}
