//  Wizard:  Khojem
//  Slot Machine
//  slot_machine.c
 
#include <std.h>

inherit OBJECT;

void init() {
	::init();
	add_action("rollim","pull");
}
 
void create() {
  ::create();
    set_name("slot machine");
    set_id( ({ "slot machine", "one-arm bandit" }) );
    set_short("A slot machine");
    set_long("A slot machine with a long handle.\n"+
      "A plaque says:  10 silver coins per play\n"+
      "\n"+
      "Payoff -        Double zeros: 1000 silver coins.\n"+
      "\n"+
      "PULL to play\n"
    );
    set_weight(9000);
    set_value(0);
}

int rollim(){
  int x,y;
  if((int)this_player()->query_money("silver") < 10) {
    write("You search your pockets... but can't find to 10 silver "+
      "coins needed to play.");
    return 1;
  }
  say(this_player()->query_cap_name()+" plays the slot machine.\n");
  this_player()->add_money("silver", -10);
  x = random(10);
  y = random(10);
  if(x==y) 
    if (x==0) {
      write(x+" "+y+"   YOU WIN 1000 SILVER COINS!\n");
      this_player()->add_money("silver", 1000);
      }
  else write(x+" "+y+ "   Sorry you lose.\n");
  return 1;
}
