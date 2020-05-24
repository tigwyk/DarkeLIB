
#include <move.h>
inherit OBJECT;

int move(object dest) {
   if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
   return ::move(dest);
}
void create() {
   ::create();
set_name("stream");
set_id(({ "stream, water" }) );
set_short("A green stream");
set_long("The stream stretchs several feet across. Green water flows down
the stream. The slug green water does not look very healthy. The stream is
so deep that it could drown a full grown giant.");
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
if( !(str == "stream") ) { 
   notify_fail("What do you want to drink?");
   return 0; 
}
   if(TP->query_quenched() > 420) {
   message("info", "You've had all you can drink right now.", TP);
   return 1;
}
message("info", "You carefully reach down and scoop up some of the green
water with your hands. You spit out the water. 'EWWWWWW.... SEWAGE!!!'",
TP);
   TP->add_quenched(-1000);
   count = 0;
   while( (TP->query_quenched() < 450) && (count < 90 ) ) {
TP->add_quenched(-10);
TP->add_poisoning(30);
   count += 1;
}
   switch(random(2)) {
case 0: drink = " shoves "+(string)TP->query_possessive()+ " hands into the
green water to take a drink. Then spits out the water.";
   break;
case 1: drink = " carefully reaches down and scoops up some of the green
water with his hands. Then spits out the water.";
   break;
}
   say(TPQCN+drink);
   return 1;
}

