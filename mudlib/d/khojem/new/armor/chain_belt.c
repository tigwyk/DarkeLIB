//  Wizard:  Khojem
//  Chain Belt
//  chain_belt.c

inherit "/std/armour";

object shadow;

void create() {
    ::create();
    set_name("chain belt");
    set("id", ({ "belt", "chain belt" }) );
    set("short", "chain belt");
    set("long", "A heavy, chain-link belt.");
    set_weight(160);
    set("value", 100);
    set_type("belt");
    set_ac(10);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_remove" :) );
}


int extra_worn(){
  if((string)this_player()->query_class() != "fighter") {
    message("info", "You can't seem to figure out how to wear it!",
      this_player());
    return 0;
  }
  shadow=clone_object("/d/khojem/new/shadow/con5");
  shadow->start_shadow(this_player());
  message("info", "You feel the power of the belt fill your mortal body.",
    this_player());
  return 1;
}

int extra_remove(){
  shadow->external_destruct(shadow);
  message("info", "The belt's power drains from your body.",
    this_player());
  return 1;
}
