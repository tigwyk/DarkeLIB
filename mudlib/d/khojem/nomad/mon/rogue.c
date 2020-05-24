//  Wizard:   Khojem
//  Monster:  Nomad Rogue
//  File:     rogue.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

void init() {
  string str;
   ::init();
  if(!this_player()->is_player()) return;
  if(this_player()->query_invis()) return;
  if(random(10)) {
    str="use back stab at "+this_player()->query_name();
    force_me(str);
    return;
  }
  str="use pick pocket at "+this_player()->query_name();
  force_me(str);
}

void reset() {
   ::reset();
   force_me("use invisibility art");
}

void create() {
  object money;
  int    zlevel;
   ::create();
    set_name("nomad peasant");
    set_id( ({ "shadowy figure", "man", "rogue", "thief", "nomad", "figure",
          "shadowy", "peasant", "nomad peasant" }) );
    zlevel=15+random(3);

if (zlevel == 15) set_short("[15]nomad peasant");
else 
if (zlevel == 16) set_short("[16]nomad peasant");
else
if (zlevel == 17) set_short("[17]nomad peasant");
else
if (zlevel == 18) set_short("[18]nomad peasant");
else set_short("[19]nomad peasant");
	set_level(zlevel);

    set_long("He is a hooded, full-bearded man with a mischevious glint "+
      "in his eyes.  He seems to wander aimlessly through camp." 
      );
    set("race", "high-man");
    set_gender("male");
    set_class("thief");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 30]));
    set_skill("pick pocket",100);
    set_skill("back stab",80);
    set_skill("invisibility art",75);
    set_wimpy(0);
    set_moving(1);
    set_speed(180);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(5, ({
      "The shadowy figure darts quickly to the left.",
      "The shadowy figure darts quickly to the right.",
      "The shadowy figure ducks your swing."
      "The shadowy figure ducks your swing."
    }),1);
    set_speech(2,"common",({ 
      "Oh!  That was a good move!",
      "Argh!  Foiled again!",
      "I'll get away!  I always do!",
    }),1);
    money=new("std/obj/coins");
    money->set_money("silver",((random(20))+80));
    money->move(this_object());
    new("/d/khojem/nomad/weapon/viper_fangs")->move(this_object());
    force_me("wield sword in right hand");
    force_me("use invisibility art");
}

int query_kho_mon() { return 1;}
