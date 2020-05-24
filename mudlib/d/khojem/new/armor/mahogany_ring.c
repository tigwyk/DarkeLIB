//  Wizard:  Khojem
//  Mahogany Ring
//  mahogany_ring.c

inherit "/std/armour";

object shadow;

void create() {
    ::create();
    set_name("mahogany ring");
    set("id", ({ "ring", "mahogany ring" }) );
    set("short", "mahogany ring");
    set("long", "A polished mahogany ring.");
    set_weight(5);
    set("value", 2000);
    set_type("ring");
    set_limbs( ({ "right hand", "left hand" }) );
    set_ac(1);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_remove" :) );
}

int extra_worn(){
  shadow=clone_object("/d/khojem/new/shadow/strength2");
  shadow->start_shadow(this_player());
  return 1;
}

int extra_remove(){
  shadow->external_destruct(shadow);
  return 1;
}
