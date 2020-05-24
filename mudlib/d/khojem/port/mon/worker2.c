//  Wizard:   Khojem
//  Non-moving version of worker1.c
//  File:     worker2.c  

#include <std.h>

inherit MONSTER;

int query_kho_mon();
int query_kho_mon() { return 1;}

create() {
  object money,carry,obj;
  int    zlevel,roll,qual,flag;  
  ::create();
    set_name("worker");
    set_id( ({ "worker", "mob" }) );
    roll=random(10);
    switch(roll){
      case 0:zlevel=3;break;
      case 1:zlevel=3;break;
      case 2:zlevel=3;break;
      case 3:zlevel=4;break;
      case 4:zlevel=4;break;
      case 5:zlevel=4;break;
      case 6:zlevel=4;break;
      case 7:zlevel=5;break;
      case 8:zlevel=5;break;
      case 9:zlevel=5;break;
    }
if (zlevel == 3) set_short("[3]worker");
else 
if (zlevel == 4) set_short("[4]worker");
else
if (zlevel == 5) set_short("[5]worker");
else set_short("[6]worker");
    set_level(zlevel);
    set_long("The dock worker is going about his tasks." 
      );
    set("race", "half-elf");
    set_gender("male");
    set_body_type("human");
    set_wimpy(10);
	set_languages(({ "middle-english","common","elvish","serra" }));
	set_lang_prof("middle-english",10);
	set_lang_prof("common",10);
	set_lang_prof("elvish",10);
	set_lang_prof("serra",9);
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+(10*zlevel)));
    money->move(this_object());
    carry=new("/d/khojem/port/obj/acontainer");
    qual = 2 + random(5);
    flag = random(51);
    if(flag == 0) {
      obj=new("std/obj/coins");
      obj->set_money("mithril",random(10));
      obj->move(carry);
    }
    if(flag == 1) {
      obj=new("/d/damned/virtual/broad-sword_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 2) {
      obj=new("/d/damned/virtual/long-sword_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 3) {
      obj=new("/d/damned/virtual/dagger_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 4) {
      obj=new("/d/damned/virtual/footman's-mace_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 5) {
      obj=new("/d/damned/virtual/battle-axe_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 6) {
      obj=new("/d/damned/virtual/hand-axe_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 7) {
      obj=new("/d/damned/virtual/footman's-flail_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 8) {
      obj=new("std/obj/coins");
      obj->set_money("gold",random(20));
      obj->move(carry);
    }
    if(flag == 9) {
      obj=new("/d/damned/virtual/glaive_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 10) {
      obj=new("/d/damned/virtual/halberd_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 11) {
      obj=new("/d/damned/virtual/bastard-sword_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 12) {
      obj=new("/d/damned/virtual/short-sword_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 13) {
      obj=new("/d/damned/virtual/two-handed-sword_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 14) {
      obj=new("/d/damned/virtual/great-axe_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 15) {
      obj=new("/d/damned/virtual/quarter-staff_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 16) {
      obj=new("/d/damned/virtual/morning-star_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 17) {
      obj=new("/d/damned/virtual/scimitar_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 18) {
      obj=new("/d/damned/virtual/war-hammer_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 19) {
      obj=new("/d/damned/virtual/hammer_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 20) {
      obj=new("/d/damned/virtual/military-pick_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 21) {
      obj=new("/d/damned/virtual/spear_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 22) {
      obj=new("/d/damned/virtual/trident_"+qual+".weapon");
      obj->move(carry);
    }
    if(flag == 23) {
      obj=new("/d/damned/virtual/breast-plate.armour");
      obj->move(carry);
    }
    if(flag == 24) {
      obj=new("/d/damned/virtual/corslet.armour");
      obj->move(carry);
    }
    if(flag == 25) {
      obj=new("/d/damned/virtual/chain-coif.armour");
      obj->move(carry);
    }
    if(flag == 26) {
      obj=new("/d/damned/virtual/scale-greaves.armour");
      obj->move(carry);
    }
    if(flag == 27) {
      obj=new("/d/damned/virtual/iron-greaves.armour");
      obj->move(carry);
    }
    if(flag == 28) {
      obj=new("/d/damned/virtual/scale-mail.armour");
      obj->move(carry);
    }
    if(flag == 29) {
      obj=new("/d/damned/virtual/chain-greaves.armour");
      obj->move(carry);
    }
    if(flag == 30) {
      obj=new("/d/damned/virtual/chain-mail.armour");
      obj->move(carry);
    }
    if(flag == 31) {
      obj=new("/d/damned/virtual/studded-leather-jacket.armour");
      obj->move(carry);
    }
    if(flag == 32) {
      obj=new("/d/damned/virtual/studded-leather-vest.armour");
      obj->move(carry);
    }
    if(flag == 33) {
      obj=new("/d/damned/virtual/studded-leather-pants.armour");
      obj->move(carry);
    }
    if(flag == 34) {
      obj=new("/d/damned/virtual/leather-jacket.armour");
      obj->move(carry);
    }
    if(flag == 35) {
      obj=new("/d/damned/virtual/leather-pants.armour");
      obj->move(carry);
    }
    if(flag == 36) {
      obj=new("/d/damned/virtual/leather-vest.armour");
      obj->move(carry);
    }
    if(flag == 37) {
      obj=new("/d/damned/virtual/great-helm.armour");
      obj->move(carry);
    }
    if(flag == 38) {
      obj=new("/d/damned/virtual/cloak.armour");
      obj->move(carry);
    }
    if(flag == 39) {
      obj=new("/d/damned/virtual/cloth-pants.armour");
      obj->move(carry);
    }
    if(flag == 40) {
      obj=new("/d/damned/virtual/wall-shield.armour");
      obj->move(carry);
    }
    if(flag == 41) {
      obj=new("/d/damned/virtual/large-shield.armour");
      obj->move(carry);
    }
    if(flag == 42) {
      obj=new("/d/damned/virtual/small-shield.armour");
      obj->move(carry);
    }
    if(flag == 43) {
      obj=new("/d/damned/virtual/buckler-shield.armour");
      obj->move(carry);
    }
    if(flag == 44) {
      obj=new("/d/damned/virtual/gauntlet.armour");
      obj->move(carry);
    }
    if(flag == 45) {
      obj=new("/d/damned/virtual/chain-glove.armour");
      obj->move(carry);
    }
    if(flag == 46) {
      obj=new("/d/damned/virtual/iron-bracer.armour");
      obj->move(carry);
    }
    if(flag == 47) {
      obj=new("/d/damned/virtual/studded-leather-glove.armour");
      obj->move(carry);
    }
    if(flag == 48) {
      obj=new("/d/damned/virtual/boiled-leather-glove.armour");
      obj->move(carry);
    }
    if(flag == 49) {
      obj=new("/d/damned/virtual/leather-glove.armour");
      obj->move(carry);
    }
    if(flag == 50) {
      obj=new("/d/damned/virtual/padded-glove.armour");
      obj->move(carry);
    }
    carry->move(this_object());
    carry->toggle_closed();
}

void directed_message(object from,string what) {
  set_primary_lang((string)from->query_primary_lang());
  if(!query_primary_lang()) set_primary_lang("common");
  if(what[0..3] == "work")
    command("say Work is a chore and a bore, but it puts food on the table.");
  else
    command("say I wish I could visit some of the addresses on these boxes and "+
      "crates.");
}

