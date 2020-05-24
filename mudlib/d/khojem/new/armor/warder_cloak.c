//  Wizard:  Khojem
//  Warder Cloak
//  cloak.c

inherit "/std/armour";

object shadow;

void create() {
    ::create();
    set_name("warder cloak");
    set("id", ({ "cloak", "warder cloak" }) );
    set("short", "A warder cloak");
    set("long", "A warder cloak which is worn alone or over other armour.  "+
      "The sturdy cloth of this fine cloak seems to change slightly and "+
      "blend with the background.");
    set_weight(60);
    set("value", 1500);
    set_type("cloak");
    set_limbs( ({ "torso" }) );
    set_ac(7);
    set_wear( (: call_other, this_object(), "extra_worn" :) );
    set_remove( (: call_other, this_object(), "extra_remove" :) );

}

int extra_worn(){
  shadow=clone_object("/d/khojem/new/shadow/hide_shadow.c");
  shadow->start_shadow(this_player());
  return 1;
}

int extra_remove(){
  shadow->external_destruct(shadow);
  return 1;
}

void remove() {
  if(!::remove())return;
  return;
}
