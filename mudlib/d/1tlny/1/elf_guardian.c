//elf_guardian.c coder:Diewarzau modifier:Byon
/*
 * This is a good example of a freaking hard monster to kill.  Challenging
for a party of
 * 25th or so level players.  He has several cool features, including he
shield bashes, and
 * he will try to get off a spell at someone if they try to spell him
first.
 *
 *  Diewarzau
 */

#include <std.h>

inherit MONSTER;

create() {
  object ob;
  
  ::create();
    set_name("guardian");
    set_id( ({ "elf", "elf guardian", "guardian" }) );
    set_short("An Elf Guardian");
    set("race", "high-elf");
    set_languages(({ "elvish", "common" }));
    set_long(
    "The Guardian is abnormally well-muscled for an elf, and bears the
scars of battle.  "
    "The aura of learnedness rests also upon his brow.  You suspect that
this fellow "
    "is a worthy opponent for even the most seasoned combatant.");
    set_body_type("human");
    set_level(25);
    set_property("melee damage", ([ "crushing" : 60]));
    set_skill("melee", 125);
    set_skill("dodge", 110);
    set_skill("parry", 165);
    set_skill("block", 165);
    set_skill("blade", 195);
    set_stats("dexterity", 90);
    set_skill("elementalism", 110);
    set_skill("electricity lore", 110);
    set_skill("whirlwind attack", 110);
    set_skill("resist stun", 100);
    set_skill("spell sense", 80);
    set_skill("shield bash", 110);
    set_property("enhance criticals", -2);
    set_overall_ac(100);
    set_spell_level("greater elemental bolt", 5);
    add_spell("greater elemental bolt", "$A");
    set("see invis", 1);
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob->set_material("metal/iysaughton");
    ob->set_property("brittle", 80);
    ob->set_property("enchantment", 20);
    ob->set_hit_bonus(25);
    ob->set_wc(12, "fire");
    ob->set_wc(12, "electricity");
    ob->move(this_object());
    force_me("wield sword in right hand");
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->set_material("metal/mithril");
    ob->set_property("brittle", 80);
    ob->set_property("enchantment", 20);
    ob->move(this_object());
    force_me("wear shield on left hand");
    set_combat_chance(200);
    set_exp(3000000);
}

string query_element() { return "electricity"; }

void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(!this_object()->query_casting() && sscanf(str, "%s begins casting a
spell.", who)) {
    if(who == "Someone") {
      inv = all_inventory(environment());
      inv = filter_array(inv, (: call_other :), "is_player");
      inv = filter_array(inv, (: call_other :), "query_invis");
      inv = filter_array(inv, (: call_other :), "query_casting");
      if(!sizeof(inv)) {
        return;
      }
      plyr = inv[0];
    }
    else
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player() && (int)plyr->query_level() > 15) {
      force_me("cast *5 greater elemental bolt at
"+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() &&
(inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *6 elemental storm");
    else if(sizeof(inv))
      force_me("cast *6 greater elemental bolt at "+
        (string)inv[0]->query_name());
  }
  return;
}

void init() {
  ::init();
  add_action("block_exit", "north");
  if(this_player()->is_player() && (int)this_player()->query_level() > 15
&&
    this_player()->query_casting() && !query_casting()) {
    force_me("speak common");
    force_me("say How dare you try to come into my domain, spell already
casting?!  "
       "Die, "+capitalize((string)this_player()->query_name())+"!");
    force_me("cast *5 greater elemental bolt at
"+(string)this_player()->query_name());
    kill_ob(this_player(), 1);
  }
  return;
}

int block_exit(string null) {
  string name = capitalize((string)this_player()->query_name());
  
  if(!this_player()->is_player()) return 0;
  if(wizardp(this_player())) return 0;
  if((int)this_player()->query_level() <= 15) return 0;
  force_me("speak common");
  if(!this_player()->query_invis()) {
    force_me("say I must not allow such powerful players as you, "+name+",
into "
        "the camp, for fear you would destroy it!");
  } else {
    write("To your great surprise, the elf guardian lays a hand on you
invisible shoulder!");
    force_me("say I don't like such tom-foolery as invisibility.  You may
not pass.");
  }
  return 1;
}

varargs void heart_beat(int flag) {
  if(query_current_attacker() && !random(4)) {
    force_me("use shield bash at
"+(string)(query_current_attacker()->query_name()));
  }
  ::heart_beat(flag);
  return;
}
