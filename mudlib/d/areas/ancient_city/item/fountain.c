
#include <move.h>
inherit OBJECT;

int move(object dest) {
   if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
   return ::move(dest);
}
void create() {
   ::create();
   set_name("fountain");
   set_id(({ "fountain" }) );
set_short("An stone fountain");
set_long("The fountain stands several times your height and glistens in the
unholy light reflecting off the stone.  Its shimmering showers of water
attract much attention as they cascade forever downward.  Several layers of
black stone hold the water until it spills over into a lower level.  The
water is shot up from the lower layer all the way to the top where it
begins its journey endlessly again.");
}
void init() {
   ::init();
   add_action("drink_fountain", "drink");
}
int drink_fountain(string str) {
   string drink;
   int count;
   if(!str) {
   notify_fail("What do you want to drink?");
   return 0;
}
   if( !(str == "fountain") ) { 
   notify_fail("What do you want to drink?");
   return 0; 
}
   if(TP->query_quenched() > 420) {
   message("info", "You've had all you can drink right now.", TP);
   return 1;
}
   message("info", "You carefully reach down and scoop up some water with
your dirty hands.  Even before you can finish your drink you notice the
water you had contaminated was made crystal clear again.", TP);
   TP->add_quenched(-1000);
   count = 0;
   while( (TP->query_quenched() < 450) && (count < 90 ) ) {
TP->add_quenched(5);
   count += 1;
}
   switch(random(2)) {
   case 0: drink = " shoves "+(string)TP->query_possessive()+ " grimy hands
into the fountain and scoops up some water.  Even before he can finish his
drink the water he contaminated was made crystal clear again.";
   break;
   case 1: drink = " carefully reaches down and scoops up some water with
his dirty hands.  Even before he can finish his drink the water he
contaminated was made crystal clear again.";
   break;
}
   say(TPQCN+drink);
   return 1;
}

