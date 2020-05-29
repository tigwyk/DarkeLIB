
#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("sentinal");
    set_id( ({ "sentinal" }) );
	set_short("A Sentinal");
     set("race", "high-man");
    set_long(
"The guard stands in front of the west exit.");
    set_body_type("human");
   set_level(18);
   set_skill("attack", 100);
set_skill("shield bash", 100);
    set_overall_ac(60);
    set_stats("strength", 300);
    set_property("handedness", "right hand");
    new("/d/damned/virtual/long-sword_5.weapon")->
      move(this_object());
    new("/d/damned/virtual/large-shield.armour")->
      move(this_object());
    new("/d/damned/virtual/chain-vest.armour")->
      move(this_object());
new("/d/damned/virtual/plate-greaves.armour")->
      move(this_object());
        new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
        new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
    force_me("wear vest");
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
    force_me("wear greaves");
    force_me("wear bracer 2 on right arm");
    force_me("wear bracer on left arm");
}

void catch_tell(string str) {
string a,b;
object ob1;
object ob2;
if(sscanf(str, "%s attacks %s", a, b) ==2){
a = lower_case(a);
b= lower_case(b);
ob1 = present(a, environment(this_object()));
ob2= present(b, environment(this_object()));
if(!ob1 || !ob2) return;
if(ob1->query_name() != "sentinal") {
force_me("kill "+a);
return;
}
}
}
